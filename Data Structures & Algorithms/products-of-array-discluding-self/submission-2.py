class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = [1] * len(nums)
        right = [1] * len(nums)
        zeroes = 0
        for i, n in enumerate(nums):
            if n == 0:
                zeroes+=1
            l = left[i-1] if i > 0 else 1
            left[i] = l * (1 if n == 0 else n)
        
        for i in range(len(nums)-1, -1, -1):
            r = right[i+1] if i < len(nums)-1 else 1
            right[i] = r * (1 if nums[i] == 0 else nums[i])
        ans = []
        if zeroes > 1:
            return [0] * len(nums)
        elif zeroes > 0:
            for i,n in enumerate(nums):
                if n!=0:
                    ans.append(0)
                    continue
                l = left[i-1] if i>0 else 1
                r = right[i+1] if i<len(nums)-1 else 1
                ans.append(l*r)
        else:
            for i,n in enumerate(nums):
                l = left[i-1] if i>0 else 1
                r = right[i+1] if i<len(nums)-1 else 1
                ans.append(l*r)
        # print(left)
        # print(right)
        # print(ans)
        # print(zeroes)
        return ans