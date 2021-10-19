# // Problem: 凸多边形的划分
# // Contest: AcWing
# // URL: https://www.acwing.com/problem/content/1071/
# // Memory Limit: 64 MB
# // Time Limit: 1000 ms
# // Code by: ING__
# //
# // Edited on 2021-08-11 10:50:32

n = int(input())

a = [0 for i in range(55)]
f = []
for i in range(55):
    f.append([0] * 55)

_ = input().split()

for i in range(0, n):
    a[i + 1] = int(_[i])

for len in range(3, n + 1):
    for i in range(1, n - len + 2):
        l = i
        r = i + len - 1
        f[l][r] = 1e38
        for k in range(l + 1, r): # 长度为1的多边形没有意义
            f[l][r] = min(f[l][r], f[l][k] + f[k][r] + a[l] * a[r] * a[k])

print(f[1][n])
