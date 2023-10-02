Pour lancer avec valgrind et ne pas gerer les leaks naturel de readline :
	valgrind --suppressions=valignore.txt ./minishell
	valgrind --suppressions=valignore.txt --leak-check=full --track-fds=yes --show-leak-kinds=all -s ./minishell


debug

while (a)
{
	printf("tokken = %d | ", a->tokken);
	int i = -1;
	if (a->tab)
		while (a->tab[++i])
			printf("%s ", a->tab[i]);
	else
		printf("fd = %d", a->fd);
	printf("\n");
	a = a->next;
}

//////////////////////// <- double free
