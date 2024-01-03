/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:38 by susajid           #+#    #+#             */
/*   Updated: 2024/01/08 10:07:20 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*set_stack(int len, char **array);
static char		*insert_value(char *str, int *result);
static bool		if_duplicate(t_stack *stack, int value);
static int		stack_len(t_stack *stack);

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
	result->total_len = stack_len(result->stack_a);
	result->len_a = result->total_len;
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
		if (current)
			array[i] = insert_value(array[i], &(current->value));
		if (!current || !array[i] || if_duplicate(result, current->value))
			return (clear_stack(result), free(current), NULL);
		if (!*array[i])
			i++;
		current->next = NULL;
		if (last)
			last->next = current;
		else
			result = current;
		last = current;
	}
	return (result);
}

static char	*insert_value(char *str, int *result)
{
	int	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (NULL);
	*result = 0;
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10 + (*str++ - '0') * sign;
		if ((*result < 0 && sign > 0) || (*result > 0 && sign < 0))
			return (NULL);
	}
	if (*str && !ft_isspace(*str))
		return (NULL);
	while (ft_isspace(*str))
		str++;
	return (str);
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

static int	stack_len(t_stack *stack)
{
	int	result;

	result = 0;
	while (stack)
	{
		stack = stack->next;
		result++;
	}
	return (result);
}
