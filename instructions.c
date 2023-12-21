/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:47:21 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 11:25:55 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	**assign_stack(t_sorting *sorting, char stack_name);

void	swap(t_sorting *sorting, char stack_name, bool if_print)
{
	t_stack	**stack;
	t_stack	*node1;
	t_stack	*node2;

	stack = assign_stack(sorting, stack_name);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = (*stack)->next;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
	if (if_print)
		ft_printf("s%c\n", stack_name);
}

void	rotate(t_sorting *sorting, char stack_name, bool if_print)
{
	t_stack	**stack;
	t_stack	*start;
	t_stack	*end;

	stack = assign_stack(sorting, stack_name);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	start = *stack;
	*stack = (*stack)->next;
	end = *stack;
	while (end->next)
		end = end->next;
	end->next = start;
	start->next = NULL;
	if (if_print)
		ft_printf("r%c\n", stack_name);
}

void	reverse_rotate(t_sorting *sorting, char stack_name, bool if_print)
{
	t_stack	**stack;
	t_stack	*previous;
	t_stack	*last;

	stack = assign_stack(sorting, stack_name);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack;
	*stack = last;
	if (if_print)
		ft_printf("rr%c\n", stack_name);
}

void	push(t_sorting *sorting, char stack_name, bool if_print)
{
	t_stack	**src_stack;
	t_stack	**dst_stack;
	t_stack	*temp;

	dst_stack = assign_stack(sorting, stack_name);
	if (stack_name == 'b')
		src_stack = assign_stack(sorting, 'a');
	else if (stack_name == 'a')
		src_stack = assign_stack(sorting, 'b');
	else
		src_stack = NULL;
	if (!src_stack || !dst_stack)
		return ;
	temp = *src_stack;
	*src_stack = (*src_stack)->next;
	temp->next = *dst_stack;
	*dst_stack = temp;
	if (if_print)
		ft_printf("p%c\n", stack_name);
}

static t_stack	**assign_stack(t_sorting *sorting, char stack_name)
{
	if (!sorting)
		return (NULL);
	if (stack_name == 'a')
		return (&(sorting->stack_a));
	else if (stack_name == 'b')
		return (&(sorting->stack_b));
	else
		return (NULL);
}
