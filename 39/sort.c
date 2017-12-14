#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	int i, a = 0, b = 0, c = 0;

	for (i = 0; i < strlen(line); i++) {
		if (line[i] == 'a')
			a++;
		else if (line[i] == 'b')
			b++;
		else if (line[i] == 'c')
			c++;
	}

	for (i = 0; i < a; i++)
		printf("a");
	for (i = 0; i < b; i++)
		printf("b");
	for (i = 0; i < c; i++)
		printf("c");
	printf("\n");
}
 
int main()
{
	char line[102400];
#if 1
	int n = 0;
  
	for (n = 0; n < 5120; n++)
		line[n] = 'c';
	for (n = 5120; n < 10240; n++)
		line[n] = 'b';
	for (n = 10240; n < 10240+5120; n++)
		line[n] = 'a';
	line[n] = '\n';
#else
	scanf("%s", line);
#endif

	solution(line);
 
	return 0;
}
