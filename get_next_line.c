#include "get_next_line.h"

size_t		ft_new_line_index(char *str)
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

/*char	*ft_strnew_2(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}*/

int		get_next_line(const int fd, char **line)
{
	static char	*leftover_str[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	size_t		new_line_index;

	if (!line || fd < 0)
		return (-1);
	if (!leftover_str[fd])
		leftover_str[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) >  0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(leftover_str[fd], buf)))
			return (-1);
		free(leftover_str[fd]);
		leftover_str[fd] = ft_strdup(tmp);;
		free(tmp);
//	si je commente la ligne au dessus ac ft_strdup 0 leaks...
//free(tmp);
		if ((ft_new_line_index(leftover_str[fd])) != ft_strlen(leftover_str[fd]))
			break;
	}
	if (ret == -1)
		return (-1);
	if (leftover_str[fd][0] == 0 && ret == 0)
		return (0);
	new_line_index = ft_new_line_index(leftover_str[fd]);
// on peut mettre direct ds les fonctions pour gagner une ligne
	*line = ft_strnew(new_line_index);
	ft_strncpy(*line, leftover_str[fd], new_line_index);
	tmp = ft_strsub(leftover_str[fd], new_line_index + 1, ft_strlen(leftover_str[fd]) - new_line_index);
	leftover_str[fd] = 0;
	free(leftover_str[fd]);
	leftover_str[fd] = tmp;
	tmp = 0;
	free (tmp);
	return (1);
}
