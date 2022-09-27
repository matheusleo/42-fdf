/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:24:01 by mleonard          #+#    #+#             */
/*   Updated: 2022/09/27 09:45:31 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char *argv[])
{
	int	map_fd;

	map_fd = validate_user_input(argc, argv);
	ft_printf("map_file %d\n", map_fd);
}
