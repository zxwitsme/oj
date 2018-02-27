#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	int d[4][2];
	int i, j, k, m, n, distance[6], a[2], b[2];
 
	memset(d, 0, sizeof(d));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	m = 0;
	while (1) {
		if (m == 0)
			line_a = strtok_r(line, ";", &saveptr);
		else
			line_a = strtok_r(NULL, ";", &saveptr);
		if (!line_a)
			break;

		n = 0;
		d[m][n++] = atoi(line_a);
		while (1) {
			line_a = strstr(line_a, ",");
			if (!line_a)
				break;
			line_a++;
			d[m][n++] = atoi(line_a);
		}
		m++;
	}


	k = 0;
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 4; j++) {
			distance[k++] = (d[j][1] - d[i][1]) * (d[j][1] - d[i][1]) + (d[j][0] - d[i][0])*(d[j][0] - d[i][0]);
		}
	}

	a[0] = distance[0];
	a[1]++;
	for (i = 1; i < 6; i++) {
		if (distance[i] == a[0])
			a[1]++;
		else if (b[0] == 0) {
			b[0] = distance[i];
			b[1]++;
		} else if (distance[i] == b[0])
			b[1]++;
	}

	if ((a[1] == 4 && b[1] == 2) || (a[1] == 2 && b[1] == 4))
		printf("1\n");
	else
		printf("0\n");

	return;
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
