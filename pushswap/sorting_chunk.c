#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return max;
}

// Obtener posición de un índice específico
int	get_position(t_stack *stack, int index)
{
	int i = 0;
	while (stack)
	{
		if (stack->index == index)
			break;
		stack = stack->next;
		i++;
	}
	return i;
}

// Mueve el número más grande de B al tope
void	rotate_b_to_top(t_stack **b, int pos, int size)
{
	while ((*b)->index != find_max_index(*b))
	{
		if (pos <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}

// Busca la distancia al primer número dentro del chunk
int get_distance(t_stack *stack, int min, int max)
{
	int dist = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			return dist;
		stack = stack->next;
		dist++;
	}
	return -1;
}

// Pasa un chunk de A a B
void	push_single_chunk(t_stack **a, t_stack **b, int start, int end)
{
	int pushed = 0;
	int size = stack_size(*a);

	while (pushed < (end - start))
	{
		int dist = get_distance(*a, start, end);
		if ((*a)->index >= start && (*a)->index < end)
		{
			pb(a, b);
			pushed++;
			if ((*b)->index < (start + end) / 2)
				rb(b);
		}
		else if (dist <= size / 2)
			ra(a);
		else
			rra(a);
	}
}

// Divide A en chunks y los empuja a B
void	push_chunks(t_stack **a, t_stack **b, int size)
{
	int	chunks = (size <= 100) ? 5 : 13;
	int	chunk_size = size / chunks;
	int	remainder = size % chunks;
	int	start = 0;
	int	end;

	for (int i = 0; i < chunks; i++)
	{
		end = start + chunk_size;
		if (i == chunks - 1)
			end += remainder;
		push_single_chunk(a, b, start, end);
		start = end;
	}
}

// Vuelve a empujar los elementos desde B a A
void	push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		int max = find_max_index(*b);
		int pos = get_position(*b, max);
		int size = stack_size(*b);
		rotate_b_to_top(b, pos, size);
		pa(a, b);
	}
}

// Función principal de ordenación
void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	assign_indexes(*a);
	push_chunks(a, b, size);
	push_back_to_a(a, b);
}
