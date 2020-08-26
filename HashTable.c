#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int hash(char *name)
{
  if (!name)
    return 0;
  
  unsigned int len = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;
  
  for (int i = 0; i < len; i++) {
    hash_value += name[i];
    hash_value *= name[i];
  }
  
  return hash_value % TABLE_SIZE;
}

unsigned int hash_table_default_size_get(void)
{
  return TABLE_SIZE;
}

void hash_table_init(list **hash_table[TABLE_SIZE])
{
  for (int i = 0; i < TABLE_SIZE; i++)
    *hash_table[i] = NULL;
}

#if 0
void print_table(list *hash_table[TABLE_SIZE])
{
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (!hash_table[i])
      printf(ANSI_COLOR_RED "\t%i\t---\n" ANSI_COLOR_RESET, i);
#if 0
    else {
      node *cur_node = hash_table[i]->head;
 
      while (cur_node) { 
        printf(ANSI_COLOR_CYAN "\t%i\t%s\n" ANSI_COLOR_CYAN, i, cur_node->data);
	cur_node = cur_node->next;
      }
    }
#endif
}
#endif

bool hash_table_insert(list *struct_db_list, node *struct_db_node, void *data, char *struct_name)
{
  node *cur_node = NULL, list_node;
  bool found = false;
  unsigned int hash_key;
  
  if (!struct_db_list || !data || !struct_db_node || !struct_name)
    return false;
  
  /* Check if specific struct_db_rec exists in the list */
  cur_node = struct_db->head;
  
  while (cur_node != NULL) {
    if (cur_node == struct_db_rec) {
      found = true;
      break;
    }
    else
      cur_node = cur_node->next;
  }
  
  if (!found)
    return false;
  
  hash_key = hash (struct_name); 
  
  return list_add_node(cur_node->hash_table[hash_key], data, STRUCT_DB_REC, &list_node);
}

node *hash_lookup(list *hash_table[TABLE_SIZE], char *name)
{
  unsigned int key;
  
  if (!name)
    return NULL;
  
  key = hash(name);
  
  if (!hash_table[key])
    return NULL;
  else {
    if (hash_table[key]->count == 1)
      return hash_table[key]->head;
    else if (hash_table[key]->count > 1)
      return list_node_lookup_by_name(hash_table, name);
  }
  
  return NULL;
}
