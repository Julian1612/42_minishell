#include <stdio.h>

int	get_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	syntax_check(char **token_arr)
{
	int	i;
	int	arr_len;

	i = 0;
	arr_len = get_arr_len(token_arr);
	printf("og%d\n", arr_len);
	if (arr_len < 2 && (token_arr[i][0] == '|' || token_arr[i][0] == '<' || token_arr[i][0] == '>' || (token_arr[i + 1][0] == '<' && token_arr[i + 1][1] == '<') || (token_arr[i + 1][0] == '>' && token_arr[i + 1][1] == '>')))
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

	if (syntax_check(a))
		printf("✔️\n");
	else
		printf("❌\n");

	if (syntax_check(b))
		printf("✔️\n");
	else
		printf("❌\n");

	if (syntax_check(c))
		printf("✔️\n");
	else
		printf("❌\n");

	if (syntax_check(d))
		printf("✔️\n");
	else
		printf("❌\n");

	if (syntax_check(e))
		printf("✔️\n");
	else
		printf("❌\n");

	if (syntax_check(f))
		printf("✔️\n");
	else
		printf("❌\n");

	// if (syntax_check(g))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(h))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(i))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(j))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(k))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(l))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(m))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(n))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(o))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(p))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(q))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(r))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(s))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(t))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(u))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(v))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(w))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(x))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(y))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(z))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// if (syntax_check(aa))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	// 	if (syntax_check(dd))
	// 	printf("✔️\n");
	// else
	// 	printf("❌\n");

	return (0);
}
