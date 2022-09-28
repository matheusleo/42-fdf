/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:04:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/09/27 23:01:26 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	shut_down(t_app *app)
{
	ft_printf("Kaboom, Rico!\n");
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	mlx_loop_end(app->mlx);
	free(app->mlx);
	exit (0);
}

static int	key_handler(int keycode, t_app *app)
{
	if (keycode == ESC_CODE)
		shut_down(app);
	return (0);
}

void	init_app(void)
{
	t_app	app;

	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, WIN_LENGTH, WIN_HEIGHT, "fdf");
	mlx_key_hook(app.win, key_handler, &app);
	mlx_hook(app.win, ON_DESTROY, 0L, shut_down, &app);
	mlx_loop(app.mlx);
}
