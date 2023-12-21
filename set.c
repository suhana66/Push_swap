/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:38 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 09:51:10 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		error_sorting(t_sorting *sorting);
static t_stack	*set_stack(int len, char **array);
static int		insert_value(const char *str, int *result);
static bool		if_duplicate(t_stack *result);

t_sorting	*set_sorting(int len, char **array)
{
	t_sorting	*result;

	result = malloc(sizeof(t_sorting));
	if (!result)
		return (error_sorting(result), NULL);
	result->stack_a = set_stack(len, array);
	if (!result->stack_a)
		return (error_sorting(result), NULL);
	result->stack_b = NULL;
	result->len_a = len;
	return (result);
}

static void	error_sorting(t_sorting *sorting)
{
	clear_sorting(sorting);
	write(2, "Error\n", 6);
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
		if (!current)
			return (NULL);
		if (last)
			last->next = current;
		else
			result = current;
		last = current;
		if (insert_value(array[i], &(current->value)) || if_duplicate(result))
			return (NULL);
		current->next = NULL;
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

	temp = result;
	while (result)
	{
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
