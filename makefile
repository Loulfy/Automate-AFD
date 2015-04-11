default:
	g++ src/*.cpp -o auto -I./src/include -std=c++11 -Wall

clean:
	rm -rf *~ */*~ */*/*~ 
