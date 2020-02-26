raw = input().split()
li = list(map(int, raw))
n = li[0]
r = li[1]

if 10 <= n:
    print(r)
else:
    tmp = 100 * (10 - n)
    print(tmp)
    print(r + tmp)
