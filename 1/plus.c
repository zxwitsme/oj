#include <stdio.h>
#include <string.h>

void solution(char *line)
{
	/*
	// 在此处理单行测试数据
	int a, b;
	sscanf(line, "%d%d", &a, &b);
	printf("%d\n", a + b);
	*/

    int a, b;
    a = atoi(line);
    b = atoi(strstr(line, " "));
    printf("%d %d\n", a, b);
    printf("%d\n", a + b);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

