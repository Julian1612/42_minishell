#include <stdio.h>

int	get_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	print_error(int error_code)
{
	if (error_code == 1)
		perror("minishell: syntax error: invalid redirection");

}

int	syntax_check(char **token_arr)
{
	int	i;
	int	arr_len;
	int	flag;

	i = 0;
	arr_len = get_arr_len(token_arr);
	flag = 0;
	if (arr_len < 2 && (token_arr[i][0] == '|' || token_arr[i][0] == '<'
		|| token_arr[i][0] == '>' || (token_arr[i + 1][0] == '<' && token_arr[i + 1][1] == '<')
		|| (token_arr[i + 1][0] == '>' && token_arr[i + 1][1] == '>')))
		flag = 1;
	if (token_arr[arr_len - 1][0] == '>' || token_arr[arr_len - 1][0] == '<')
		flag = 2;
	if (token_arr[0][0] == '|' || token_arr[arr_len - 1][0] == '|')
		flag = 3;
	i++;
	while (token_arr[i] != NULL)
	{
		if (token_arr[i][0] == '<')
		{
			if (token_arr[i - 1][0] == '>' || token_arr[i - 1][0] == '<')
				flag = 4;
			if (token_arr[i - 1][0] == '|')
				flag = 5;
		}
		if (token_arr[i][0] == '>')
		{
			if (token_arr[i - 1][0] == '>' || token_arr[i - 1][0] == '<')
				flag = 6;
			if (token_arr[i - 1][0] == '|')
				flag = 7;
		}
		if (token_arr[i][0] == '|')
		{
			if (token_arr[i - 1][0] == '>' || token_arr[i - 1][0] == '<')
				flag = 8;
			if (token_arr[i - 1][0] == '|')
				flag = 9;
		}
		i++;
	}
	if (flag > 0)
		print_error(flag);
	if (flag > 0)
		return (1);
	return (0);
}

int main(void)
{
	char	*a[] = {"<", NULL};
	char	*b[] = {">", NULL};
	char	*c[] = {"<<", NULL};
	char	*d[] = {">>>>>", NULL};
	char	*dd[] = {"<<<<<", NULL};
	char	*e[] = {">", ">", ">", ">", ">", NULL};
	char	*f[] = {"<", "<", "<", "<", "<", NULL};
	char	*g[] = {">>", ">>", ">>", ">>", ">>", NULL};
	char	*h[] = {"<<", "<<", "<<", "<<", "<<", NULL};
	char	*i[] = {"/bin/cat", ">", "<", NULL};
	char	*j[] = {"/bin/cat", "<", "Makefile",  ">", NULL};
	char	*k[] = {"echo", ">", NULL};
	char	*l[] = {"echo", ">", "<", NULL};
	char	*m[] = {">", "echo", ">", NULL};
	char	*n[] = {">>", "echo", ">>", NULL};
	char	*o[] = {"|", "echo", "|", NULL};
	char	*p[] = {"|", NULL};
	char	*q[] = {"|", "test", NULL};
	char	*r[] = {"|", "|", "|", NULL};
	char	*s[] = {"|", "|", "|", "test", NULL};
	char	*t[] = {"<", "<<", "in", "cat", NULL};
	char	*u[] = {"<<", "<<", "in", "cat", NULL};
	char	*v[] = {"<", "<", "in", "cat", NULL};
	char	*w[] = {"echo", "hi", ">", ">>", "out", NULL};
	char	*x[] = {"echo", ">>", "|", "out", NULL};
	char	*y[] = {"echo", "<<", "|", "out", NULL};
	char	*z[] = {"echo", ">", "|", "out", NULL};
	char	*aa[] = {"echo", "<", "|", "out", NULL};
	char	*bb[] = {">", "out", "echo", "hi", "<", "Makefile", "|", "wc", "-l", NULL};
	char	*cc[] = {"echo", "<,", "Makefile", "|", "wc", "-l", NULL};
	char	*ee[] = {"echo", "<", "Makefile", "hi", ">", "out", "|", "wc", "-l", NULL};

	printf("----------1---------\n");
	if (syntax_check(aa))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------2---------\n");
	if (syntax_check(bb) == 0)
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------3---------\n");
	if (syntax_check(cc) == 0)
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------4---------\n");
	if (syntax_check(ee) == 0)
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------5---------\n");
	if (syntax_check(a))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------6---------\n");
	if (syntax_check(b))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------7---------\n");
	if (syntax_check(c))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------8---------\n");
	if (syntax_check(d))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------9---------\n");
	if (syntax_check(dd))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------10---------\n");
	if (syntax_check(e))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------11---------\n");
	if (syntax_check(f))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------12---------\n");
	if (syntax_check(g))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------13---------\n");
	if (syntax_check(h))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------14---------\n");
	if (syntax_check(i))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------15---------\n");
	if (syntax_check(j))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------16---------\n");
	if (syntax_check(k))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------17---------\n");
	if (syntax_check(l))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------18---------\n");
	if (syntax_check(m))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------19---------\n");
	if (syntax_check(n))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------20---------\n");
	if (syntax_check(o))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------21---------\n");
	if (syntax_check(p))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------22---------\n");
	if (syntax_check(q))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------23---------\n");
	if (syntax_check(r))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------24---------\n");
	if (syntax_check(s))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------25---------\n");
	if (syntax_check(t))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------26---------\n");
	if (syntax_check(u))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------27---------\n");
	if (syntax_check(v))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------28---------\n");
	if (syntax_check(w))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------29---------\n");
	if (syntax_check(x))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------30---------\n");
	if (syntax_check(y))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------31---------\n");
	if (syntax_check(z))
		printf("✔️\n");
	else
		printf("❌\n");
	printf("----------32---------\n");
	if (syntax_check(aa))
		printf("✔️\n");
	else
		printf("❌\n");

	return (0);
}
