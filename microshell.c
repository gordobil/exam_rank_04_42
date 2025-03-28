#include "microshell.h"

int	error(char *str)
{
	int	i = -1;

	while (str[++i] != '\0')
		write(1, str[i], 1);
	return (-1);

}

int	main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int	j;
	int	status = 0;

	while (++i < argc)
	{
		j = i;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i != j)
			status = execution();
	}
}