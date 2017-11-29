/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:24:57 by pclement          #+#    #+#             */
/*   Updated: 2017/11/29 19:57:10 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_realloc(char **line, size_t line_index, size_t new_line_size)
{
	char	**tmp;
	size_t	i;

	if (!(tmp = (char**)malloc(sizeof(line) + sizeof(char) *
					(new_line_size + 1))))
		return (NULL);
	i = -1;
	while (i++ < line_index)
		tmp[line_index] = ft_strdup((const char *)line[line_index]);
	i = -1;
	while (i++ < line_index)
		free(line[line_index]);
	return (tmp);
}

size_t	ft_new_line_size(char *pending_str)
{
	size_t		new_line_size;
	size_t		flag;

	if (pending_str == 0)
		return (0);
	new_line_size = 0;
	flag = 0;
	while (pending_str[new_line_size] != '\0' && flag == 0)
	{
		if (pending_str[new_line_size] == '\n')
			flag = 1;
		new_line_size++;
	}
	if (flag == 0)
		return (0);
	return (new_line_size);
}

int		get_next_line(const int fd, char **line)
{
	static char		*pending_str = "";
	static size_t	line_index = -1;
	size_t			new_line_size;
	char			*buf[BUFF_SIZE + 1];
	int				read_ret;

	read_ret = 1;
	//write(1, "TESTa\n", 6);
	if ((new_line_size = ft_new_line_size(pending_str)) == 0)
	{
		//write(1, "TESTb\n", 6);
		while ((read_ret = read(fd, buf, BUFF_SIZE)) && (new_line_size == 0))
		{
			//write(1, "TESTc\n", 6);
			buf[read_ret] = 0;
			//ft_putstr("\n buf =\t");
			//ft_putstr((const char *)buf);
			if (!(pending_str = ft_strjoin((char const *)pending_str, (char const *)buf)))
				return (-1);
			//ft_putstr("\n pending =\t");
			//ft_putstr(pending_str);
			new_line_size = ft_new_line_size(pending_str);
		}
	}
	line_index++;
	if (read_ret == 0)
		new_line_size = ft_strlen(pending_str);
	if (!(line = ft_realloc(line, line_index, new_line_size)))
		return (-1);
	if (!(line[line_index] = ft_strnew(new_line_size)))
		return (-1);
	ft_strncpy(line[line_index], (const char *)pending_str, new_line_size);
	ft_putstr(line[line_index]);
	write(1,"\n",1);
	pending_str = ft_strchr((const char *)pending_str, '\n');
	return (read_ret >= 1 ? 1 : read_ret);
}
