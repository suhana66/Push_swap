/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:47:21 by susajid           #+#    #+#             */
/*   Updated: 2023/12/15 19:09:48 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char stack_name)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	print_swap(stack_name);
}

void	rotate(t_list *stack, char stack_name)
{
	t_list	*start;

	if (!stack)
		return ;
	start = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = start;
	start->next = NULL;
	print_rotate(stack_name);
}

void	reverse_rotate(t_list *stack, char stack_name)
{
	t_list	*previous;
	t_list	*last;

	if (!stack)
		return ;
	last = stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = stack;
	print_reverse_rotate(stack_name);
}
