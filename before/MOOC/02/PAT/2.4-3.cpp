//https://blog.csdn.net/qq_39339575/article/details/89341925
#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack <int> s;
    int num, capcity, testnum;
    cin >> capcity >> num >> testnum;
    for(int i = 0; i < testnum; i++){
        int n = 1;
        int cnt = 0;
        for(int k = 0; k < num; k++)
        {
            int temp;
            cin >> temp; cnt ++;
            if(s.size() == 0)  s.push(n++);
            while(temp != s.top()){
                s.push(n++);
                if(s.size() > capcity)
                     break;
            } 
            if(s.size() > capcity){
                for(int j = cnt; j < num; j++){
                    int temp;
                    cin >> temp;
                }
                break;
            }
            s.pop();
        }
        if(s.size() > capcity) cout << "NO" << endl;
        else cout << "YES" << endl;
        while(s.size() > 0) s.pop();
    }
    return 0;
}