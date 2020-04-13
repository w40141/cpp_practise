import math
import itertools

K = int(input().split()[0])


def gcd_args(i, j, k):
    return math.gcd(math.gcd(i, j), k)


ans = 0
for i in range(1, K+1):
    for j in range(i, K+1):
        for k in range(j, K+1):
            tmp_ans = gcd_args(i, j, k)
            l = [i, j, k]
            c = set()
            for v in itertools.permutations(l, 3):
                c.add(v)

            ans += tmp_ans * len(c)

print(ans)
