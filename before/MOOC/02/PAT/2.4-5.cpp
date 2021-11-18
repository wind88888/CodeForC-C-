//错误
//也可以用堆栈直接模拟
#include <stack>
#include <iostream>
using namespace std;
int main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while (k--) {
		bool flag = true;
		stack<int> s;
		int nt = n;
		int j = 1;
		while (nt--) {
			int num;
			scanf("%d", &num);
			if (flag) {
				while (s.empty() || s.top() != num) {
					s.push(j++);
					if (s.size() > m) { flag = false;break; }
				}
				if (flag && s.size() >= 1 && s.top() == num)
					s.pop();
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
		printf("---\n");
	}
	return 0;
}
//原文链接：https://blog.csdn.net/xijujie/article/details/52951460