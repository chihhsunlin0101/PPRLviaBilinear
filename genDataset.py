import random
import string
data_number = 100
same_data_number = 20
def gen_random_string():
	rstring = ""
	for j in range(0,5):
		rstring +=" "+''.join(random.choice(string.ascii_letters + string.digits) for x in range(random.randint(5,10)))		
	return (rstring)
	
def genDataset():
	with open("datasetA","w") as A:
		with open("datasetB","w") as B:
			for i in range(1, same_data_number+1):
				#generate same random string
				rstring = gen_random_string()
				A.write(str(i).zfill(7)+" "+rstring+"\n")
				B.write(str(i).zfill(7)+" "+rstring+"\n")
				
			for i in range(same_data_number+1,data_number+1):
				#generate different random string
				A.write(str(i).zfill(7)+" "+gen_random_string()+"\n")
				B.write(str(i).zfill(7)+" "+gen_random_string()+"\n")
			
genDataset()
			
