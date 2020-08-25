#include "Mld.h"

#include <stdbool.h>

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

bool structure_db_list_add_hashtable_node()
{
}