#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*type
 * 0: 单个
 * 1: 对子
 * 2：2队
 * 3：3条
 * 4：葫芦
 * 5：4条
 * 6: 顺子
 */
void solution(char *line)
{
	int poker_a[5], poker_b[5], hash_a[15], hash_b[15];
	int hulu_a[2], hulu_b[2], mark_a[2], mark_b[2];
	int type_a, type_b;
	char *line_a, *line_b, str_tmp;
	int i, j, m, n;

	memset(hash_a, 0, sizeof(hash_a));
	memset(hash_b, 0, sizeof(hash_b));
	memset(mark_a, 0, sizeof(mark_a));
	memset(mark_a, 0, sizeof(mark_a));
	memset(hulu_b, 0, sizeof(hulu_b));
	memset(hulu_b, 0, sizeof(hulu_b));

	line_a = strtok(line, ",");
	line_b = strtok(NULL, ",");

	printf("%s\n", line_a);
	printf("%s\n", line_b);
	while (1) {
		if (*line_a == 'J')
			i = 11;
		else if (*line_a == 'Q')
			i = 12;
		else if (*line_a == 'K')
			i = 13;
		else if (*line_a == 'A')
			i = 14;
		else if (*line_a >= '1' && *line_a <= '9')
			i = atoi(line_a);
		else {
			line_b = strstr(line_b, " ");
			if (!line_b)
				break;
			else
				line_b += 1;
		}

		hash_a[i]++;
		line_a = strstr(line_a, " ");
		if (!line_a)
			break;
		else
			line_a += 1;
	}
	while (1) {
		if (*line_b == 'J')
			i = 11;
		else if (*line_b == 'Q')
			i = 12;
		else if (*line_b == 'K')
			i = 13;
		else if (*line_b == 'A')
			i = 14;
		else if (*line_b >= '1' && *line_b <= '9')
			i = atoi(line_b);
		else {
			line_b = strstr(line_b, " ");
			if (!line_b)
				break;
			else
				line_b += 1;
			continue;
		}
		printf("i %d\n", i);
		hash_b[i]++;
		line_b = strstr(line_b, " ");
		if (!line_b)
			break;
		else
			line_b += 1;
	}

	for (i = 2; i <= 14; i++)
		printf("%2d ", i);
	printf("\n");
	for (i = 2; i <= 14; i++)
		printf("%2d ", hash_a[i]);
	printf("\n");
	for (i = 2; i <= 14; i++)
		printf("%2d ", hash_b[i]);
	printf("\n");

	m = 0;
	n = 0;
	for (i = 2; i <= 14; i++) {
		if (hash_a[i] != 0) {
			poker_a[m++] = i;
			if (hash_a[i] == 3) {
				mark_a[0] = 1;
				hulu_a[0] = i;
			}
			if (hash_a[i] == 2) {
				mark_a[1] = 1;
				hulu_a[1] = i;
			}
		}


		if (hash_b[i] != 0) {
			poker_b[n++] = i;
			if (hash_b[i] == 3) {
				mark_b[0] = 1;
				hulu_b[0] = i;
			}
			if (hash_b[i] == 2) {
				mark_b[1] = 1;
				hulu_b[1] = i;
			}
		}
	}

	type_a = 0;
	type_b = 0;
	for (i = 0; i < m; i++)
		printf("%2d ", poker_a[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%2d ", poker_b[i]);
	printf("\n");
	if (m == 5) {
		if ((poker_a[0]+1)==poker_a[1] &&
			(poker_a[1]+1)==poker_a[2] &&
			(poker_a[2]+1)==poker_a[3] &&
			(poker_a[3]+1)==poker_a[4])
			type_a = 6;
		else
			type_a = 0;
	}

	if (n == 5) {
		if ((poker_b[0]+1)==poker_b[1] &&
			(poker_b[1]+1)==poker_b[2] &&
			(poker_b[2]+1)==poker_b[3] &&
			(poker_b[3]+1)==poker_b[4])
			type_b = 6;
		else
			type_b = 0;
	}

	if (type_a > type_b) {
		printf("win\n");
		return;
	} else if (type_a < type_b) {
		printf("lose\n");
		return;
	} else if (type_a == 6) {
		if (poker_a[0] > poker_b[0]) {
			printf("win\n");
			return;
		} else if (poker_a[0] < poker_b[0]) {
			printf("lose\n");
			return;
		} else {
			printf("draw\n");
			return;
		}
	}

	if (mark_a[0] && mark_a[1]) {
		if (mark_b[0] && mark_b[1]) {
			if(hulu_a[0] > hulu_b[0]) {
				printf("win\n");
				return;
			} else if(hulu_a[0] < hulu_b[0]) {
				printf("lose\n");
				return;
			} else {
				if(hulu_a[1] > hulu_b[1]) {
					printf("win\n");
					return;
				} else if(hulu_a[1] < hulu_b[1]) {
					printf("lose\n");
					return;
				} else {
					printf("draw\n");
					return;
				}

			}
		} else {
			printf("win\n");
			return;
		}
	} else if (mark_b[0] && mark_b[1]) {
		printf("lose\n");
		return;
	}
	
	for (i = 14; i >= 2; i--) {
		if (hash_a[i] == 4 && hash_b[i] != 4) {
			printf("win\n");
			return;
		} else if (hash_a[i] != 4 && hash_b[i] == 4) {
			printf("lose\n");
			return;
		}
	}

	for (i = 14; i >= 2; i--) {
		if (hash_a[i] == 3 && hash_b[i] != 3) {
			printf("win\n");
			return;
		} else if (hash_a[i] != 3 && hash_b[i] == 3) {
			printf("lose\n");
			return;
		}
	}

	for (i = 14; i >= 2; i--) {
		if (hash_a[i] == 2 && hash_b[i] != 2) {
			printf("win\n");
			return;
		} else if (hash_a[i] != 2 && hash_b[i] == 2) {
			printf("lose\n");
			return;
		} else {
			for (j = i; j >= 2; j--) {
				if (hash_a[j] == 2 && hash_b[j] != 2) {
					printf("win\n");
					return;
				} else if (hash_a[j] != 2 && hash_b[j] == 2) {
					printf("lose\n");
					return;
				}
			}
		}
	}
	for (i = 14; i >= 2; i--) {
		printf("hash_a %d hash_b %d\n" ,hash_a[i], hash_b[i]);
		if (hash_a[i] == 1 && hash_b[i] != 1) {
			printf("win\n");
			return;
		} else if (hash_a[i] != 1 && hash_b[i] == 1) {
			printf("lose\n");
			return;
		} else 
			continue;
	}

	printf("draw\n");
	return;
}

int main()
{
	char line[1024];
	
	scanf("%[^\n]", line);
	solution(line);
}

