/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:55:55 by pclement          #+#    #+#             */
/*   Updated: 2017/11/13 18:59:09 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
