/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:16:49 by susajid           #+#    #+#             */
/*   Updated: 2023/12/16 16:35:58 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_list(--argc, &argv[1]);
	stack_b = NULL;
	if (!stack_a)
		return (1);
	if (argc < 2)
		return (clear_list(&stack_a), clear_list(&stack_b), 0);
	assign_indices(argc, stack_a);
	push_swap(stack_a, stack_b, argc);
	return (clear_list(&stack_a), clear_list(&stack_b), 0);
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
