class Solution {
public:
    int strStr(string haystack, string needle) {
        if ( needle == "" )     //���򷵻�0
            return 0;
        int hlen = haystack.length();
        int nlen = needle.length();
        int i,j;
        for(i=0;i<hlen;i++){
            for(j=0;j<nlen;j++)
                if(haystack[i+j]!=needle[j])
                    break;      //�����Ͼͽ�������ƥ��
            if(j==nlen)
                return i;
        }
        return -1;
    }
};

