#include <example/sort/tree/node.h>
#include <gc.h>

typedef struct example_sort_tree_Node_s {
    otterop_lang_Array_t *_children;
    int _value;
} example_sort_tree_Node_t;




example_sort_tree_Node_t *example_sort_tree_Node_new(int value, otterop_lang_Array_t *children) {
    example_sort_tree_Node_t *this = GC_malloc(sizeof(example_sort_tree_Node_t));
    this->_value = value;
    this->_children = children;
    return this;
}

int example_sort_tree_Node_value(example_sort_tree_Node_t *this) {
    return this->_value;
}

example_sort_tree_Node_t *example_sort_tree_Node_child(example_sort_tree_Node_t *this, int i) {
    otterop_lang_Array_t *children = this->_children;
    return otterop_lang_Array_get(children, i);
}

otterop_lang_Array_t *example_sort_tree_Node_children(example_sort_tree_Node_t *this) {
    return this->_children;
}
