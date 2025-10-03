class Solution:
    def trap(self, height: List[int]) -> int:
        leftMax = [0] * len(height)
        rightMax = [0] * len(height)
        leftValue = -1
        rightValue = -1
        leftMax[0] = 0
        rightMax[len(height) - 1] = 0
        for i in range(1, len(height)):
            leftValue = height[i - 1] if height[i - 1] > leftValue else leftValue
            leftMax[i] = leftValue
        for i in range(len(height) - 2, -1, -1):
            rightValue = height[i + 1] if height[i + 1] > rightValue else rightValue
            rightMax[i] = rightValue

        water = 0
        for i in range(len(height)):
            possible = min(leftMax[i], rightMax[i])
            # print(leftMax[i])
            # print(rightMax[i])
            # print(possible)
            # print(possible-height[i])
            # print(" ")
            if(possible-height[i]>0):
                water += possible-height[i]

        return water