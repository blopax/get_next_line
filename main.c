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

	i = 0;
	fd = open("./tests/test_1", O_RDONLY);

	//ft_putnbr(ft_new_line_size("bonjour\nPablo"))
	line = (char **)malloc(sizeof(char*));;

//	get_next_line(fd, line);
//	get_next_line(fd, line);

//	while (get_next_line(fd, line))
//		ft_putstr(*line);
	while (get_next_line(fd, line) != 0)
	{
		ft_putstr(*line);
		write(1, "?", 1);
		
		i++;
	}
	free (line);
	return (0);
}
