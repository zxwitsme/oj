#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void find_island(int i, int j, int m, int n, char g[][128])
{
	g[i][j] = 0;
	if (i > 0 && g[i-1][j] == 1)
		find_island(i-1, j, m, n, g);
	if (j > 0 && g[i][j-1] == 1)
		find_island(i, j-1, m, n, g);
	if (i < m - 1 && g[i+1][j] == 1)
		find_island(i+1, j, m, n, g);
	if (j < n - 1 && g[i][j+1] == 1)
		find_island(i, j+1, m, n, g);
}

void solution(char *line)
{
	char *line_a, *saveptr;
	char g[128][128];
	int i, j, m, n, result = 0;
 
	memset(g, 0, sizeof(g));
	m = 0;
	while (1) {
		if (m == 0)
			line_a = strtok_r(line, " ", &saveptr);
		else
			line_a = strtok_r(NULL, " ", &saveptr);
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

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (g[i][j] == 1) {
				find_island(i, j, m, n, g);
				result++;
			}
		}
	}

	printf("%d\n", result);
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
