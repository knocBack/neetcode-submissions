// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        const int m = nums1.size();
        const int n = nums2.size();
        const int left_count = (m + n + 1) / 2;
        int lo = 0, hi = m;

        while (lo <= hi) {
            const int cut1 = lo + (hi - lo) / 2;
            const int cut2 = left_count - cut1;

            const int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            const int right1 = cut1 == m ? INT_MAX : nums1[cut1];
            const int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            const int right2 = cut2 == n ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            if (left1 > right2) {
                hi = cut1 - 1;
            } else {
                lo = cut1 + 1;
            }
        }

        return 0.0;
    }
};