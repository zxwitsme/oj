#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permutation(int m, int n)
{
	if (m == 1 || n == 1)
		return 1;
	else if (m <= n)
		return 1 + permutation(m, m-1);
	else
		return permutation(m-n, n) + permutation(m, n-1); 

}

void solution(char *line)
{
	int m, n;

	m = atoi(line);
	line = strstr(line, ",");
	if (!line)
		return;
	else
		line += 1;
	n = atoi(line);
	printf("%d\n", permutation(m, n));
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

