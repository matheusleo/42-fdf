/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:43:42 by mleonard          #+#    #+#             */

/*   Updated: 2022/10/05 23:59:05 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(t_app *app, int x, int y, int color)
{
	int		offset;
	char	*real_pixel;

	offset = y * app->img_line_size + x * (app->img_bpp / 8);
	real_pixel = app->img_addr + offset;
	*(unsigned int *)real_pixel = color;
}
