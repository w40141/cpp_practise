raw = input()
N, K = raw.split(' ')
N = int(N)
K = int(K)
str_li = input().split(' ')
num_li = list(map(int, str_li))
sum_li = [0]
for i in num_li:
    sum_li.append(sum_li[-1] + i + 1)
ans = 0
for index in range(K, N+1):
    ans_tmp = sum_li[index] - sum_li[index - K]
    if ans_tmp > ans:
        ans = ans_tmp
print(ans/2)
