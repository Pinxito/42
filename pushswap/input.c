/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:10:05 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 15:38:13 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *a, int num)
{
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	push(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*temp;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	node->next = NULL;
	if (!*stack)
		*stack = node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

char	**get_numbers(int argc, char **argv)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
		{
			write(2, "Error1\n", 7);
			return (NULL);
		}
	}
	else
		numbers = &argv[1];
	return (numbers);
}

int	validate_and_push(t_stack **stack, char **numbers, int argc)
{
	int	num;
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!ft_atoi(numbers[i], &num))
		{
			write(2, "Error2\n", 7);
			if (argc == 2)
				free_split(numbers);
			return (free_stack(stack), 0);
		}
		if (is_duplicate(*stack, num))
		{
			write(2, "Error3\n", 7);
			if (argc == 2)
				free_split(numbers);
			return (free_stack(stack), 0);
		}
		push(stack, num);
		i++;
	}
	return (1);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*a;
	char	**numbers;

	a = NULL;
	numbers = get_numbers(argc, argv);
	if (!numbers)
		return (NULL);
	if (!validate_and_push(&a, numbers, argc))
		return (NULL);
	if (argc == 2)
		free_split(numbers);
	return (a);
}
