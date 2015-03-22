class Building:
	jumpPower = 0  
	rescues = [] 
	numOfResc = 0
	currentHeight = 0 
	rescued = 0 

	def __init__(self):
		inputs = map(int , raw_input().strip().split(" "))
		self.numOfResc = inputs[0]
		if(self.numOfResc):
			self.rescues = inputs[1:]; 
	
	def clear(self):
		self.rescued = 0 

	def setHeight(self , h):
		self.currentHeight = h 
	
	def rescu(self , floor):
		if(not self.rescues.count(floor)):
			return 0 
		self.rescued += self.rescues.count(floor)
	
	def numOfRescu(self , floor ):
		return self.rescues.count(floor);
	
	
class Superman:
	numOfApt = 0
	jumpPower = 0 
	height = 0 
	currentL = 0
	buildings = []

	def __init__(self , inputs):
		self.numOfApt = inputs[0]
		self.height = inputs[1]
		self.currentL = self.height 
		self.jumpPower = inputs[2]

	def setBuildings(self , buildings ):
		self.buildings = buildings 

	def start(self , buildingNo):
		cb = buildingNo #current building
		
		i = max(self.buildings[cb].rescues)
		while i > 0  : 
			#print "--------"
			#print "b:"+str(cb) + " ,floor: " + str(i)
			if(self.buildings[cb].numOfRescu(i)):
				self.buildings[cb].rescu(i)
			else:
				cb_new = self.searchInOther(cb , i - self.jumpPower + 1 )
				if(cb_new != cb):
					i  = i - self.jumpPower + 2 
					cb = cb_new
			i -= 1 
		resc = 0 
		for apt in buildings:
			resc += apt.rescued
			apt.clear()
		return resc

	def searchInOther(self , bNo  , floor):
		#print "**********"
		temp_resc = []
		for i in range(0 , len(self.buildings)):
			temp_resc.append(0)
			if(i != bNo):
				temp_resc[i] = self.buildings[i].numOfRescu(floor)
			#print "bp: " +str(bNo)+ " , bn:"+str(i)+" , floor: "+str(floor)
		maxResc = max(temp_resc)
		if(maxResc == 0 ):
			return bNo
		indexBuild = temp_resc.index(maxResc)
		return indexBuild


arg = map(int , raw_input().strip().split(" ")) 
N = arg[0]
H = arg[1]
I = arg[2]

buildings = [] 
for i in range(0,N):
	buildings.append(Building())
superman = Superman(arg)
superman.setBuildings(buildings)
result = []
for i in range(0 , N):
	if(len(buildings[i].rescues) == 0 ):
		result.append(0)
		continue
	result.append(superman.start(i))
print max(result)

