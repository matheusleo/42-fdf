/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:50:00 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/16 18:25:01 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	lstiter(t_list *lst, t_app *app, void (*f)(t_app *, t_list *, int))
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

int	render(t_app *app)
{
	put_map(app);
	put_menu(app);
	return (1);
}

void	reset(t_app *app)
{
	app->fdf->edge_len = 15;
	app->fdf->zoom = 2;
	app->fdf->x_offset = 0;
	app->fdf->y_offset = 0;
	app->fdf->level_height = 15;
	app->fdf->angle_x = 0;
	app->fdf->angle_y = 0;
	app->fdf->angle_z = 0;
	app->fdf->angle_proj = 0.46;
	app->color = WHITE_CODE;
	render(app);
}
