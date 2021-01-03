#include <iostream> 
using namespace std;
int n;
typedef struct arc{
	int n;
	int m;
}Arc;
Arc set[100];
int dp[100][100];//dp[i][j] 表示i-j个矩阵合并需要的运算次数 
int sum[100][100]={0};
void init(){
	cout<<"请输入连乘的矩阵个数\n";
	cin>>n;
	cout<<"请依次输入矩阵的信息\n";
	for(int i=0;i<n;i++){
		cout<<"输入矩阵的行列数\n";
		cin>>set[i].n>>set[i].m;
	} 
	cout<<"那么最优的计算次序是：\n"; 
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
