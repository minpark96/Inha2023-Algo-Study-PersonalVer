class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // size�� 1�̰ų� rotate�� �Ͼ�� ���� ���
        if (n == 1 || nums[0] < nums[n - 1]) return nums[0];

        int l = 0, r = n - 1;
        while (l < r) 
        {
            int m = l + (r - l) / 2;
            // nums[l], nums[m], nums[r] ���� ��.
            // nums[l] < nums[r]�� ��쿡 ���� ����ó���� ����
            if (nums[l] <= nums[m] && nums[l] > nums[r]) l = m + 1;
            else r = m;
        }
        // l: �ּ� index
        return nums[l];
    }
};