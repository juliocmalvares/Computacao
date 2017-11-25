import random;
f = open("numeros.csv", "w")

for i in range(50):
	f.write(str(int(random.random()*100))+"\n")

f.close()