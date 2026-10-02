class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n-1;
        int area = (r-l) * min(h[l], h[r]);
        bool _should_increase = true;
        int cmp = 0, base = 0;
        while(l<r){
            // check which is the smallest of l and r
            if(h[l] > h[r]){_should_increase = false; cmp = r;}
            else{_should_increase = true; cmp=l;}
            base = cmp;
            while(cmp <= r && cmp >= l && h[base] >= h[cmp]){
                (_should_increase)?cmp++:cmp--;
            }
            if(_should_increase){l = cmp;}
            else{r = cmp;}
            if(l<r)area = max(area, (r-l) * min(h[l], h[r]));
            // cout<<l<<' '<<r<<' '<<cmp<<' '<<_should_increase<<' '<<area<<'\n';
        }
        return area;
    }
};
