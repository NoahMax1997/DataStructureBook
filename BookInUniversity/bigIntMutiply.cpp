#include <iostream>
#include <math.h>
using namespace std;
long long X,Y,n;
void input(){
	cin>>X>>Y>>n;
} 
long long mutiply(long long x,long long y,int n){
	if(n==1){
		return x*y;
	}
	else{
		long long A,B,C,D,AC,BD;
		A=x/(int)pow(10,n/2);
		B=x%(int)pow(10,n/2);
		C=y/(int)pow(10,n/2);
		D=y%(int)pow(10,n/2);
		AC=mutiply(A,C,n-n/2);
		BD=mutiply(B,D,n/2);
		return AC*(int)pow(10,n)+BD+((A-B)*(D-C)+AC+BD)*pow(10,n/2);
	}
}
int main (){
	input();
	cout<<mutiply(X,Y,n)<<endl;
	return 0;
}
