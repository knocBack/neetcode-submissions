class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> pairs;
        map<int,int> idx;
        for(int i:nums){
            if(idx.contains(i))pairs[idx[i]].second++;
            else{
                idx[i]=pairs.size();
                pairs.push_back({i,1});
            }
        }
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pairs[i].first);
        }
        return ans;
    }
};
