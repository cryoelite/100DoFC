#Lists,Tuples,Sets and Dictionaries

aString = "Hello World"
aList = [2, 4, 5]          #Unlike array takes all data and puts them in 1 variable
aTuple=(2,4,5)             #Faster in sorting and traversal than lists
aSet={2,4,5}               #Unordered list which discards duplicates and is faster in traversal than lists
aDict={'name':'henry','age':25,'subjects':['CS','French']}        #key-value pairs
anInt = 24
aFloat = 24.00

# aList.extend(aString.split()) #Extend extends a list by appending the 2nd list, unlike append which works better for single elements
# l1=aList                          #split returns a list after splitting the string wherever and however many times it find the specified element, default ' '
# print(l1)

# bList=aList[:] #Simple way to copy a list and not its address
# bList.append(2)
# print(aList)

# aList.sort() #sorts list
# aList.sort(reverse=True) #reverseSort
# bList=sorted(aList) #returns a sorted list

# aList.remove('2') 
# aList.pop() #pops last and returns it

# aList.index('2') # returns index posn of 1st '2'


# for elem in enumerate(aList,start=1):   #enumerate returns an iterable with index posn along each element, with start index 1 , default 0, of a list.
#     print(elem)

# aList = ['a', 'b', 'c']
# bList = ''.join(aList)  # removes ',' , '[' , ']' , ''' and inserts whatever is between ' ' instead and returns a string version of the list with string elements
# print(bList)

# bTuple=aTuple #works bc tuples cant have more values appended or removed, also bc tuple copies the values and not address

# bSet=set(aSet)
# bSet.add(3)
# print(aSet,'\n',bSet)

# Rule of thumb for replicating any of instance of the basic data structures in Python (lists, dict, set, frozenset, string):
# a2 = list(a)      #a is a list
# b2 = set(b)       #b is a set
# c2 = dict(c)      #c is a dict
# d2 = frozenset(d) #d is a frozenset
# e2 = str(e)       #e is a string
#All of the above give a (shallow) copy.

# bSet={2,4,7,8}
# print(bSet.intersection(aSet))       #returns values that are in both the sets

# bSet={2,4,7,8}
# print(bSet.difference(aSet))         #returns values present in bSet but NOT in aSet

# bSet={2,4,7,8}
# print(bSet.union(aSet))              #returns a set with both the sets combined and removed duplicates

# print(aDict['age'])
# print(aDict.get('age', 'NA')) #returns the value of the given key and specified string if the key not found , default 'None'

#  aDict.update({'name':'Kim', 'speed':46})  #updates dictionary

# del aDict['age'] #removes specified key and its value
# aDict.pop('name') #removes specified key and returns its value

# print(aDict.items()) #returns key and value pairs
# print(aDict.keys()) #returns all keys
# print(aDict.values()) #returns all values   

""" def pp(num):         simple error collection
  try:
    print(int(num))
    print("bbo")
  except ValueError:
    print("nana") """