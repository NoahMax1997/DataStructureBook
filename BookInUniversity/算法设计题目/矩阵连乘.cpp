#include <iostream> 
using namespace std;
int n;
typedef struct arc{
	int n;
	int m;
}Arc;
Arc set[100];
int dp[100][100];//dp[i][j] ��ʾi-j������ϲ���Ҫ��������� 
int sum[100][100]={0};
void init(){
	cout<<"���������˵ľ������\n";
	cin>>n;
	cout<<"����������������Ϣ\n";
	for(int i=0;i<n;i++){
		cout<<"��������������\n";
		cin>>set[i].n>>set[i].m;
	} 
	cout<<"��ô���ŵļ�������ǣ�\n"; 
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=0;
		}
	}
}
int main (){
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			dp[i][j]=dp[i+1][j]+set[i].n*set[i].m*set[j].m;
			sum[i][j]=i;
			for(int k=i;k<j;k++){
				if(dp[i][j]<dp[i][k]+dp[k+1][j]+set[i].n*set[k].m*set[j].m){
					dp[i][j]=dp[i][k]+dp[k+1][j]+set[i].n*set[k].m*set[j].m;
					sum[i][j]=k;
				}
			}
		}
	}
	return 0;
}
