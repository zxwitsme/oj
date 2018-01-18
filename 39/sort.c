#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	int i = 0, a = 0, b = 0, c = 0;

	while(line[i] != '\0') {
		if (line[i] == 'a')
			a++;
		else if (line[i] == 'b')
			b++;
		else if (line[i] == 'c')
			c++;
		else
			break;
		i++;
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

	scanf("%s", line);
	solution(line);
 
	return 0;
}
