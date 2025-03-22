n = int(input())
for i in range(n):
    a, b, k = map(int, input().split())
    if k == 1:
        print(0)
    else:
        k -= 1
        if a > b:
            if k % 2 != 0:
                k += 1
            else:
                k -= 1
        even = (k // 2) + (k % 2)
        odd = k // 2
        ans = (even * a) + ((b - a) * odd)
        print(ans)
