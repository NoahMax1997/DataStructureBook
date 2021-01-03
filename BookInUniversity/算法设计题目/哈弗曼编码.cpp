#include <iostream>
#include <queue>
using namespace std;
typedef struct node{
	char ch;
	double fre;
}Node;
int n;
typedef struct node1{
	Node* left;
	Node* right;
}treeNode;
class cmp{
	public:
		bool operator() (Node a,Node b){
			return a.fre>b.fre;
		}
};
priority_queue <Node,vector<Node>,cmp> Q;
void init(){
	cout<<"请输入待编码字符个数\n";
	cin>>n; 
	cout<<"请输入编码的字符以及出现的频率\n"; 
	Node temp;
	while(n--){
		cin>>temp.ch>>temp.fre;
		Q.push(temp);
	}
	while(!Q.empty()){
		temp=Q.top();
		Q.pop();
		cout<<temp.ch<<" "<<temp.fre<<endl;
	}
}
int main (){
	init();
	return 0;
}
