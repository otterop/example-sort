#include <example/sort/inheritance/animal.h>
#include <gc.h>

typedef struct example_sort_inheritance_Animal_s {
    otterop_lang_String_t *word;
} example_sort_inheritance_Animal_t;




example_sort_inheritance_Animal_t *example_sort_inheritance_Animal_new(otterop_lang_String_t *word) {
    example_sort_inheritance_Animal_t *this = GC_malloc(sizeof(example_sort_inheritance_Animal_t));
    this->word = word;
    return this;
}

otterop_lang_String_t *example_sort_inheritance_Animal_act(example_sort_inheritance_Animal_t *this) {
    return this->word;
}

otterop_lang_String_t *example_sort_inheritance_Animal_species(example_sort_inheritance_Animal_t *this) {
    return otterop_lang_String_wrap("unknown");
}
