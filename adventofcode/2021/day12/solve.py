import copy


def is_big(s):
    return s.upper() == s


def is_small(s):
    return not is_big(s)


cons = [(x.split('-')[0], x.split('-')[1])
        for x in open('input.txt').read().rstrip().split('\n')]


adj = dict()
count = dict()
for x, y in cons:
    adj[x] = set()
    adj[y] = set()
    count[x] = 0
    count[y] = 0

for x, y in cons:
    adj[x].add(y)
    adj[y].add(x)


count['start'] = 1
cur = [('start', set())]
while True:
    changes = False
    cur_new = []
    print(cur)
    for u, vis in cur:
        for v in adj[u]:
            if not v in vis:
                vis2 = copy.copy(vis)
                if is_small(u):
                    vis2.add(u)
                cur_new.append((v, vis2))
                count[v] += 1
                changes = True

    cur = copy.copy(cur_new)
    if changes is False:
        break
print(count['end'])
print(count)
