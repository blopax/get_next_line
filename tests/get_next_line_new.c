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


int		get_next_line(const int fd, char **line)
{
	static char	*leftover_str[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	size_t		new_line_index;

//cmt initialiser la var ?

	// mettre les tests 
	//
	if (!line || fd < 0)
		return (-1);

	if (!leftover_str[fd])
		leftover_str[fd] = "";

	while ((ret = read(fd, buf, BUFF_SIZE)) >  0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(leftover_str[fd], buf)))
			return (-1);
		leftover_str[fd] = ft_strdup(tmp);
		if (tmp)
			free(tmp);
		if ((new_line_index = ft_new_line_index(leftover_str[fd])) != ft_strlen(leftover_str[fd]))
			break;
	// leftover_str[fd][new_line_index] = \n
	}
//				ft_putstr("TESTA\n");
	
	if (leftover_str[fd] == 0)
		return (0);

	*line = ft_strnew(new_line_index);
	ft_strncpy(*line, leftover_str[fd], new_line_index);
	//ou je free line ds main ? cas ou newline = 0
	tmp = ft_strsub(leftover_str[fd], new_line_index + 1, ft_strlen(leftover_str[fd]) - new_line_index);
	free(leftover_str[fd]);
	leftover_str[fd] = ft_strdup(tmp);
	if (tmp)
		free (tmp);

//				ft_putstr(*line);
//				ft_putstr("?");
//				ft_putnbr(ret);
//				ft_putstr("?");

	// a l air ok pour le print essayer ac chaine vide, rajouter etteurs et changer buff size. essayer tests ecole pui 42File checker
	// pb ac la valeur de retour

	return (ret >= 1 ? 1 : ret);
}
