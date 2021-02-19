/**P4779��Dijkstra+���Ż�+ǰ���Ƕ�ȡ**/
#include<queue>
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#define mp(x,y) make_pair(x,y)
using namespace std;

const int MaxN = 100010, MaxM = 500010;
priority_queue<pair<int, int> > q;//��һ����·���ĳ��ȣ��ڶ����ǽڵ�ı��
//���ȶ���Ϊ������ ȡ�����һ����С 

int n,m,s;
	
	
//���ߵĶ���
struct edge {
	int next, to, w;
} edge[MaxM];

//��ʽǰ����
int head[MaxN], cnt;//headΪ�ڽӱ�Ľڵ�ͷ��cnt��ȫ��ָ��

void addEdge(int u, int v, int w) {
	edge[++cnt].next = head[u];
	edge[cnt].w = w;
	edge[cnt].to = v;
	head[u] = cnt;
}


bool vis[MaxN];	//�Ƿ��߹��ýڵ�
int ans[MaxN];	//���ýڵ����С·��


void dijkstra() {
	for(int i=1; i<=n; i++) {//����Ϊ����� 
		ans[i]=2147483647;//0x3f 
	}

	ans[s] = 0;
	q.push(mp(0,s));
	while(!q.empty()){
		int u=q.top().second;//��ǰ�ڵ� 
		q.pop();//��Ҫu
		
		if(vis[u])	//			�������������ѭ�� 
			continue;
		vis[u] = 1;
		for(int i=head[u]; i;i=edge[i].next){
			int v=edge[i].to,w=edge[i].w;
			if(ans[v]>ans[u]+w) {
				ans[v] = ans[u]+w;
				q.push(mp(-ans[v],v));//����Ϊ������Ҫ������Ҫ���һ�� 
			}
		} 
	}
	
}


int main() {

	cin>>n>>m>>s;		//����һ�� n ���㣬m ������ߵĴ��Ǹ�Ȩͼ���������� s ��������ÿ����ľ��롣
	int u,v,w;
	for(int i=1; i<=n; i++) {
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}

//	//������һ���ڵ���ٱ�
//	for(int i=head[1];i!=0;i=edge[i].next){
//		cout<<edge[i].to<<" ";
//	}
	dijkstra();
	
	 for(int i=1;i<=n;i++){
	 	cout<<ans[i]<<' ';
	 }


	return 0;
}
