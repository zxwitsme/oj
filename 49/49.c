#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct edge {
	int u;
	int v;
	int w;
} EDGE;

int getparent(int n, int *parent)
{
	int root, tmp;
	for (root = n; parent[root] >= 0; root = parent[root]);
	while (root != n) {
		tmp = parent[n];
		parent[n] = root;
		n = tmp;
	}

	return root;
}

void merge(int n1, int n2, int *parent)
{
	int r1, r2;
	int new_n;

	r1 = getparent(n1, parent);
	r2 = getparent(n2, parent);
	new_n = parent[r1] + parent[r2];

	if (parent[r1] > parent[r2]) {
		parent[r1] = r2;
		parent[r2] = new_n;
	} else {
		parent[r2] = r1;
		parent[r1] = new_n;
	}
}

void solution(char *line)
{
	char *line_a, *saveptr;
	EDGE edge[1024];
	int parent[256];
	int i, j, m, n;
	int u, v, w;
	int sum = 0, edge_num = 0;
 
	memset(edge, 0, sizeof(edge));
	memset(parent, -1, sizeof(parent));
	line_a = strtok_r(line, ";", &saveptr);
	n = atoi(line_a);
	m = 0;

	while (1) {
		line_a = strtok_r(NULL, ";", &saveptr);
		if (!line_a)
			break;

		edge[m].u = atoi(line_a);
		line_a = strstr(line_a, ",");
		if (!line_a)
			break;
		line_a++;
		edge[m].v = atoi(line_a);
		line_a = strstr(line_a, ",");
		if (!line_a)
			break;
		line_a++;
		edge[m].w = atoi(line_a);
		m++;
	}

	for (i = 0; i < m; i++) {
		for (j = m - 1; j > i; j--) {
			if (edge[j].w < edge[j-1].w) {
				u = edge[j].u;
				v = edge[j].v;
				w = edge[j].w;
				edge[j].u = edge[j-1].u;
				edge[j].v = edge[j-1].v;
				edge[j].w = edge[j-1].w;
				edge[j-1].u = u;
				edge[j-1].v = v;
				edge[j-1].w = w;
			}
		}
	}

	for (i = 0; i < m; i++) {
		u = edge[i].u;
		v = edge[i].v;
		if (getparent(u, parent) != getparent(v, parent)) {
			sum += edge[i].w;
			edge_num++;
			merge(u, v, parent);
		}
		if (edge_num >= n - 1)
			break;
	}

	printf("%d\n", sum);
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
