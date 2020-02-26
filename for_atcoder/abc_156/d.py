raw = input().split()
li = list(map(int, raw))
n = li[0]
a = li[1]
b = li[2]

def count(n, a):
    ans = 1
    for num in range(a):
        ans *= (n - num) / (a - num)
    return ans % (10 ** 9 + 7)

ans = 2 ** n - 1
ans -= count(n, a)
ans -= count(n, b)
print(int(ans))
