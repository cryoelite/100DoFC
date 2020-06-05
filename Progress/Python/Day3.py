""" def adder(depth,tree):
    if(depth>=0):
        tree.left=Node('R')
        tree.right=Node('B')
        return(adder(depth-1,tree.left))
        return(adder(depth-1,tree.right))
    else:
        return(depth,tree)
def printr(depth,tree):
    if(depth>=0):
        print("L"+str(tree.left.val))
        print("R"+str(tree.right.val))
        print("/n")
        return(printr(depth-1,tree.left))
        return(printr(depth-1,tree.right))  
    else:
        return(depth,tree)
    

class Node:
  def __init__(self,val):
    self.val=val
    self.left=None
    self.right=None
class Starter:
  def __init__(self):
    self.start=None
if __name__=='__main__':
  nOfTestCases=1#int(input())
  for i in range(nOfTestCases):
    maxSize=[3,2]#list(map(int,input().split()))
    maxSize,forbid=maxSize
    antiRule=[input() for i in range(forbid)]
    tree=Starter()
    elem=antiRule[0]
    elem=elem[0]
    nope=0
    header=tree.start
    if(elem[0]=='R'):
        header=Node('B')
        nope,tree=adder(maxSize-1,header)
    else:
        header=Node('R')
        nope,tree=adder(maxSize-1,header)
    header=tree.start
    print(printr(maxSize,header))
 """
if __name__=='__main__':
  nOfTestCases=1#int(input())
  for i in range(nOfTestCases):
    maxSize=[3,2]#list(map(int,input().split()))
    maxSize,forbid=maxSize
    antiRule=[input() for i in range(forbid)]
  
