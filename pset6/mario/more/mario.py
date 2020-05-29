from cs50 import get_int

n = 0
while (n <= 0 or n > 8):
    n = get_int("Heigh: ")
space = n - 1
for i in range(n):
    print(" "*space + "#"*(i+1) +'  '+"#"*(i+1))
    space = space - 1
