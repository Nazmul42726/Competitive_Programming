n = int(input())
a = [int(x) for x in input().split()]

low = 0
high = int(1e9+7)

def cal_cost(m):
    result = 0
    for i in range(n):
        result += abs(a[i] - m)
    return result

while high - low > 2:
    thrd = (high - low) // 3
    mid1 = low + thrd
    mid2 = high - thrd
    cost1 = cal_cost(mid1)
    cost2 = cal_cost(mid2)

    if cost1 < cost2:
        high = mid2
    else:
        low = mid1

print(min(cal_cost(low), min(cal_cost(low + 1), cal_cost(high))))