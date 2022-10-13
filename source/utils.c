/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:50:00 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 22:31:44 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	lstiter(t_list *lst, t_app *app, void (*f)(void *, void *, int))
{
	t_list	*cur_node;
	int		node_pos;

	cur_node = lst;
	node_pos = 0;
	while (cur_node && cur_node->content)
	{
		f(app, cur_node, node_pos);
		cur_node = cur_node->next;
		node_pos++;
	}
}

int	ternary(int codition, int return_true, int return_false)
{
	if (codition)
		return (return_true);
	return (return_false);
}
