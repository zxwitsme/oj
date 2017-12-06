#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char *div, *a, *b, *save_ptr;
	char result[1024];
	int type, a_com_b = 2;
	int i, j, k, m, n, add = 0;
	char x, y;

	memset(result, 0, 1024);
	div = strstr(line, ">");
	if (div) {
		type = 1;
		a = strtok_r(line, ">", &save_ptr);
		b = strtok_r(NULL, ">", &save_ptr);
	} else {
		div = strstr(line, "<");
		if (div) {
			type = 0;
			a = strtok_r(line, "<", &save_ptr);
			b = strtok_r(NULL, "<", &save_ptr);
		} else {
			div = strstr(line, "+");
			if (div) {
				type = 2;
				a = strtok_r(line, "+", &save_ptr);
				b = strtok_r(NULL, "+", &save_ptr);
			}
		}
	}

	if (type < 2) {
		if (strlen(a) > strlen(b))
			a_com_b = 1; /*a > b*/
		else if (strlen(a) < strlen(b))
			a_com_b = 0; /*a < b*/
		else {
			for (i = 0; i < strlen(a); i++) {
				if (a[i] > b[i]) {
					a_com_b = 1;
					break;
				} else if (a[i] < b[i]) {
					a_com_b = 0;
					break;
				}
			}
		}
		if (a_com_b == type)
			printf("Y\n");
		else
			printf("N\n");
	} else {
		j = 0;
		m = strlen(a) < strlen(b) ? strlen(b): strlen(a);
		for (i = 0; i < m; i++) {
			if (((int)strlen(a)-1-i) >= 0)
				x = a[strlen(a)-1-i];
			else
				x = '0';
			if (((int)strlen(b)-1-i) >= 0)
				y = b[strlen(b)-1-i];
			else
				y = '0';

			k = x-'0'+y-'0'+add;

			add = 0;
			if (k > 9) {
				k -= 10; 
				add = 1;
			}
			result[j++] = k+'0';
		}

		if (add)
			printf("1");
		for(i = j-1; i >= 0; i--)
			printf("%c", result[i]);
		printf("\n");
	}
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

