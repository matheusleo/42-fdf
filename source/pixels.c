/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:13:57 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/13 00:07:22 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(t_app *app, int x, int y, int color)
{
	int		offset;
	char	*real_pixel;

	if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
	{
		offset = y * app->img_line_size + x * (app->img_bpp / 8);
		real_pixel = app->img_addr + offset;
		*(unsigned int *)real_pixel = color;
	}
}
