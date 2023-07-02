#include <example/sort/tree/node.h>
#include <gc.h>

typedef struct example_sort_tree_Node_s {
    otterop_lang_Array_t *children;
} example_sort_tree_Node_t;


;


example_sort_tree_Node_t *example_sort_tree_Node_new(otterop_lang_Array_t *children) {
    example_sort_tree_Node_t *this = GC_malloc(sizeof(example_sort_tree_Node_t));
    this->children = children;
    return this;
}

example_sort_tree_Node_t *example_sort_tree_Node_child(example_sort_tree_Node_t *this, int i) {
    otterop_lang_Array_t *children = this->children;
    return otterop_lang_Array_get(children, i);
}

otterop_lang_Array_t *example_sort_tree_Node_children(example_sort_tree_Node_t *this) {
    return this->children;
}