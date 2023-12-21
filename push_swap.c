/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:05 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 11:28:19 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_sorting *sorting)
{
	if (is_sorted(sorting->stack_a))
		return ;
	if (sorting->len_a == 2)
		swap(sorting, 'a', true);
	else if (sorting->len_a == 3)
		sort_3(sorting);
	else
		sort(sorting);
}

void	sort_3(t_sorting *sorting)
{
	int	max_value;

	if (is_sorted(sorting->stack_a))
		return ;
	max_value = find_max(sorting->stack_a);
	if (sorting->stack_a->value == max_value)
		rotate(sorting, 'a', true);
	else if (sorting->stack_a->next->value == max_value)
		reverse_rotate(sorting, 'a', true);
	if (sorting->stack_a->value > sorting->stack_a->next->value)
		swap(sorting, 'a', true);
}
