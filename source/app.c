/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:04:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 22:18:45 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	clean_win(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img);
	app->img = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	app->img_addr = mlx_get_data_addr(app->img, &(app->img_bpp), \
		&(app->img_line_size), &(app->img_endian));
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int	shutdown_app(t_app *app)
{
	t_fdf	*fdf;

	ft_printf("Kaboom, Rico! 🐧\n");
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_display(app->mlx);
	mlx_loop_end(app->mlx);
	fdf = app->fdf;
	ft_lstclear(&(fdf->map_matrix), free);
	free(app->mlx);
	free(app);
	exit (0);
}

t_app	*init_app(t_fdf *fdf)
{
	t_app	*app;

	app = (t_app *)malloc(sizeof(t_app));
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	app->img = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	app->img_addr = mlx_get_data_addr(app->img, &(app->img_bpp), \
		&(app->img_line_size), &(app->img_endian));
	app->fdf = fdf;
	put_map(app);
	mlx_key_hook(app->win, key_handler, app);
	mlx_hook(app->win, ON_DESTROY, 0L, shutdown_app, app);
	mlx_loop(app->mlx);
	return (app);
}
