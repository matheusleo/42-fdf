/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:27:08 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/15 16:35:44 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	translate_map(int keycode, t_app *app)
{
	if (keycode == UP_KEY)
		app->fdf->y_offset -= (app->fdf->edge_len / 2);
	else if (keycode == LEFT_KEY)
		app->fdf->x_offset -= (app->fdf->edge_len / 2);
	else if (keycode == DOWN_KEY)
		app->fdf->y_offset += (app->fdf->edge_len / 2);
	else if (keycode == RIGHT_KEY)
		app->fdf->x_offset += (app->fdf->edge_len / 2);
	put_map(app);
	return (1);
}

int	zoom_map(int keycode, t_app *app)
{
	if (keycode == PLUS_KEY)
		app->fdf->zoom *= 2;
	else if (keycode == MINUS_KEY && app->fdf->zoom / 2 > 0)
		app->fdf->zoom /= 2;
	put_map(app);
	return (1);
}

int	color_handler(int keycode, t_app *app)
{
	static int	colors[5] = {WHITE_CODE, RED_CODE, GREEN_CODE, \
							MANGO_CODE, VIOLET_CODE};
	static int	cur_color = 0;

	if (keycode == ONE_KEY)
		cur_color = (cur_color - 1) % 5;
	else if (keycode == TWO_KEY)
		cur_color = (cur_color + 1) % 5;
	app->color = colors[abs(cur_color)];
	put_map(app);
	return (1);
}

int	level_handler(int keycode, t_app *app)
{
	if (keycode == GT_KEY)
		app->fdf->level_height += 1;
	else if (keycode == LT_KEY)
		app->fdf->level_height -= 1;
	put_map(app);
	return (1);
}

int	key_handler(int keycode, t_app *app)
{
	static int	translate_keys[4] = {UP_KEY, DOWN_KEY, LEFT_KEY, RIGHT_KEY};
	static int	rotation_keys[6] = {W_KEY, A_KEY, S_KEY, D_KEY, Q_KEY, E_KEY};
	static int	zoom_keys[2] = {PLUS_KEY, MINUS_KEY};
	static int	colors_keys[2] = {ONE_KEY, TWO_KEY};
	static int	level_keys[2] = {GT_KEY, LT_KEY};

	if (keycode == ESC_KEY)
		shutdown_app(app);
	else if (ft_memchr(translate_keys, keycode, sizeof(int) * 4))
		translate_map(keycode, app);
	else if (ft_memchr(rotation_keys, keycode, sizeof(int) * 6))
		rotate_map(keycode, app);
	else if (ft_memchr(zoom_keys, keycode, sizeof(int) * 2))
		zoom_map(keycode, app);
	else if (ft_memchr(colors_keys, keycode, sizeof(int) * 2))
		color_handler(keycode, app);
	else if (ft_memchr(level_keys, keycode, sizeof(int) * 2))
		level_handler(keycode, app);
	return (1);
}
