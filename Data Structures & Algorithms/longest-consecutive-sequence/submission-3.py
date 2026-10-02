class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        vals = set(nums)
        seen = set()
        ans = 0
        for n in nums:
            # find starting element
            if n-1 in vals:
                continue
            
            # n is the start
            l = 0
            while True:
                # break if it's already traversed - no element is traversed twice
                if n in seen:
                    break
                # break if it's not in vals - not consecutive
                if n not in vals:
                    break
                seen.add(n)
                n += 1
                l += 1
            ans = max(ans, l)
        return ans