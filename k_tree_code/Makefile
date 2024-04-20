all: k_tree.o relaxed_k_tree.o squarish_k_tree.o main mainPar
	
mainPar: k_tree.o relaxed_k_tree.o squarish_k_tree.o main.cpp
	g++ -o mainPar mainDimPar.cpp k_tree.o relaxed_k_tree.o squarish_k_tree.o

main: k_tree.o relaxed_k_tree.o squarish_k_tree.o main.cpp
	g++ -o main main.cpp k_tree.o relaxed_k_tree.o squarish_k_tree.o

k_tree.o: k_tree.cpp k_tree.hh
	g++ -c k_tree.cpp k_tree.hh

relaxed_k_tree.o: relaxed_k_tree.cpp relaxed_k_tree.hh
	g++ -c relaxed_k_tree.cpp relaxed_k_tree.hh

squarish_k_tree.o: squarish_k_tree.cpp squarish_k_tree.hh
	g++ -c squarish_k_tree.cpp squarish_k_tree.hh

clean:
	rm -f main *.o *.gch mainPar

executar_test:
	./main > temps.out

executar_tests_par:
	
	( trap 'kill 0' 2; \
	 ./mainPar 2 > out/tempsDim2.out & \
	 ./mainPar 3 > out/tempsDim3.out & \
	 ./mainPar 4 > out/tempsDim4.out & \
	 ./mainPar 5 > out/tempsDim5.out & \
	 ./mainPar 6 > out/tempsDim6.out & \
	 ./mainPar 7 > out/tempsDim7.out & \
	 wait )
	 
fer_plots:
	python3 plotScript.py
fer_plots2:
	python3 plotDimensions.py 