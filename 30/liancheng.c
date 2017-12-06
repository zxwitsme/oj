#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substr(char *dest, char *src, int m, size_t n)
{
	strncpy(dest, src+m, n);
	dest[n] = '\0';

	return dest;
}
void solution(char *line)
{ 
	char dest[1024], r[1024];
	int i, j;
	int a, b, c, p, hit = 0;

	memset(dest, 0, sizeof(dest));
	memset(r, 0, sizeof(r));

	for (i = 0; i < strlen(line); i++) {
		for (j = i + 1; j < strlen(line); j++) {
			a = atoi(substr(dest,line,0,i+1));
			b = atoi(substr(dest,line,i+1,j-i));
			c = a * b;
			sprintf(r, "%d", c);
			p = j + 1;
			if (atoi(substr(dest,line,p,strlen(r))) != c) {
					hit = 0;
					continue;
			} else
				hit = 1;
			p += strlen(r);
			while (p < strlen(line)) {
				a = b;
				b = c;
				c = a * b;
				sprintf(r, "%d", c);
				if (atoi(substr(dest,line,p,strlen(r))) != c) {
					hit = 0;
					break;
				} else {
					p += strlen(r);
					hit = 1;
				}
			}
			if (p >= strlen(line)) {
				if (hit) {
					printf("true\n");
					return;
				}
			}
		}
	}

	if (hit)
		printf("true\n");
	else
		printf("false\n");
}   

int main()
{
	char a[1024];
	scanf("%s", a);
	solution(a);
	return 0;
}

