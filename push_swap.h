/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:54:45 by susajid           #+#    #+#             */
/*   Updated: 2023/12/20 10:25:36 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

t_list	*create_list(int len, char **array);
void	push_swap(t_list *stack_a, t_list *stack_b, int len_a);
void	clear_list(t_list **lst);

void	swap(t_list **stack, char stack_name);
void	rotate(t_list **stack, char stack_name);
void	reverse_rotate(t_list **stack, char stack_name);
void	push(t_list **src_stack, t_list **dst_stack, char dst_stack_name);
void	print_instruction(char *instruction, char name);

#endif /* PUSH_SWAP_H */