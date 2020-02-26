raw = input().split()
li = list(map(int, raw))
n = li[0]
k = li[1]

flag = 0
while 0 < n:
    flag += 1
    n = int(n / k)

print(flag)
