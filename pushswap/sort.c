/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:06:43 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/01 18:18:45 by gguillen         ###   ########.fr       */
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

int	find_min_index(t_stack *a)
{
	int	min;
	int	index;
	int	i;

	min = a->value;
	index = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	index;

	while (stack_size(*a) > 3)
	{
		index = find_min_index(*a);
		if (index == 0)
			pb(a, b);
		else if (index <= stack_size(*a) / 2)
		{
			while (index-- > 0)
				ra(a);
			pb(a, b);
		}
		else
		{
			while (index++ < stack_size(*a))
				rra(a);
			pb(a, b);
		}
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 10)
		sort_small(a, b);
	else if (size <= 500)
		chunk_sort(a, b, size);
	else
	{
		radix_sort(a, b, size);
	}
}
