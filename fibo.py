import time
ansDict = {}
 
def fibo(n):
    if n == 1 or n == 2:
        return 1
    else:
        if n not in ansDict.keys():
            ansDict[n] = fibo(n-1)+fibo(n-2)
        return ansDict[n]

n = int(input("Enter a number "))
t1 = time.time()
ans = fibo(n)
t2 = time.time()
print("The answer is ",ans)
print("The time taken is ",t2-t1," s")