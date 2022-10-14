/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:57:06 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/13 22:49:00 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	bresenham_fast_x(t_app *app, t_coord *pos_i, t_coord *pos_f)
{
	int		d_x;
	int		d_y;
	int		inc_x;
	int		inc_y;
	double	eps;

	d_x = pos_f->x - pos_i->x;
	d_y = pos_f->y - pos_i->y;
	inc_x = ternary(d_x > 0, 1, -1);
	inc_y = ternary(d_y > 0, 1, -1);
	eps = 0;
	while (ternary(inc_x < 0, pos_i->x >= pos_f->x, pos_i->x <= pos_f->x))
	{
		put_pixel(app, pos_i->x, pos_i->y, app->color);
		eps += abs(d_y);
		if (eps >= abs(d_x))
		{
			pos_i->y += inc_y;
			eps -= abs(d_x);
		}
		pos_i->x += inc_x;
	}
}

static void	bresenham_fast_y(t_app *app, t_coord *pos_i, t_coord *pos_f)
{
	int		d_x;
	int		d_y;
	int		inc_x;
	int		inc_y;
	double	eps;

	d_x = pos_f->x - pos_i->x;
	d_y = pos_f->y - pos_i->y;
	inc_x = ternary(d_x > 0, 1, -1);
	inc_y = ternary(d_y > 0, 1, -1);
	eps = 0;
	while (ternary(inc_y < 0, pos_i->y >= pos_f->y, pos_i->y <= pos_f->y))
	{
		put_pixel(app, pos_i->x, pos_i->y, app->color);
		eps += abs(d_x);
		if (eps >= abs(d_y))
		{
			pos_i->x += inc_x;
			eps -= abs(d_y);
		}
		pos_i->y += inc_y;
	}
}

void	bresenham(t_app *app, t_coord *pos_i, t_coord *pos_f)
{
	int	d_x;
	int	d_y;

	d_x = pos_f->x - pos_i->x;
	d_y = pos_f->y - pos_i->y;
	if (abs(d_x) > abs(d_y))
		bresenham_fast_x(app, pos_i, pos_f);
	else
		bresenham_fast_y(app, pos_i, pos_f);
}
