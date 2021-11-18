
#include<iostream>
#define countof_macro(x) (sizeof(x)/sizeof(x)[0]);
using namespace std;
 
int middle_select(int x[],int y[],int x_low,int x_high,int y_low,int y_high){
	if(x_low==x_high){
		return x[x_low];
	}else if(y_low==y_high){
		return y[y_low];
	}
	
	int x_mid,y_mid;
	x_mid=(x_low+x_high)/2;
	y_mid=(y_low+y_high)/2;
	
	if(x[x_mid]>y[y_mid]){
		x_high=x_mid;
		y_low=y_mid;
	}else if(x[x_mid]<y[y_mid]){
		x_low=x_mid;
		y_high=y_mid;
	}else{
		return x[x_mid];
	}
	middle_select(x,y,x_low,x_high,y_low,y_high);
}
 
int main(){
     int x[]={1,4,6,10,22,43,44};
     int y[]={2,9,14,23,42,89,99};
	
	int x_low,x_high,y_low,y_high;
	x_low=0;
	x_high= countof_macro(x);
	y_low=0;
	y_high= countof_macro(y);
	
	int midNum;
	midNum=middle_select(x,y,x_low,x_high,y_low,y_high);
	cout<<midNum<<endl;
	system("pause");
	return 0;
}