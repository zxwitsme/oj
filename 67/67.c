#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(int numbers[], int start, int length, int first);

void permutation_i(int numbers[], int start, int length, int first)
{
	int i, copy[1024];
	int j, t, temp;

	memset(copy, 0, sizeof(copy));

	for (i=start+1; i<length; i++){
		if (numbers[i] > numbers[start] && numbers[i] != numbers[i-1])
		{
			for (t=0; t<length; t++)
				copy[t] = numbers[t];
			for (j=i; j>start; j--) {
				temp = copy[j];
				copy[j] = copy[j-1];
				copy[j-1] = temp;
			}
			permutation(copy, start+1, length, first);
		}
	}
}

void permutation(int numbers[], int start, int length, int first)
{
	int i;

	if (first)
		first = 0;
	else
		printf(";");

	for (i = 0; i < length; i++) {
		printf("%d",numbers[i]);
		if (i != length - 1)
			printf(",");
	}

	for (i = length - 2; i > start - 1; i--)
		permutation_i(numbers, i, length, first);
}

void solution(char *line)
{
	int i, j, temp;
	int m = 0, first = 1;
	int numbers[1024];

	memset(numbers, 0, sizeof(numbers));

	while (1) {
		i = atoi(line);
		numbers[m++] = i;
		line = strstr(line, ",");
		if (!line)
			break;
		else
			line += 1;
	}

	for (i = 0; i < m; i++) {
		for (j = 0;j < m - 1 - i; j++) { 
			if (numbers[j] > numbers[j+1]) {
				temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
			}
		}
	}

	permutation(numbers, 0, m, first);
	printf("\n");
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

