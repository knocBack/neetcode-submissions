class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = [1] * len(nums)
        right = [1] * len(nums)
        for i, n in enumerate(nums):
            left[i] = (
                left[i-1] if i > 0 else 1
            ) * n
        for i in range(len(nums)-1, -1, -1):
            right[i] = (
                right[i+1] if i < len(nums)-1 else 1
            ) * nums[i]
        ans = []
        for i, n in enumerate(nums):
            l = left[i-1] if i > 0 else 1
            r = right[i+1] if i < len(nums)-1 else 1
            ans.append(l*r)
        return ans