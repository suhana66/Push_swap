/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:16:49 by susajid           #+#    #+#             */
/*   Updated: 2023/12/15 12:57:47 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = create_list(--argc, &argv[1]);
	if (!stack_a)
		return (1);
	assign_indices(argc, stack_a);
	while (stack_a)
	{
		ft_printf("%d ", stack_a->value);
		ft_printf("[%d]\n", stack_a->index);
		stack_a = stack_a->next;
	}
	return (0);
}
