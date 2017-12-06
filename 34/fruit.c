#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list_head {
	int good;
	int used;
	struct list_head *next;
} LIST, *PLIST;

void solution(char *line)
{
	PLIST list, head, next, prev;
	int i, j, k, m = 0;

	k = atoi(line);

	list = (PLIST)calloc(2*k, sizeof(LIST));
	if (!list) {
		printf("list calloc failed\n");
		return;
	}

	next = head;
	for (i = 0; i < 2 * k; i++) {
		if (i < k)
			list[m].good = 0;
		else
			list[m].good = 1;
		list[m].used = 0;
		if (i == 0) {
			head = &list[0];
			next = head;
		} else {
			next->next = &list[m];
			next = next->next;
		}
		m++;
	}
	next->next = head;

	next = head;
	for (i = 0; i < 2 * k; i++) {
		printf("%p %d ", next, next->good);
		next = next->next;
	}
	printf("\n");

	for (m = k + 1; ;m++) {
		//printf("m %d\n", m);
		j = 0;
		next = head;
		for (i = 0; i < 2 * k; i++) {
			next->used = 0;
			next = next->next;
		}
		next = head;
		while (1) {
			for (i = 1; i < m;) {
				while (1) {
					if (next->used == 0) {
						i++;
						break;
					} else {
						next = next->next;
					}
					
				}
				
				if (i < m)
					next = next->next;
				else
					break;
			}
			//printf("%p\n", next);
			if (next->good) {
				next->used = 1;
				j++;
				if (j >= k) {
					printf("%d\n", m-1);
					return;
				}
			} else {
				break;
			}
		}
	}
		
}


int main()
{
	char line[1024];

	scanf("%s", line);
	solution(line);

}

