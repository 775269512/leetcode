# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		vector<int> nums(size1+size2);
		int size = size1+ size2;
        //��������i1��i2�ֱ��ʾ��������nums1��nums2���±꣬i��ʾ����nums�±�
        int i1 = 0, i2 = 0, i = 0;

        //ѭ��ֱ��i1��i2������������ĩβ
        while (i1 < size1 || i2 < size2) {
            //nums1��Ԫ�ش���nums2��i2�ѱ�����ĩβ
            if (i2 >= size2 || (i1 < size1 && nums1[i1] <= nums2[i2])) {  
                nums[i++] = nums1[i1++];
            }
            //nums2��Ԫ�ش���nums1��i1�ѱ�����ĩβ
            else {
                nums[i++] = nums2[i2++];
            }
        }
		return (size1+size2) % 2 == 0 ? ((double)nums[size / 2 - 1] + (double)nums[size / 2]) / 2 : (double)nums[size/2];
    }
};

int main(){
	vector<int> num1 = {1,3,5,9};
		vector<int> num2 = {3,8,9};

	Solution().findMedianSortedArrays(num1,num2);
	return 0;
}
