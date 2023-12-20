/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:16:57 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 18:18:00 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*to_delete;

	if (!stack)
		return ;
	while (*stack)
	{
		to_delete = *stack;
		*stack = to_delete->next;
		free(to_delete);
	}
	*stack = NULL;
}
