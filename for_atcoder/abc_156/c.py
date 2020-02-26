N = int(input())

raw = input().split()
li = list(map(int, raw))
s = sum(li)
a = round(s / N)
all_tairyoku = 0
for i in li:
    tairyoku = (i - a) ** 2
    all_tairyoku += tairyoku
print(all_tairyoku)
