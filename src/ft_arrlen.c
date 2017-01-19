#include "fillit.h"

int 	ft_arrlen(void **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
