#include <iostream>
#include <algorithm>
#include <queue> 
using namespace std;
typedef struct node{
	double wei;
	double pri;
	double prip;//单位价格 
}Node; 
Node set[100]; 
int n;
int bag;
priority_queue<double> q;
double BEST=0,best=0;
bool cmp(Node a,Node b){
	return a.prip>b.prip;
}

void init(){
	cout<<"请输入总共物品的个数 以及背包容量"<<endl;
	cin>>n>>bag;
	cout<<"请依次输入物品重量和价格"<<endl;
	for(int i=1;i<=n;i++){
		cin>>set[i].wei>>set[i].pri;
		set[i].prip=set[i].pri/set[i].wei;
	}
	sort(set+1,set+n+1,cmp);
}
double bound(int i,double nowP,int nowBag){
	//求出i以后物品理论最优值 
	int j=i;
	while(j<=n&&set[j].wei<=nowBag){
		nowP+=set[j].pri;
		nowBag-=set[j].wei;
		j++;
	}
	if(j<=n){
		nowP+=nowBag*set[j].prip;
	}
	return nowP;
} 
void dfs(int i){
	if(i>n){
		best=BEST;
		cout<<best<<endl;
		return;
	} 
	if(set[i].wei<=bag){
		bag-=set[i].wei;
		BEST+=set[i].pri;
		dfs(i+1);
		bag+=set[i].wei;
		BEST-=set[i].pri;
	}
	if(bound(i+1,BEST,bag)>=best) 
	 dfs(i+1);
}
void output(){
	cout<<best<<endl;
}
int main (){
	init();
	dfs(1);
	output();
	return 0;
}
