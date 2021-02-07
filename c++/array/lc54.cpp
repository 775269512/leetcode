#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(!matrix.size()||!matrix[0].size()) return ans;
        int u=0;       //�ϱ߽�
        int d=matrix.size()-1; //�±߽�
        int l=0;           //��߽�
        int r=matrix[0].size()-1;//�ұ߽�
        int i,j;
        while(true){   
            for(j=l;j<=r;j++){ //�����ϱ�
                ans.push_back(matrix[u][j]);
            }
            if(++u>d) break;     //�ж����±߽��м仹��û��δ������Ԫ��
            for(i=u;i<=d;i++){  //�����ұ�
            	ans.push_back(matrix[i][r]);
			}
			if(--r<l) break;    //�ж����ұ߽��м仹��û��δ������Ԫ��
			for(j=r;j>=l;j--){//�����±�
				ans.push_back(matrix[d][j]);
			}
			if(--d<u) break;  //�ж����±߽��м仹��û��δ������Ԫ��
			for(i=d;i>=u;i--){//�������
			    ans.push_back(matrix[i][l]);	
			}
			if(++l>r) break;//�ж����ұ߽��м仹��û��δ������Ԫ��
			
        }
        return ans;
		}
};


int main(){
	
	return 0;
}
