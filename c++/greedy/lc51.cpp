#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<vector<int>> attack(n, vector<int>(n, 0));	//�ʺ󹥻���Χ
			vector<vector<string>> reses;	//���������
			vector<string> res; //�������

			for(int i=0; i<n; i++) {
				res.push_back("");
				res[i].append(n,'.');
			}

			backtrack(reses,res,n,attack, 0);

			return reses;
		}


//    vector<string> generateBoard(vector<string>& res, int n) {
//        auto board = vector<string>();
//        for (int i = 0; i < n; i++) {
//            board.push_back(res[i]);
//        }
//        return board;
//    }


		void backtrack(vector<vector<string>>& reses,vector<string>& res, int n,vector<vector<int>>& attack, int index) {
			if(index==n) {
//				vector<string> board = generateBoard(res, n);
//					cout<<"==========="<<endl;
//
//				for(int x=0; x<n; x++) {
//					cout<<res[x]<<endl;
//				}
				reses.push_back(res);
				return;
			}

			for(int i=0; i<n; i++) {
				
				if(attack[index][i] == 0) {
					
					
					vector<vector<int>> attack_temp= attack;	//�������attack��
					
					res[index][i] = 'Q';	// ��index�У���i�з�һ��Q;
					
				
					put_queen(index,i,attack); //����attack�ķ�Χ��

//					for(int j=0; j<n; j++) {
//						cout<<res[j]<<endl;
//					}
//					for(int k=0; k<n; k++) {
//						for(int j=0; j<n; j++) {
//							cout<<attack[k][j];
//						}
//						cout<<endl;
//					}
//					cout<<endl;

					backtrack(reses, res, n, attack, index+1);
					res[index][i] = '.';	// ��index�У���i�з�һ��Q;
					attack = attack_temp;
				}
			}

		}

		void put_queen(int x, int y, vector<vector<int>>& attack) {
			attack[x][y] = 1;//�����ܷ�
			int n = attack.size();
			for(int i=0; i<n; i++) {
				attack[x][i] = 1;//���ŵĲ��ܷ�
				attack[i][y] = 1;//���ŵĲ��ܷ�
				
				
				if(x-i>=0 && y-i>=0)
					attack[x-i][y-i] = 1;//���ϵĲ��ܷ�		
				if(x+i<n && y+i<n)
					attack[x+i][y+i] = 1;//���µĲ��ܷ�
				if(x+i<n && y-i>=0)
					attack[x+i][y-i] = 1;//���µĲ��ܷ�
				if(x-i>=0 && y+i<n)
					attack[x-i][y+i] = 1;//���ϵĲ��ܷ�	

			}

		}


};

int main() {
	int n=4;
	vector<vector<int>> attack(n, vector<int>(n, 0));	//�ʺ󹥻���Χ
	vector<vector<string>> res = Solution().solveNQueens(n);
	vector<string> ress= res[0];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<ress[i][j];
		}
		cout<<endl;
	}
	return 0;
}
