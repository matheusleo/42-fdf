/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:59:54 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/16 16:11:50 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_coord	rotate_y(t_app *app, int x_real, int z_real, int y_real)
{
	t_coord		rotated_coord;
	t_fdf		*fdf;
	float		x;
	float		z;

	fdf = app->fdf;
	x = x_real - (fdf->cols * fdf->edge_len) / 2;
	z = z_real - (fdf->rows * fdf->edge_len) / 2;
	rotated_coord.x = cos(fdf->angle_y) * x - sin(fdf->angle_y) * z;
	rotated_coord.y = y_real;
	rotated_coord.z = sin(fdf->angle_y) * x + cos(fdf->angle_y) * z;
	return (rotated_coord);
}

t_coord	rotate_z(t_app *app, int x_real, int z_real, int y_real)
{
	t_coord	rotated_coord;
	t_fdf	*fdf;
	float	x;

	fdf = app->fdf;
	x = x_real - (fdf->cols * fdf->edge_len) / 2;
	rotated_coord.x = cos(fdf->angle_z) * x - sin(fdf->angle_z) * y_real;
	rotated_coord.y = sin(fdf->angle_z) * x + cos(fdf->angle_z) * y_real;
	rotated_coord.z = z_real;
	return (rotated_coord);
}

t_coord	rotate_x(t_app *app, int x_real, int z_real, int y_real)
{
	t_coord	rotated_coord;
	t_fdf	*fdf;
	float	z;

	fdf = app->fdf;
	z = z_real - (fdf->rows * fdf->edge_len) / 2;
	rotated_coord.x = x_real;
	rotated_coord.y = cos(fdf->angle_x) * y_real - sin(fdf->angle_x) * z;
	rotated_coord.z = sin(fdf->angle_x) * y_real + cos(fdf->angle_x) * z;
	return (rotated_coord);
}

int	rotate_map(int keycode, t_app *app)
{
	if (keycode == D_KEY)
		app->fdf->angle_y -= 0.1;
	else if (keycode == A_KEY)
		app->fdf->angle_y += 0.1;
	else if (keycode == S_KEY)
		app->fdf->angle_x += 0.1;
	else if (keycode == W_KEY)
		app->fdf->angle_x -= 0.1;
	else if (keycode == Q_KEY)
		app->fdf->angle_z -= 0.1;
	else if (keycode == E_KEY)
		app->fdf->angle_z += 0.1;
	render(app);
	return (1);
}
