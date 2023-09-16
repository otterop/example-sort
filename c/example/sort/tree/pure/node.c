#include <example/sort/tree/pure/node.h>
#include <gc.h>

typedef struct example_sort_tree_pure_Node_s example_sort_tree_pure_Node_t;
typedef struct example_sort_tree_pure_Node_s {
    example_sort_tree_Node_t *_otterop;
} example_sort_tree_pure_Node_t;


static example_sort_tree_pure_Node_t *example_sort_tree_pure_Node_wrap(example_sort_tree_Node_t *wrapped) {
    example_sort_tree_pure_Node_t *this = GC_malloc(sizeof(example_sort_tree_pure_Node_t));
    this->_otterop = wrapped;
    return this;
}
;
;


example_sort_tree_pure_Node_t *example_sort_tree_pure_Node_new(int value, example_sort_tree_pure_Node_t **children, size_t children_cnt) {
    size_t i;
    example_sort_tree_Node_t **_children_array = GC_malloc(children_cnt * sizeof(example_sort_tree_Node_t *));
    for (i = 0; i < children_cnt; i++) {
        _children_array[i] = example_sort_tree_pure_Node_unwrap(children[i]);
    }
    otterop_lang_Array_t *_children = otterop_lang_Array_wrap(_children_array, children_cnt);
    example_sort_tree_pure_Node_t *this = GC_malloc(sizeof(example_sort_tree_pure_Node_t));
    this->_otterop = example_sort_tree_Node_new(value, _children);
    return this;
}



int example_sort_tree_pure_Node_value(example_sort_tree_pure_Node_t *this) {
    int ret_otterop = example_sort_tree_Node_value(this->_otterop);
    int ret = ret_otterop;
    return ret;
}


example_sort_tree_pure_Node_t *example_sort_tree_pure_Node_child(example_sort_tree_pure_Node_t *this, int i) {
    example_sort_tree_Node_t * ret_otterop = example_sort_tree_Node_child(this->_otterop, i);
    if (ret_otterop == this->_otterop) return this;
    example_sort_tree_pure_Node_t *ret = example_sort_tree_pure_Node_wrap(ret_otterop);
    return ret;
}


example_sort_tree_pure_Node_t **example_sort_tree_pure_Node_children(example_sort_tree_pure_Node_t *this, size_t *_ret_cnt) {
    otterop_lang_Array_t * ret_otterop = example_sort_tree_Node_children(this->_otterop);
    int _ret_size = otterop_lang_Array_size(ret_otterop), _ret_i;
    *_ret_cnt = _ret_size;
    example_sort_tree_pure_Node_t **ret = GC_malloc(_ret_size * sizeof(void *));
    for (_ret_i = 0; _ret_i < _ret_size; _ret_i++) {
        example_sort_tree_Node_t *ret_i = otterop_lang_Array_get(ret_otterop, _ret_i);
        if (ret_i == this->_otterop) {
            ret[_ret_i] = this;
            continue;
        }
        ret[_ret_i] = example_sort_tree_pure_Node_wrap(ret_i);
    }
    return ret;
}

example_sort_tree_Node_t *example_sort_tree_pure_Node_unwrap(example_sort_tree_pure_Node_t *this) {
    return this->_otterop;
}
