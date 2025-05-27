#include "push_swap.h"

int is_number(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+') // Permite números negativos o positivos
        i++;

    if (!str[i]) // Evita casos como "-" o "+"
        return (0);

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9') // Si no es un número, devuelve falso
            return (0);
        i++;
    }
    return (1);
}

int is_duplicate(t_stack *a, int num)
{
    while (a)
    {
        if (a->value == num)
            return (1);
        a = a->next;
    }
    return (0);
}

void push(t_stack **stack, int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    t_stack *temp;

    if (!node)
        return;
    node->value = value;
    node->next = NULL;

    if (!*stack)  // Si la pila está vacía
        *stack = node;
    else
    {
        temp = *stack;
        while (temp->next)  // Ir al último nodo
            temp = temp->next;
        temp->next = node;  // Insertar al final
    }
}

t_stack *parse_input(int argc, char **argv)
{
    t_stack *a = NULL;
    char **numbers;
    int num, i = 0;

    if (argc == 2) // Caso donde la entrada es un solo string "1 2 3 4 5"
    {
        numbers = ft_split(argv[1], '\n'); // Divide el string en tokens
        if (!numbers)
            return (write(2, "Error1\n", 6), NULL);
         // Empezamos desde el primer número
    }
    else
        numbers = &argv[1]; // Si hay múltiples argumentos, los usamos directamente

    while (numbers[i])
    {
        if (!is_number(numbers[i]) || (num = atol(numbers[i])) > INT_MAX || num < INT_MIN)
            return (write(2, "Error2\n", 6), NULL);

        if (is_duplicate(a, num))
            return (write(2, "Error3\n", 6), NULL);

        push(&a, num);
        i++;
    }

    if (argc == 2)
        free_split(numbers); // Liberar memoria si usamos ft_split()
    
    return (a);
}
