h,m = [int(e) for e in input().strip().split()]
x = int(input())
m += x
h = (h+(m//60))%24
m = m%60
h = '0' + str(h)
m = '0' + str(m)
print(h[-2:], m[-2:])