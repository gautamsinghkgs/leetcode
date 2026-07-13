class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,  n= nums.size() - 1;

        while (low <= n) {
            int mid = low + (n - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                n = mid - 1;
        }
        return low;
    }
};