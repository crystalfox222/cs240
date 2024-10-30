#include "hw8.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
 * Your answer to the following part will require compiling and running
 * hw8_main and selecting "gdb" (option 1)
 */

char *g_user_hash = "gubzc^Z[";

/*
 * The remainder of the homework will only require running hw8_test
 */


/*
 * Function that initializes new list and allocates memory for said list
 */
llist *new_llist() {
  llist *list;
  list = malloc(sizeof(llist));
  list->head = NULL;
  return list;
} /*new_llist*/

/*
 * Inserts nodes containing integer values and links them in numerical order
 */
int ll_insert(llist *list, int val) {
  assert(list != NULL);
  struct s_node *node = malloc(sizeof(struct s_node));
  struct s_node *cur;
  struct s_node *prev = NULL;
  for (cur = list->head; cur != NULL; cur = cur->right) {
    if (val > cur->val && cur->right == NULL) {
      cur->right = node;
      node->left = cur;
      node->right = NULL;
      node->val = val;
      return LL_SUCCESS;
    } else if (val <= cur->val) {
      cur->left = node;
      node->right = cur;
      node->left = prev;
      node->val = val;
      if (cur != list->head) {
        prev->right = node;
      } else {
        list->head = node;
      }
      return LL_SUCCESS;
    }
    prev = cur;
  }
  if (cur == NULL) {
    node->val = val;
    node->right = NULL;
    node->left = NULL;
    list->head = node;
    return LL_SUCCESS;
  }
  return GEN_LL_ERR;
} /*ll_insert*/

/*
 * Deletes nodes while maintaining previous list order
 */
int ll_remove(llist *list, node *to_remove) {
  assert(list != NULL);
  assert(to_remove != NULL);

  struct s_node *prev = NULL;
  for (struct s_node *cur = list->head; cur != NULL; cur = cur->right) {
    if (to_remove == cur) {
      if (cur->right == NULL && cur->left == NULL) {
        list->head = NULL;
      } else {
        if (cur != list->head) {
          prev->right = cur->right;
        }
        if (cur->right != NULL) {
          cur->right->left = prev;
          if (cur == list->head) {
            list->head = cur->right;
          }
        }
      }
      free(to_remove);
      return LL_SUCCESS;
    }
    prev = cur;
  }
  return NOT_IN_LIST;
} /*ll_remove*/

/*
 * Deletes list and frees memory
 */
int ll_delete_list(llist *list) {
  assert(list != NULL);
  struct s_node *prev = NULL;
  for (struct s_node *cur = list->head; cur != NULL; cur = cur->right) {
    if (prev != NULL) {
      free(prev);
    }
    if (cur->right == NULL) {
      free(cur);
      free(list);
      return LL_SUCCESS;
    }
    prev = cur;
  }

  return GEN_LL_ERR;
} /*ll_delete_list*/

/*
 * Combines two linked lists and maintains ascending numerical order
 */
llist *ll_combine(llist *l1, llist *l2) {
  assert(l1 != NULL);
  assert(l2 != NULL);
  llist *list = new_llist();
  for (struct s_node *cur = l1->head; cur != NULL; cur = cur->right) {
    ll_insert(list, cur->val);
  }
  for (struct s_node *cur = l2->head; cur != NULL; cur = cur->right) {
    ll_insert(list, cur->val);
  }
  return (llist *) list;
} /*ll_combine*/

/*
 * Converts integer array to linked list
 */
llist *arr_to_ll(int *arr, int length) {
  assert(arr != NULL);
  assert(length >= 0);
  llist *list = new_llist();
  for (int i = 0; i < length; i++) {
    ll_insert(list, arr[i]);
  }
  return (llist *) list;
} /*arr_to_ll*/
