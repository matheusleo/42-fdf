/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:50:00 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 11:50:14 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	lstiter(t_list *lst, t_app *app, void (*f)(void *, void *))
{
	t_list	*cur_node;

	cur_node = lst;
	while (cur_node && cur_node->content)
	{
		f(cur_node, app);
		cur_node = cur_node->next;
	}
}
