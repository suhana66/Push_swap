/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:16:49 by susajid           #+#    #+#             */
/*   Updated: 2023/12/21 09:58:49 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_sorting	*sorting;

	sorting = set_sorting(--argc, &argv[1]);
	if (!sorting)
		return (1);
	if (sorting->len_a >= 2)
		push_swap(sorting);
	return (clear_sorting(sorting), 0);
}
