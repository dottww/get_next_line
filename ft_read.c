/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:42:04 by weilin            #+#    #+#             */
/*   Updated: 2018/09/16 21:27:28 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biblio.h"

char		*ft_read(void)
{
	char	buff[256];
	int		total_size;
	int		size_count;
	char	*tmp;
	char	*result;

	result = NULL;
	total_size = 0;
	while ((size_count = read(0, buff, 255)) > 0)
	{
		total_size = total_size + size_count;
		tmp = result;
		buff[size_count] = '\0';
		if (!(result = (char*)malloc(sizeof(char) * (total_size + 1))))
			return (0);
		*result = '\0';
		if (tmp)
			ft_strcpy(result, tmp);
		ft_strcat(result, buff);
		if (tmp)
			free(tmp);
	}
	return (result);
}
