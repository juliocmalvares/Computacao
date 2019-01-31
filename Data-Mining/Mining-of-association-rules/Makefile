all:
	python3 dados.py
	./apriori -tr -s1 -c50 input_apriori.csv Results/confianca50.txt
	echo "\n"
	./apriori -tr -s1 -c10 input_apriori.csv Results/confianca10.txt
	echo "\n"
	./apriori -tr -s1 -c90 input_apriori.csv Results/confianca90.txt
	echo "\n"
	./apriori -tr -s2 -c10 input_apriori2.csv Results/confianca10_2item.txt
	echo "\n"
	./apriori -tr -s2 -c50 input_apriori2.csv Results/confianca50_2item.txt
	echo "\n"
	./apriori -tr -s2 -c90 input_apriori2.csv Results/confianca90_2item.txt
	echo "\n"
	
    
