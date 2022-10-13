/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:24:01 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 23:47:56 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_fdf	init_fdf(void)
{
	t_fdf	fdf;

	fdf.cols = 0;
	fdf.rows = 0;
	fdf.map_fd = 0;
	fdf.edge_len = 15;
	fdf.zoom = 1;
	fdf.x_offset = 0;
	fdf.y_offset = 0;
	fdf.level_height = 1;
	fdf.map_matrix = NULL;
	return (fdf);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;
	t_app	*app;
	char	*line;

	fdf = init_fdf();
	fdf.map_fd = validate_user_input(argc, argv);
	fdf.map_matrix = parse_map(&fdf);
	app = init_app(&fdf);
}
