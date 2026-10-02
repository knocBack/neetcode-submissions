class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n

        left_product = 1
        for i in range(n):
            ans[i] *= left_product # ans[i] = ans[i] * left_product (i-1) => multiply by previous left_product
            left_product *= nums[i]
        
        right_product = 1
        for i in range(n-1, -1, -1):
            ans[i] *= right_product # ans[i] = ans[i] * right_product (i+1) => multiply by next right_product
            right_product *= nums[i]
        
        return ans