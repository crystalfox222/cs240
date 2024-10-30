/*
 * CS 240 - Fall 2023 - Suresh Jagannathan
 *
 * Please type your name in place of <Edythe Thompson> to verify that you will
 * not cheat on this homework.
 *
 * Academic Honesty Pledge:
 * I certify that this code is of my own original work, and not that of other
 * students, online services, or other dishonesty. If I need help on homework,
 * I will ask a TA or the professor.
 *
 * Signed, <Edythe Thompson> */

#include "hw9.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*This function initializes and allocates memory for the specified type of list
 * (type is specified through the assigning of the rm and ins functions)*/
llist *new_llist(ll_insert_fn ins, ll_remove_fn rm) {
  assert(ins != NULL);
  assert(rm != NULL);
  llist *list;
  list = malloc(sizeof(llist));
  list->head = NULL;
  list->insert = ins;
  list->remove = rm;
  return list;
} /*new_llist*/

/*This function inserts integers into an integer linked list*/
int ll_int_insert(llist *list, void *val) {
  assert(list != NULL);
  struct s_node *node = malloc(sizeof(struct s_node));
  struct s_node *cur;
  struct s_node *prev = NULL;
  int *valPtr = malloc(sizeof(int));
  memcpy(valPtr, val, sizeof(int));
  for (cur = list->head; cur != NULL; cur = cur->right) {
    if (*valPtr > *(int *) cur->val && cur->right == NULL) {
      cur->right = node;
      node->left = cur;
      node->right = NULL;
      node->val = valPtr;
      return LL_SUCCESS;
    } else if (*valPtr <= *(int *) cur->val) {
      cur->left = node;
      node->right = cur;
      node->left = prev;
      node->val = valPtr;
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
    node->val = valPtr;
    node->right = NULL;
    node->left = NULL;
    list->head = node;
    return LL_SUCCESS;
  }
  return GEN_LL_ERR;
} /*ll_int_insert*/

/*This function takes a string stored in a void type variable,
 * casts it into a char pointer, and stores it in the correct
 * lexicon order*/
int ll_str_insert(llist *list, void *val) {
  assert(list != NULL);
  assert(val != NULL);
  unsigned long size = (strlen((char *) val)) + 1;
  char *str = malloc(sizeof(char) * size);
  memcpy(str, val, sizeof(char) * size);
  struct s_node *node = malloc(sizeof(struct s_node));
  struct s_node *cur;
  struct s_node *prev = NULL;
  printf("%s", str);
  for (cur = list->head; cur != NULL; cur = cur->right) {
    if (strcmp(str, (char *) cur->val) > 0 && cur->right == NULL) {
      cur->right = node;
      node->left = cur;
      node->right = NULL;
      node->val = str;
      return LL_SUCCESS;
    } else if (strcmp(str, (char *) cur->val) < 0) {
      cur->left = node;
      node->right = cur;
      node->left = prev;
      node->val = str;
      if (cur != list->head) {
        prev->right = node;
      } else {
        list->head = node;
      }
      return LL_SUCCESS;
    } else if (strcmp(str, (char *) cur->val) == 0) {
      cur->left = node;
      node->right = cur;
      node->left = prev;
      node->val = str;
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
    node->val = str;
    node->right = NULL;
    node->left = NULL;
    list->head = node;
    return LL_SUCCESS;
  }
  return GEN_LL_ERR;

} /*ll_str_insert*/

/*This function removes a given integer from the integer list*/
int ll_int_remove(llist *list, node *to_remove) {
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
      free(to_remove->val);
      free(to_remove);
      return LL_SUCCESS;
    }
    prev = cur;
  }
  return NOT_IN_LIST;
} /*ll_int_remove*/

/*This function removes a string using the previous function*/
int ll_str_remove(llist *list, node *to_remove) {
  assert(list != NULL);
  assert(to_remove != NULL);

  return ll_int_remove(list, to_remove);
} /*ll_str_remove*/

/*This function deletes a given list and frees memory utilized
 * by the given list*/
int ll_delete_list(llist *list) {
  assert(list != NULL);
  struct s_node *prev = NULL;
  for (struct s_node *cur = list->head; cur != NULL; cur = cur->right) {
    if (prev != NULL) {
      free(prev->val);
      free(prev);
    }
    if (cur->right == NULL) {
      free(cur->val);
      free(cur);
      free(list);
      return LL_SUCCESS;
    }
    prev = cur;
  }

  return GEN_LL_ERR;
} /*ll_delete_list*/


