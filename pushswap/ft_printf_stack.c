#include "push_swap.h"
void ft_print_stack(t_stack *stack)
{
    if (!stack)
    {
        ft_printf("La pila está vacía.\n");
        return;
    }

    while (stack)
    {
        //ft_printf("Imprimiendo: %d\n", stack->value);
        stack = stack->next;
    }
}
