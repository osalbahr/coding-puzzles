#!/usr/bin/python3
opt = 12 * 2018 + 3
now = 12 * int(input())

while (now > opt):
    opt = opt + 26

if (opt // 12 == now / 12):
    print("yes")
else:
    print("no")
