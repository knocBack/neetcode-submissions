class Solution {
public:
    // paste the LeetCode / NeetCode function signature here
    int search(vector<int>& nums, int target) {
        int l,r,n,mid,val;
        n = nums.size();
        l = 0; r = n-1;
        while(l<=r){
            mid = l + (r-l)/2;
            val = nums[mid];
            if(val == target) return mid;
            // check mid is in left or right branch
            if(nums[l] <= val){ // mid is in left branch
                // target is in left subset
                if(target < val && target >= nums[l]){
                    r = mid-1;
                }
                // target is in right subset
                else{
                    l = mid+1;
                }
            }
            else{ // mid is in right branch
                // target is in right subset
                if(target > val && target <= nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};