class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        mult = 1
        zeroes = 0
        for n in nums:
            if n == 0:
                zeroes+=1
                continue
            mult*=n
        if zeroes > 1:
            return [0] * len(nums)
        elif zeroes > 0:
            return [ 0 if n!=0 else mult for n in nums ]
        return [ mult//n if n!=0 else mult for n in nums ]