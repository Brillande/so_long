static void	*free_split(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

static char	*word_dupe(const char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] != '\0' && str[len] != c)
		++len;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

static char	**fill_words(char **array, const char *str, char c)
{
	int			word_index;
	const char	*ptr;

	word_index = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		while (*ptr == c)
			++ptr;
		if (*ptr != '\0')
		{
			array[word_index] = word_dupe(ptr, c);
			if (array[word_index] == NULL)
				return (free_split(array, word_index));
			++word_index;
		}
		while (*ptr != '\0' && *ptr != c)
			++ptr;
	}
	return (array);
}

static int	count_words(const char *str, char c)
{
	int	num_words;
	int	i;

	num_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++num_words;
			while (str[i] != '\0' && str[i] != c)
				++i;
		}
		else
			++i;
	}
	return (num_words);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**array;

	if (s == NULL)
		return (NULL);
	num_words = count_words(s, c);
	array = malloc(sizeof(char *) * (num_words + 1));
	if (array == NULL)
		return (NULL);
	array = fill_words(array, s, c);
	if (array == NULL)
		return (NULL);
	array[num_words] = NULL;
	return (array);
}
