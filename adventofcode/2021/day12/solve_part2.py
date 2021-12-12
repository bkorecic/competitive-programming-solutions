import copy


def is_big(s):
    return s.upper() == s


def is_small(s):
    return not is_big(s)


cons = [(x.split('-')[0], x.split('-')[1])
        for x in open('input.txt').read().rstrip().split('\n')]


adj = dict()
for x, y in cons:
    adj[x] = set()
    adj[y] = set()

for x, y in cons:
    adj[x].add(y)
    adj[y].add(x)


cur = [('start', {'start'}, False)]
ans = 0
while True:
    changes = False
    cur_new = []
    for u, vis, twice in cur:
        if u == 'end':
            continue
        for v in adj[u]:
            if v == 'start':
                continue
            if not v in vis:
                vis2 = copy.copy(vis)
                if is_small(u):
                    vis2.add(u)
                cur_new.append((v, vis2, twice))
                if v == 'end':
                    ans += 1
                changes = True
            elif is_small(v) and twice == False:
                vis2 = copy.copy(vis)
                if is_small(u):
                    vis2.add(u)
                cur_new.append((v, vis2, True))
                if v == 'end':
                    ans += 1
                changes = True

    cur = copy.copy(cur_new)
    if changes is False:
        break
print(ans)
