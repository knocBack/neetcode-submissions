class Solution {
    int get_idx(char c){
        if(c >= 'A' && c <= 'Z')return c-'A';
        return 26 + (c-'a');
    } 
public:
    // paste the LeetCode / NeetCode function signature here
    string minWindow(string s, string t) {
        unordered_map<char, int> subs, tubs;
        bitset<52> resolved;
        for(const char&c: t){
            tubs[c]++;
            resolved[get_idx(c)]=1;
        }
        int ans = INT_MAX;
        int idx = -1;
        int l = 0, r = 0;
        while(l <= r && r < s.size()){
            // increment the substr
            subs[s[r]]++;
            if(tubs[s[r]] <= subs[s[r]])resolved[get_idx(s[r])] = 0;

            // if the substr is resolved, decrement it until we unresolve it
            while(resolved.none() && l<=r){
                // update the best substr if the shortened version is resolved. 
                if(r-l+1 < ans){
                    ans = r-l+1;
                    idx = l;
                }
                // shorten the substr
                subs[s[l]]--;
                if(tubs[s[l]] > subs[s[l]]){
                    resolved[get_idx(s[l])] = 1;
                }
                l++;
            }
            r++;
        }
        if(idx == -1)return "";
        return s.substr(idx, ans);
    }
};