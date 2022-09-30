/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:44:00 by mleonard          #+#    #+#             */
/*   Updated: 2022/09/29 22:46:28 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	count_elem_from(char **splitted_line)
{
	int	counter;

	counter = 0;
	while (splitted_line[counter])
		counter++;
	return (counter);
}

int	*parse_line(int map_fd)
{
	char	*line;
	char	**line_splitted;
	int		line_elem;
	int		*matrix_line;
	int		counter;

	counter = 0;
	line = get_next_line(map_fd);
	if (!line)
		return (NULL);
	line_splitted = ft_split(line, ' ');
	line_elem = count_elem_from(line_splitted);
	matrix_line = (int *)malloc(sizeof(int) * line_elem);
	while (counter < line_elem)
	{
		matrix_line[counter] = ft_atoi(line_splitted[counter]);
		free(line_splitted[counter]);
		counter++;
	}
	free(line);
	free(line_splitted);
	return (matrix_line);
}

t_list	*parse_map(int map_fd)
{
	t_list	*matrix_head;
	t_list	*new_node;
	int		*matrix_line;

	matrix_line = parse_line(map_fd);
	new_node = ft_lstnew(matrix_line);
	matrix_head = new_node;
	while (matrix_line)
	{
		matrix_line = parse_line(map_fd);
		new_node = ft_lstnew(matrix_line);
		ft_lstadd_back(&matrix_head, new_node);
	}
	return (matrix_head);
}
