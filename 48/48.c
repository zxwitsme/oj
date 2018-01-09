#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	int f[1024];
	int i, j, k, m = 0;
	int min, max = 0;

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

	for (j = 1; j <= m; j++) {
		for (i = 0; i <= m - j; i++) {
			for (k = i; k < i + j; k++) {
				if (k == i)
					min = f[k];
				else {
					if (f[k] < min)
						min = f[k];
				}
			}

			if (min * j > max)
				max = min * j;
		}
	}

	printf("%d\n", max);
}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
