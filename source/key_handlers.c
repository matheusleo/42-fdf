/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:27:08 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/13 22:50:30 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	translate_map(int keycode, t_app *app)
{
	if (keycode == W_CODE)
		app->fdf->y_offset -= (app->fdf->edge_len / 2);
	else if (keycode == A_CODE)
		app->fdf->x_offset -= (app->fdf->edge_len / 2);
	else if (keycode == S_CODE)
		app->fdf->y_offset += (app->fdf->edge_len / 2);
	else if (keycode == D_CODE)
		app->fdf->x_offset += (app->fdf->edge_len / 2);
	put_map(app);
	return (1);
}

int	zoom_map(int keycode, t_app *app)
{
	if (keycode == PLUS_CODE)
		app->fdf->zoom *= 2;
	else if (keycode == MINUS_CODE && app->fdf->zoom / 2 > 0)
		app->fdf->zoom /= 2;
	put_map(app);
	return (1);
}

int	color_handler(int keycode, t_app *app)
{
	static int	colors[5] = {WHITE_CODE, RED_CODE, GREEN_CODE, \
							MANGO_CODE, VIOLET_CODE};
	static int	cur_color = 0;

	if (keycode == Q_CODE)
		cur_color = (cur_color - 1) % 5;
	else if (keycode == E_CODE)
		cur_color = (cur_color + 1) % 5;
	app->color = colors[abs(cur_color)];
	put_map(app);
	return (1);
}

int	level_handler(int keycode, t_app *app)
{
	if (keycode == GT_CODE)
		app->fdf->level_height += 2;
	else if (keycode == LT_CODE)
		app->fdf->level_height -= 2;
	put_map(app);
	return (1);
}

int	key_handler(int keycode, t_app *app)
{
	static int	translation_keys[4] = {W_CODE, A_CODE, S_CODE, D_CODE};
	static int	zoom_keys[2] = {PLUS_CODE, MINUS_CODE};
	static int	colors_keys[2] = {Q_CODE, E_CODE};
	static int	level_keys[2] = {GT_CODE, LT_CODE};

	if (keycode == ESC_CODE)
		shutdown_app(app);
	else if (ft_memchr(translation_keys, keycode, sizeof(int) * 4))
		translate_map(keycode, app);
	else if (ft_memchr(zoom_keys, keycode, sizeof(int) * 2))
		zoom_map(keycode, app);
	else if (ft_memchr(colors_keys, keycode, sizeof(int) * 2))
		color_handler(keycode, app);
	else if (ft_memchr(level_keys, keycode, sizeof(int) * 2))
		level_handler(keycode, app);
	return (1);
}
