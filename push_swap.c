/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/15 18:40:40 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *stack_a, t_list *stack_b, int len_a)
{
	if (!is_sorted(stack_a))
		if (len_a == 2)
			sa(stack_a);
		else if (len_a == 3)
			sort_3(stack_a, len_a);
	(void) stack_b;
}

void	sort_3(t_list *stack, int stack_size)
{
	if (stack->index == stack_size)
		swap(stack);
	if (stack->next->index == stack_size)
		reverse_rotate(stack);		
}
