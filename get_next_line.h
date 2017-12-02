/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:24:52 by pclement          #+#    #+#             */
/*   Updated: 2017/11/29 19:59:26 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 25

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line);

typedef struct	s_read
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int			ret;
}				t_reading;


#endif
