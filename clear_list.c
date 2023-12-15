/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:00:50 by susajid           #+#    #+#             */
/*   Updated: 2023/12/15 17:01:02 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_list(t_list **lst)
{
	t_list	*to_delete;

	if (!lst)
		return ;
	while (*lst)
	{
		to_delete = *lst;
		*lst = to_delete->next;
		free(to_delete);
	}
	*lst = NULL;
}
