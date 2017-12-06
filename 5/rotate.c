#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int number[1024];
	int a;
	int len, max = 0, max_location = 0;

	len = 0;
	memset(number, 0, 1024); 
	while (1) {
		a = atoi(line);
		printf("%d\n", a);
		number[len++]=a;
		if (a >= max) {
			max = number[len-1];
			max_location = len;
		}
		line = strstr(line, ",");
		if (line == NULL)
			break;
		else
			line += 1;
	}

	printf("max_loc:%d len:%d\n", max_location,len);
	if (max_location > (len-1)/2)
		printf("%d\n", number[(max_location-(len-max_location))/2]);
	else
		printf("%d\n", number[len-1-((len-max_location)-max_location)/2]);

}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

