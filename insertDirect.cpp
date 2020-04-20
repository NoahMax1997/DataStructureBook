#include <iostream>
using namespace std;
void insertSort(int* start,int* end){
	int temp;
	for(int* index=start+1;index!=end;index++){
		if(*index<*(index-1)){
			temp=*index;
			int* j;
			for( j=index-1;*j>temp&&j>=start;j--){
				*(j+1)=*j;
			}
			*(j+1)=temp;
		}
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
	insertSort(a,a+n);
	coutIntList(a,a+n);
	return 0;
} 
