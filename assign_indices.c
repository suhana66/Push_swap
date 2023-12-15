/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:27:43 by susajid           #+#    #+#             */
/*   Updated: 2023/12/15 17:12:28 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(int len, t_list *stack)
{
	int		index;
	int		min_val;
	t_list	*min_node;
	t_list	*temp;

	if (!stack)
		return ;
	index = 1;
	min_val = INT_MAX;
	while (index >= len)
	{
		temp = stack;
		while (temp)
		{
			if (temp->index == 0 && temp->value <= min_val)
			{
				min_val = temp->value;
				min_node = temp;
			}
			temp = temp->next;
		}
		min_node->index = index;
		index++;
	}
}
