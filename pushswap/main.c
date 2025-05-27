#include "push_swap.h"

/*int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);

    a = parse_input(argc, argv);
    b = NULL;
    if (!a)
        return (1);

    ft_printf("Pila A:   ");
    ft_printf("Pila B:\n");
    ft_print_stack(a); // Muestra los números en la pila

    return (0);
}*/
/*#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    // Verificar que se pase al menos un argumento
    if (argc < 2)
        return (0);

    // Parsear la entrada y construir la pila A
    a = parse_input(argc, argv);
    if (!a)
        return (1);

    // Imprimir la pila antes de realizar operaciones
    ft_printf("Pila A antes de operaciones:\n");
    ft_print_stack(a);

    // Realizar algunas operaciones de prueba
    sa(&a);
    pb(&a, &b);
    ra(&a);
    rra(&a);

    // Imprimir las pilas después de las operaciones
    ft_printf("Pila A después de operaciones:\n");
    ft_print_stack(a);
    ft_printf("Pila B:\n");
    ft_print_stack(b);

    return (0);
}*/
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int size;

    // Si no hay suficientes argumentos, terminamos
    if (argc < 2)
    {
        ft_printf("No hay suficientes argumentos.\n");
        return (0);
    }

    // Convertimos la entrada en una pila y validamos
    a = parse_input(argc, argv);
    if (!a)
    {
        ft_printf("Error en la entrada\n");
        return (1);
    }

    //  Imprimir la pila después de `parse_input()`
    //ft_printf("Pila A después de parse_input:\n");
    //ft_print_stack(a);  //  Revisa que los números estén en el orden correcto

    // Contamos los elementos en la pila
    size = stack_size(a);
    ft_printf("Tamaño de la pila: %d\n", size); 

    // Si la pila ya está ordenada, terminamos
    if (is_sorted(a))
    {
        ft_printf("La pila ya está ordenada. No se hacen operaciones.\n");
        free_stack(&a);
        return (0);
    }

    //  Mensaje antes de llamar a `sort_stack`
   // ft_printf("Ejecutando algoritmo de ordenación...\n");
    sort_stack(&a, &b, size);

    //  Mensaje después de la ordenación
   // ft_printf("Pila A después de ordenación:\n");
   // ft_print_stack(a);
    //ft_print_stack(b);

    // Liberamos memoria antes de salir
    free_stack(&a);
    free_stack(&b);

    //ft_printf("Programa finalizado correctamente.\n");
    return (0);
}
