import math
import random
import copy
import sys
import timeit
import matplotlib.pyplot as plt

def LinearSearch(A,n,key):
    found=[]
    for i in range(n):
        if A[i] == key:
            found.append(i)
    return found

def BinarySearch(A,l,r,key):
    found=[]
    while(l<=r):
        m=math.floor((l+r)/2)
        if (A[m]==key):
            found.append(m)
            break
        elif(A[m]<key):
            l=m+1
        else:
            r=m-1
    i=m-1
    j=m+1
    while(i>=l and A[i]==key):
        found.append(i)
        i= i-1
    while(j<=r and A[j]==key):
        found.append(j)
        j=j+1
    return found

##def rBinary_Search(A,l,r,key):
 ##   if(l>r):
 ##       return -1
 ##   else:
  ##      m=math.floor((l+r)/2)
  ##      if(A[m]==key):
  ##          return m
   ##     elif(A[m]<key):
  ##          return rBinary_Search(A,m+1,r,key)
   ##     else:
   ##         return rBinary_Search(A,l,m-1,key)
    
if __name__ =="__main__":
    input_size=[10,100,1000,10000,20000,100000,200000,1000000]
    key = int(sys.argv[1])
    l_time=[]
    b_time=[]
    for n in input_size:
      list1=[]
      for _ in range(n):
        list1.append(random.randint(1,1000))
      t1= timeit.default_timer()
      answer1= LinearSearch(list1,n,key)
      t2=timeit.default_timer()
      l_time.append((t2-t1))
    

      list2 = copy.deepcopy(list1)
      list2.sort()
      t3= timeit.default_timer()
      answer2= BinarySearch(list2,0,n-1,key)
      t4=timeit.default_timer()
      b_time.append((t4-t3))
plt.plot(input_size,l_time,label="Linear Search")
plt.plot(input_size,b_time,label="Binary Search")
plt.legend()
plt.grid(True)
plt.xlabel("N")
plt.ylabel("Time")
plt.title("N vs Time")
plt.show()
plt.savefig('plot.png')



