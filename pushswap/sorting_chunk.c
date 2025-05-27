#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	if (!stack)
		return (-1); // o error definido

	int max = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}


int	get_position(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}


void rotate_b_to_top(t_stack **b, int pos, int size)
{
	while ((*b)->index != find_max_index(*b))
	{
		if (pos <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}



void	push_single_chunk(t_stack **a, t_stack **b, int chunk_start, int chunk_end)
{
	int pushed = 0;
	int chunk_size = chunk_end - chunk_start;

	while (*a && pushed < chunk_size)
	{
		if ((*a)->index >= chunk_start && (*a)->index < chunk_end)
		{
			pb(a, b);
			pushed++;
			if ((*b)->index < chunk_start + (chunk_size / 2))
				rb(b);
		}
		else
			ra(a);
	}
}
void	push_chunks(t_stack **a, t_stack **b, int size)
{
	int	chunk_count = 5;
	int	chunk_size = size / chunk_count;
	int	remainder = size % chunk_count;
	int	chunk_start = 0;
	int	chunk_end;

	for (int i = 0; i < chunk_count; i++)
	{
		chunk_end = chunk_start + chunk_size;
		if (i == chunk_count - 1)
			chunk_end += remainder;

		push_single_chunk(a, b, chunk_start, chunk_end);
		chunk_start = chunk_end;
	}
}



void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*b)
	{
		max_index = find_max_index(*b);
		pos = get_position(*b, max_index);
		size = stack_size(*b);
    
		rotate_b_to_top(b, pos, size);
		pa(a, b);
        ft_print_stack(*a);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	assign_indexes(*a);
    t_stack *tmp = *a;
    while (tmp)
    {
        tmp = tmp->next;
    }

	push_chunks(a, b, size);
	push_back_to_a(a, b);
}