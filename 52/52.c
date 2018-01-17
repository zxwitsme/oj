#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	unsigned short map[1024][1024];
	unsigned short q[102400][3];
	int a[6];
	int i, m, first, last;
	int r, c, n, rr, cc, nn;
	int d[8][2] = {{-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1}};
 
	memset(map, 0, sizeof(map));
	memset(q, 0, sizeof(q));
	m = 0;
	while (1) {
		if (m == 0)
			line_a = strtok_r(line, ";", &saveptr);
		else
			line_a = strtok_r(NULL, ";", &saveptr);
		if (!line_a)
			break;

		a[m] = atoi(line_a);
		m++;
	}

	map[a[2]][a[3]] = 1;
	map[a[4]][a[5]] = 2;

	if (a[2] == a[4] && a[3] == a[5]) {
		printf("0\n");
		return;
	}

	q[0][0] = a[2];
	q[0][1] = a[3];
	q[0][2] = 0;

	first = 0;
	last = 0;
	while (last >= first) {
		r = q[first][0];
		c = q[first][1];
		n = q[first][2];
		first++;
		for (i = 0; i < 8; i++) {
			rr = r + d[i][0];
			cc = c + d[i][1];
			nn = n + 1;
			if (rr >= 0 && rr <= a[0] && cc >= 0 && cc <= a[1]) {
				if (map[rr][cc] == 2) {
					printf("%d\n", nn);
					return;
				}
				if (map[rr][cc] == 0) {
					last++;
					if (last >= 102400) {
						printf("q too small\n");
						return;
					}
					q[last][0] = rr;
					q[last][1] = cc;
					q[last][2] = nn;
					map[rr][cc] = 1;
				}

			}
		}
	}

	printf("-1\n");
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
