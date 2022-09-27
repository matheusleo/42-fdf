/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:56:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/09/27 20:30:24 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	validate_user_input(int argc, char *argv[])
{
	char	*map_name;
	int		map_fd;
	char	*extension;

	if (argc != 2)
	{
		ft_printf("Arguments error: Invalid number of arguments!\n");
		ft_printf("The input should be './fdf MAP.fdf'\n");
		exit(0);
	}
	map_name = argv[1];
	extension = ft_strrchr(map_name, '.');
	if (!extension || !(ft_strnstr(extension, ".fdf", 5) \
		&& ft_strlen(extension) == 4))
	{
		ft_printf("File eror: map file should end with the extension'.fdf'\n");
		exit(0);
	}
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
	{
		perror("File error");
		exit(0);
	}
	return (map_fd);
}
