
# coding: utf-8

# In[27]:


# Uses python3
n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)
a.sort()
for index in range(n-2,0,-1):
    if a[index] != a[n-1]:
        result = a[n-1]*a[index]
        break




print(result)

