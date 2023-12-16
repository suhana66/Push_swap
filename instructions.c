/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:47:21 by susajid           #+#    #+#             */
/*   Updated: 2023/12/16 10:34:30 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_instruction(char instruction, char name);

void	swap(t_list *stack, char stack_name)
{
	t_list	*temp;

	if (!stack)
		return ;
	temp = stack->next->next;
	stack->next->next = stack;
	stack->next = temp;
	print_instruction('s', stack_name);
}

void	rotate(t_list **stack, char stack_name)
{
	t_list	*start;
	t_list	*end;

	if (!*stack || !(*stack)->next)
		return ;
	start = *stack;
	*stack = (*stack)->next;
	end = *stack;
	while (end->next)
		end = end->next;
	end->next = start;
	start->next = NULL;
	ft_printf("a\n");
	print_instruction('r', stack_name);
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
	print_instruction('u', stack_name);
}

static void	print_instruction(char instruction, char name)
{
	static char	previous_instruction = 0;
	static char	previous_name = 0;

	if (!previous_instruction && !previous_name)
	{
		previous_instruction = instruction;
		previous_name = name;
	}
	else
	{
		if (previous_instruction == instruction && previous_name != name)
			ft_printf("%cr\n", instruction);
		else
			ft_printf("%c%c\n", instruction, name);
	}
	previous_instruction = 0;
	previous_name = 0;
}
