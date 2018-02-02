#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	int i, j, n, tmp;
	int s[512];

	n = strlen(line) + 1;

	for (i = 0; i < n; i++)
		s[i] = i + 1;

	for (i = 0; i < n; i++) {
		for (j = n - 1; j > i; j--) {
			if (line[j-1] == '+')
			{
				if (s[j-1] > s[j]) {
					tmp = s[j-1];
					s[j-1] = s[j];
					s[j] = tmp;
				}
			}
			if (line[j-1] == '-')
			{
				if (s[j-1] < s[j]) {
					tmp = s[j-1];
					s[j-1] = s[j];
					s[j] = tmp;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d", s[i]);
	printf("\n");
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
