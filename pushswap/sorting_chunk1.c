/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:15:53 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/31 04:53:46 by gguillen         ###   ########.fr       */
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
	t_chunk_info	info;

	if (size <= 100)
		info.chunks = 5;
	else
		info.chunks = 13;
	info.chunk_size = size / info.chunks;
	info.remainder = size % info.chunks;
	push_chunks_loop(a, b, info);
}

void	push_chunks_loop(t_stack **a, t_stack **b, t_chunk_info info)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (i < info.chunks)
	{
		end = start + info.chunk_size;
		if (i == info.chunks - 1)
			end += info.remainder;
		push_single_chunk(a, b, start, end);
		start = end;
		i++;
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
