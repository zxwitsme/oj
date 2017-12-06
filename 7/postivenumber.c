// 以下头文件已引入
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
// #include <ctype.h>

/**
 * @param  char*  单行测试数据
 */
void solution(char *line)
{
	int a, min = 1;

	while (1) {
		a = atoi(line);
		if (a > 0 && min == a)
			min++;
		line = strstr(line, ",");
		if (line == NULL)
			break;
		else
			line += 1;
	}

	printf("%d\n", min);
}

int main()
{
        char line[1024];
        scanf("%[^\n]", line);
        solution(line);
}

