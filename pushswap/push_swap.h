#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
# include <stdarg.h>

typedef struct s_stack
{
    int value;            // Valor numérico
    int index; // posicion del valor real en una pila ordenada
    struct s_stack *next; // Puntero al siguiente nodo
} t_stack;
//printf
int			ft_uitoa(unsigned int nb);
int			ft_puthex(unsigned int num, const char format);
int			ft_itoa(int n);
char		*ft_convert(long int n, int is_negative);
char		*ft_convert_unsigned(unsigned int n);
void		ft_convert_hex(unsigned int num, const char format);
int			ft_countlen(long int n);
int			ft_strlen(char *str);
int			ft_putchar(char c);
int			ft_putstr(char *str);
void		ft_convert_ptr(unsigned long num);
int			ft_countptr(unsigned int n);
int			ft_putptr(void *ptr);
int	        ft_printf(const char *format, ...);
int	        ft_format(va_list lista, const char *format);
int	        ft_countuilen(unsigned int n);
//input
int is_number(char *str);
int is_duplicate(t_stack *a, int num);
t_stack *parse_input(int argc, char **argv);
void push(t_stack **stack, int value);
void ft_print_stack(t_stack *stack);
//split
void free_split(char **split);
char **ft_split(char const *s, char c);
//main
int main(int argc, char **argv);
//operations
void ft_push(t_stack **from, t_stack **to);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **b, t_stack **a);
void swap(t_stack **stack);
void sa(t_stack **a);
void sb(t_stack **b);
void reverse_rotate(t_stack **stack);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rotate(t_stack **stack);
//sort
int is_sorted(t_stack *a);
void bubble_sort(t_stack **a);
void sort_stack(t_stack **a, t_stack **b, int size);
void radix_sort(t_stack **a, t_stack **b, int size);
int get_max_bits(t_stack *a);
void push_back_to_a(t_stack **a, t_stack **b);
int find_max_index(t_stack *stack);
int get_position(t_stack *stack, int index);
void push_chunks(t_stack **a, t_stack **b, int size);
void chunk_sort(t_stack **a, t_stack **b, int size);


//stack
void free_stack(t_stack **stack);
int stack_size(t_stack *stack);
t_stack *rotate_to_first(t_stack *stack);
void assign_indexes(t_stack *a);
t_stack *create_sorted_stack(t_stack *a);
t_stack *sort_stack_values(t_stack *stack);
void swap_nodes(t_stack *a, t_stack *b);


#endif