/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:27:10 by weilin            #+#    #+#             */
/*   Updated: 2018/12/07 19:24:53 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define MAX_FD 1024
/*
static int	ft_read(const int fd, char **line, char **rest)
{
	char			buff[BUFF_SIZE + 1];
	int				total_size;
	int				rd;
	char			*tmp;

	//tmp = *rest;
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ft_strchr(buff, '\n') == NULL)
		{
			if (*rest)
				*rest = ft_strjoin(*rest, buff);
			else
				*rest = ft_strdup(buff);
		}
		else
		{
			if (*rest)
				*line = ft_strjoin(*rest, ft_strsub(buff, 0, ft_strchr(buff, '\n') - buff + 1));
			else
				ft_memccpy(*line, buff, '\n', BUFF_SIZE + 1);
				*rest = ft_strdup(ft_strstr(buff, "\n"));
				//save = ft_strsub(buff, ft_strchr(buff, '\n') - buff + 1, ft_strlen(buff));
			return (1);
			break ;
		}
		//if (tmp)
	//		free(tmp);
	}
	if (rd == 0)
		return (0);
	return (1);
}
*/
/*
int	get_next_line(const int fd, char **line)
{
	char			*tmp;
	static char		*rest;
	char			buff[BUFF_SIZE + 1];
	int				rd;
	
	if (!fd || !line || read(fd, NULL, 0) < 0)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ft_strchr(buff, '\n') == NULL)
		{
			if (rest)
			{	
				tmp = rest;
				rest = ft_strjoin(rest, buff);
				free(tmp);
			}
			else
				rest = ft_strdup(buff);
		}
		else
		{
			if (rest)
				*line = ft_strjoin(rest, ft_strsub(buff, 0, ft_strchr(buff, '\n') - buff));
			else
				ft_memccpy(*line, buff, '\n', ft_strchr(buff, '\n') - buff);
				rest = ft_strdup(ft_strstr(buff, "\n") + 1);
			return (1);
			break ;
		}
	}
	if (rd == 0)
		return (0);
	return (1);
}
*/
int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}

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
		printf("[Return: %d] Line #%d: %s\n", ret, ++nol, line);
		free(line);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++nol, line);
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

/*
txt1:
Hello\n
World\n
 new line
last line
djfbkjdhf

buff=8
[Hello\nWo]

Wo+rld

buff=[rld\nnew]


[Hello]
fd,[Wo]

[Wo] + [rld\n new]
[World]
fd, [ new]

txt2:
Other file
only 2 lines

fd=1 txt==4 lines
|table = {"World\n new line\nlast line"}
-> line = "Hello"

static char** fd[409600]
bzero(fd, sizeof(abc));

char **fd[0~409600]
java
*/
