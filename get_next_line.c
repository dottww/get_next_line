/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:27:10 by weilin            #+#    #+#             */
/*   Updated: 2018/11/29 19:18:01 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readlinewidth(int fd)
{
	char	buff[2];
	size_t	nbread;

	(void) memset((void *) buff, 0, (size_t) 2);
	nbread = read(fd, (void *) buff,(size_t) 2);
	if (nbread == -1 || nbread == 0)
		return (-1);
	buff[1] = '\0';
	return(atoi(buff));
}

void	readandprintlines(int fd, size_t linewidth)
{
	char	*buff;
	size_t	nbread;

	buff = (char *)malloc((linewidth + 1) * sizeof(*buff));
	if (buff == NULL)
		return ;
	(void) memset((void *) buff, 0, linewidth + 1);
	while ((nbread = read(fd, (void *)buff, linewidth)) != 0)
	{
		printf("%s", buff);
		(void) memset((void *)buff, 0, linewidth);
	}
	free(buff);
	return ;
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	int			total_size;
	int			nbread;
	static char	*ptr;
	static char	*result;
	static int	count;


	
	if ((nbread = read(fd, buff, BUFF_SIZE - 1)) < 0)
		return (-1);
	else if (nbread == 0)
		return (0);
	result = NULL;
	ptr = result;
	buff[nbread] = '\0';
	count = 0;
	if (!(line[count] = (char*)malloc(sizeof(char) * (total_size + 1))))
	{
		count++;
		return (1);
	}

		*result = '\0';
		if (tmp)
			ft_strcpy(result, tmp);
		ft_strcat(result, buff);
		if (tmp)
			free(tmp);
	}
	newlist->content_size = content ? content_size : 0;
	if(ft_putstr(result))
		return (1)
	if(!ft_putstr(result))
	return (result);
}
char	*ft_strchr(const char *s, int c)


int			main(void)
{

	char	*readpipe;
	int		match;

	if (!(readpipe = ft_read()))
		ft_putstr("aucune");
	else
	{
		i = -1;
		match = 0;
		while (i++ < 4)
		{
			ft_print(i, w, h);
			match++;
		}
	}
	ft_putchar('\n');
	return (0);
}
