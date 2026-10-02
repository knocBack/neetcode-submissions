class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        hash map of num -> idx say idx
        next := find next element idx; ex: next(n) = idx.get(n+1, -1)
        prev := find previous element idx; ex: prev(n) = idx.get(n+1, -1)

        """
        idx = {}
        for i, n in enumerate(nums):
            idx.setdefault(n, i) # n: i if n not in idx else continue

        next_idx = [ 
            idx.get(n+1, -1) for n in nums # -1 => last element in the graph
        ]

        prev_idx = [
            idx.get(n-1, -1) for n in nums # -1 => first element in the graph
        ]
        
        seen = set()
        ans = 0
        for i, start in enumerate(prev_idx):
            # continue if it's not the starting element
            if start != -1:
                continue
            
            _next = next_idx[i]
            seen.add(nums[i]) # cur element is seen
            l = 1 # cur length is 1
            while _next != -1 and nums[_next] not in seen:
                seen.add(nums[_next])
                l += 1
                _next = next_idx[_next]
            ans = max(ans, l)

        return ans
            
            
                