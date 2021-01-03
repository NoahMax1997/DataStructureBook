#include <iostream>
#include <string.h>
using namespace std;
int strX[100],strY[100],ans[200];
int* move(int* str,int n){
	int* ret=new int [200];
	memset(ret,0,sizeof(ret));
	int i=0;
	for(i=0;str[i]!=0;i++);
	for(;i<200;i++){
		ret[i-n]=str[i];
	}
	return ret;
}
int* intAnd(int* x,int* y){
	int* ret=new int[200];
	int s1,s2,flag=0;
	for(s1=0;x[s1]!=0;s1++);
	for(s2=0;x[s2]!=0;s2++);
	int i;
	for(i=199;i>=s1||i>=s2;i--){
		int temp=x[i]+y[i]+flag;
		if(temp>=10)   ret[i]=temp-10,flag=1;
		else ret[i]=temp;
	}
	if(flag){
		ret[i]=flag;
	}
	return ret;
}
int* mutiply(int* str1 ,int low1,int high1,int* str2,int low2,int high2){ 
    int* ret=new int[200];
    int* ans=new int [200];
	if(low1==high1&&low2==high2){
		int temp=str1[low1]*str2[low2];
		if(temp<10) ret[199]=temp;
		else{
			ret[199]=temp/10;
			ret[198]=temp%10;
		}	
	}
	else{
		int mid1=(low1+high1)/2,mid2=(low2+high2)/2;
		int* ans1=mutiply(str1,low1,mid1,str2,low2,mid2);//AC 
		int* ans2=intAdd(mutiply(str1,low1,mid1,str2,mid2+1,high2),mutiply(str1,mid1+1,high1,str2,low2,mid2));//AD+BC 
		int* ans3=mutiply(str1,mid1+1,high1,str2,mid2+1,high2);//BD
		ans1=move(ans1,high1-low1+1);
		
	}
	
	
}
int main (){
		
	return 0;
}
