#include "get_next_line.h"


size_t	ft_new_line_size(char *str)
{
	size_t		new_line_size;
	size_t		flag;

	new_line_size = -1;
	while (pending_str[new_line_size++] != 0 && flag == 0)
	{
		if (pending_str[new_line_size] == '\n')
			flag = 1;
	}
	if (flag == 0)
		return (0);
	return (ft_new_line_size);
}

int		get_next_line(const int fd, char **line)
{
	static char		*pending_str = 0;
	static size_t	line_nb = 0;
	static size_t	total_line_size;
	//verifier usage static --> je peux faire une struct statique ou un tableau ?
	size_t		new_line_size;
	char		*buf[BUFF_SIZE + 1];
	int			ret;
	
	new_line_size = ft_new_line_size(pending_str);

	while ((ret = read(fd, buf, BUFF_SIZE)) && (new_line_size == 0))
	{
		buf[BUFF_SIZE] = '\0';
		pending_str = ft_strjoin(pending_str, buf);
		// verifier si ok d'utilsiser pending str ou si on doit renouveler
		new_line_size = ft_new_line_size(pending_str);
	}
	line_nb++;
	if (ret == 0)
		new_line_size = ft_strlen(pending_str);
	line = ft_mem_realloc(line, new_line_size);
	// comment faire pour avoir place suffisante pour char --> malloc line nb en utilisant static
	// utiliser autre fonction ac tmp ?
	line[line_nb] = ft_strnew(new_line_size);
	ft_strncpy(line[line_nb], (const char)pending_str, new_line_size);
	pending_str = ft_strchr((const char)pending_str, (int)((char)'\n');

	return (ret >= 1 ? 1 : ret);
}
