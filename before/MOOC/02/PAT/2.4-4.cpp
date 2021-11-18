
#include <iostream>
#include <vector>
using namespace std;
bool judge(vector<int> v, int m);
int main(void) {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while (k--) {
		int i = 0;
		vector<int> v(n);
		while (i < n) 
			scanf("%d", &v[i++]);
		if (judge(v, m)) printf("YES\n");
		else printf("NO\n");
		v.clear();
	}
	return 0;
}
 
bool judge(vector<int> v, int m) {
	int t = v[0], t1 = v[0], n = v.size();
	for (size_t i = 0; i != n; ++i) {		
		if (v[i] >= t) {
			t = v[i];
			if (t - i > m) return false;
			t1 = v[i];
		}
		else{
			if(v[i] <= t1) t1 = v[i];
			else return false;
		}	
	}
	return true;
} 
//原文链接：https://blog.csdn.net/xijujie/article/details/52951460