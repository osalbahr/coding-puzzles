#!/usr/bin/python3

import sys

for i in sys.stdin:
    c, k = i.split()
    c = int(c)
    k = int(k)

m = 10 ** k
ans = c / m
ans = round(ans)
print(ans * m)
