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

char	**ft_realloc(char **line, size_t line_index, size_t total_size)
{
	char	**tmp;
	size_t	i;

	if (!(tmp = (char**)malloc(total_size)))
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

char	*ft_new_pending_str(char *pending_str)
{
	char	*tmp;


//	write(1, "\nA\n", 3);
//	ft_putstr(pending_str);
//	write(1, "\nB\n", 3);
	tmp = ft_strchr((const char *)pending_str, '\n');
//	ft_putstr(tmp);
//	write(1, "\nC\n", 3);
	free(pending_str);
	pending_str = ft_strdup(tmp + 1);
//	ft_putstr(pending_str);
//	write(1, "\n\n\n", 3);
	return (pending_str);
}

int		get_next_line(const int fd, char **line)
{
	static char		*pending_str = "";
	static size_t	line_index = -1;
	static size_t	total_size = 0;
	size_t			new_line_size;
	char			buf[BUFF_SIZE + 1];
	int				read_ret;
	size_t				i;

	read_ret = 1;
	if ((new_line_size = ft_new_line_size(pending_str)) == 0)
	{
		while ((read_ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[read_ret] = '\0';
			if (!(pending_str = ft_strjoin((char const *)pending_str, (char const *)buf)))
				return (-1);
			if ((new_line_size = ft_new_line_size(pending_str)) != 0)
				break;
		}
	}
	ft_putnbr(read_ret);

	write(1, "\nTESTa\n", 7);
	line_index++;
	if (read_ret == 0)
		new_line_size = ft_strlen(pending_str);
	
	write(1, "\nTESTb\n", 7);
	total_size = total_size + sizeof(char)*(new_line_size + 1);
	if (!(line = ft_realloc(line, line_index, total_size)))
		return (-1);
	write(1, "\nTESTc\n", 7);
	if (!(line[line_index] = ft_strnew(new_line_size)))
		return (-1);
	i = -1;
//	while (i++ < new_line_size)
		line[line_index][0] = '\0';
	write(1, "\nTESTd\n", 7);
	line[line_index] = ft_strncpy(line[line_index], (const char *)pending_str, new_line_size);
	ft_putstr(line[line_index]);
//	write(1, "\nTESTe\n", 7);
	ft_putstr("\npending_str avant resize =\t");
	ft_putstr(pending_str);
	ft_putstr("?\n\n");
	pending_str = ft_new_pending_str(pending_str);

// PROBLEMENE AC INITIALISATION LIN LINE INDEX 0 SI UN SEUL CA MARCHE


	ft_putstr("FINAL FIN GNL\n");
	ft_putstr("return =\t");
	ft_putnbr(read_ret >= 1 ? 1 : read_ret);
	ft_putstr("\n\n");
		
	ft_putstr("new_line_sizew_line_size =\t");
	ft_putnbr(new_line_size);
	ft_putstr("\n\n");

	
	ft_putstr("buf =\t");
	ft_putstr(buf);
	ft_putstr("\n\n");

	ft_putstr("pending_str =\t");
	ft_putstr(pending_str);
	ft_putstr("?\n\n");

	ft_putstr("line_index =\t");
	ft_putnbr(line_index);
	ft_putstr("\n\n");

	ft_putstr("line[line_index][0] =\t");
	write(1, &(line[line_index][0]),1);
//	write(1, &(line[line_index][1]),1);
//	write(1, &(line[line_index][2]),1);
//	write(1, &(line[line_index][3]),1);
	ft_putstr("\n\n");
	ft_putstr("line[line_index] =\t");
	ft_putstr(line[line_index]);
	ft_putstr("?\n\n");
	return (read_ret >= 1 ? 1 : read_ret);
}
