#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{
	int Num;
	struct Node *next;
}JoseNode, *PNode, *HNode;

int JoseInit(HNode *h)
{
	if (!h)
		return 0;
	(*h)->next = (*h);
	return 1;
}

int JoseInsert(JoseNode *h, int pos, int x)
{
	PNode p=h,q;
	int i=1;
	if (pos == 1) {
		p->Num = x;
		p->next = p;
		return 1;
	}
	while(i<pos-1) {
		p=p->next;
		i++;
	}
	q=(PNode)malloc(sizeof(JoseNode));
	q->Num=x;
	q->next=p->next;
	p->next=q;
	return 1;
}

void TraverseList(HNode h, int m)
{
	int i = 0;
	PNode p = h;
	while (i<m) {
		p = p->next;
		i++;
	}
}

int JoseDelete(HNode h, int n, int m, int k)
{
	int i, t = n;
	PNode p=h,q;
	while(n>1) {
		for(i=1;i<k-1;i++)
			p=p->next;
		q=p->next;
		p->next=q->next;
		if (t - n == m - 1)
			printf("%d\n",q->Num);
		free(q);
		p=p->next;
		n--;
	}
	return 1;
}

void solution(char *line)
{
	int i;
	int m, n = 500;
	int k = 3;
	HNode h = ((HNode)malloc(sizeof(JoseNode)));

	m = atoi(line);

	JoseInit(&h);

	for (i = 1; i <= n; i++)
		JoseInsert(h, i, i);

	TraverseList(h,n);

	JoseDelete(h, n, m, k);
}

int main()
{
	char line[102400];

	scanf("%s", line);
	solution(line);

	return 0;
}

