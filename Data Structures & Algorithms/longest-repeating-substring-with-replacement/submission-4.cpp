class Solution {
public:
    // paste the LeetCode / NeetCode function signature here
    int characterReplacement(string s, int k) {
        unordered_map<char, int> win_cnt;
        int maxi = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            win_cnt[s[i]]++;
            maxi = max(maxi, win_cnt[s[i]]);
        }
        vector<char> max_chars;
        for(char c='A'; c<='Z'; c++){
            if(win_cnt[c]==maxi)max_chars.push_back(c);
        }

        int ans = 0;
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
                // cout<<l<<' '<<r<<' '<<ans<<'\n';
                cur_max = max(cur_max, r-l);
            }
            ans = max(ans, cur_max);
        }
        return ans;
    }
};