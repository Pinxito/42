#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int size;

    if (argc < 2)
        return (0);
    a = parse_input(argc, argv);
    if (!a)
        return (1);
    size = stack_size(a);
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    sort_stack(&a, &b, size);
    free_stack(&a);
    free_stack(&b);

    return (0);
}
