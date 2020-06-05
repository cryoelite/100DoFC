"""
https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""



"""class Solution:
  def twoSum(self,arr,target: int):
    arr=str(arr).replace("[","").replace("]","")
    arr=list(map(int,arr.split(',')))
    lenny=len(arr)
    for i in range(lenny):
      for j in range(lenny):
        if(i!=j):
          if(arr[j]+arr[i]==target):
            return [i,j]
"""

"""https://www.techgig.com/codegladiators/opencontest"""

"""
class Sols:
  
  def __init__(self):
    self.jList=list()
  def filler(self,j):
    self.jList.append(j)
  def checker(self,j):
    for i in self.jList:
      if i==j:
        return False
    return True

if __name__=='__main__':
  testCases=int(input())
  for i in range(testCases):
    obj=Sols()
    totalInps=int(input())
    teamA=list(map(int,input().split()))
    teamB=list(map(int,input().split()))
    teamA.sort()
    teamB.sort()
    selector=int()
    success=0
    flag=0
    bIndex=int()
    for i in range(totalInps):
      selector=teamA[i]
      for j in range(totalInps):
        if(teamB[j]<selector and obj.checker(j)==True):
            bIndex=j
            flag=1
            break
      if(flag==1):
        flag=0
        success+=1
        obj.filler(bIndex)
    print(success)
    """