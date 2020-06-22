def S(x, y):
    if x < 1 or y < 1:
        return 0
    return (x*y*(2*x*x + 3*x*(y+1) +  2*y*y - 3*y+5))//12

def suma(x1, y1, x2, y2):
    return S(x2, y2) - S(x2,y1-1) - S(x1-1,y2) + S(x1-1, y1-1)

t = int(input())
for testcase in range(t):
    line = [int(x) for x in input().split(" ")]
    x1 = line[0]
    y1 = line[1]
    x2 = line[2]
    y2 = line[3]
    suma_tot = suma(x1,y1,x2,y2)
    if x1 == x2 or y1 == y2:
        print(1)
    else:
        suma_mayor = suma_tot - suma(x1,y1+1,x2-1,y2)
        suma_menor = suma_tot - suma(x1+1,y1,x2,y2-1)
        print(suma_mayor - suma_menor + 1)
