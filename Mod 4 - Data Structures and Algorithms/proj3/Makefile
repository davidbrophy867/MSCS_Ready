all:	LinkedHashNodeTester HashMapTester MarketTester

LinkedHashNodeTester: Stock.h Stock.cpp LinkedHashNode.h LinkedHashNode.cpp LinkedHashNodeTester.cpp 
	g++ -ggdb -o LinkedHashNodeTester LinkedHashNodeTester.cpp LinkedHashNode.cpp Stock.cpp 

HashMapTester:	HashMapTester.cpp HashMap.h HashMap.cpp LinkedHashNode.h LinkedHashNode.cpp Stock.h Stock.cpp
	g++ -g -o HashMapTester HashMapTester.cpp HashMap.cpp LinkedHashNode.cpp Stock.cpp

MarketTester:	MarketTester.cpp Market.cpp HashMap.h HashMap.cpp LinkedHashNode.h LinkedHashNode.cpp Stock.h Stock.cpp StringList.h StringList.cpp
	g++ -g -o MarketTester MarketTester.cpp Market.cpp HashMap.cpp LinkedHashNode.cpp Stock.cpp StringList.cpp

clean:
	rm LinkedHashNodeTester HashMapTester MarketTester
