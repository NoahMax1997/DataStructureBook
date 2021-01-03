#include <iostream>
using namespace std;
double findTheDis(int i,int j){
	//¼ÆËãi£¬jµÄÏÒ³¤ 
	return 0;
} 
int n;
int dp[100][100];
void input(){
	cin>>n;
}
void cut(){
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			dp[i][j]=100000;
			for(int k=i;k<j;k++){
				if(dp[i][j]<dp[i][k]+dp[k+1][j]+findTheDis(i,j)+findTheDis(k,j)+findTheDis(i,k)){
					dp[i][j]=dp[i][k]+dp[k+1][j]+findTheDis(i,j)+findTheDis(k,j)+findTheDis(i,k);
				}
			}
		}
	}
}
void output(){
	
}
int main(){
	
	
	return 0;
} 
