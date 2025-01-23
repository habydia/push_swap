
#include "push_swap.h"

/*fonction compte nombre mot dans s*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_empty_substr(void)
{
	char	*d;

	d = malloc(sizeof(char) * 1);
	if (!d)
		return (NULL);
	d[0] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
		return (ft_empty_substr());
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = 0;
	return (substr);
}
static int	ft_count_word(char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

/*fonction free tab si echec allocation de ft_substr*/
static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*fonction complete tab a l'aide de substr*/
static int	write_split(char **tab, char const *s, char c)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			tab[j] = ft_substr(s, start, i - start);
			if (!tab[j])
			{
				ft_free_tab(tab);
				return (0);
			}
			j++;
		}
	}
	return (1);
}

/*fonction check securite malloc, gere overflow*/
char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = ft_count_word((char *)s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	if (!write_split(tab, s, c))
	{
		return (NULL);
	}
	tab[words] = NULL;
	return (tab);
}
int static	ft_check_sign(const char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = sign * -1;
		++(*i);
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	r;
	long	sign;

	i = 0;
	r = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	sign = ft_check_sign(nptr[i], &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((r * 10 + (nptr[i] - '0')) < r)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}

