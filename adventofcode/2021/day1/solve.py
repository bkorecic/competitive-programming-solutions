nums = [int(x) for x in open('input.txt', 'r').read().rstrip().split('\n')]

ans = 0
for i in range(1, len(nums)):
    if nums[i] > nums[i-1]:
        ans += 1
print(ans)

ans = 0
for i in range(3, len(nums)):
    if sum(nums[i-2:i+1]) > sum(nums[i-3:i]):
        ans += 1
print(ans)
