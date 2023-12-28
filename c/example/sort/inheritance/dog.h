#ifndef __example_sort_inheritance_Dog
#define __example_sort_inheritance_Dog
#include <otterop/lang/string.h>

typedef struct example_sort_inheritance_Dog_s example_sort_inheritance_Dog_t;




example_sort_inheritance_Dog_t *example_sort_inheritance_Dog_new();

otterop_lang_String_t *example_sort_inheritance_Dog_act(example_sort_inheritance_Dog_t *this);


otterop_lang_String_t *example_sort_inheritance_Dog_species(example_sort_inheritance_Dog_t *this);
#endif
