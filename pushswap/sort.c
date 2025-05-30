/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:06:43 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 00:06:43 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	bubble_sort(t_stack **a)
{
	int		swapped;
	t_stack	*ptr;

	if (!(*a) || !(*a)->next)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = *a;
		while (ptr && ptr->next)
		{
			if (ptr->value > ptr->next->value)
			{
				sa(a);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		if (is_sorted(*a))
			break ;
		ra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size <= 500)
		chunk_sort(a, b, size);
	else
		radix_sort(a, b, size);
	rotate_to_first(*a);
}
