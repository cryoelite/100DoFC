# https://www.hackerrank.com/challenges/extra-long-factorials/problem

# def fact(num):
#     if num==1:
#         return 1
#     else:
#         return num*fact(num-1)
# if __name__=='__main__':
#     num=int(input())
#     print(fact(num))

# https://www.hackerrank.com/challenges/append-and-delete/problem

# if __name__=='__main__':
#     str1=list(map(str,input()))
#     str2=list(map(str,input()))
#     k=int(input())
#     s1len=len(str1)
#     s2len=len(str2)
#     count=0
#     flag=(s2len-s1len)
#     ctr=0
#     if(abs(flag)>k):
#         print("No")
#     else:
#         if(flag<0):
#             for m in range(flag,0,1):
#                 str1.pop()
#                 count+=1
#                 s1len-=1
#         i=s1len-1
#         while(i>=0):
#             ctr+=1
#             if(str1[i]!=str2[i]):
#                 for j in range(ctr):
#                     str1.pop()
#                     ctr-=1
#                     count+=1
#                     s1len-=1
#             i-=1
#         flag=s2len-s1len
#         if(flag>0):
#           for i in range(flag):
#             str1.append(str2[i])
#             count+=1
#         if(count<=k):
#           print("Yes")
#         else:
#           print("No")    
    

""" 14 - Problem of the Day:
Given an array, please check if we can remove at most one element to make it strictly increasing.

Example:
                      
Input:[1, 2, 3, 7, 5, 6]
Output: true

Input: [1, 2, 3, 7, 8, 4, 5]
Output: false

asked by Google """


# def checker(listOne,m=0):
#     count=0
#     index=0+m
#     lenny=len(listOne)-1
#     for i in listOne:
#         index+=1
#         if(index<=lenny):
#             if(listOne[index]<=i):
#                 listOne.pop(index-m)
#                 count+=1
#                 return count,listOne
#     return count,listOne
# if __name__=='__main__':
#     listOne=list(map(int,input().split()))
#     count,listOne=checker(listOne,2)
#     n,listOne=checker(listOne)
#     if(n==1 and count==0):
#         n,listOne=checker(listOne)
#         print("Yes") if(n==0) else print("No")
#     elif(n==1 and count==1):
#         print("No")
#     else:
#         print("Yes")

def checker(listOne,m=0):
    lenny=len(listOne)
    if m==0:
        index=0
    else:
        index=1
    for i in range(m,lenny,2):
        index+=2
        if(index<lenny):
            if(listOne[i]>=listOne[index]):
                listOne.remove(i)
                return 1,listOne
    return 0,listOne
if __name__=='__main__':
    listOne=list(map(int,input().split()))
    first,listOne=checker(listOne,0)
    second,listOne=checker(listOne,1)
    print("Yes") if(first+second<=1) else print("No")
    


