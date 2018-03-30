
# coding: utf-8

# In[9]:


def calc_fib(n):
    a=list()
    a.append(0)
    a.append(1)
    for i in range(2,n+1,1):
        a.append(a[i-1]+a[i-2])
        
    return(a[n])

def get_fibonacci_huge_fast(n,m):
    if (n<m):
        return(n)
    
    return(get_fibonacci_huge_fast(calc_fib(n)%m,m))

if __name__ == '__main__':
    input = sys.stdin.read();
    n, m = map(int, input.split())
    print(get_fibonacci_huge_fast(n, m))

