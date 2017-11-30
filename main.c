#include "get_next_line.h"
#include "unistd.h"
#include <fcntl.h>


size_t	ft_new_line_size(char *pending_str);


int		main()
{
	char	**line;
	size_t	i;
	int		fd;
//	int		ret;

	line = 0;
	i = 0;
	fd = open("./tests/test_1", O_RDONLY);

	//ft_putnbr(ft_new_line_size("bonjour\nPablo"));

	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	{
//		ft_putstr(line[i]);
//		write(1, "\n", 1);
//		i++;
	}
	free (line);
	return (0);
}
