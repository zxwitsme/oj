#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int element[1024], stack[1024], sum, cal;
	int m = 0, n = 0;
	char *line_element, *save_ptr;
	int i, stack_top = 0;

	memset(element, 0, sizeof(element)); 
	memset(stack, -1, sizeof(stack)); 

	line_element = strtok_r(line, " ", &save_ptr);
	sum = atoi(strtok_r(NULL, " ", &save_ptr));


	while (1) {
		i = atoi(line_element);
		element[n++] = i;
		line_element = strstr(line_element, ",");
		if (line_element == NULL)
			break;
		else
			line_element += 1;
	}

	while (1) {
		if (stack_top < 0)
			break;

		if (stack[stack_top] >= n - 1) {
			if (stack_top >= 0)
				stack[stack_top] = -1;
			stack_top--;
			continue;
		} else {
			stack[stack_top]++;
			stack_top++;
		}

		for (i = 0, cal = 0; i < stack_top; i++)
			cal += element[stack[i]];
		if (cal == sum) {
			m++;
			if (stack_top >= 0)
				stack[stack_top] = -1;
			stack_top--;
		} else if (cal > sum) {
			if (stack_top >= 0)
				stack[stack_top] = -1;
			stack_top--;
		}
	}

	printf("%d\n", m);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);

	return 0;
}

