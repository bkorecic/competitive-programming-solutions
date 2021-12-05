marked = set()


class Board:
    def __init__(self):
        self.matrix = [[0 for _ in range(5)] for _ in range(5)]
        self.winner = False

    def check(self):
        for i in range(5):
            row = self.matrix[i]
            if all([x in marked for x in row]):
                return self.sum_unmarked()
        for j in range(5):
            col = [self.matrix[i][j] for i in range(5)]
            if all([x in marked for x in col]):
                return self.sum_unmarked()
        return False

    def sum_unmarked(self):
        ans = 0
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] not in marked:
                    ans += self.matrix[i][j]
        return ans


f = open('input.txt', 'r').read().rstrip().split('\n')
f = list(filter(lambda x: x != '', f))

print(f)

nums = [int(x) for x in f[0].split(',')]
boards = []

for i in range(1, len(f), 5):
    boards.append(Board())
    for j in range(5):
        boards[-1].matrix[j] = [int(x) for x in f[i+j].split()]

for mark in nums:
    marked.add(mark)
    for board in boards:
        if board.winner:
            continue
        r = board.check()
        if r is not False:
            board.winner = True
            print(r*mark)
