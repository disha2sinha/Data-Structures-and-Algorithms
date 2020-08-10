def maxSubArray(nums):
    maxi = -99999999999999999
    summ=0
    for i in nums:
        summ+=i 
        if maxi<summ:
            maxi=summ
        if summ<0:
            summ=0
    return maxi


array = list(map(int, input().split()))
maxi = maxSubArray(array)
print(maxi)
