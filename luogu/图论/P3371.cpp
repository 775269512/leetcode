#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;


bool vis[1000000];	//�Ƿ��߹��ýڵ�
long long ans[1000000];	//���ýڵ����С·��

//ͼ�Ķ���
struct edge {
	int next;
	int to;
	int w;
} edge[1000000];

/**��ʽǰ����**/
int head[1000000];//head[i]Ϊi��ĵ�һ����
int cnt=0;//ָ��
void addedge(int u,int v,int w) { //��㣬�յ㣬Ȩֵ
	edge[++cnt].next=head[u];//����cnt
	edge[cnt].to=v;
	edge[cnt].w=w;
	head[u]=cnt;
}


int main() {
	int m,n,s;
	cin>>m>>n>>s;	//����������ߵĸ�����������ı�š�
	for(int i=1; i<=n; i++) {
		ans[i]=2147483647;
	}
	ans[s]=0;	//��ʼ�ڵ����С·��Ϊ0

	for(int i=1; i<=n; i++) {//��ʽǰ����
		int a,b,c;
		cin>>a>>b>>c;
		addedge(a,b,c);
	}

	//����ͼ���ڱ�����xΪ�������б�ʱ��ֻ��Ҫ�������У� 	for(int i=head[x];i!=0;i=edge[i].next)

	/**Dijkstra**/
	int pos=s;	//��ǰλ��
	while(vis[pos]==0) {
		long long minn=2147483647;
		vis[pos]=1;	//pos�ڵ���ʹ�

		//����ͼ�ĵ�pos���ڵ�
		for(int i=head[pos]; i!=0; i=edge[i].next) {
			if(!vis[edge[i].to]&&ans[edge[i].to]>ans[pos]+edge[i].w) { //�����ǰ�ڵ�����edge[i].to�Ľڵ�û�����ʣ�����Ȩ�ش�����
				ans[edge[i].to]=ans[pos]+edge[i].w;	//��Ȩ�ص�����
			}
		}
		for(int i=1; i<=m; i++) {
			if(ans[i]<minn&&vis[i]==0) {
				minn=ans[i];
				pos=i;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	
	
	return 0;
}


/**Dijkstra
	1.����ans[100000]��ans[i]������i�����С����

	2.����bool����visit�������Ƿ�������� ans[���]=0,����ĸ�ֵΪinf

	ע�⣺����ķ��ʹ�����ָ���������Ϊ���ļ��������������ansֵ�����¹�

	3.����һ��curr������visit[current]=1�����ʹ������������ڵ�λ�ã���ʼֵΪ��㡣

	4. �о�������curr����ͨ�ĵĵ㣬����Щ��(i)��ansֵ���£�

	ans[i]=min(ans[i],ans[curr]+ans[i]=min(ans[i],ans[curr]+����Щ����Ҫ�Ļ��� ))

	5. �о�����û�й��ĵĵ㣬�ҵ�ansֵ��С�ĵ㣬��ֵ��curr��visit[current]=1�����ʹ���

	6 ���е㶼���ʹ���visit[i]��==1���������������ʱ��ans[i]�������㵽i�����·��
	α���룺
	bool vis[1000000];//�Ƿ���ʹ�
	int ans[1000000];
	int curr=���;
	memset(ans,0x7fffffff,sizeof(ans))
	while(vis[curr]==0)
	{
	vis[curr]=1;
	for(int i;�о�����curr��ͨ�ĵ㣩
	{
		ans[i]=min(ans[i],ans[curr]+k)//k�����curr�㵽i������·
	}
	int minn=2147483647;
	for(int i=1;i<=m;i++)//�о����е�
	{
		if(vis[i]==0&&ans[i]<minn)//û���ʹ���С
	    {
	    	minn=ans[i];//������Сֵ
	        curr=i;//������һ����
	    }
	}
	}**/
