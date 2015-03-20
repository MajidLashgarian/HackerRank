def compareAndRep(numbers , a  , b):
	temp = numbers[a]
	numbers[a] = numbers[b]
	numbers[b] = temp
	return numbers 

def printList(numbers):
	strp = ""
	for i in range(0 , len(numbers)):
		strp += str(numbers[i])
		if(i+1 < len(numbers)):
			strp += " "
	print strp

N = int(raw_input())
numbers = map(int , raw_input().strip().split(" "))
for i in range(1 , N):
	for j in range (0 , i ):
		if(numbers[i] < numbers[j]):
			numbers = compareAndRep(numbers , i , j)

	printList(numbers) 

