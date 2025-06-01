/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:32:21 by gguillen          #+#    #+#             */
/*   Updated: 2025/06/01 18:51:17 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(int *array, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	get_index(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indexes1(t_stack *stack)
{
	int		size;
	int		*array;
	t_stack	*temp;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	temp = stack;
	if (!array)
		return ;
	fill_array(array, stack);
	sort_array(array, size);
	while (temp)
	{
		temp->index = get_index(array, size, temp->value);
		temp = temp->next;
	}
	free(array);
}
