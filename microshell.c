#include "microshell.h"

int	error(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		write(1, str[i], 1);
	return (1);
}

int	cd(int argc, char **argv)
{
	if (argc > 2)
		return (error("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (error("error: cd: cannot change directory to "), error(argv[1]), error("\n"));
	return (0);
}

int	execute(int argc, char **argv, char **envp, int pipeFlag)
{
	if (strcmp(argv[0], "cd") == 0)
		return (cd(argc, argv));
	if (pipeFlag != 0)
}

int	main(int argc, char **argv, char **envp)
{
	int	j;
	int	status;

	if (argc < 2 || !argv[1])
		return (1);
	for (int i = 0; i < argc, i++)
	{
		j = i;
		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		if (i != j)
			status = execute(i - j, &argv[j], envp, (argv[i] && !strcmp(argv[i], "|")));
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}