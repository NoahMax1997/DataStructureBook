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
	cout<<"�������ܹ��ж��ٸ���ͱߵ�����"<<endl;
	cin>>n>>m;
	int a,b,c;
	cout<<"����������˶˵�ͳ���(�˵��1��ʼ)"<<endl;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		dis[a][b]=c;
		dis[b][a]=c; 
	}
	cout<<"��������ʼ��"<<endl;
	cin>>start; 
	set[start]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<":���"<<dis[i][j]<<endl;
//	}

}

void djs(){
	//Ѱ��set����������start����ĵ�
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
		//ͨ��indexȥ����start ��������ľ���
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
		cout<<start<<i<<":�������Ϊ��"<<dis[start][i]<<endl;
	}
}
int main (){
	init();
	djs();
	output();
	return 0;
} 
