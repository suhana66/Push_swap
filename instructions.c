/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:47:21 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 15:07:03 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char stack_name)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!*stack || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = (*stack)->next;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
	print_instruction("s", stack_name);
}

void	rotate(t_stack **stack, char stack_name)
{
	t_stack	*start;
	t_stack	*end;

	if (!*stack || !(*stack)->next)
		return ;
	start = *stack;
	*stack = (*stack)->next;
	end = *stack;
	while (end->next)
		end = end->next;
	end->next = start;
	start->next = NULL;
	print_instruction("r", stack_name);
}

void	reverse_rotate(t_stack **stack, char stack_name)
{
	t_stack	*previous;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
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
	print_instruction("rr", stack_name);
}

void	push(t_stack **src_stack, t_stack **dst_stack, char dst_stack_name)
{
	t_stack	*temp;

	temp = *src_stack;
	*src_stack = (*src_stack)->next;
	temp->next = *dst_stack;
	*dst_stack = temp;
	print_instruction("p", dst_stack_name);
}

void	print_instruction(char *instruction, char name)
{
	static char	*previous_instruction = NULL;
	static char	previous_name = 0;
	size_t		instruction_len;

	instruction_len = ft_strlen(previous_instruction);
	if (ft_strlen(instruction) > instruction_len)
		instruction_len = ft_strlen(instruction);
	if (!previous_instruction && !previous_name && instruction && name)
	{
		previous_instruction = instruction;
		previous_name = name;
	}
	else if (instruction && previous_name != name
		&& !ft_strncmp(previous_instruction, instruction, instruction_len))
	{
		ft_printf("%sr\n", instruction);
		previous_instruction = NULL;
		previous_name = 0;
	}
	else
	{
		ft_printf("%s%c\n", previous_instruction, previous_name);
		previous_instruction = instruction;
		previous_name = name;
	}
}
