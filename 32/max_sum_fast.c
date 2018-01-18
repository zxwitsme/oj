#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char *line_a, *saveptr;
	int s[512], lr[256][2], num[512];
	int i, j, temp, max = 0;
	int q = 0, m = 0, n = 0;

	memset(s, 0, sizeof(s));
	memset(num, 0, sizeof(num));
	memset(lr, 0, sizeof(lr));

	n = atoi(strtok_r(line, ";", &saveptr));
	q = atoi(strtok_r(NULL, ";", &saveptr));
	line_a = strtok_r(NULL, ";", &saveptr);
	while (1) {
		i = atoi(line_a);
		s[m++] = i;
		line_a = strstr(line_a, " ");
		if (!line_a)
			break;
		else
			line_a += 1;
	}
	for (i = 0; i < q; i++) {
		line_a = strtok_r(NULL, ";", &saveptr);
		m = 0;
		while (1) {
			j = atoi(line_a);
			if (m >= 2)
				printf("m too large\n");
			lr[i][m++] = j;
			line_a = strstr(line_a, " ");
			if (!line_a)
				break;
			else
				line_a += 1;
		}
	}

	for (j = 0; j < n; j++) {
		for (i = n - 1; i > j; i--) {
			if (s[i-1] < s[i]) {
				temp = s[i];
				s[i] = s[i-1];
				s[i-1] = temp;
			}
		}
	}

	for (i = 0; i < q; i++) {
		for (j = lr[i][0] - 1; j < lr[i][1]; j++) {
			if (j < 0)
				printf("j < 0\n");
			num[j]++;
		}
	}

	for (j = 0; j < n; j++) {
		for (i = n - 1; i > j; i--) {
			if (num[i-1] < num[i]) {
				temp = num[i];
				num[i] = num[i-1];
				num[i-1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
		max += s[i] * num[i];

	printf("%d\n", max);
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

