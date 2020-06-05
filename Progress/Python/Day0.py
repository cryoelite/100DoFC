testCases=int(input())
for i in range(testCases):
  sizeOfList,groupSize=map(int,input().split())
  mList=list(map(int,input().split()))
  bList=[]
  sumList=[]
  ptr=0
  ogGroupSize=groupSize
  if(sizeOfList%groupSize==0):
    for elem in range(int(sizeOfList/groupSize)):
      for elem2 in range(ptr,groupSize):
        bList.append(mList[elem2])
      sumList.append(sum(bList))
      bList.clear()
      ptr=elem2+1
      groupSize+=ogGroupSize
    print(max(sumList))
  else:
    for elem in range(int(sizeOfList/groupSize)):
      for elem2 in range(ptr,groupSize):
        bList.append(mList[elem2])
      sumList.append(sum(bList))
      bList.clear()
      ptr=elem2+1
      groupSize+=ogGroupSize
    for elem in range(ptr,len(mList)):
      sumList.append(mList[elem])
    print(max(sumList))