#include "libft.h"

int 	ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}