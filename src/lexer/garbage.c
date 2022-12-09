

// void count_str_len(char *str, int *j, int *token_length)
// {
// 	(*token_length)++;
// 	while ((str[*j] >= '!' && str[*j] <= '~') && str[*j] != '\0')
// 	{
// 		printf("istr[%d] = %c\n", (*j), str[*j]);
// 		(*j)++;
// 		(*token_length)++;
// 	}
// }

// int	get_token_length(char *str, int *j)
// {
// 	int token_length;

// 	token_length = 0;
// 	// Hier wird dann i immer weiter hoch gezählt um durch den string zu gehen
// 	// quasi um von string zu string zu springen
// 	// gleihzeitig muss in der function mit token_length gezaehlt werden
// 	// Aus der differenz von i und token_length kann dann die laenge des tokens
// 	// berechnet werden anschließend kann dann returned werden
// 	// und das token erstellt.
// 	while (str[*j] != '\0')
// 	{
// 		if (str[*j] == ' ')
// 			skip_whitespace(str, j);
// 		else if (str[*j] >= '!' && str[*j] <= '~')
// 		{
// 			count_str_len(str, j, &token_length);
// 			return (token_length);
// 		}
// 	}
// 	printf("token_length = %d\n", token_length);
// 	return (-1);
// }

// int create_token(char *token_arr, char *str, int *j)
// {
// 	// int i;
// 	// int token_length;

// 	// i = 0;
// 	// // erst token len fertig machen
// 	// token_length = get_token_length(str, j);
// 	// token_arr = (char *) malloc(sizeof(char) * (token_length + 1));
// 	// if (token_arr == NULL)
// 	// {
// 	// 	perror("minishell: malloc failed\n");
// 	// 	return (1);
// 	// }
// 	// token_arr[token_length] = '\0';
// 	// token_arr[0] = '1'; // delet when not used anymore
// 	// // while (i < token_length)
// 	// // {
// 	// // 	token_arr[(*i)] = str[j];
// 	// // 	(*i)++;
// 	// // 	j++;
// 	// // }
// 	(void) token_arr;
// 	(void) str;
// 	(void) j;
// 	// char *token;

// 	// token = (char*) malloc(sizeof(char) * 5);
// 	// if (token == NULL)
// 	// {
// 	// 	perror("minishell: malloc failed\n");
// 	// 	return (1);
// 	// }
// 	// token[0] = '1';
// 	// token[1] = '2';
// 	// token[2] = '3';
// 	// token[3] = '4';
// 	// token[5] = '\0';
// 	return (0);
// }

// int tokenizer(char *str)
// {
// 	int		i;
// 	int		j;
// 	int		num_tokens;
// 	char	**token_arr;
// 	(void) str;

// 	i = 0;
// 	j = 0;
// 	num_tokens = token_counter(str);
// 	printf("num_tokens = %d\n", num_tokens);
// 	token_arr = (char **) malloc(sizeof(char *) * (num_tokens + 1));
// 	if (token_arr == NULL)
// 	{
// 		perror("iminishell: malloc failed\n");
// 		return (1);
// 	}
// 	token_arr[num_tokens] = NULL;
// 	while (i < num_tokens)
// 	{
// 		token_arr[i] = (char*) malloc(sizeof(char) * 5);
// 		if (token_arr == NULL)
// 		{
// 			perror("minishell: malloc failed\n");
// 			return (1);
// 		}
// 		// token_arr[i][5] = '\0';
// 		i++;
// 	}
// 	int x = 0;
// 	int p = 0;
// 	while (token_arr[x] != NULL)
// 	{
// 		p = 0;
// 		while (token_arr[x][p] != '\0')
// 		{
// 			token_arr[x][p] = '1';
// 			p++;
// 		}
// 		x++;
// 	}
// 	print_token_arr(token_arr);
// 	return (0);
// }

