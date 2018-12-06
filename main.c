/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:52:13 by weilin            #+#    #+#             */
/*   Updated: 2018/11/30 19:15:17 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	//int fd2;
	int ret;
	//int ret2;
	int nol;
	//int nol2;
	char *line;
	//char *line2;

	(void)argc;
	nol = 0;
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
	//else if (ret == 0)
	//	printf("-----------End of file\n");
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
