class Solution {
public:
    int minCut(string s) {
        int len=s.length();

        // ״̬���壺dp[i]��ǰ׺�Ӵ� s[0:i] ���������� i �����ַ�������Ҫ������ٷָ����
        int dp[len];

        // 1 ���ַ����ָ� 0 �Σ�
        // 2 ���ַ����ָ� 1 �Σ�
        // 3 ���ַ����ָ� 2 ��
        // ��ʼ����ʱ�����ó�Ϊ������ָ����
        for(int i=0;i<len;i++){
            dp[i]=i;
        }

        //������ά�������ڼ�¼�Ӵ�s[a:b]�Ƿ�Ϊ���Ĵ�����һ��ʼȫ����ʼ��Ϊfalse�����Է���a<=b��
        vector<vector<bool>> checkPalindrome(len, vector<bool>(len, false));
        
        //�����������ַ���s����������¼�Ӵ�s[a:b]�Ƿ�Ϊ���Ĵ�
        for(int right=0;right<len;right++){
            for(int left=0;left<=right;left++){
                if(s[left]==s[right] && (right-left<=2 || checkPalindrome[left+1][right-1])){ // "right-left<=2" �� "checkPalindrome[left+1][right-1]"λ�ò��ɻ�
                    checkPalindrome[left][right]=true;
                }
            }
        }

        // ״̬ת�Ʒ��̣�
        // dp[i] = min(dp[j] + 1 if s[j + 1: i] �ǻ��� for j in range(i))
        for(int i=0;i<len;i++){
            if(checkPalindrome[0][i]){
                dp[i]=0;
                continue;
            }
            for(int j=0;j<i;j++){
                if(checkPalindrome[j+1][i]){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }

        return dp[len-1];
    }
};

