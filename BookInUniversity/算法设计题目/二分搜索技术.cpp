#include <iostream>
using namespace std;
int n,temp;
int L[100];
int co[100];
void input(){
	scanf("%d",&n);
	temp=n;
	for(int i=0;i<n;i++){
		scanf("%d",L+i);
	}
}
void adjustHeap(int s,int m){
	int rc=L[s];
	for(int j=s*2+1;j<=m;j=j*2+1){
		if(j<m&&L[j]<L[j+1]) j++;
		if(rc>L[j]) break;
		L[s]=L[j],s=j;
	}
	L[s]=rc;
} 
void output();
void heapSort(int n){
	for(int i=n/2-1;i>=0;i--){
		adjustHeap(i,n-1); 
	}
	output();
	for(int i=n-1;i>=1;i--){
//		cout<<L[0]<<L[i]<<endl;
		output(); 
		cout<<L[0]<<L[i]<<endl;
		L[0]=L[0]+ L[i];
		L[i]=L[0]-L[i];
		L[0]=L[0]-L[i];
		output(); 
		adjustHeap(0,i-1);
	}
}
void quickSort(int low,int high){
	//快速排序 
	int key=L[low];
	int i=low+1,j=high;
	cout<<i<<j<<endl;
	if(i<j){
		while(1){
			while(i<high&&L[i]<key) i++;
			while(L[j]>key) j--;
			if(i>=j) break;
			L[i]=L[i]+L[j];
			L[j]=L[i]-L[j];
			L[i]=L[i]-L[j];
//			cout<<L[i]<<" "<<L[j]<<endl;
		}
		key=L[j];
		L[j]=L[low];
		L[low]=key;
		quickSort(low,j-1);
		quickSort(j+1,high);	
	}
}
void mergeSort(int low,int high){
	//归并排序 
	if(low>=high) return;
	int mid=(low+high)/2;
//	cout<<mid<<endl;
//	cout<<low<<high<<endl;
	mergeSort(low,mid);
	mergeSort(mid+1,high);
	int i=low,j=mid+1,index=0;
	while(i<=mid&&j<=high){
		if(L[i]<L[j]){
			co[index++]=L[i++];
		}
		else{
			co[index++]=L[j++];
		}
	}
	while(i<=mid) co[index++]=L[i++];
	while(j<=high) co[index++]=L[j++];
	index=0;
	while(low<=high){   //将合并好的low 至high 部分拷贝至L 
		L[low++]=co[index++];
	}
}
int binarySearch(int num,int low,int high){
	//二分搜索 
	int mid=(low+high)/2;
	if(low>high) return -1;
	if(num>L[mid]){
		return binarySearch(num,mid+1,high);
	}
	else if(num<L[mid]){
		return binarySearch(num,low,mid-1);
	}
	else return mid;
}
void output(){
	for(int i=0;i<temp;i++){
		printf("%d ",L[i]);
	}
	printf("\n");
}
int main (){
	input();
//	quickSort(0,n-1);
//	mergeSort(0,n-1);
	heapSort(n);
//	cout<<binarySearch(2,0,n-1);
	output();
	return 0;
}
