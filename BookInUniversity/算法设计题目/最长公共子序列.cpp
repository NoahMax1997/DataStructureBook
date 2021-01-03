#include <iostream>
#include <string.h>
using namespace std;
char strX[100],strY[100];
int m,n;
int dp[100][100];
void input(){
	printf("ÇëÊäÈëÁ½¸ö×Ö·û´®\n");
	scanf("%s%s",strX,strY);
	m=strlen(strX),n=strlen(strY);
	memset(dp,0,sizeof(dp));
} 
void LSC(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(strX[i-1]==strY[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
}
int main (){
	while(1){
		input();
		LSC();
		printf("%d\n",dp[m][n]);	
	}
	return 0;
} 
