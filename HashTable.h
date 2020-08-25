#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <stdbool.h>

#define TABLE_SIZE 256
#define MAX_NAME 128

list *hash_table[TABLE_SIZE];

void hash_table_init(list *hash_table[TABLE_SIZE]);
void print_table(list *hash_table[TABLE_SIZE]);
node *hash_lookup(char *name);
bool hash_table_insert(list *struct_db_list, node *struct_db_node, void *data, char *struct_name);
#endif

