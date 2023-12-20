/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:16:49 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 15:07:15 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack(--argc, &argv[1]);
	stack_b = NULL;
	if (!stack_a)
		return (1);
	if (argc < 2)
		return (clear_stack(&stack_a), 0);
	push_swap(stack_a, stack_b, argc);
	return (clear_stack(&stack_a), clear_stack(&stack_b), 0);
}
