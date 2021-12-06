import copy
f = open('input.txt', 'r').read().rstrip().split(',')


nums = [int(x) for x in f]


freq = [0 for _ in range(12)]
for x in nums:
    freq[x] += 1

for _ in range(256):
    freq_new = [0 for _ in range(12)]
    for i in range(9, -1, -1):
        freq_new[i] += freq[i+1]
    freq_new[6] += freq[0]
    freq_new[8] += freq[0]
    freq = copy.copy(freq_new)


print(sum(freq))
