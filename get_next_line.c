/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:27:10 by weilin            #+#    #+#             */
/*   Updated: 2019/01/05 12:51:54 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define MAX_FD 1024

int get_next_line(const int fd, char **line, int nol)
{
	static char *rest = NULL;
	int rd;
	char buff[BUFF_SIZE + 1];
	char *tmp;
	char *n;

	if (!fd || !line || read(fd, NULL, 0) < 0)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		if (rest)
			rest = ft_strjoin(rest, buff);
		else
			rest = ft_strdup(buff);
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (rest != '\0' && (n = ft_strchr(rest, '\n')))
	{
		*line = ft_strsub(rest, 0, n - rest);
		rest = ft_strsub(rest, n - rest + 1, ft_strlen(rest) - (n - rest) - 1);
		return (1);
	}
	else if (rest != '\0')
	{
		*line = ft_strdup(rest);
		rest = NULL;
		return (1);
	}
	//	if (rd == 0 && rest == NULL)
	return (0);
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
	while ((ret = get_next_line(fd, &line, nol)) > 0)
	{
		printf("[Return: %d] Line #%.2d: %s\n", ret, ++nol, line);
		free(line);
	}
	printf("[Return: %d] Line #%.2d: %s = Last Line\n", ret, nol, line);
	get_next_line(fd, &line, nol);
	printf("[Return: %d] Line #%.2d: %s = Last Line\n", ret, nol, line);
	get_next_line(fd, &line, nol);
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
