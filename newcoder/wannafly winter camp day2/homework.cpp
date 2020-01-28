#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int question_cnt, num, min_op, max_op;
int random(int l, int r) {
	return rand() % (r - l + 1) + l;
}
int check(int* x, int* y) {
	int rhs = x[0];
	for (int i = 0; i < 4; ++i) {
		rhs += x[i + 1] * y[i];
		if (rhs <= 0 || rhs >= 20)
			return -1;
	}
	return rhs;
}
int main()
{
	//fopen("1.out", "w", stdout);
	srand((int)time(0));
	printf("输入每个题目的最少运算符数量和最多运算符数量:\n");
	scanf("%d%d", &min_op, &max_op);
	printf("输入运算结果范围\n");
	scanf("%d", &num);
	printf("输入题目数量\n");
	scanf("%d", &question_cnt);
	for(int i = 1; i <= question_cnt; ++i) {
		int ans, cnt, x[max_op + 1], y[max_op + 1];
		while (true) {
			cnt = random(min_op, max_op);
			memset(x, 0, sizeof(x));
			memset(y, 0, sizeof(y));
			x[0] = random(1, num - 1);
			for (int j = 0; j < cnt; ++j) {
				int opt = random(0, 1);
				if (opt)
					y[j] = 1;
				else
					y[j] = -1;
				x[j + 1] = random(1, num - 1);
			}
			if (check(x, y) != -1) {
				ans = check(x, y);
				break;
			}
		}
		printf("第%d题：%d", i, x[0]);
		for (int i = 0; i < cnt; ++i) {
			printf("%c%d", y[i] == -1 ? '-' : '+', x[i + 1]);
		}
		printf(" = %d\n", ans);
	}
}