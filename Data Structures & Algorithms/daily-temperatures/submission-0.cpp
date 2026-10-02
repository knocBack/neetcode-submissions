class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic decreasing stack approach
        int n = temperatures.size();
        stack<pair<int,int>> s;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!s.empty()){
                pair<int,int> top = s.top();
                if(top.first>=temperatures[i])break;
                ans[top.second] = i-top.second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        return ans;
    }
};
