#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int door[512], dist[512], temp[512];
	int i, j, n = 0;

	memset(door, 0, sizeof(door));
	memset(dist, -1, sizeof(dist));
	memset(temp, 0, sizeof(temp));

	while (1) {
		door[n++] = atoi(line);
		line = strstr(line, ",");
		if (!line)
			break;
		else
			line++;
	}

	//for (i = 0; i < n; i++)
	//	printf("door[%d] %d\n", i, door[i]);

	for (i = 0; i < n-1; i++) {
		for (j = 0; j < door[i]; j++) {
			if ((i + j) > (n - 2))
				break;
			if(i == 0)
				temp[j] = 1;
			else if (dist[i-1] == -1) {
				printf("-1\n");
				return;
			}
			temp[i+j] = dist[i-1] + 1;
			//printf("i %d j %d temp[%d] %d\n", i, j, i+j, temp[i+j]);
			if (dist[i+j] == -1 || temp[i+j] < dist[i+j])
				dist[i+j] = temp[i+j];
		}
	}

	printf("%d\n", dist[n-2]);
}

int main()
{
	char line[1024];

	scanf("%s", line);
	solution(line);

	return 0;
}

