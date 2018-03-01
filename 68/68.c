#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int s[1024], hash[102400];
	int i, m = 0, max = 0;

	memset(s, 0, sizeof(s));
	memset(hash, 0, sizeof(hash));

	while (1) {
		i = atoi(line);
		s[m++] = i;
		line = strstr(line, ",");
		if (!line)
			break;
		else
			line += 1;
	}


	for (i = 0; i < m; i++) {
		hash[s[i]]++;
		if (s[i] > max)
			max = s[i];
	}

	for (i = 0; i <= max; i++) {
		if(hash[i] == 1) {
			printf("%d\n", i);
			return;
		}
	}

}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

