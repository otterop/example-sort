#include <stdio.h>
#include <string.h>
#include <example/sort/service/pure/heapsort_service.h>
#include <example/sort/service/pure/quicksort_service.h>
#include <example/sort/tree/pure/node.h>
#include <example/sort/service/pure/sort_service.h>

int main(int args_cnt, char *args_arr[]) {
    args_cnt = args_cnt - 1;
    char **args = args_arr + 1;

    if (args_cnt < 1) {
        printf("Usage: <quick|heap> ...values\n");
        return 1;
    }

    int is_quick = strcmp("quick", args[0]) == 0;
    int is_heap = strcmp("heap", args[0]) == 0;

    if (!(is_quick || is_heap)) {
        printf("Usage: <quick|heap> ...values\n");
        return 1;
    }

    args++;
    args_cnt--;
    example_sort_service_pure_SortService_t *sort_service = example_sort_service_pure_QuicksortService__to_example_sort_service_pure_SortService(example_sort_service_pure_QuicksortService_new());

    if (is_heap) {
        sort_service = example_sort_service_pure_HeapsortService__to_example_sort_service_pure_SortService(example_sort_service_pure_HeapsortService_new());
    }
    size_t ret_cnt;
    char **ret = example_sort_service_pure_SortService_sort(sort_service, args, args_cnt, &ret_cnt);
    for (size_t i = 0; i <ret_cnt; i++) {
        printf("%s\n", ret[i]);
    }

    example_sort_tree_pure_Node_t *children[8];
    example_sort_tree_pure_Node_t *a = example_sort_tree_pure_Node_new(1, children, 0);
    example_sort_tree_pure_Node_t *b = example_sort_tree_pure_Node_new(2, children, 0);

    children[0] = a;
    children[1] = b;

    example_sort_tree_pure_Node_t *c = example_sort_tree_pure_Node_new(3, children, 2);
    example_sort_tree_pure_Node_t *d = example_sort_tree_pure_Node_new(4, children, 0);
    example_sort_tree_pure_Node_t *e = example_sort_tree_pure_Node_new(5, children, 0);

    children[0] = d;
    children[1] = e;
    example_sort_tree_pure_Node_t *f = example_sort_tree_pure_Node_new(6, children, 2);

    children[0] = c;
    children[1] = f;
    example_sort_tree_pure_Node_t *g = example_sort_tree_pure_Node_new(7, children, 2);

    int children_cnt = 1;
    example_sort_tree_pure_Node_t **children_curr = children;
    example_sort_tree_pure_Node_t **children_next = &children[4];

    children[0] = g;
    while (children_cnt > 0) {
        int i;
        example_sort_tree_pure_Node_t **children_app;
        size_t children_next_cnt = 0;
        for (i = 0; i < children_cnt; i++) {
            int j = 0;
            size_t children_node_cnt = 0;
            example_sort_tree_pure_Node_t **children_node;

            printf("value: %d ", example_sort_tree_pure_Node_value(children_curr[i]));
            children_node = example_sort_tree_pure_Node_children(children_curr[i], &children_node_cnt);
            for (j = 0; j < children_node_cnt; j++)
                children_next[children_next_cnt++] = children_node[j];
        }

        children_cnt = children_next_cnt;
        children_app = children_curr;
        children_curr = children_next;
        children_next = children_app;
        printf("\n");
    }
}
