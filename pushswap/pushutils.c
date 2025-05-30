/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:50:19 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/29 16:50:21 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!(*from))
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
