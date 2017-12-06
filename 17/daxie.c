#include <stdio.h>
#include <string.h>

/*00 零
*01 壹
*02 贰
*03 叁
*04 肆
*05 伍
*06 陆
*07 柒
*08 捌
*09 玖
*0a 拾
*0b 佰
*0c 仟
*0d 万
*0e 亿
*0f 元整
*/
void solution(char *line)
{
	int i, size = strlen(line);
	int result[1024], num, len = 0, wan_not_zero = 0;
	int gewei_is_zero = 0, shiwei_is_zero = 0, baiwei_is_zero = 0, qianwei_is_zero = 0;

	memset(result, 0, 1024);
	for (i = size - 1; i >= 0; i--) {
		num = line[i] - '0';
		if (num == 0 && size == 1) {
			printf("零元整\n");
			return;
		}

		if (i == size - 1) {
			result[len++] = 0x0f;
			if (num!= 0) {
				result[len++] = num;
				gewei_is_zero = 0;
			} else
				gewei_is_zero = 1;
		} else if (i == size - 2) {
			if (num!= 0) {
				result[len++] = 0x0a;
				result[len++] = num;
			} else
				shiwei_is_zero = 1;
		} else if (i == size - 3) {
			if (num!= 0) {
				if(shiwei_is_zero && !gewei_is_zero)
					result[len++] = 0x00;
				result[len++] = 0x0b;
				result[len++] = num;
			} else
				baiwei_is_zero = 1;
		} else if (i == size - 4) {
			if (num!= 0) {
				if(baiwei_is_zero &&
					(!gewei_is_zero || !shiwei_is_zero))
					result[len++] = 0x00;
				result[len++] = 0x0c;
				result[len++] = num;
				qianwei_is_zero = 0;
			} else
				qianwei_is_zero = 1;
		} else if (i == size - 5) {
			if (qianwei_is_zero &&
				(!gewei_is_zero || !shiwei_is_zero || !baiwei_is_zero))
				result[len++] = 0x00;
			result[len++] = 0x0d;
			if (num != 0) {
				result[len++] = num;
				wan_not_zero = 1;
				gewei_is_zero = 0;
			} else
				gewei_is_zero = 1;
		} else if (i == size - 6) {
			if (num!= 0) {
				result[len++] = 0x0a;
				result[len++] = num;
				wan_not_zero = 1;
				shiwei_is_zero = 0;
			} else
				shiwei_is_zero = 1;
		} else if (i == size - 7) {
			if (num!= 0) {
				if(shiwei_is_zero && !gewei_is_zero)
					result[len++] = 0x00;
				result[len++] = 0x0b;
				result[len++] = num;
				wan_not_zero = 1;
				baiwei_is_zero = 0;
			} else
				baiwei_is_zero = 1;
		} else if (i == size - 8) {
			if (num!= 0) {
				if(baiwei_is_zero &&
					(!gewei_is_zero || !shiwei_is_zero))
					result[len++] = 0x00;
				result[len++] = 0x0c;
				result[len++] = num;
				wan_not_zero = 1;
				qianwei_is_zero = 0;
			} else
				qianwei_is_zero = 1;
		} else if (i == size - 9) {
			if (qianwei_is_zero &&
				(!gewei_is_zero || !shiwei_is_zero || !baiwei_is_zero))
				result[len++] = 0x00;
			result[len++] = 0x0e;
			if (num!= 0) {
				result[len++] = num;
				gewei_is_zero = 0;
			} else
				gewei_is_zero = 1;
		} else if (i == size - 10) {
			if (num!= 0) {
				result[len++] = 0x0a;
				result[len++] = num;
				shiwei_is_zero = 0;
			} else
				shiwei_is_zero = 1;
		} else if (i == size - 11) {
			if (num!= 0) {
				if(shiwei_is_zero && !gewei_is_zero)
					result[len++] = 0x00;
				result[len++] = 0x0b;
				result[len++] = num;
			}
		}
	}

	for (i = len - 1; i >= 0; i--) {
		switch (result[i]) {
			case 0x00:
				printf("零");
				break;
			case 0x01:
				printf("壹");
				break;
			case 0x02:
				printf("贰");
				break;
			case 0x03:
				printf("叁");
				break;
			case 0x04:
				printf("肆");
				break;
			case 0x05:
				printf("伍");
				break;
			case 0x06:
				printf("陆");
				break;
			case 0x07:
				printf("柒");
				break;
			case 0x08:
				printf("捌");
				break;
			case 0x09:
				printf("玖");
				break;
			case 0x0a:
				printf("拾");
				break;
			case 0x0b:
				printf("佰");
				break;
			case 0x0c:
				printf("仟");
				break;
			case 0x0d:
				if (wan_not_zero)
					printf("万");
				break;
			case 0x0e:
				printf("亿");
				break;
			case 0x0f:
				printf("元整");
				break;
			default:
				break;
		}
	}
	printf("\n");
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

