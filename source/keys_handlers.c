/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:27:08 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 22:21:26 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	translate_map(int keycode, t_app *app)
{
	t_fdf	*fdf;

	fdf = app->fdf;
	if (keycode == W_CODE)
		fdf->y_offset -= (fdf->edge_len / 2);
	else if (keycode == A_CODE)
		fdf->x_offset -= (fdf->edge_len / 2);
	else if (keycode == S_CODE)
		fdf->y_offset += (fdf->edge_len / 2);
	else if (keycode == D_CODE)
		fdf->x_offset += (fdf->edge_len / 2);
	put_map(app);
	return (1);
}

int	key_handler(int keycode, t_app *app)
{
	static int	translation_keys[4] = {W_CODE, A_CODE, S_CODE, D_CODE};
	static int	zoom_keys[2] = {PLUS_CODE, MINUS_CODE};

	if (keycode == ESC_CODE)
		shutdown_app(app);
	else if (ft_memchr(translation_keys, keycode, sizeof(int) * 4))
		translate_map(keycode, app);
	return (1);
}
