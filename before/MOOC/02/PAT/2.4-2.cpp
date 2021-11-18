//https://blog.csdn.net/qq_39339575/article/details/89341925
#include<iostream>
#include<stack>
using namespace std;
int main() {
    int max, num, n;
	stack <int> s;
    cin >> max >> num >>n;
    while(n--) {
        int j = 0;
        int temp;
        for(int i = 0; i< num; i++) {
            cin >> temp;
			if(s.empty()) s.push(++j);
            while(temp !=  s.top()) {
                s.push(++j);
				if(s.size() > max) {
					break;
				}
            }
            if(s.size() < 0 || s.size() > max) {   //保证不影响下一次的检查
			    for(i++; i < num; i++) cin >> temp;
                break;
            }
            s.pop();
        }
        if(s.size() == 0) 
            printf("YES\n");
		else {
			printf("NO\n");
			while(!s.empty()) s.pop();
		}
    }
	return 0;
}