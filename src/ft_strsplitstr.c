#include "fillit.h"

static int		ft_startswith(const char *str, const char *delim)
{
	size_t		i;
	
	i = 0;
	while (i < ft_strlen(str)) 
	{
		if (delim[i] == '\0')
			return (1);
		if (str[i] == '\0' || str[i] != delim[i])
			return (0);
		i++;
	}

	/*
	** We've reached the end of the string, check if the string
	** equals the delimiter
	*/
	if (str[i] == delim[i])
		return (1);
	return (0);
}

static int		ft_wordcount(char const *s, char *delim)
{
	int prev;
	int count;

	prev = 0;
	count = 0;
	while (*s)
	{
		if (ft_startswith(s, delim))
		{
			prev = 0;
			s += ft_strlen(delim) - 1;
		} else if (prev == 0) {
			prev = 1;
			count++;
		}

		s++;
	}
	return (count);
}

char			**ft_strsplitstr(char const *s, char *delim)
{
	int		sholder;
	char	**new_s;
	int		i;
	int		j;
	int		begin;

	i = 0;
	j = -1;
	if (s == 0 || delim == 0)
		return (NULL);
	sholder = ft_wordcount(s, delim);
	if (!(new_s = malloc((sizeof(char*) * (sholder + 1)))))
		return (NULL);
	while (++j < sholder)
	{
		// Skip over delimiters in the string
		while (s[i] && ft_startswith(s + i, delim))
			i += ft_strlen(delim);

		// Record the start of the substring
		begin = i;

		// Count each character that isn't the delimiter
		while (s[i] && !ft_startswith(s + i, delim))
			i++;

		// Put the substring in the new_s array
		new_s[j] = ft_strsub(s, begin, i - begin);
	}
	new_s[j] = NULL;
	return (new_s);
}

// int main(void)
// {
// 	char **str1;
// 	char **str2;
// 	// int strn;
// 	// char *str = "#...a#...aa#...aa";
// 	char *str = "..##\n..##\n....\n....\n\n#...\n###.\n....\n....\n";

// 	// strn = ft_wordcount(str, "...");
// 	// printf("\n\nWords: %d.\n", strn);
// 	str1 = ft_strsplitstr(str, "\n\n");
// 	str2 = ft_strsplitstr(str1[0], "\n");
// 	printf("# strings: %d\n", ft_arrlen(str1));
// 	printf("# strings: %d\n", ft_arrlen(str2));

// 	int i = 0;
// 	while (str1[i] != '\0')
// 	{
// 		printf("%d: %s\n", i, str1[i]);
// 		i++;
// 	}

// 	int j = 0;
// 	while (str2[j] != '\0')
// 	{
// 		printf("%d: %s\n", j, str2[j]);
// 		j++;
// 	}
// 	printf("%d: %s\n", j, str2[4]);

// 	return (0);
// }