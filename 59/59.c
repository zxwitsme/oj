#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	int i, n, s = 0;

	n = atoi(line);

	for (i = 0; i < n; i++) {
		while (s++) {
			if ((s%7 != 0) 
			&& (s%10 != 7)
			&& ((s%100)/10 != 7)
			&& ((s%1000)/100 != 7)
			&& ((s%10000)/1000 != 7)
			&& ((s%100000)/10000 != 7))
				break;
		}
	}

	printf("%d\n", s);
}
 
int main()
{
	char line[10240];
 
	while (1) {
		memset(line, 0, sizeof(line));
		scanf("%s", line);
		solution(line);
	}
 
	return 0;
}
