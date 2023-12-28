#include <example/sort/inheritance/animal.h>
#include <example/sort/inheritance/dog.h>
#include <gc.h>

typedef struct example_sort_inheritance_Dog_s {
    example_sort_inheritance_Animal_t *_super;
    otterop_lang_String_t *dog_word;
} example_sort_inheritance_Dog_t;




example_sort_inheritance_Dog_t *example_sort_inheritance_Dog_new() {
    example_sort_inheritance_Dog_t *this = GC_malloc(sizeof(example_sort_inheritance_Dog_t));
    this->_super = example_sort_inheritance_Animal_new(otterop_lang_String_wrap("I don't know"));
    this->dog_word = otterop_lang_String_wrap("bark");
    return this;
}

otterop_lang_String_t *example_sort_inheritance_Dog_act(example_sort_inheritance_Dog_t *this) {
    example_sort_inheritance_Animal_act(this->_super);
    return this->dog_word;
}

otterop_lang_String_t *example_sort_inheritance_Dog_species(example_sort_inheritance_Dog_t *this) {
    return  example_sort_inheritance_Animal_species(this->_super);
}
