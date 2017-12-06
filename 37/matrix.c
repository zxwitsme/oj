#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	int f[512][512];
	int i, j, k, max = 0;
	int m = 0, n = 0;
 
	memset(f, 0, sizeof(f));
	while (1) { 
		if (m == 0)
			line_a = strtok_r(line, ";", &saveptr);
		else    
			line_a = strtok_r(NULL, ";", &saveptr);
                         
		if (!line_a)
			break;

		n = 0;                
		while (1) {
			f[m][n++] = atoi(line_a);
			line_a = strstr(line_a, ",");
			if (!line_a)
				break;
			else    
				line_a++;
		}               
		m++;
	}
 
	for (i = 0; i < m - 1; i++) {
		for (j = 0; j < n - 1; j++) {
			k = f[i][j] + f[i+1][j+1];
			if (k > max)
				max = k;
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
