"""
Piyush is lost in a magical park which contains N rows and M columns.In order to get out of park safely and return home, he needs atleast K amount of strength.Given a N by M pattern, your task is to find weather Piyush can ever escape the park.



Piyush enters the park with strength S. The park is filled with some obstacles denoted by ‘.’ , some magical beans denoted by ‘*’ and some blockades denoted as ‘#’. If he encounters an obstacle (.) , strength decreases by 2. If he encounters a magic bean (' * ') , his strength increases by 5. Piyush can only walk row wise, so he starts from left of a row and moves towards right and he does this for every row. However when he encounters a blockade (#) , he cannot go any further in his current row and simply jumps to the start of a new line without losing any strength. Piyush requires a strength of 1 for every step. His strength should always be greater than K while traversing or else Piyush will get lost. Assume that Piyush can shift immediately from last of one row to the start of next one without loss of any strength, help out Piyush to escape the park. His escape is successful if he is able to return home with atleast K strength.

Input Format
First line of input contains four integers – N,M,K and S. Next N lines contains M space separated characters which can be '.', '*' or '#'.

Constraints
1 <= N,M,K,S <= 100

Output Format
Print "Yes" or "No" depending on whether Piyush can escape or not. If the answer is "Yes", also print the amount of strength he escaped with.

Sample Input
4 4 5 20
. . * .
. # . .
* * . .
. # * *
Sample Output
Yes
13
"""

# My Soln 
if __name__=='__main__':
  n,m,k,s=[x for x in list(map(int,input().split(' ')))]
  chk=0
  for x in range(0,n):
    temp=input()
    if(chk==0):
      for y in temp:
        s-=1
        if(s<k):
          chk=1
          break
        else:
          if(y=="."):
            s-=2
          elif(y=="*"):
            s+=5
          elif(y=="#"):
            s+=1
            break
  if(chk==0):
    print("Yes \n",s,sep="")
  else:
    print("No")
 