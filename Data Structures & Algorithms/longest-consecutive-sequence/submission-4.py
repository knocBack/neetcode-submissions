class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        vals = set(nums)
        ans = 0

        for n in vals:
            # find start
            if n-1 in vals:
                continue
            
            # start = n
            l = 1 # current length
            # start, start+1, ... start+x all are in vals
            # some point n+l wont be in vals
            while (n+l) in vals:
                l+=1
            
            ans = max(ans, l)
        return ans