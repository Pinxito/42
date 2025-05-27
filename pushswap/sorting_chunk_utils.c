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


t_stack *create_sorted_stack(t_stack *original)
{
	t_stack *sorted = NULL;
	t_stack *temp = original;

	while (temp)
	{
		stack_add_sorted(&sorted, temp->value);
		temp = temp->next;
	}
	return (sorted);
}

void assign_indexes(t_stack *stack)
{
	t_stack *sorted = create_sorted_stack(stack);
	t_stack *ptr = stack;

	while (ptr)
	{
		t_stack *s = sorted;
		int index = 0;
		while (s)
		{
			if (s->value == ptr->value)
			{
				ptr->index = index;
				break;
			}
			index++;
			s = s->next;
		}
		ptr = ptr->next;
	}
	free_stack(&sorted);
}
