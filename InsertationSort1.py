def shifList(numbers , n ):
	if(n-1 < 0):
		return numbers 
	numbers[n] = numbers[n-1];
	return numbers ; 

def findIndex(numbers , num ):
	for i in range(0 , len(numbers)):
		if(numbers[i] > num ):
			return i 
	return len(numbers)-1

def printList(numbers):
	strp = ""
	for i in range(0 , len(numbers)):
		strp += str(numbers[i])
		if(i+1 < len(numbers)):
			strp += " "
	print strp

N = int(raw_input()); 
numbers = map(int , raw_input().strip().split(" "));
placeIndex = findIndex(numbers , numbers[len(numbers)-1])
smallest = numbers[len(numbers)-1]
for i in range(0 , N):
	index = N-1-i 	
	numbers = shifList(numbers , index )   
	if(index == placeIndex):
		numbers[index] = smallest ; 
		printList(numbers)
		break
	else :
		printList(numbers)


