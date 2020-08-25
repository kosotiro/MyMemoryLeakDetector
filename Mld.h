#ifndef MLD_H
#define MLD_H

#include "LinkedList.h"

#define MAX_NAME 128
#define FIELD_OFFSET(struct_name, fld_name) \
        (unsigned int) (&((struct_name *)0)->fld_name)
#define FIELD_SIZE(struct_name, fld_name) \
        sizeof(((struct_name *)0)->fld_name)

typedef enum {
    UINT8,
    UINT32,
    INT32,
    CHAR,
    OBJ_PTR,
    FLOAT,
    DOUBLE,
    OBJ_STRUCT
} data_type_t;

typedef struct _field_info {
  char fname[MAX_NAME];
  unsigned int size;
  unsigned int offset;
  data_type_t dtype;
  char nested_str_name[MAX_NAME];
} field_info_t;

typedef struct _struct_db_rec {
  unsigned int ds_size;
  char struct_name[MAX_NAME];
  unsigned int n_fields;
  field_info_t *fields;
} struct_db_rec;

list *struct_db_lst;
static bool struct_db_lst_init_done;

bool structure_db_list_create(void);
list *get_struct_db_lst(void);

int /*return 0 on success, -1 on failure for some reason*/
add_structure_to_struct_db(struct_db_t *struct_db, struct_db_rec_t *struct_rec);

#define REG_STRUCT(struct_db_list, struct_db_node, st_name, fields_arr)           \
        do {                                                                      \
	     struct_db_rec *rec = (struct_db_rec *)malloc(sizeof(struct_db_rec)); \
	     rec->ds_size = sizeof(st_name);                                      \
	     strncpy(rec->struct_name, #st_name, MAX_NAME);                       \
	     rec->n_fields = sizeof(fields_arr)/sizeof(field_info_t);             \
	     rec->fields = fields_arr;                                            \
	     if (!hash_table_insert(list *struct_db_list, node *struct_db_rec, void *data/*char *struct_name, field_info_t *fields*/)

#endif