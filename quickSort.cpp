#include <iostream>
using namespace std;
int partition(int* a,int low,int high){
	int temp=a[low];
	while(high>low){
		while(high>low&&a[high]>=temp)  high--;
		a[low]=a[high];
		while(high>low&&a[low]<=temp)  low++;	
		a[high]=a[low];
	}
	a[low]=temp;
	return low;
}
void quickSort(int* a,int low,int high){
	if(low<high){
		int index=partition(a,low,high);
		for(int i=low;i<high+1;i++){
			cout<<a[i]<<" ";	
		}
		cout<<endl;
		quickSort(a,low,index);
		quickSort(a,index+1,high);	
	}
}
int main (){
	int n;
	cin>>n;
	int* a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	getchar();
	cout<<endl;
	return 0;
} 
