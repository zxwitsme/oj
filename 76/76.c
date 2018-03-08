#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int first[256], second[256];
	int i, len;
	char *first_str, *second_str, *save_ptr;

	first_str = strtok_r(line, ",", &save_ptr);
	second_str = strtok_r(NULL, ",", &save_ptr);

	len = strlen(first_str);
	if (strlen(second_str) != len) {
		printf("0\n");
		return;
	}

	memset(first, 0, sizeof(first));
	memset(second, 0, sizeof(second));

	for (i = 0; i < len; i++) {
		first[first_str[i]]++;
		second[second_str[i]]++;
	}

	for (i = 0; i < len; i++) {
		if (first[first_str[i]] != second[second_str[i]]) {
			printf("0\n");
			return;
		} else {
			first[first_str[i]] = i + 1;
			second[second_str[i]] = i + 1;
		}
	}
	
	printf("1\n");
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);
	solution(line);
}

