nums = open('input.txt', 'r').read().rstrip().split('\n')
n = len(nums)
m = len(nums[0])


def get_cnt(arr):
    cnt_1 = [0 for _ in range(m)]
    for b in arr:
        for i, c in enumerate(b):
            if c == '1':
                cnt_1[i] += 1
    return cnt_1


cnt_part1 = get_cnt(nums)

a = ['0' for _ in range(m)]
b = ['0' for _ in range(m)]
for i in range(m):
    if cnt_part1[i] > n-cnt_part1[i]:
        a[i] = '1'
        b[i] = '0'
    else:
        a[i] = '0'
        b[i] = '1'

# first puzzle solution:
print(int(''.join(a), 2)*int(''.join(b), 2))

oxygen = list(nums)
co2 = list(nums)

cur_bit = 0
while len(oxygen) > 1:
    cnt_1 = get_cnt(oxygen)
    stays = '1'
    if cnt_1[cur_bit] < len(oxygen)-cnt_1[cur_bit]:
        stays = '0'
    oxygen = list(filter(lambda b: b[cur_bit] != stays, oxygen))
    cur_bit += 1

cur_bit = 0
while len(co2) > 1:
    cnt_1 = get_cnt(co2)
    stays = '1'
    if len(co2)-cnt_1[cur_bit] <= cnt_1[cur_bit]:
        stays = '0'
    co2 = list(filter(lambda b: b[cur_bit] != stays, co2))
    cur_bit += 1

# second puzzle solution:
print(int(oxygen[0], 2)*int(co2[0], 2))
