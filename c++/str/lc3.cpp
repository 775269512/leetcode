#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //���������α�,���г���,����,����ʼ��Ϊ0
        int start(0),end(0),length(0),result(0);
        //ֻҪend<�ַ�����С
        while(end<s.size())
        {
            //��ע�ʹ���		//�ݴ��׸��ַ�char,
            //��ʵӦ�����ݴ�end��ָ����Ǹ�ֵ,��ʱ����index��ָ���ֵ�Ƚ�
            char tempChar=s[end];
            //����index,��ֻ���ڸı�start��ָ��һ��Ϊindex+1
            //��Ϊindex��������end��ֵ���,��û��ͳ�Ƶı�Ҫ��
            //forѭ��ֻ�����ж��Ƿ����
            //
            for(int index=start;index<end;index++)
            {
                //�ж��Ƿ�����ظ��ַ���
                if(tempChar==s[index])
                {
                    //start++;//���Ǵ����Ŷ,û���Ż���
                    //�������,��start�����ظ��ַ�indexָ�����һ�ַ�
                    start=index+1;
                    //���泤��
                    length=end-start;
                    /////////
                    //ǧ��ע��,������,����ж�Ӧ�ý�����
                    break;
                }
            }
            //��ʱ,end����ƶ�,ÿһһ��,����+1
            end++;
            length++;
            //���ظ��º��length,�������,��Ϊ��
            result=max(result,length);
        }
        return result;
    }
};

int main(){
	Solution s;
	int len  = s.lengthOfLongestSubstring("pwwkew");
	cout<<len;
	return 0;
}
