#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int f[1024][1024];
	int weight[1024], value[1024];
	char *line_w, *line_v;
	int i, j, tmp;
	int w, n = 0;

	memset(f, 0, sizeof(f));
	memset(weight, 0, sizeof(weight));
	memset(value, 0, sizeof(value));

	w = atoi(strtok(line, ";"));
	line_w = strtok(NULL, ";");
	line_v = strtok(NULL, ";");

	while (1) {
		i = atoi(line_w);
		weight[n++] = i;
		line_w = strstr(line_w, ",");
		if (!line_w)
			break;
		else
			line_w += 1;
	}
	n = 0;
	while (1) {
		i = atoi(line_v);
		value[n++] = i;
		line_v = strstr(line_v, ",");
		if (!line_v)
			break;
		else
			line_v += 1;
	}

	printf("w:%d\n", w);
	for (i = 0; i < n; i++)
		printf("weight:%d\n", weight[i]);
	for (i = 0; i < n; i++)
		printf("value:%d\n", value[i]);

	for (i = 1; i <= w; i++) {
		if (i >= weight[0])
			f[0][i] = value[0];
		else
			f[0][i] = 0;
	}

	for (i = 1; i < n; i++) {
		for (j = 1; j <= w; j++) {
			if (j > weight[i])
				tmp = f[i - 1][j - weight[i]] + value[i];
			else if (j == weight[i])
				tmp = value[i];
			else
				tmp = 0;
			f[i][j] = f[i-1][j] > tmp ? f[i-1][j] : tmp;
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", f[n-1][w]);
}

int main()
{
	char line[1024];
	
	scanf("%[^\n]", line);
	solution(line);
}

