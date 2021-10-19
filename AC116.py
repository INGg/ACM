# Problem: 国王游戏
# Contest: AcWing
# URL: https://www.acwing.com/problem/content/116/
# Memory Limit: 64 MB
# Time Limit: 1000 ms
# Code by: ING__
#
# Powered by CP Editor (https://cpeditor.org)

n = int(input())

shou = []
_ = input().split()
a = int(_[0])
b = int(_[1])

for i in range(n):
	_ = input().split()
	shou.append((int(_[0]), int(_[1])))

shou.sort(key = lambda x: (x[0] * x[1]))

ans = -1
cheng = a

for i in range(n):
	ans = max(cheng // shou[i][1], ans)
	cheng = cheng * shou[i][0]

print(ans)