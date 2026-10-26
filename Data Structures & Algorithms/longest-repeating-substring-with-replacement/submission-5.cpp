class Solution {
public:
    // paste the LeetCode / NeetCode function signature here
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.length();
        for(char c='A';c<='Z';c++){
            int cur_max = 0;
            int replace = 0;
            int l = 0, r = 0;
            while(r<n){
                if(s[r]!=c){
                    if(replace < k){
                        replace++;
                    }
                    else{
                        while(s[l]==c && l<=r)l++;
                        l++;
                    }
                }
                r++;
                cur_max = max(cur_max, r-l);
            }
            ans = max(ans, cur_max);
        }
        return ans;
    }
};