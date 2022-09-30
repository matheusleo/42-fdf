/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:24:01 by mleonard          #+#    #+#             */
/*   Updated: 2022/09/29 22:55:57 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_fdf	init_fdf(void)
{
	t_fdf	fdf;

	fdf.cols = 0;
	fdf.rows = 0;
	fdf.map_fd = 0;
	fdf.map_matrix = NULL;
	return (fdf);
}

int	main(int argc, char *argv[])
{
	int		map_fd;
	char	*line;
	t_fdf	fdf;

	fdf = init_fdf();
	fdf.map_fd = validate_user_input(argc, argv);
	fdf.map_matrix = parse_map(fdf.map_fd);
	ft_lstclear(&(fdf.map_matrix), free);
	free(fdf.map_matrix);
}
