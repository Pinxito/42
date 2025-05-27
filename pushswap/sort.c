#include "push_swap.h"

// Verifica si la pila A está ordenada
int is_sorted(t_stack *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}


void bubble_sort(t_stack **a)
{
    int swapped;
    t_stack *ptr;

    if (!(*a) || !(*a)->next)
        return;

    swapped = 1;
    while (swapped)  // Repetir hasta que no haya intercambios
    {
        swapped = 0;
        ptr = *a;
        
        while (ptr && ptr->next)
        {
            if (ptr->value > ptr->next->value)
            {
                sa(a);  // Intercambia los dos primeros elementos
                swapped = 1;
            }
            ptr = ptr->next;
        }

        if (is_sorted(*a))  // Verifica si la pila está ordenada
            break;
        
        ra(a);  // Rota los elementos de la pila A
    }
}

// Función principal de ordenamiento
void sort_stack(t_stack **a, t_stack **b, int size)
{
    if (size <= 500)
        chunk_sort(a, b, size);
    else
        radix_sort(a, b, size);
    // Después de ordenar la pila A, rotamos para que el primer elemento quede arriba
    rotate_to_first(*a);  // Esta línea asegura que el primer elemento esté de nuevo arriba
}
