
"""Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

Input Format
First line contains input N.
Next line contains N space separated integers denoting the elements of the array.
The third line contains a single integer T denoting the target element.

Constraints
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in the array in a new line each. The triplets must be printed as A, B and C where A,B and C are the elements of the triplet ( A<=B<=C) and all triplets must be printed in sorted order. Print only unique triplets.

Sample Input
9
5 7 9 1 2 4 6 8 3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
Explanation
Array = {5, 7, 9, 1, 2, 4, 6 ,8 ,3}. Target number = 10. Find any three number in the given array which sum to target number.
"""







def calc(times: int, inplist: list, target: int):
    answers = set()
    a = int()
    b = int()
    c = int()
    for i in range(times):
        if (inplist[i] < target - 1):
            a = inplist[i]
            for j in range(times):
                if ((i != j) and (inplist[j] < (target - a))):
                    b = inplist[j]
                    for k in range(times):
                        if ((j != k) and (i != k)
                                and (inplist[k] == target - (a + b))):
                            c = inplist[k]
                            temp = sorted([a, b, c])
                            temp = str("{0}, {1} and {2}".format(
                                temp[0], temp[1], temp[2]))
                            answers.update([temp])
    answers = sorted(answers)
    for i in answers:
        print(i)
        
if __name__ == '__main__':
    times = int(input())
    inplist = list(map(int, input().split()))
    target = int(input())
    calc(times, inplist, target)
