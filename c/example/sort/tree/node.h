#ifndef __example_sort_tree_Node
#define __example_sort_tree_Node
#include <otterop/lang/array.h>

typedef struct example_sort_tree_Node_s example_sort_tree_Node_t;




example_sort_tree_Node_t *example_sort_tree_Node_new(int value, otterop_lang_Array_t *children);

int example_sort_tree_Node_value(example_sort_tree_Node_t *this);


example_sort_tree_Node_t *example_sort_tree_Node_child(example_sort_tree_Node_t *this, int i);


otterop_lang_Array_t *example_sort_tree_Node_children(example_sort_tree_Node_t *this);

#endif
