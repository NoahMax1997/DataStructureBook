#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef struct point{
	int x;
	int y;
}Point; 
Point S[100];
int n;
bool cmp1(Point a,Point b){
	return a.x<b.x;
}
bool cmp2(Point a,Point b){
	return a.y<b.y;
}
void initPoint(){
	printf("请输入点的个数");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>S[i].x>>S[i].y;
	}
	sort(S,S+n,cmp1);
}
double dis(Point a,Point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double closePoint(Point* Set,int beg,int end,int n){
	//已经排好序 
	int midNum=0;
	for(int i=beg;i<=end;i++){
		midNum+=Set[i].x;
	}
	midNum/=n;
	if(n==2){
		return dis(Set[beg],Set[end]);
	}
	else if(n==3){
		double d1=dis(Set[beg],Set[beg+1]);
		double d2=dis(Set[beg],Set[beg+2]);
		double d3=dis(Set[beg+2],Set[beg+1]);
		return min(min(d1,d2),min(d2,d3));
	}
	else{
		int mid=(beg+end)/2;
		double d1=closePoint(Set,beg,mid,n/2);
		double d2=closePoint(Set,mid+1,end,n-n/2); 
		double d=min(d1,d2);
		Point P1[100],P2[100];
		int sum1=0,sum2=0;
		for(int i=beg;i<=end;i++){
			if(Set[i].x<=midNum&&abs(Set[i].x-midNum)<=d){
				P1[sum1++]=Set[i];
			}
			else if(Set[i].x>midNum&&abs(Set[i].x-midNum)<=d){
				P1[sum2++]=Set[i];
			}
		}
		double best=100000000;
		for(int i=0;i<sum1;i++){
			for(int j=0;j<sum2;j++){
				if(abs(P2[j].y-P1[i].y)<=d){
					if(dis(P1[i],P2[j])<best){
						best=dis(P1[i],P2[j]);
					}
				}
			}
		}
		return min(d,best);
	}
}
int main (){
	initPoint();
	cout<<closePoint(S,1,n,n)<<endl;
	return 0;
}
