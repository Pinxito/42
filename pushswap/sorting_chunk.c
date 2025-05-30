/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:07:07 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 16:20:09 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
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

int	get_distance(t_stack *stack, int min, int max)
{
	int	dist;

	dist = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			return (dist);
		stack = stack->next;
		dist++;
	}
	return (-1);
}
