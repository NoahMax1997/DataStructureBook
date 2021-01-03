#include <iostream>
#include <string.h>
using namespace std;
int dis[100][100];
int n,m,start,sum=1;
int set[100];
void init(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++) dis[i][j]=1000000;
	}
	memset(set,sizeof(set),0);
	cout<<"请输入总共有多少个点和边的数量"<<endl;
	cin>>n>>m;
	int a,b,c;
	cout<<"请输入边两端端点和长度(端点从1开始)"<<endl;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		dis[a][b]=c;
		dis[b][a]=c; 
	}
	cout<<"请输入起始点"<<endl;
	cin>>start; 
	set[start]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<":相距"<<dis[i][j]<<endl;
//	}

}

void djs(){
	//寻找set集合以外离start最近的点
	cout<<"n:"<<n<<"m:"<<m<<"start"<<start<<endl;
	int index;
	while(sum!=n){
//		cout<<sum<<endl;
		int min=1000000;
		for(int i=1;i<=n;i++){
		if(set[i]) continue;
		if(dis[start][i]<min) min=dis[start][i],index=i;
	} 
		set[index]=1;
		cout<<index<<endl;
		sum++;
		//通过index去更新start 到其他点的距离
	for(int i=1;i<=n;i++){
		if(set[i]) continue;
		if(dis[start][i]>dis[start][index]+dis[index][i]){
			dis[start][i]=dis[start][index]+dis[index][i];
		}
		} 
	}
}

void output(){
	for(int i=1;i<=n;i++){
		if(i==start) continue;
		cout<<start<<i<<":最近距离为："<<dis[start][i]<<endl;
	}
}
int main (){
	init();
	djs();
	output();
	return 0;
} 
