
CXX = g++



all: td


td:
	$(CXX) src/main.cpp -o $@


.PHONY: clean mrproper

clean:
	rm src/*.o *.o

mrproper: clean
	rm ./td
