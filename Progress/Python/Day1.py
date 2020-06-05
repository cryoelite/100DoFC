# https://www.hackerrank.com/challenges/compare-the-triplets/problem

# alice=list(map(int,input().split()))
# bob=list(map(int,input().split()))
# alicept=0
# bobpt=0
# for i in range(3):
#   if(alice[i]>bob[i]):
#     alicept+=1
#   elif(bob[i]>alice[i]):
#     bobpt+=1
# print("{a} {b}".format(a=str(alicept),b=str(bobpt)))

# https://www.hackerrank.com/challenges/a-very-big-sum/problem

# def aVeryBigSum(aNum):
#   return sum(aNum)
# if __name__=='__main__':
#   nofinput=int(input())
#   aNums=list(map(int,input().split()))
#   print(aVeryBigSum(aNums))

# https://www.hackerrank.com/challenges/diagonal-difference/problem

# if __name__=='__main__':
#   nOfrows=int(input())
#   arr=[]
#   nCount=0
#   summer=0
#   summer2=0
#   for i in range(nOfrows):
#     arr.append(list(map(int,input().split())))
#   for i in range(nOfrows):
#     summer+=arr[i][i]
#   for j in range(0,nOfrows,1):
#     summer2+=arr[i][j]
#     i-=1 
#   print(abs(summer-summer2))

# https://www.hackerrank.com/challenges/plus-minus/problem

# if __name__=='__main__':
#   nofNums=int(input())
#   arr=list(map(int,input().split()))
#   posv=0
#   negv=0
#   zero=0
#   for elem in arr:
#     if(elem>0):
#       posv+=1
#     elif(elem<0):
#       negv+=1
#     else:
#       zero+=1
#   print("{a:.6f}\n{b:.6f}\n{c:.6f}".format(a=float(posv/nofNums),b=float(negv/nofNums),c=float(zero/nofNums)))


# Sum of all diagonals,columns and rows of any matrix
# if __name__=='__main__':
#   arr=[]
#   for i in range(3):
#     arr.append(list(map(int,input().split())))
#   rowDict={}
#   colDict={}
#   colList=[]
#   diaDict1={}
#   diaDict2={}
#   diaList1=[]
#   diaList2=[]
#   k=0
#   z=(len(arr))-1
#   flag=z+1
#   for i in range(len(arr)):
#     for j in arr:
#       rowDict.update({sum(j):j})
#       colList.append(j[i])
#       if(k==i):
#         diaList1.append(j[i])
#       if flag>0:
#         diaList2.append(j[z])
#         flag-=1
#       z-=1
#       k+=1
#     colDict.update({sum(colList):list(colList)})
#     colList.clear()
#     k=0
#   diaDict1.update({sum(diaList1):list(diaList1)})
#   diaDict2.update({sum(diaList2):list(diaList2)})
    