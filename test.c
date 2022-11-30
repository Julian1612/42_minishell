#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX))
		printf("%s\n", buf);
	return 0;
}