#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int sum=0;
typedef struct node{
	int start;
	int end;
}Node;
Node party[100];
int set[100];
int index=0;
bool cmp(Node a,Node b){
	return a.end<b.end;
}
void init(){
	cout<<"请输入总共有多少个活动"<<endl;
	cin>>n;
	cout<<"请输入各活动开始结束时间"<<endl;
	for(int i=0;i<n;i++) cin>>party[i].start>>party[i].end;
	sort(party,party+n,cmp);
}
void select(){
	int time=0;
	for(int i=0;i<n;i++){
		if(party[i].start>=time){
			sum++,time=party[i].end;
			set[index++]=i;
		} 
		
	}
} 
void output(){
	cout<<"最多可以容纳"<<sum<<"个活动"<<endl;
	cout<<"可安排的活动是：";
	for(int i=0;i<index;i++) cout<<set[i]<<" ";
	cout<<endl;
}
int main (){
	init();
	select();
	output();
	return 0;
} 
