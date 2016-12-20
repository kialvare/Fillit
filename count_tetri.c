int	count_tetri(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if((((i & 20) == 0 && i <= 20) || (i + 1 % 21 == 0 && i > 21)) && s[i] != '\n')
			return (0);
		i++;
	}
	if (i > 20)
		if ((i - 20) % 21 == 0 && (i / 21) <= 26)
			return ((i + 1) / 21);
	if (i == 20)
		return (1);
	return (0);
}

int	tetri_valid(char *s, int i)
{
	int	j;
	int	limit;
	int	k;
	int	hash;
	int ans;

	ans = 0;
	hash = 0;
	j = (i * 21);
	limit = (j + 21);
	k = j;
	while (s[k] && k < limit)
	{
		if(s[k] == '#')
			hash++;
		k++;
	}
	if ((hash % 4) != 0)
		return (0);
	while (j < limit)
	{
		if (s[j] == '#')
		{
			if (s[j + 1] == '#')
				ans += 1;
			if (s[j + 5] == '#')
				ans += 1;
		}			
		j++;
	}
	if (ans >= 3)
		return (1);
	return (0);
}
