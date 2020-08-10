def maxSubArray(nums):
    maxi = -90000000000000
    for i in range(0, len(nums)):
        summ = 0
        for j in range(i, len(nums)):
            summ += nums[j]
            if (maxi < summ):
                maxi = summ
    return maxi
array=list(map(int,input().split()))
maxi=maxSubArray(array)
print(maxi)
