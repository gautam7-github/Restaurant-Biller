biller : biller.cpp mainDo.cpp items.cpp
	g++ -c items.cpp -o items.o
	g++ -c mainDo.cpp -o mainDo.o
	g++ -c biller.cpp -o biller.o
	g++ items.o mainDo.o biller.o -o billerRUN