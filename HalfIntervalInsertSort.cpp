#include <iostream>
using namespace std;
void halfIntervalInsertSort(int* start,int* end){
	int temp;
	for(int* i=start+1;i!=end;i++){
		temp=*i;
		int* low=start;int* high=i-1;int* mid;
		while(low<=high){
			mid=low+(high-low)/2;
			if(*mid>*i) high=mid-1;
			else low=mid+1;
		}
		for(int* j=i-1;j>=high+1;j--){
			*(j+1)=*j;
		}
		*(high+1)=temp;
	} 
} 
void coutIntList(int* start,int* end){
	for(int* i=start;i!=end;i++){
		cout<<*i<<" ";
	}
	cout<<endl;
}
int main (){
	int*a=new int[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>*(a+i); 
	}
	coutIntList(a,a+n);
	halfIntervalInsertSort(a,a+n);
	coutIntList(a,a+n);
	return 0;
} 
