#include <stdio.h>
#include <string.h>
#include <example/sort/service/pure/heapsort_service.h>
#include <example/sort/service/pure/quicksort_service.h>
#include <example/sort/service/pure/sort_service.h>

int main(int args_cnt, char *args_arr[]) {
    args_cnt = args_cnt - 1;
    char **args = args_arr + 1;

    if (args_cnt < 1) {
        printf("Usage: <quick|heap> ...values\n");
        return 1;
    }

    int is_quick = strncmp("quick", args[0], 5) == 0;
    int is_heap = strncmp("heap", args[0], 4) == 0;

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
}
