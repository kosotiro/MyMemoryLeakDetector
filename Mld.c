#include "Mld.h"
#include "HashTable.h"
#include "css.h"

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

void print_table(list *hash_table[TABLE_SIZE])
{
  struct_db_rec *db_rec;
  
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (!hash_table[i])
      printf(ANSI_COLOR_RED "\t%i\t---\n" ANSI_COLOR_RESET, i);
    else {
      node *cur_node = hash_table[i]->head;
 
      while (cur_node) { 
        db_rec = (struct_db_rec *)cur_node->data;
        printf(ANSI_COLOR_CYAN "\t%i\t%s\n" ANSI_COLOR_CYAN, i, db_rec->struct_name, ANSI_COLOR_RESET);
        cur_node = cur_node->next;
      }
    }
   }
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

void
print_structure_rec(struct_db_rec_t *struct_rec){
    if(!struct_rec) return;
    int j = 0;
    field_info_t *field = NULL;
    printf(ANSI_COLOR_CYAN "|------------------------------------------------------|\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "| %-20s | size = %-8d | #flds = %-3d |\n" ANSI_COLOR_RESET, struct_rec->struct_name, struct_rec->ds_size, struct_rec->n_fields);
    printf(ANSI_COLOR_CYAN "|------------------------------------------------------|------------------------------------------------------------------------------------------|\n" ANSI_COLOR_RESET);
    for(j = 0; j < struct_rec->n_fields; j++){
        field = &struct_rec->fields[j];
        printf("  %-20s |", "");
        printf("%-3d %-20s | dtype = %-15s | size = %-5d | offset = %-6d|  nstructname = %-20s  |\n",
                j, field->fname, DATA_TYPE[field->dtype], field->size, field->offset, field->nested_str_name);
        printf("  %-20s |", "");
        printf(ANSI_COLOR_CYAN "--------------------------------------------------------------------------------------------------------------------------|\n" ANSI_COLOR_RESET);
    }
}

void
print_structure_db(struct_db_t *struct_db){
    
    if(!struct_db) return;
    printf("printing STRUCURE DATABASE\n");
    int i = 0;
    struct_db_rec_t *struct_rec = NULL;
    struct_rec = struct_db->head;
    printf("No of Structures Registered = %d\n", struct_db->count);
    while(struct_rec){
        printf("structure No : %d (%p)\n", i++, struct_rec);
        print_structure_rec(struct_rec);
        struct_rec = struct_rec->next;
    }
}

