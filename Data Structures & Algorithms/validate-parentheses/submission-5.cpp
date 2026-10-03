class Solution {
public:
    // paste the LeetCode / NeetCode function signature here
    bool isValid(string s) {
        if(s.size()==1)return false;
        vector<char> v;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                v.push_back(c);
            }
            else if(
                (c==')' && v.size() && v.back()=='(') ||
                (c==']' && v.size() && v.back()=='[') ||
                (c=='}' && v.size() && v.back()=='{')
            ){
                v.pop_back();
            }
            else return false;
        }
        return v.size() == 0;
    }
};