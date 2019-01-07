/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:27:10 by weilin            #+#    #+#             */
/*   Updated: 2019/01/07 15:38:47 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_return_line(char **s, char **line, const int fd, int rd)
{
	char		*n;
	int			len;
	int			slen;

	if (s[fd] != '\0' && (n = ft_strchr(s[fd], '\n')))
	{
		len = n - s[fd];
		slen = ft_strlen(s[fd]);
		*line = ft_strsub(s[fd], 0, len);
		s[fd] = ft_strreset(s[fd], ft_strsub(s[fd], len + 1, slen - len - 1));
		return (1);
	}
	else if (s[fd] != '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		if (ft_strlen(*line) == 0 && rd == 0)
		{
			*line = ft_strreset(*line, "\0");
			return (0);
		}
		return (1);
	}
	ft_strdel(&s[fd]);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[256];
	int			rd;
	char		*buff;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1 ||
		!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (s[fd])
			s[fd] = ft_strreset(s[fd], ft_strjoin(s[fd], buff));
		else
			s[fd] = ft_strdup(buff);
		if (ft_strchr(buff, '\n'))
			break ;
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	return (ft_return_line(s, line, fd, rd));
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int nol;
	char *line;

	(void)argc;
	nol = 0;
	//int fd2;
	//int ret2;
	//int nol2;
	//char *line2;
	//nol2= 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[Return: %d] Line #%.2d: %s\n", ret, ++nol, line);
		ft_strdel(&line);
	}
	printf("[Return: %d] Line #%.2d: %s = Last Line\n", ret, nol, line);
	get_next_line(fd, &line);
	printf("[Return: %d] Line #%.2d: %s = Last Line\n", ret, nol, line);
	if (ret == -1)
		printf("-----------Error\n");
	else if (ret == 0)
		printf("-----------End of file\n");
	close(fd);
	/*fd2 = open(argv[2], O_RDONLY);
	while ((ret2 = get_next_line(fd2, &line2)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret2, ++nol2, line2);
		free(line2);
	}
	if (ret2 == -1)
		printf("-----------Error\n");
	else if (ret2 == 0)
		printf("-----------End of file\n");
	close(fd2);*/
	return (0);
}

