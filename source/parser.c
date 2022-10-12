/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:44:00 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/05 10:05:44 by mleonard         ###   ########.fr       */
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

static int	count_cols(char *line)
{
	int		counter;
	int		temp_counter;
	char	**line_splitted;

	temp_counter = 0;
	line_splitted = ft_split(line, ' ');
	counter = count_elem_from(line_splitted);
	while (temp_counter < counter)
	{
		free(line_splitted[temp_counter]);
		temp_counter++;
	}
	free(line_splitted);
	return (counter);
}

int	*parse_line(char *line)
{
	char	**line_splitted;
	int		line_elem;
	int		*matrix_line;
	int		counter;

	counter = 0;
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
	free(line_splitted);
	return (matrix_line);
}

t_list	*parse_map(t_fdf *fdf)
{
	t_list	*matrix_head;
	t_list	*new_node;
	int		*matrix_line;
	char	*line;

	line = get_next_line(fdf->map_fd);
	if (!line)
		exit(0);
	fdf->cols = count_cols(line);
	matrix_line = parse_line(line);
	free(line);
	new_node = ft_lstnew(matrix_line);
	matrix_head = new_node;
	while (matrix_line)
	{
		line = get_next_line(fdf->map_fd);
		matrix_line = parse_line(line);
		free(line);
		new_node = ft_lstnew(matrix_line);
		ft_lstadd_back(&matrix_head, new_node);
	}
	fdf->rows = ft_lstsize(matrix_head);
	return (matrix_head);
}
