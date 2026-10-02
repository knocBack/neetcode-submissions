class Solution {
public:
    // paste the LeetCode / NeetCode function signature here
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1, mid = 0;
        int ans = nums[l];
        while(l<r){
            mid = l + (r-l)/2;
            ans = min(ans, nums[mid]);
            ans = min(ans, min(nums[l], nums[r]));
            if(nums[l] >= nums[mid]){
                r = mid-1; // 4 5 0 1 2 , 0 4 2
            }
            else{
                l = mid+1; // 4 5, 0 1 0
            }
        }
        return ans;
    }
};