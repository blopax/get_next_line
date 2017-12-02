#include "get_next_line.h"
#include "unistd.h"
#include <fcntl.h>


size_t	ft_new_line_size(char *pending_str);


int		main(int argc, char ** argv)
{
	char	**line;
	int		fd;
	int		ret;

	argc = 0;
	fd = open(argv[1], O_RDONLY);

	line = (char **)malloc(sizeof(char*));
	
	while ((ret = (get_next_line(fd, line)) != 0))
	{
		ft_putstr("\nline = \t"); 
		ft_putstr(*line);
		write(1, "?", 1);
	}
	free (line);

	return (0);
}
