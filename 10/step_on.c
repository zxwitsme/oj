#include <stdio.h>
//#include <string.h>

void solution(char *line)
{
	int a, i;
	long p[100];

	a = atoi(line);

	p[1] = 1;
	p[2] = 2;
	if (a < 3)
		printf("%ld\n", p[a]);
	else {
		for(i = 3; i <= a; i++)
			p[i] = p[i-1] + p[i-2];
		printf("%ld\n", p[a]);
	}
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);
	solution(line);
}

