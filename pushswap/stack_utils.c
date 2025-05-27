#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}


void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}
t_stack *rotate_to_first(t_stack *stack)
{
    // Verificamos si la pila está vacía
    if (!stack)
        return NULL;

    // Retornamos el puntero al primer elemento
    return stack;
}
