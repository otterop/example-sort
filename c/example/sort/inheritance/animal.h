#ifndef __example_sort_inheritance_Animal
#define __example_sort_inheritance_Animal
#include <example/sort/tree/node.h>
#include <otterop/lang/string.h>

typedef struct example_sort_inheritance_Animal_s example_sort_inheritance_Animal_t;




example_sort_inheritance_Animal_t *example_sort_inheritance_Animal_new(otterop_lang_String_t *word);

otterop_lang_String_t *example_sort_inheritance_Animal_act(example_sort_inheritance_Animal_t *this);


otterop_lang_String_t *example_sort_inheritance_Animal_species(example_sort_inheritance_Animal_t *this);

#endif
