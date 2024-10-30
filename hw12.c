/*
 * CS 240 - Fall 2023 - Suresh Jagannathan
 * Please type your name in place of <Edythe Thompson> to verify that you will
 * not cheat on this homework.
 *
 * Academic Honesty Pledge:
 * I certify that this code is of my own original work, and not that of other
 * students, online services, or other dishonesty. If I need help on homework,
 * I will ask a TA or the professor.
 *
 * Signed, <Edythe Thompson>
 */

/*
 * Parts of this homework are from Jeff Turkstra's CS 240 class at Purdue Univ.
 */

#include "hw12.h"

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>


/*
 * We've included some helper functions below for debugging purposes
 * Make full use of them for hw12
 */

/*
 * Function to print the internal data of a app_t struct passed as a void
 * pointer to standard out
 */

void print_app_data(void *p) {
  app_t *ptr = (app_t *) p;
  assert(ptr && ptr->name);

  printf("%s: %dMB, $%.2f, %.2f/5\n", ptr->name, ptr->size, ptr->price,
         ptr->rating);
} /* print_app_data() */

/*
 * Function to print the internal data of a phone_t struct passed as a void
 * pointer to standard out
 */

void print_phone_data(void *p) {
  phone_t *ptr = (phone_t *) p;
  assert(ptr && ptr->model);

  printf("%s: %dGB, released %d, $%.2f, %.2f hours\n", ptr->model,
         ptr->storage, ptr->release_year, ptr->price, ptr->battery_life);
} /* print_phone_data() */

/*
 * Function to print the tree node by dynamically dispatching the print function
 * stored in the node on the data stored in the node
 */


void print_node(node_t *n_ptr) {
  assert(n_ptr && n_ptr->data && n_ptr->print);

  (n_ptr->print)(n_ptr->data);
} /* print_node() */

/*
 * Function to recursively print the tree using an in-order traversal
 */

void print_tree(node_t *root) {
  if (!root) {
    return;
  }

  print_tree(root->left_child);
  print_node(root);
  print_tree(root->right_child);

} /* print_tree() */


/* define the rest of the functions below (you can delete this comment) */

void create_app_data(void **p, const char *name, int size, float price,
                     float rating) {
  assert(p != NULL);
  assert(*p == NULL);
  assert(name != NULL);

  app_t *app = malloc(sizeof(app_t));
  app->name = malloc(sizeof(char) * strlen(name) + 1);

  strcpy(app->name, name);
  app->size = size;
  app->price = price;
  app->rating = rating;
  *p = (void *) app;

}

void delete_app_data(void **p) {
  assert(p);
  assert(*p);
  app_t *app_d = (app_t *) *p;
  app_d->price = 0;
  app_d->size = 0;
  app_d->rating = 0;
  free(app_d->name);
  free(app_d );
  *p = NULL;

}

int compare_app_data(void *vl, void *vr) {
  assert(vl);
  assert(vr);
  app_t *app1 = (app_t *) vl;
  app_t *app2 = (app_t *) vr;

  float comp1 = app1->rating / (app1->size * (app1->price + 1));
  float comp2 = app2->rating / (app2->size * (app2->price + 1));

  if (comp1 == comp2) {
    return 0;
  } else if (comp1 > comp2) {
    return 1;
  } else {
    return -1;
  }
}

void create_phone_data(void **p, const char *model, int storage,
                       int release_year, float price, float battery_life) {
  assert(p);
  assert(*p == NULL);
  assert(model);
  assert(storage);
  assert(release_year);
  assert(price);
  assert(battery_life);

  phone_t *phone = malloc(sizeof(phone_t));
  phone->model = malloc(sizeof(char) * strlen(model) + 1);

  strcpy(phone->model, model);
  phone->storage = storage;
  phone->release_year = release_year;
  phone->price = price;
  phone->battery_life = battery_life;
  *p = (void *) phone;
}

void delete_phone_data(void **p) {
  assert(p);
  assert(*p);
  phone_t *phone_d = (phone_t *) *p;
  phone_d->price = 0;
  phone_d->release_year = 0;
  phone_d->battery_life = 0;
  phone_d->storage = 0;
  free(phone_d->model);
  free(phone_d);
  *p = NULL;
}

int compare_phone_data(void *vl, void *vr) {
  assert(vl);
  assert(vr);
  phone_t *phone1 = (phone_t *) vl;
  phone_t *phone2 = (phone_t *) vr;

  float comp1 = (phone1->storage * phone1->battery_life) / (phone1->price * (CURRENT_YEAR - phone1->release_year));
  float comp2 = (phone2->storage * phone2->battery_life) / (phone2->price * (CURRENT_YEAR - phone2->release_year));

  if (comp1 == comp2) {
    return 0;
  } else if (comp1 > comp2) {
    return 1;
  } else {
    return -1;
  }
}

void create_node(node_t **node, void *data, void (*print_fn)(void *),
                 void (*delete_fn)(void **),
                 int (*compare_fn)(void *, void *)) {
  assert(node);
  assert(*node == NULL);
  assert(data);
  assert(print_fn);
  assert(delete_fn);
  assert(compare_fn);
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = malloc(sizeof(node_t));

  new_node->data = data;
  new_node->print = print_fn;
  new_node->delete = delete_fn;
  new_node->compare = compare_fn;
  *node = (void *) new_node;
}

void delete_node(node_t **node) {
  assert(node != NULL);
  assert(*node);
  assert((*node)->left_child == NULL);
  assert((*node)->right_child == NULL);
  (*node)->delete(&(*node)->data);
  (*node)->delete = NULL;
  (*node)->compare = NULL;
  (*node)->print = NULL;
  //free((*node)->data);
  free(*node);
  *node = NULL;
}

void insert_node(node_t **root_ptr, node_t *new_ptr) {
  assert(root_ptr);
  assert(new_ptr);
  int comp = (*root_ptr)->compare(*root_ptr, new_ptr);
  if (comp > 0) {
    if ((*root_ptr)->right_child == NULL) {
      (*root_ptr)->right_child = new_ptr;
      return;
    }
    else  {
      insert_node(&(*root_ptr)->right_child, new_ptr);
    }
  } else {
    if ((*root_ptr)->left_child == NULL) {
      (*root_ptr)->left_child = new_ptr;
      return;
    } else {
      insert_node(&(*root_ptr)->left_child, new_ptr);
    }
  }
  printf("##\n");
  print_tree(*root_ptr);
  printf("--\n");
  print_node(new_ptr);
  printf("**\n");
}

void count_nodes(node_t *root_ptr, void *data, int *count) {
  assert(data != NULL);
  assert(*count == 0);
  if (root_ptr == NULL) {
    return;
  }
  if (root_ptr->compare(root_ptr, data) == 0) {
    (*count)++;
  } else if (root_ptr->compare(root_ptr, data) < 0) {
    count_nodes(root_ptr->left_child, data, count);
  } else {
    count_nodes(root_ptr->right_child, data, count);
  }
}

void collect_nodes(node_t *root_ptr, void *data, node_t **i) {
  assert(data);
  assert(i);
  if (root_ptr == NULL) {
    return;
  }
  if (root_ptr->compare(root_ptr, data) == 0) {
    *i = root_ptr;
    collect_nodes(root_ptr->right_child, data, i);
  }
  if (root_ptr->compare(root_ptr, data) < 0) {
    collect_nodes(root_ptr->left_child, data, i);
  } else if (root_ptr->compare(root_ptr, data) > 0) {
    collect_nodes(root_ptr->right_child, data, i);
  }
}


node_t **find_nodes(node_t *root_ptr, void *data, int *count) {
  assert(root_ptr);
  assert(data);
  assert(count);

  count_nodes(root_ptr, &data, count);
  node_t **result = malloc(sizeof(node_t) * (*count + 1));
  node_t **i = result;
  i[*count] = NULL;
  collect_nodes(root_ptr, data, i);
  return i;
}


void remove_node(node_t **root, node_t *node) {
  assert(root);
  assert(*root);
  assert(node);
  return (void)NOT_IMPLEMENTED_ERR;
  node_t **cur = malloc(sizeof(node_t));
  if ((*root)->compare(root, node) == 0) {
    if ((*root)->left_child && (*root)->right_child == NULL) {
      delete_node(root);
    } else if ((*root)->right_child == NULL && (*root)->left_child != NULL) {
      if ((*root)->compare(root, (*root)->left_child) == 0) {
        for (cur = root; (*cur)->compare(root,node) == 0; *cur = (*root)->right_child) {
          root = (node_t **) (*root)->right_child;
          delete_node(cur);
        }
      } else {
        *root = (*root)->left_child;
        remove_node(root, node);
      }
    } else if ((*root)->left_child == NULL && (*root)->right_child != NULL) { // right not null
       *root = (*root)->right_child;
      remove_node(root, node);
    } else { // neither are null
      //if ((*root)->compare(root, (*root)->right_child) > 0) {
        //send up left child
      //}
    }
    //insert_node(root);
    remove_node((node_t **) (*root)->right_child, node);
  } else {
    if ((*root)->compare(root, node) < 0) {
      remove_node((node_t **) (*root)->left_child, node);
    } else {
      remove_node((node_t **) (*root)->right_child, node);
    }
  }
}

void delete_tree(node_t **root) {
  assert(root);
  if (*root == NULL) {
    return;
  }
  delete_tree(&(*root)->left_child);
  delete_tree(&(*root)->right_child);
  free((*root)->data);
  free(*root);
  *root = NULL;
}
