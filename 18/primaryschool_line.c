#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_head {
	int height;
	int num;
	struct list_head *next;
} LIST, *PLIST;

void solution(char *line)
{
	PLIST list, head, prev, next, change_prev, change, change_next, bak;
	char *div, *saveptr;
	int a, b, m = 0;
	int first = 1;

	list = (PLIST)calloc(128, sizeof(LIST));
	if (!list) {
		printf("list calloc failed\n");
		return;
	}

	do {
		if (first) {
			first = 0;
			div = strtok_r(line, "[", &saveptr);
		} else
			div = strtok_r(NULL, "[", &saveptr);
		if (div == NULL)
			break;
		a = atoi(div);
		b = atoi(strstr(div, ",") + 1);
		
		list[m].height = a;
		list[m].num = b;
		if (!m) {
			head = &list[0];
			head->next = NULL;
			m++;
			continue;
		}

		next = head;
		prev = next;
		while (next != NULL) {
			if (a > next->height ||
				(a == next->height && b < next->num)) {
				if (next == head) {
					list[m].next = head;
					head = &list[m];
				} else {
					prev->next = &list[m];
					list[m].next = next;
				}
				break;
			} if (next->next == NULL) {
				list[m].next = NULL;
				next->next = &list[m];
				break;
			}
			prev = next;
			next = next->next;
		}
		m++;
	} while (1);

	change = head->next;
	while (change != NULL) {
		change_next = change->next;

		next = head;
		while (next != NULL) {
			if (next->next == change) {
				change_prev = next;
				break;
			}
			next = next->next;
		}
		
		next = head;
		a = 0;
		while (next != NULL) {
			if (a == change->num) {
				if (a == 0) {
					bak = change->next;
					change->next = head;
					head = change;
					change_prev->next = bak;
				} else {
					if (change != next) {
						prev->next = change;
						bak = change->next;
						change->next = next;
						if (change == next->next)
							next->next = bak;
						else
							change_prev->next = bak;
					}
				}
				break;
			}
			a++;
			prev = next;
			next = next->next;
		}
		
		next = head;
		change = change_next;
	}

	next = head;
	printf("[");
	while (next != NULL) {
		if (next != head)
			printf(",");
		printf("[%d,%d]", next->height, next->num);
		next = next->next;
	}
	printf("]\n");
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

