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
        // resolved.set(); // makes all one
        for(const char&c: t){
            tubs[c]++;
            resolved[get_idx(c)]=1;
        }
        int ans = 0;
        string sub_str = "";
        for(const char& c: s){
            subs[c]++;
            ans++;
            if(tubs[c] <= subs[c]){
                resolved[get_idx(c)] = 0;
            }
            if(resolved.none())break;
        }
        if(resolved.any())return "";

        int l = 0, r = ans; // [l, r)
        sub_str = s.substr(l,r-l); // start_idx, str_length
        // normalize first few
        while(resolved.none() && l<r && (!tubs.contains(s[l]) || tubs[s[l]] < subs[s[l]])){
            subs[s[l]]--;
            // if(subs[s[l]] < tubs[s[l]])resolved[get_idx(s[l])] = 1;
            l++;
        }
        sub_str = s.substr(l,r-l);
        // cout<<sub_str<<'\n';
        while(l<r && r<s.size()){
            // shorten as much as possible
            while(resolved.none() && l<r && (!tubs.contains(s[l]) || tubs[s[l]] < subs[s[l]])){
                subs[s[l]]--;
                // if(subs[s[l]] < tubs[s[l]])resolved[get_idx(s[l])] = 1;
                l++;
            }
            // cout<<"pushed l: "<<l<<' '<<r<<'\n';
            if(resolved.none()){
                if(r-l <= ans){
                    ans = r-l;
                    sub_str = s.substr(l,r-l);
                }
                subs[s[l]]--;
                resolved[get_idx(s[l])] = 1;
                l++;
                // cout<<"resolved l: "<<l<<' '<<r<<' '<<sub_str<<' '<<'\n';
            }
            subs[s[r]]++;
            if(tubs[s[r]] <= subs[s[r]])resolved[get_idx(s[r])] = 0;
            r++;
            // cout<<"pushed r: "<<l<<' '<<r<<' '<<'\n';
        }
        // normalize last few
        while(resolved.none() && l<r && (!tubs.contains(s[l]) || tubs[s[l]] < subs[s[l]])){
            subs[s[l]]--;
            // if(subs[s[l]] < tubs[s[l]])resolved[get_idx(s[l])] = 1;
            l++;
        }
        if(resolved.none()){
            if(r-l < ans){
                ans = r-l;
                sub_str = s.substr(l,r-l);
            }
        }
        // cout<<sub_str;
        return sub_str;
    }
};