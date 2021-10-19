import math

n = int(input())

print(6 * (pow(4, (pow(2, n) - 2), 1000000007)) % 1000000007)