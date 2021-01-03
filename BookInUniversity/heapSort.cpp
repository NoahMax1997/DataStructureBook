#include <iostream>
using namespace std;
int n;
int L[100];
void input(){
	cout<<"��������������鳤��"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>L[i];
	}
}
void output(){
	for(int i=0;i<n;i++){
		cout<<L[i]<<" ";
	}
	cout<<endl;
} 
void adjustHeap(int s,int m){
	//s�����������ʼ���꣬m�����������������
	int rc=L[s];
	for(int j=s*2+1;j<=m;j=j*2+1){
		if(j<m&&L[j]<L[j+1]) j++;
		if(rc>L[j])   break;
		L[s]=L[j],s=j;
 	} 
 	L[s]=rc;
}
void heapSort(int maxIndex){
	for(int i=(maxIndex+1)/2-1;i>=0;i--){
		adjustHeap(i,maxIndex);
	}
	for(int i=maxIndex;i>=1;i--){
		printf("����ǰ");
		output();
		printf("������");
		L[0]=L[0]+L[i];
		L[i]=L[0]-L[i];
		L[0]=L[0]-L[i];
		output();
		adjustHeap(0,i-1);
		printf("t������");
	}
}
int main (){
	input();
	heapSort(n-1);
	output();
	return 0;
}
