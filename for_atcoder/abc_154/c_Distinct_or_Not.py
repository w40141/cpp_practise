N = int(input())
num_li = input().split(' ')
num_set = set(num_li)
if len(num_set) == len(num_li):
    print('YES')
else:
    print('NO')
