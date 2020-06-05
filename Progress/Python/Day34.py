"""
N=9+99+999+9999+.....+999999... up to 999 digits
find the sum of the digits of N.
"""
def calc(N: str):
  summer=0
  answer=0
  for i in range(1000):
    summer+=int(N)
    N="%s9" % N
  for i in str(summer):
    answer+=int(i)
  print(answer)




if __name__ == '__main__':
    calc("9")