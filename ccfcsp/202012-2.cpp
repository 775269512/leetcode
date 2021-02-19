#include<iostream>
#include<algorithm>
using namespace std;
 
typedef struct Node{
	int theta;
	int result;
}Node;
 
bool cmp(Node a,Node b){
	return a.theta<b.theta;
}
 
int main(){
	int m;
	Node node[100005];
	int flag0[100005]={0}; //��¼С��ÿ��λ�õ���ֵ��result=0�ĸ��� 
	int flag1[100005]={0}; //��¼���ڵ���ÿ��λ�õ���ֵ��result=1�ĸ��� 
	
	/*--����--*/ 
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>node[i].theta>>node[i].result;
	}
	sort(node,node+m,cmp); //��������� 
	
	int i=0,j=1;
	int temp0=0,temp1=0;
	/*--ͳ��С��ÿ����ֵ��result=0�ĸ���--*/ 
	while(j<m){
		if(node[j].theta==node[i].theta){
			j++;
			continue;
		}
		int temp=0;
		while(i<j){
			if(node[i].result==0)temp++;
			flag0[i]=temp0;
			i++;
		}
		temp0+=temp;
	}
	while(i<j){
		flag0[i]=temp0;
		i++;
	}
	/*--����ͳ��С��ÿ����ֵ��result=0�ĸ���--*/ 
	/*--����ͳ�ƴ��ڵ���ÿ����ֵ��result=1�ĸ���--*/ 
	for(int i=0;i<m;i++){
		if(node[m-1-i].result==1){
			temp1++;
		}
		flag1[m-1-i]=temp1;
	}
	
	//����flag0��flag1����ÿ����ֵ��׼ȷ������������Ķ�Ӧ����ֵ 
	int ans=0,num=0;
	for(int i=0;i<m;i++){
		if(flag0[i]+flag1[i]>=num){
			num=flag0[i]+flag1[i];
			ans=node[i].theta;
		}
	}
	cout<<ans;
}
