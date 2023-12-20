/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 10:40:43 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *stack);
void	sort(t_list *stack_a, t_list *stack_b, int len_a);
bool	is_sorted(t_list *stack);

void	push_swap(t_list *stack_a, t_list *stack_b, int len_a)
{
	if (is_sorted(stack_a))
		return ;
	if (len_a == 2)
		swap(&stack_a, 'a');
	else if (len_a == 3)
		sort_3(stack_a);
	else
		sort(stack_a, stack_b, len_a);
	print_instruction(0, 0);
}

void	sort_3(t_list *stack)
{
	int	max_value;
	t_list	*temp;

	if (is_sorted(stack))
		return ;
	temp = stack;
	max_value = INT_MIN;
	while (temp)
	{
		if (temp->value > max_value)
			max_value = temp->value;
		temp = temp->next;
	}
	if (stack->value == max_value)
		rotate(&stack, 'a');
	else if (stack->next->value == max_value)
		reverse_rotate(&stack, 'a');
	if (stack->value > stack->next->value)
		swap(&stack, 'a');
}

void	sort(t_list *stack_a, t_list *stack_b, int len_a)
{
	(void)stack_a;
	(void)stack_b;
}

bool	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
