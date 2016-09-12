int split(char *str, char c, char ***arr)
{
	int count = 1;
	int token_len = 1;
	int i = 0;
	char *p;
	char *t;

	p = str;
	while (*p != '\0')
	{
		if (*p == c)
			count++;
		p++;
	}

	*arr = (char**)malloc(sizeof(char*)* count);
	if (*arr == NULL)
		exit(1);

	p = str;
	while (*p != '\0')
	{
		if (*p == c)
		{
			(*arr)[i] = (char*)malloc(sizeof(char)* token_len);
			if ((*arr)[i] == NULL)
				exit(1);

			token_len = 0;
			i++;
		}
		p++;
		token_len++;
	}
	(*arr)[i] = (char*)malloc(sizeof(char)* token_len);
	if ((*arr)[i] == NULL)
		exit(1);

	i = 0;
	p = str;
	t = ((*arr)[i]);
	while (*p != '\0')
	{
		if (*p != c && *p != '\0')
		{
			*t = *p;
			t++;
		}
		else
		{
			*t = '\0';
			i++;
			t = ((*arr)[i]);
		}
		p++;
	}

	return count;
}