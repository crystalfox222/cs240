#ifndef HW9_H
#define HW9_H

#define NOT_IN_LIST             (-1)
#define LL_SUCCESS              (-2)
#define GEN_LL_ERR              (-3)
#define NOT_IMPLEMENTED_ERR     (-240)

extern char *g_user_hash;

struct s_llist {
  struct s_node* head;
  int (*insert)(struct s_llist *, void *);
  int (*remove)(struct s_llist *, struct s_node *);
};

struct s_node {
  void *val;
  struct s_node* left;
  struct s_node* right;
};

typedef struct s_node node;
typedef struct s_llist llist;

typedef int (*ll_insert_fn)(struct s_llist *, void *);
typedef int (*ll_remove_fn)(struct s_llist *, struct s_node *);

llist *new_llist();
int ll_int_insert(llist *list, void *val);
int ll_str_insert(llist *list, void *val);
int ll_int_remove(llist *list, node *to_remove);
int ll_str_remove(llist *list, node *to_remove);
int ll_delete_list(llist *list);

#endif // HW9_H


