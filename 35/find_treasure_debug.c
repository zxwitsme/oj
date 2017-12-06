#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char *line_a, *saveptr;
	int d[512][2], t[512][512], num[512];
	int i, j, k, repeat, back_i;
	int n, p = 0;

	i = -1;
	j = -1;
	k = -1;
	repeat = -1;
	back_i = -1;

	memset(d, 0, sizeof(d));
	memset(d, 0, sizeof(t));
	memset(d, 0, sizeof(num));

	n = atoi(strtok_r(line, ";", &saveptr));
	printf("n %d\n", n);
	for (i = 0; i < n; i++) {
		line_a = strtok_r(NULL, ";", &saveptr);
		if (!line_a)
			break;
		d[i][0] = atoi(line_a);
		line_a = strstr(line_a, ",") + 1;
		d[i][1] = atoi(line_a);
	}

	p = i;

	for (i = 0; i < p; i++) {
		for (j = 0, repeat = 0; j < num[d[i][0]]; j++) {
			if (d[i][1] == t[d[i][0]][j]) {
				printf("repeat:%d %d\n",d[i][0], d[i][1]);
				repeat = 1;
			}
		}
		printf("a %d b %d\n", d[i][0], d[i][1]);
		if (!repeat)
			t[d[i][0]][num[d[i][0]]++] = d[i][1];
	}

	for (i = 0; i < n;) {
		printf("i %d num[%d] %d\n", i, i, num[i]);
		back_i = 0;
		if(num[i] == 0) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < num[j]; k++) {
					printf("t[%d][%d] %d\n", j, k, t[j][k]);
					if (t[j][k] == i) {
						printf("clear %d for %d\n", t[j][k], j);
						if (k != num[j]-1) {
							t[j][k] = t[j][num[j]-1];
						}
						num[j]--;
						if (num[j] == 0 && j < i) {
							printf("get i from %d to %d\n", i, j-1);
							//back_i = j-1;
							back_i = 1;
						}
						break;
					}
				}
			}
		}
		if (back_i)
			i = 0;
		else
			i++;
	}

	for (i = 0; i < n; i++) {
		if (num[i] != 0) {
			printf("false\n");
			return;
		}
	}

	printf("true\n");
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

