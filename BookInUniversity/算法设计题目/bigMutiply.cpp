#include <iostream>
#include <string.h>
#include <stdio.h>
/*这个大整数乘法没有输入要求、用字符串实现的*/ 
using namespace std;
string strA,strB;
void input(){
	printf("请输入两个整数\n");
	cin>>strA>>strB;

//	swap(strA,strB);
//	cout<<strA<<" "<<strB<<endl; 
}
void swap(string& str1,string& str2){
	//确保str1>str2 
	int len1=str1.length(),len2=str2.length();
	if(len1<len2){
		string temp=str1;
		str1=str2;
		str2=temp;
	}
	else if(len1==len2){
		if(str1<str2){
			string temp=str1;
			str1=str2;
			str2=temp;
		}
	}
}
string getBigger(string str,int n){
	str.insert(str.length(),n,'0');
	return str;
}
string strAnd(string str1,string str2){
	//字符串加法 
	string ret;
	int len1=str1.length(),len2=str2.length();
	int flag=0;
	if(len1>len2){
		str1.insert(0,1,'0');
		str2.insert(0,len1-len2+1,'0');
		for(int i=str1.length()-1;i>=0;i--){
			int temp=(str1[i]-'0'+str2[i]-'0'+flag)/10;
			str1[i]=(str1[i]-'0'+str2[i]-'0'+flag)%10+'0';
			flag=temp;
		}
		ret=str1;
	}
	else{
		str2.insert(0,1,'0');
		str1.insert(0,len2-len1+1,'0');
		for(int i=str2.length()-1;i>=0;i--){
			int temp=(str1[i]-'0'+str2[i]-'0'+flag)/10;
			str2[i]=(str1[i]-'0'+str2[i]-'0'+flag)%10+'0';
			flag=temp;
		}
		ret=str2;	
	}
	if(ret.at(0)=='0')  ret.erase(0,1);
	return ret;
}
string  strExc(string str1,string str2){
	//字符串减法 
	string ret;
	int len1=str1.length(),len2=str2.length();
	int flag=0;
	swap(str1,str2);
	str2.insert(0,len1-len2,'0');
	for(int i=str1.length()-1;i>=0;i--){
		int temp=str1[i]-str2[i]-flag;
		if(temp<0){
			flag=1;
			str1[i]=temp+10+'0';
		}
		else{
			flag=0;
			str1[i]=temp+'0';
		}
	}
	int index=str1.find_first_not_of('0');
	if(index==-1) return "0";
	else ret=str1.substr(index,str1.length()-index);
	return ret;
}
string strMutiply(string str1,string str2){
	int len1=str1.length(),len2=str2.length(),mid1=(len1-1)/2,mid2=(len2-1)/2;
	string A,B,C,D,ret="0",AC,AD,BC,BD;
	if(len1==1&&len2==1){
		ret.clear();
		ret.insert(0,1,(str1[0]-'0')*(str2[0]-'0')+'0');
		return ret;
	}
	else if(len1==1&&len2>1){
		if(str1=="0") return "0";
		else{
			ret="0";
			for(int i=0;i<str1[0]-'0';i++){
				ret=strAnd(ret,str2);
			}
			return ret;
		}
	}
	else if(len2==1&&len1>1){
		if(str2=="0") return "0";
		else{
			ret="0";
			for(int i=0;i<str2[0]-'0';i++){
				ret=strAnd(ret,str1);
			}
			return ret;
		}
	}
	A=str1.substr(0,mid1+1);
	B=str1.substr(mid1+1,len1-mid1-1);
	C=str2.substr(0,mid2+1);
	D=str2.substr(mid2+1,len2-mid2-1);
	AC=strMutiply(A,C);
	AD=strMutiply(A,D);
	BC=strMutiply(B,C);
	BD=strMutiply(B,D);
	AC=getBigger(AC,mid1+2+mid2);
	AD=getBigger(AD,mid1+1);
	BC=getBigger(BC,mid2+1);
	ret=strAnd(strAnd(AC,AD),strAnd(BC,BD));
	return ret;
}
int main (){
	input();
//	string str="123";
//	str.insert(0,1,'k');
//	cout<<str<<endl;
//		cout<<strAnd(strA,strB)<<endl;
	cout<<strMutiply(strA,strB)<<endl;	
	return 0;
}
