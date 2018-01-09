#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	int f[1024];
	int i, j, m = 0, count = 0;
 
	memset(f, 0, sizeof(f));
	while (1) { 
		if (m == 0)
			line_a = strtok_r(line, ",", &saveptr);
		else    
			line_a = strtok_r(NULL, ",", &saveptr);
                         
		if (!line_a)
			break;

		f[m++] = atoi(line_a);
	}

	for (i = 0; i < m - 1; i++) {
		for(j = i + 1; j < m; j++) {
			if (f[i] + f[j] == 10 || abs(f[i]-f[j]) == 10)
				count++;
		}
	}

	printf("%d\n", count);
}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
