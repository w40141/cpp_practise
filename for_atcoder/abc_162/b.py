N = int(input().split()[0])
all_sum = int(N * (N+1) / 2)

for i in range(3, N+1, 3):
    all_sum -= i

for i in range(5, N+1, 5):
    all_sum -= i

for i in range(15, N+1, 15):
    all_sum += i

print(all_sum)
