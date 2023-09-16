#ifndef __example_sort_tree_pure_Node
#define __example_sort_tree_pure_Node
#include <otterop/lang/array.h>
#include <example/sort/tree/node.h>

typedef struct example_sort_tree_pure_Node_s example_sort_tree_pure_Node_t;
typedef struct example_sort_tree_pure_Node_s example_sort_tree_pure_Node_t;




example_sort_tree_pure_Node_t *example_sort_tree_pure_Node_new(int value, example_sort_tree_pure_Node_t **children, size_t children_cnt);

int example_sort_tree_pure_Node_value(example_sort_tree_pure_Node_t *this);


example_sort_tree_pure_Node_t *example_sort_tree_pure_Node_child(example_sort_tree_pure_Node_t *this, int i);


example_sort_tree_pure_Node_t **example_sort_tree_pure_Node_children(example_sort_tree_pure_Node_t *this, size_t *_ret_cnt);

example_sort_tree_Node_t *example_sort_tree_pure_Node_unwrap(example_sort_tree_pure_Node_t *this);
#endif
