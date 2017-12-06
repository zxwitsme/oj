#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char *line_a, *saveptr;
	int d[512][2], t[512][512], num[512];
	int i, j, k, repeat, back_i;
	int n, p = 0;

	memset(d, 0, sizeof(d));
	memset(t, 0, sizeof(t));
	memset(num, 0, sizeof(num));

	n = atoi(strtok_r(line, ";", &saveptr));
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
			if (d[i][1] == t[d[i][0]][j])
				repeat = 1;
		}
		if (!repeat)
			t[d[i][0]][num[d[i][0]]++] = d[i][1];
	}

	for (i = 0; i < n;) {
		back_i = 0;
		if(num[i] == 0) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < num[j]; k++) {
					if (t[j][k] == i) {
						if (k != num[j]-1) {
							t[j][k] = t[j][num[j]-1];
						}
						num[j]--;
						if (num[j] == 0 && j < i)
							back_i = 1;
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

	return 0;
}

