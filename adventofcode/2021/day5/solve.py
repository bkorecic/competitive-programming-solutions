f = open('input.txt', 'r').read().rstrip().split('\n')

xy = []
mx = 0
for line in f:
    left, right = line.split('->')
    left = left.strip()
    right = right.strip()
    x1, y1 = [int(x) for x in left.split(',')]
    x2, y2 = [int(x) for x in right.split(',')]
    xy.append((x1, y1, x2, y2))
    mx = max(mx, x1, x2, y1, y2)

m = [[0 for _ in range(mx+1)] for _ in range(mx+1)]

for x1, y1, x2, y2 in xy:
    print(x1, y1, x2, y2)
    if x1 == x2:
        for y in range(min(y1, y2), max(y1, y2)+1):
            m[x1][y] += 1
    elif y1 == y2:
        for x in range(min(x1, x2), max(x1, x2)+1):
            m[x][y1] += 1
    else:
        if x1 > x2:
            x1, x2 = x2, x1
            y1, y2 = y2, y1
        difx = 1
        dify = 1
        if y2 < y1:
            dify = -1
        x, y = x1, y1
        while x != x2 and y != y2:
            m[x][y] += 1
            x += difx
            y += dify
        m[x2][y] += 1

ans = 0
for l in m:
    print(l)
    for x in l:
        if x > 1:
            ans += 1

print(ans)
