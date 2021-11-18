//https://blog.csdn.net/lianwaiyuwusheng/article/details/79652697
/*题意：1-N按顺序压入栈，中间可以弹出数据。判断给定的序列是否可能是弹出的序列。

思路：建立一个栈，如果读入的数小于栈顶元素（肯定不可能，输出NO），如果读入的数为栈顶元素，则栈顶指针指向下一个数，继续判断，如果读入的数大于栈顶元素，继续压入元素。

如果所有的数都满足要求则输出yes

注意点：栈为空，需要压入一个数。栈溢出，输出也是NO。
*/
#include<stdio.h>
 
int main() 
{
	int N,M,K;
	int i,j,a[10];
	scanf("%d %d %d",&M,&N,&K);
	for(i=0;i<K;i++){
		for(j=0;j<N;j++)scanf("%d",&a[j]);
		int stack[1000]={0},top=0;//创建一个栈 
		int num=1;
		j=0,stack[0]=num;
		while(j<N){
			if(a[j]<stack[top])break;//比栈顶元素小 
			while(a[j]>stack[top]){  //需要继续压入数据 
				stack[++top]=++num;
			}
			if(top>=M)break; 
			if(a[j]==stack[top]){
				top--;
			}
			if(top<0)stack[++top]=++num;
			j++;
		}
		if(j==N)printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}