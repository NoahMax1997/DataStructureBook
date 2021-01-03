#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100];
int n;
void input(){
	printf("请输入序列的个数\n");
	scanf("%d",&n);
	printf("请输入整个序列\n");
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
}
int searchK(int beg,int end,int k){
	if(beg==end){
		if(k==1)
			return a[beg];
		else return -1;
	} 
	int mid=(beg+end)/2;
	if(k<=mid){
		return searchK(beg,mid,k);
	}
	else{
		return searchK(mid+1,end,k-(mid-beg+1));
	}
}
void output(){
	int k;
	printf("请输入k（k代表第k小的数\n");
	scanf("%d",&k);
	printf("%d\n",searchK(1,n,k)); 
}
int main (){
	input();
	output(); 
	return 0;
}
