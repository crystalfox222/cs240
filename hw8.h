#ifndef HW8_H
#define HW8_H

#pragma once

#define NOT_IN_LIST             (-1)
#define LL_SUCCESS              (-2)
#define GEN_LL_ERR              (-3)
#define NOT_IMPLEMENTED_ERR     (-240)

extern char *g_user_hash;

struct s_llist {
    struct s_node* head;
};

struct s_node {
    int val;
    struct s_node* left;
    struct s_node* right;
};

typedef struct s_node node;
typedef struct s_llist llist;

llist *new_llist();
int ll_insert(llist *list, int val);
int ll_remove(llist *list, node *to_remove);
int ll_delete_list(llist *list);
llist *ll_combine(llist *l1, llist *l2);
llist *arr_to_ll(int *arr, int length);

#endif // HW8_H




