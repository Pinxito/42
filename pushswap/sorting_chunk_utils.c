/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:22:58 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 16:23:08 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_sorted(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = value;
	new->index = 0;
	new->next = NULL;
	if (!*stack || value < (*stack)->value)
	{
		new->next = *stack;
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next && current->next->value < value)
		current = current->next;
	new->next = current->next;
	current->next = new;
}

t_stack	*create_sorted_stack(t_stack *original)
{
	t_stack	*sorted;
	t_stack	*temp;

	sorted = NULL;
	temp = original;
	while (temp)
	{
		stack_add_sorted(&sorted, temp->value);
		temp = temp->next;
	}
	return (sorted);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*sorted;
	t_stack	*ptr;
	t_stack	*s;
	int		index;

	sorted = create_sorted_stack(stack);
	ptr = stack;
	while (ptr)
	{
		s = sorted;
		index = 0;
		while (s)
		{
			if (s->value == ptr->value)
			{
				ptr->index = index;
				break ;
			}
			index++;
			s = s->next;
		}
		ptr = ptr->next;
	}
	free_stack(&sorted);
}
