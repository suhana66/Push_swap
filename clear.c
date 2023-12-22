/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:16:57 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 12:48:29 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack(t_stack *stack);

void	clear_sorting(t_sorting *sorting)
{
	if (!sorting)
		return ;
	clear_stack(sorting->stack_a);
	clear_stack(sorting->stack_b);
	free(sorting);
}

static void	clear_stack(t_stack *stack)
{
	t_stack	*to_delete;

	while (stack)
	{
		to_delete = stack;
		stack = to_delete->next;
		free(to_delete);
	}
}
