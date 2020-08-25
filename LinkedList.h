#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum _DB_REC {
  STRUCT_DB_REC, /* Entry for structure database */
  OBJECT_DB_REC, /* Entry for object database */
  STRUCT_DB,     /* Structure database entry */
  OBJECT_DB      /* Object database entry */
} DB_REC;

typedef struct _list_node {
  node *next;
  DB_REC db_rec;
  void *data;
} node;

typedef struct _list {
  node *head;
  int count;
} list;

bool list_add_node(list *lst, void *data);
void list_remove_node(list *lst, void *key);
node *list_node_lookup_by_name(list *lst, char *name);
node *list_node_lookup_by_ptr(list *lst, void *ptr);
node *list_node_lookup(list *lst, node *n);
#endif