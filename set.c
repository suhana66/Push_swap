/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:38 by susajid           #+#    #+#             */
/*   Updated: 2023/12/29 07:57:29 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*set_stack(int len, char **array);
static int		insert_value(const char *str, int *result);
static bool		if_duplicate(t_stack *stack, int value);

t_sorting	*set_sorting(int len, char **array)
{
	t_sorting	*result;

	result = malloc(sizeof(t_sorting));
	if (!result)
		return (NULL);
	result->stack_b = NULL;
	result->stack_a = set_stack(len, array);
	if (!result->stack_a && len != 0)
		return (free(result), write(2, "Error\n", 6), NULL);
	result->total_len = len;
	result->len_a = len;
	result->len_b = 0;
	return (result);
}

static t_stack	*set_stack(int len, char **array)
{
	t_stack	*result;
	t_stack	*current;
	t_stack	*last;
	int		i;

	i = 0;
	result = NULL;
	last = NULL;
	while (i < len)
	{
		current = malloc(sizeof(t_stack));
		if (!current || insert_value(array[i++], &(current->value))
			|| if_duplicate(result, current->value))
			return (clear_stack(result), free(current), NULL);
		current->next = NULL;
		if (last)
			last->next = current;
		else
			result = current;
		last = current;
	}
	return (result);
}

static int	insert_value(const char *str, int *result)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	*result = 0;
	if (!*str)
		return (1);
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10 + (*str - '0') * sign;
		if ((*result < 0 && sign > 0) || (*result > 0 && sign < 0))
			return (2);
		str++;
	}
	if (*str)
		return (3);
	return (0);
}

static bool	if_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}
