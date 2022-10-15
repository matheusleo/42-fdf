/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:59:54 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/15 16:09:57 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_real	rotate_y(t_app *app, int x_real, int z_real, int y_real)
{
	t_real	rotated_coord;
	t_fdf	*fdf;

	fdf = app->fdf;
	rotated_coord.x = cos(fdf->angle_y) * x_real - sin(fdf->angle_y) * z_real;
	rotated_coord.y = y_real;
	rotated_coord.z = sin(fdf->angle_y) * x_real + cos(fdf->angle_y) * z_real;
	return (rotated_coord);
}

t_real	rotate_z(t_app *app, int x_real, int z_real, int y_real)
{
	t_real	rotated_coord;
	t_fdf	*fdf;

	fdf = app->fdf;
	rotated_coord.x = cos(fdf->angle_z) * x_real - sin(fdf->angle_z) * y_real;
	rotated_coord.y = sin(fdf->angle_z) * x_real + cos(fdf->angle_z) * y_real;
	rotated_coord.z = z_real;
	return (rotated_coord);
}

t_real	rotate_x(t_app *app, int x_real, int z_real, int y_real)
{
	t_real	rotated_coord;
	t_fdf	*fdf;

	fdf = app->fdf;
	rotated_coord.x = x_real;
	rotated_coord.y = cos(fdf->angle_x) * y_real - sin(fdf->angle_x) * z_real;
	rotated_coord.z = sin(fdf->angle_x) * y_real + cos(fdf->angle_x) * z_real;
	return (rotated_coord);
}

int	rotate_map(int keycode, t_app *app)
{
	if (keycode == RIGHT_CODE)
		app->fdf->angle_y -= 0.1;
	else if (keycode == LEFT_CODE)
		app->fdf->angle_y += 0.1;
	else if (keycode == UP_CODE)
		app->fdf->angle_x += 0.1;
	else if (keycode == DOWN_CODE)
		app->fdf->angle_x -= 0.1;
	put_map(app);
	return (1);
}
