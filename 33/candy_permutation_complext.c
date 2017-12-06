#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(int s[], int m, int n, int p, int *c)
{
	int i;

	if (n == 1) {
		s[n-1] = m;
		for (i = 0; i < p-1; i++) {
			if (s[i] < s[i+1])
				return;
		}
#if 0
		for (i = 0; i < p; i++)
			printf("%d ", s[i]);
		printf("\n");
#endif
		(*c)++;
		return;
	}

	for (i = 0; i <= m/n; i++) {
		s[n-1] = i;
		//printf("s[%d] %d\n", n-1, i);
		permutation(s, m-i, n-1, p, c);
	}
}

void solution(char *line)
{
	int s[64];
	int m = 0, n = 0, c = 0;

	memset(s, 0, sizeof(s));

	m = atoi(line);
	line = strstr(line, ",");
	if (!line)
		return;
	else
		line += 1;
	n = atoi(line);

	printf("%d %d\n", m, n);
	permutation(s, m, n, n, &c);

	printf("%d\n", c);
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

