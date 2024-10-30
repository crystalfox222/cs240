#include "hw10.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*Creates an employee node and initializes left and right pointers*/
employee_t *create_employee(char *name) {
  assert(name != NULL);
  employee_t *employ = malloc(sizeof(employee_t));
  assert(employ != NULL);
  employ->name = malloc(sizeof(char) * strlen(name) + 1);
  assert(employ->name != NULL);
  strcpy(employ->name, name);
  employ->left_child_ptr = NULL;
  employ->right_child_ptr = NULL;
  return employ;
}/*create_employee*/

/*Inserts previously created node recursively*/
void insert_employee(employee_t **root, employee_t *employee) {
  assert(root != NULL);
  assert(employee != NULL);
  assert(employee->left_child_ptr == NULL && employee->right_child_ptr == NULL);

  // creating the node to be placed
  employee_t *tempNode = malloc(sizeof(employee_t));
  tempNode->left_child_ptr = NULL;
  tempNode->right_child_ptr = NULL;
  tempNode->name = malloc(sizeof(char) * strlen(employee->name) + 1);
  strcpy(tempNode->name, employee->name);

  if ((*root) == NULL) { // root case
    ((*root)) = tempNode;
    return;
  } else {
    if (strcmp(employee->name, (*root)->name) < 0) {

      insert_employee(&(*root)->left_child_ptr, employee);
    } else {
      insert_employee(&(*root)->right_child_ptr, employee);
    }
  }
} /*insert_employee*/

/*Finds employee using name
 * This function uses recursion to do so*/
employee_t *find_employee(employee_t *root, char *name) {
  assert(name != NULL);
  if (root == NULL) {
    return NULL;
  }
  if (strcmp(root->name, name) == 0) {
    return root;
  } else {
    if (strcmp(root->name, name) > 0) {
      return find_employee(root->left_child_ptr, name);
    } else {
      return find_employee(root->right_child_ptr, name);
    }
  }
} /*find_employee*/

/*Deletes tree using the given node
 * Done recursively */
void delete_tree(employee_t **root) {
  assert(root != NULL);

  if (*root == NULL) {
    return;
  }

  delete_tree(&(*root)->left_child_ptr);
  delete_tree(&(*root)->right_child_ptr);
  free((*root)->name);
  free(*root);
  *root = NULL;
} /*delete_tree*/

employee_t *traverse_employees(employee_t *employee, int i, int j) {
  return NULL;
}

employee_t *previous_employee(employee_t *employee, char *name) {
  return NULL;
}