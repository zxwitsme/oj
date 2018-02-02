#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	char g[128][20], r[1048575];
	int i, j, m, n, result, f;
 
	memset(g, 0, sizeof(g));
	memset(r, 0, sizeof(r));

	m = 0;
	while (1) {
		if (m == 0)
			line_a = strtok_r(line, ";", &saveptr);
		else
			line_a = strtok_r(NULL, ";", &saveptr);
		if (!line_a)
			break;

		n = 0;
		g[m][n++] = atoi(line_a);
		while (1) {
			line_a = strstr(line_a, ",");
			if (!line_a)
				break;
			line_a++;
			g[m][n++] = atoi(line_a);
		}
		m++;
	}

	if (n >= 20) {
		printf("n too large\n");
		return;
	}

	for (i = 0; i < m; i++) {
		for (j = n - 1, f = 1, result = 0; j >= 0; j--) {
			result += g[i][j] * f;
			f *= 2;
		}
		if(result >= 1048575) {
			printf("matrix too large");
			return;
		}
		if (r[result] != 0) {
			printf("%d,%d\n", r[result], i+1);
			return;
		} else
			r[result] = i + 1;
	}

	return;
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
