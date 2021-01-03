#include <iostream> 
#include <string.h> 
using namespace std;
int sum,n;
typedef struct thing{
	int w;
	int p;
}Thing;
Thing T[100];
int dp[100][100] ;//表示背包重量为j在前i个物品中 选择可得最大价值 
void init(){
	cout<<"请输入背包总重量\n";
	cin>>sum;
	cout<<"请输入物品数量\n";
	cin>>n;
	cout<<"请输入物品的重量和价格\n";
	for(int i=1;i<=n;i++)  cin>>T[i].w>>T[i].p; 
	memset(dp,0,sizeof(dp));
}
int main (){
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<T[i].w)  dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-T[i].w]+T[i].p);
		}
	}
	cout<<dp[n][sum]<<endl;
	return 0;
} 
