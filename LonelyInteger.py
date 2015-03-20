N = raw_input()
#map function apply int() function for all result
#which return from raw_input
list = map(int, raw_input().strip().split(" "))
for i in list: 
	if(list.count(i) == 1):
		print i  
		break;




