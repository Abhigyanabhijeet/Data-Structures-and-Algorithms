# Uses python3
n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)
a.sort()
for index in range(n-2,-1,-1):
    if a[index] != a[n-1]:
        result = a[n-1]*a[index]
        print (result)
        break




