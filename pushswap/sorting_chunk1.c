/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:15:53 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 16:20:46 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_single_chunk(t_stack **a, t_stack **b, int start, int end)
{
	int	pushed;
	int	size;
	int	dist;

	pushed = 0;
	size = stack_size(*a);
	while (pushed < (end - start))
	{
		dist = get_distance(*a, start, end);
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

void	push_chunks(t_stack **a, t_stack **b, int size)
{
	int	chunks;
	int	chunk_size;
	int	remainder;
	int	start;
	int	end;

	chunks = (size <= 100) ? 5 : 13;
	chunk_size = size / chunks;
	remainder = size % chunks;
	start = 0;
	for (int i = 0; i < chunks; i++)
	{
		end = start + chunk_size;
		if (i == chunks - 1)
			end += remainder;
		push_single_chunk(a, b, start, end);
		start = end;
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = find_max_index(*b);
		pos = get_position(*b, max);
		size = stack_size(*b);
		rotate_b_to_top(b, pos, size);
		pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	assign_indexes(*a);
	push_chunks(a, b, size);
	push_back_to_a(a, b);
}
