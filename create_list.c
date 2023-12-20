/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:53:25 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 10:23:55 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_list(t_list **result);
static int	insert_value(const char *str, int *result);
static bool	if_duplicate(t_list *result);

t_list	*create_list(int len, char **array)
{
	t_list	*result;
	t_list	*current;
	t_list	*last;
	int		i;

	i = 0;
	result = NULL;
	last = NULL;
	while (i < len)
	{
		current = malloc(sizeof(t_list));
		if (!current)
			return (error_list(&result), NULL);
		if (last)
			last->next = current;
		else
			result = current;
		last = current;
		if (insert_value(array[i], &(current->value)) || if_duplicate(result))
			return (error_list(&result), NULL);
		current->next = NULL;
		i++;
	}
	return (result);
}

static void	error_list(t_list **result)
{
	clear_list(result);
	write(2, "Error\n", 6);
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

static bool	if_duplicate(t_list *result)
{
	t_list	*temp;

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
