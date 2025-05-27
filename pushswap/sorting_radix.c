#include "push_swap.h"

// Encuentra el número de bits en el número más grande
int get_max_bits(t_stack *a)
{
    int max = a->value;
    int bits = 0;

    while (a)
    {
        if (a->value > max)
            max = a->value;
        a = a->next;
    }

    while ((max >> bits) != 0)
        bits++;

    return bits;
}

void radix_sort(t_stack **a, t_stack **b, int size)
{
    int max_bits;
    int i;
    int j;

    max_bits = get_max_bits(*a);
    i = 0;
    while (i < max_bits)  // Iteramos sobre cada bit
    {
        j = 0;
        while (j < size)  // Recorremos toda la pila
        {
            if ((((*a)->value >> i) & 1) == 0)
                pb(a, b);  // Mueve a `B` si el bit en `i` es 0
            else
                ra(a);  // Rota si el bit en `i` es 1
            j++;
        }

        while (*b)  // Devuelve todo de `B` a `A`
            pa(a, b);

        i++;
    }
}
