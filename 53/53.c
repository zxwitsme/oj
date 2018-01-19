#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *saveptr;
	char r[1024];
	char *a, *b, *c;
	int i, m, n, s = 0, num_b[2], num;
 
	memset(num_b, 0, sizeof(num_b));
	memset(r, 0, sizeof(r));

	a = strtok_r(line, " ", &saveptr);
	b = strtok_r(NULL, " ", &saveptr);

	if (!strcmp(a, b)) {
		printf("1\n");
		return;
	}

	for (i = 0; i < strlen(a); i++) {
		if (a[i] == 'B')
			num_b[0]++;
	}

	for (i = 0; i < strlen(b); i++) {
		if (b[i] == 'B')
			num_b[1]++;
	}

	num = (num_b[1] - num_b[0]) / 2;
	if (num <= 0)
		s = 0;
	else {
		for (i = 0, m = 0; i < strlen(b); i++) {
			if (b[i] == 'B') {
				m++;
				if (m >= num) {
					s = i + 1;
					break;
				}
			}
		}
	}

	c = strstr(b + s, a);
	if (c != NULL) {
		m = 0;
		n = 0;
		for (i = 0; i < c - b; i++) {
			if (b[i] == 'B')
				m++;
		}
		for (i = strlen(a); i < strlen(c); i++) {
			if (c[i] == 'B')
				n++;
		}
		if (m == n) {
			if (n == 0) {
				printf("1\n");
				return;
			} else {
				if (*(c-1) == 'B') {
					printf("1\n");
					return;
				} else {
					printf("0\n");
					return;
				}
			}

		} else {
			printf("0\n");
			return;
		}
	} else {
		m = 0;
		n = 0;
		for (i = 0; i < strlen(a); i++) {
			r[i] = *(a + strlen(a) - i -1);
		}
		r[i] = '\0';

		c = strstr(b+s, r);
		if (c == NULL) {
			printf("0\n");
			return;
		}
		for (i = 0; i < c - b; i++) {
			if (b[i] == 'B')
				m++;
		}
		for (i = strlen(r); i < strlen(c); i++) {
			if (c[i] == 'B')
				n++;
		}
		if (m + 1 == n) {
			if (*(c+strlen(r)) == 'B') {
				printf("1\n");
				return;
			} else {
				printf("0\n");
				return;
			}
		} else {

			printf("0\n");
			return;
		}
	}
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
