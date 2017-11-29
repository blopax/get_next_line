#include "get_next_line.h"
#include "unistd.h"
#include <fcntl.h>

int		main()
{
	char	**line;
	size_t	i;
	int		fd;
	int		ret;

	line = 0;
	i = 0;
	fd = open("./tests/test_1", O_RDONLY);

	while ((ret = get_next_line(fd, line)))
	{
		//ft_putstr(line[i]);
		//write(1, "\n", 1);
		i++;
	}
	return (0);
}
