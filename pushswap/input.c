#include "push_swap.h"

int ft_atoi(const char *str, int *out)
{
	long result = 0;
	int sign = 1;
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0); // No hay dígitos

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}

int is_duplicate(t_stack *a, int num)
{
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void push(t_stack **stack, int value)
{
	t_stack *node = malloc(sizeof(t_stack));
	t_stack *temp;

	if (!node)
		return;
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

t_stack *parse_input(int argc, char **argv)
{
	t_stack *a = NULL;
	char **numbers;
	int num, i = 0;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (write(2, "Error1\n", 7), NULL);
	}
	else
		numbers = &argv[1];

	while (numbers[i])
	{
		if (!ft_atoi(numbers[i], &num))
		{
			write(2, "Error2\n", 7);
			if (argc == 2)
				free_split(numbers);
			free_stack(&a);
			return NULL;
		}
		if (is_duplicate(a, num))
		{
			write(2, "Error3\n", 7);
			if (argc == 2)
				free_split(numbers);
			free_stack(&a);
			return NULL;
		}
		push(&a, num);
		i++;
	}

	if (argc == 2)
		free_split(numbers);
	return a;
}

