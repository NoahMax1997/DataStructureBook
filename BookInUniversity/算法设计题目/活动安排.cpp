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
	cout<<"�������ܹ��ж��ٸ��"<<endl;
	cin>>n;
	cout<<"����������ʼ����ʱ��"<<endl;
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
	cout<<"����������"<<sum<<"���"<<endl;
	cout<<"�ɰ��ŵĻ�ǣ�";
	for(int i=0;i<index;i++) cout<<set[i]<<" ";
	cout<<endl;
}
int main (){
	init();
	select();
	output();
	return 0;
} 
