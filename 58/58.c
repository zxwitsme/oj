#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	int i, n, p = 0;
	char s[102400];

	memset(s, 0, sizeof(s));

	n = strlen(line);

	if (n > 102400) {
		printf("string too large\n");
		return;
	}

	for (i = 0; i < n; i++) {
		if (line[i] == '{' || line[i] == '[' || line[i] == '(') {
			s[p] = line[i];
			p++;
		}
		if (line[i] == '}' || line[i] == ']' || line[i] == ')') {
			if (p <= 0) {
				printf("0\n");
				return;
			}

			if (line[i] == '}') {
				if (s[p-1] == '{')
					p--;
				else {
					printf("0\n");
					return;
				}
			}
			if (line[i] == ']') {
				if (s[p-1] == '[')
					p--;
				else {
					printf("0\n");
					return;
				}
			}
			if (line[i] == ')') {
				if (s[p-1] == '(')
					p--;
				else {
					printf("0\n");
					return;
				}
			}
		}
	}

	if (p == 0)
		printf("1\n");
	else
		printf("0\n");

}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
