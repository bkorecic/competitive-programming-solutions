instr = [(x.split()[0], int(x.split()[1]))
         for x in open('input.txt', 'r').read().rstrip().split('\n')]

hor = 0
dep = 0
for ins, x in instr:
    if ins == 'forward':
        hor += x
    if ins == 'down':
        dep += x
    if ins == 'up':
        dep -= x

print(dep*hor)

hor = 0
dep = 0
aim = 0
for ins, x in instr:
    if ins == 'forward':
        hor += x
        dep += aim*x
    if ins == 'down':
        aim += x
    if ins == 'up':
        aim -= x
print(hor*dep)
