#include "get_next_line.h"

size_t		ft_nl_index(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_GNL_update(char **line, char *leftover_str)
{
	char	*tmp;
	size_t	new_line_index;

	new_line_index = ft_nl_index(leftover_str);
	*line = ft_strnew(new_line_index);
	ft_strncpy(*line, leftover_str, new_line_index);
	tmp = ft_strsub(leftover_str, new_line_index + 1, ft_strlen(leftover_str) - new_line_index);
	free(leftover_str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*leftover_str[OPEN_MAX];
	t_reading	reading;

	if (!line || fd < 0)
		return (-1);
	if (!leftover_str[fd])
		leftover_str[fd] = ft_strnew(0);
	while ((reading.ret = read(fd, reading.buf, BUFF_SIZE)) >  0)
	{
		reading.buf[reading.ret] = '\0';
		if (!(reading.tmp = ft_strjoin(leftover_str[fd], reading.buf)))
			return (-1);
		free(leftover_str[fd]);
		leftover_str[fd] = ft_strdup(reading.tmp);;
		free(reading.tmp);
		if ((ft_nl_index(leftover_str[fd])) != ft_strlen(leftover_str[fd]))
			break;
	}
	if (reading.ret == -1)
		return (-1);
	if (leftover_str[fd][0] == 0 && reading.ret == 0)
		return (0);
	leftover_str[fd] = ft_GNL_update(line, leftover_str[fd]);
	return (1);
}
