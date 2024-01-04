class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // size가 1이거나 rotate가 일어나지 않은 경우
        if (n == 1 || nums[0] < nums[n - 1]) return nums[0];

        int l = 0, r = n - 1;
        while (l < r) 
        {
            int m = l + (r - l) / 2;
            // nums[l], nums[m], nums[r] 값을 비교.
            // nums[l] < nums[r]인 경우에 대한 예외처리를 포함
            if (nums[l] <= nums[m] && nums[l] > nums[r]) l = m + 1;
            else r = m;
        }
        // l: 최소 index
        return nums[l];
    }
};