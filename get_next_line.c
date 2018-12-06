/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:27:10 by weilin            #+#    #+#             */
/*   Updated: 2018/12/06 15:38:36 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(const int fd, char **all, char ***all_table)
{

	char		buff[BUFF_SIZE + 1];
	int			total_size;
	int			size_count;
	char		*tmp;


	total_size = 0;
	while ((size_count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		total_size = total_size + size_count;
		tmp = *all;
		buff[size_count] = '\0';
		if (!(*all = (char*)malloc(sizeof(char) * (total_size + 1))))
			return (-1);
		**all = '\0';
		if (tmp)
			ft_strcpy(*all, tmp);
		ft_strcat(*all, buff);
		if (tmp)
			free(tmp);
	}
	if (total_size == 0)
		return (0);
	if(!(*all_table = ft_strsplit(*all, '\n')))
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			nbread;
	char		*all;
	char		**all_table;
	static int	count;

	if (!fd || *line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	count = 0;
	all = NULL;
	all_table = NULL;
	nbread = ft_read(fd, &all, &all_table);
	*line = all_table[count];
	count++;
	free(all);
	ft_memdel((void*)all_table);
	return (nbread);
}
