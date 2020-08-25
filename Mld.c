#include "Mld.h"
#include "HashTable.h"

#include <stdbool.h>

/* It should be called once */
bool structure_db_list_create(void)
{
  if (!struct_db_lst_init_done) {
    struct_db_lst = (list *)malloc(sizeof(list));
    
    if(!struct_db_lst)
      return false;
    
    memset(struct_db_lst, sizeof(list), 0);
  }
  
  return true;
}

list *get_struct_db_lst(void)
{
  return struct_db_lst; 
}

/* It will create a new structure db for a specific app in a form of hashtable
 * and it will be added to linkedlist
 */
bool structure_db_list_add_hashtable_node(node *new_node)
{
  unsigned int hash_table_size;
  list *hash_table[TABLE_SIZE];
  
  hash_table_init(&hash_table);
  
  return list_add_node(struct_db_lst, hash_table, STRUCT_DB, new_node);
}

