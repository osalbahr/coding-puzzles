w=0
t=0
for i in range(1,6):
	n=sum(map(int,input().split()))
	if n>t:
	    w=i
	    t=n
print(w,t)