#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	else
		while (s[i])
			i++;
	return (i);
}

// The function ft_strjoin joins strings s1 and s2, freeing s1 at the end.

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1 || !s2)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		i = -1;
		j = -1;
		while (s1[++i])
			str[i] = s1[i];
		while (s2[++j])
			str[i++] = s2[j];
		str[i] = '\0';
	}
	free(s1);
	return (str);
}

// The function search_newline returns 1 if '\n' is found in string s.

int	search_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	} 
	return (0);
}
