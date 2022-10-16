/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:49:52 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/16 16:01:31 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	projection_handler(int keycode, t_app *app)
{
	if (keycode == I_KEY)
	{
		app->fdf->angle_proj = 0.46;
	}
	else if (keycode == P_KEY)
	{
		app->fdf->angle_proj = 0.52;
		app->fdf->angle_x = 0.95;
		app->fdf->angle_y = -0.79;
		app->fdf->angle_z = 0;
	}
	render(app);
	return (1);
}
