/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:38 by susajid           #+#    #+#             */
/*   Updated: 2023/12/23 10:56:41 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*set_stack(int len, char **array);
static int		insert_value(const char *str, int *result);
static bool		if_duplicate(t_stack *result);

t_sorting	*set_sorting(int len, char **array)
{
	t_sorting	*result;

	result = malloc(sizeof(t_sorting));
	if (!result)
		return (NULL);
	result->stack_b = NULL;
	result->stack_a = set_stack(len, array);
	if (!result->stack_a && len != 0)
		return (clear_sorting(result), write(2, "Error\n", 6), NULL);
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
		if (!current || insert_value(array[i], &(current->value)))
			return (clear_stack(result), free(current), NULL);
		current->next = NULL;
		if (last)
			last->next = current;
		else
			result = current;
		last = current;
		if (if_duplicate(result))
			return (clear_stack(result), NULL);
		i++;
	}
	return (result);
}

static int	insert_value(const char *str, int *result)
{
	int	sign;

	if (*str == 0)
		return (1);
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	*result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (2);
		*result = *result * 10 + (*str - 48) * sign;
		if (*result > INT_MAX || *result < INT_MIN)
			return (3);
		str++;
	}
	return (0);
}

static bool	if_duplicate(t_stack *result)
{
	t_stack	*temp;
	t_stack	*start;

	start = result;
	while (result)
	{
		temp = start;
		while (temp)
		{
			if (result != temp && result->value == temp->value)
				return (true);
			temp = temp->next;
		}
		result = result->next;
	}
	return (false);
}
