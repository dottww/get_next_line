/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:43:35 by weilin            #+#    #+#             */
/*   Updated: 2018/11/22 18:19:36 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		newlist->content = NULL;
	else
	{
		if (!content_size || !(newlist->content = malloc(content_size)))
			return (NULL);
		newlist->content = ft_memcpy(newlist->content, content, content_size);
	}
	newlist->content_size = content ? content_size : 0;
	newlist->next = NULL;
	return (newlist);
}
