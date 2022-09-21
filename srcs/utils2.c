#include "../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	if (!s2[i])
		return (0);
	else
		return (-s2[i]);
}
