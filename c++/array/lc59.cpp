class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> ans(n,vector<int>(n,0));
			if(n==0) return ans;
			int u=0;       //�ϱ߽�
			int d=n-1; //�±߽�
			int l=0;           //��߽�
			int r=n-1;//�ұ߽�
			int c=1;
			int j; 
			while(c<=n*n) {
				for(j=l; j<=r; j++) { //�����ϱ�
					ans[u][j] = c++;
				}
				u++;
					
				for(j=u; j<=d; j++) { //�����ұ�
					ans[j][r] = c++;
				}
				r--;
				for(j=r; j>=l; j--) { //�����±�
					ans[d][j] = c++;
				}
				d--;
				for(j=d; j>=u; j++) { //�������
					ans[j][l] = c++;
				}
				l++;
			}
			return ans;
		}
};
