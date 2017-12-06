#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int a[1024], b[1024], result[1024], max[1024], k;
	int stack_a[1024], stack_b[1024], top_a, top_b;
	char *line_a, *line_b;
	int i, j, l, m, f, len_a, len_b, hit_a;

	len_a = 0;
	len_b = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(stack_a, 0, sizeof(stack_a));
	memset(stack_b, 0, sizeof(stack_b));
	memset(result, 0, sizeof(result));
	memset(max, 0, sizeof(max));
	line_a = strtok(line, " ");
	line_b = strtok(NULL, " ");
	k = atoi(strtok(NULL, " "));
	while (1) {
		l = atoi(line_a);
		a[len_a++] = l;
		line_a = strstr(line_a, ",");
		if (!line_a)
			break;
		else
			line_a += 1;
	}
	while (1) {
		l = atoi(line_b);
		b[len_b++] = l;
		line_b = strstr(line_b, ",");
		if (!line_b)
			break;
		else
			line_b += 1;
	}

	for (i = 0; i < len_a; i++)
		printf("a:%d\n", a[i]);
	for (i = 0; i < len_b; i++)
		printf("b:%d\n", b[i]);
	printf("k:%d\n", k);

	for (i = 0; i <= k; i++) {
		printf("i:%d\n", i);
		if (len_a < i || len_b < k - i)
			continue;
		for(j = 0, l = 0, top_a = 0; j < len_a; j++) {
			if (j == 0) {
				printf("first a:%d\n", a[0]);
				stack_a[top_a++] = a[0];
				printf("top_a+:%d\n", top_a);
				continue;
			}
			printf("l %d len_a-i %d\n", l, len_a - i);
			if (l == len_a - i) {
				stack_a[top_a++] = a[j];
				printf("top_a++:%d\n", top_a);
			} else {
				printf("add a:%d\n", a[j]);
				stack_a[top_a++] = a[j];
				printf("top_a+++:%d\n", top_a);
				for (f = top_a - 2; f >= 0; f--) {
					if (a[j] > stack_a[f]) {
						printf("change %d use %d\n", stack_a[f], a[j]);
						stack_a[f] = a[j];
						top_a--;
						printf("top_a:%d\n", top_a);
						l++;
						if (l == len_a - i)
							break;
						printf("abandon:%d\n",l);
					}
				}
			}
		}
		top_a = i; 
		for(j = 0, l = 0, top_b = 0; j < len_b; j++) {
			if (j == 0) {
				stack_b[top_b++] = b[0];
				continue;
			}
			if (l == len_b - (k - i)) {
				stack_b[top_b++] = b[j];
			} else {
				printf("add b:%d\n", b[j]);
				stack_b[top_b++] = b[j];
				printf("top_b+++:%d\n", top_b);
				for (f = top_b - 2; f >= 0; f--) {
					if (b[j] > stack_b[f]) {
						printf("change %d use %d\n", stack_b[f], b[j]);
						stack_b[f] = b[j];
						top_b--;
						printf("top_b:%d\n", top_b);
						l++;
						if (l == len_b - (k - i))
							break;
						printf("abandon b:%d\n",l);
					}
				}	
			}
		}
		top_b = k - i;
		for (j = 0; j < top_a; j++)
			printf("#%d\n", stack_a[j]);
		for (j = 0; j < top_b; j++)
			printf("##%d\n", stack_b[j]);

		for (j = 0, l = 0, m = 0; j < k; j++) {
			printf("l %d top_a %d\n", l, top_a);
			printf("m %d top_b %d\n", m, top_b);
			printf("stack_a[l] %d stack_b[m] %d\n", stack_a[l], stack_b[m]);
			if ( l >= top_a || m >= top_b) {
				printf("some used up\n");
				if (l >= top_a) {
					printf("a used up: %d\n", stack_b[m++]);
					result[j] = stack_b[m++];
				} else {
					printf("b used up: %d\n", stack_a[l]);
					result[j] = stack_a[l++];
				}
				continue;
			}
			if (stack_a[l] > stack_b[m]) {
				result[j] = stack_a[l++];
			} else if(stack_a[l] < stack_b[m]) {
				result[j] = stack_b[m++];
			} else {
				for (f = 1; f < k; f++) {
					if( f + l >= top_a || f + m >= top_b) {
						if (f + l >= top_a)
							hit_a = 0;
						else
							hit_a = 1;
						break;
					}
					if (stack_a[l+f] > stack_b[m+f]) {
						hit_a = 1;
						break;
					} else if (stack_a[l+f] < stack_b[m+f]) {
						hit_a = 0;
						break;
					}

				}

				if (hit_a)
					result[j] = stack_a[l++];
				else
					result[j] = stack_b[m++];
			}
		}

	for (j = 0; j < k; j++)
		printf("***%d", result[j]);
	printf("\n");

		for (j = 0; j < k; j++) {
			if (result[j] < max[j])
				break;
			else if(result[j] > max[j]) {
				for (f = 0; f < k; f++)
					max[f] = result[f];
			}
		}
	}

	for (i = 0; i < k; i++)
		printf("%d", max[i]);
	printf("\n");
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}


