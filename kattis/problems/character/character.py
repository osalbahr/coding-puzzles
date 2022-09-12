import math

n = int( input() )

result = 0
for i in range(2, n+1):
    result += math.comb(n, i)
  
print(result)