class Solution {
public:
    // paste the LeetCode / NeetCode function signature here
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> vals;
        int n = nums.size();
        int l,r,sum,target,prev;
        for (int i=0; i<n; i++){
            if(i!=0 && nums[i]==prev)continue;
            l=i+1;
            r=n-1;
            target=-1 * nums[i];
            while(l<r){
                if(l==i){l++;continue;}
                else if(r==i){r--;continue;}
                sum = nums[l] + nums[r];
                if(sum==target){
                    vals.insert({nums[i], nums[l], nums[r]}); // insert in a<=b<=c to avoid duplicates
                    r--; // move anything and continue
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
            prev=nums[i];
        }
        for(auto n: vals)ans.push_back(n);
        return ans;
    }
};