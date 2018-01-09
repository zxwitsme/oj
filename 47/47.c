#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	int person, brick;
	int t, average;
 
	line_a = strtok_r(line, ",", &saveptr);
	brick = atoi(line_a);

	line_a = strtok_r(NULL, ",", &saveptr);
	person = atoi(line_a);

	if (brick == 0) {
		printf("0\n");
		return;
	}

	average = brick / person;
	if (brick % person)
		average++;

	t = 4 * (average * 2 - 1);
	t += 5 * ((t - 1) / 18);

	printf("%d\n", t);
}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
