#include "LinkedList.h"

bool list_add_node(list *lst, void *data, DB_REC db_rec, node *list_node)
{
  node *cur_node = NULL;
  
  if (!lst || !data)
    return false;
  
  node *new_node = (node *)malloc(sizeof(node));
  
  new_node->next = NULL;
  new_node->db_rec = db_rec;
  new_node->data = data;
  
  /* If there is no other node, this will be the head of list */
  if (!lst->head) {
    lst->head = new_node;
    lst->count = 1;
  }
  else {
    cur_node = lst->head;
    
    while (cur_node->next != NULL)
      cur_node = cur_node->next;
    
    cur_node->next = new_node;
    lst->count++;
  }
  
  *list_node = *new_node;
  
  return true;
}

void print_list(list *lst)
{
  node *cur_node;
  
  if (!lst)
    return;
 
  while ((cur_node = lst->head) != NULL) {
    
  }
    
}

node *list_node_lookup_by_name(list *lst, char *name)
{
  node *cur_node = NULL;
  
  if (!lst || !name)
    return NULL;
  
  if (!lst->head)
    return NULL;
  
  cur_node = lst->head;
  
  while (cur_node != NULL) {
    if (cur_node->db_rec == STRUCT_DB_REC && strncmp(cur_node-))
  }
}