#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop(int *element, int size, int sum)
{
	int i, j;
	int store[1024];

	if (sum == 0) {
		for (j = 0; j < size; j++)
			printf("%d ", store[j]);
		printf(" return\n");
		k = 0;
		return;
	}
	for (i = 0; i < size; i++) {
		store[k++] = element[i];
		loop(element, size, sum-1);
	}
}

void solution(char *line)
{
	int element[1024], sum, p, temp;
	int max = 0;
	int a, b, n = 0;
	char *line_element;
	int i, j;

	memset(element, 0, 1024); 

	line_element = strtok(line, " ");
	sum = atoi(strtok(NULL, " "));
	printf("sum:%d\n",sum);
	printf("line_element:%s\n",line_element);


	while (1) {
		a = atoi(line_element);
		printf("%d\n", a);
		element[n++] = a;
		line_element = strstr(line_element, ",");
		if (line_element == NULL)
			break;
		else
			line_element += 1;
	}


	loop(element, n, sum);

	//printf("%d\n", p);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

