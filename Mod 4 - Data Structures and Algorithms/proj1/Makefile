all:	StockTester1 StockTester2 StockTester3 StockListTester StockListTester2 MarketTester

StockTester1:	Stock.h Stock.cpp StockTester1.cpp
	g++ -ggdb -o StockTester1 StockTester1.cpp Stock.cpp

StockTester2:	Stock.h Stock.cpp StockTester2.cpp
	g++ -ggdb -o StockTester2 StockTester2.cpp Stock.cpp

StockTester3:	Stock.h Stock.cpp StockTester3.cpp
	g++ -ggdb -o StockTester3 StockTester3.cpp Stock.cpp

StockListTester: Stock.h Stock.cpp StockNode.h StockList.h StockList.cpp StockListTester.cpp
	g++ -ggdb -o StockListTester Stock.cpp StockListTester.cpp StockList.cpp

StockListTester2: Stock.h Stock.cpp StockNode.h StockList.h StockList.cpp StockListTester2.cpp
	g++ -ggdb -o StockListTester2 Stock.cpp StockListTester2.cpp StockList.cpp

MarketTester: Stock.h Stock.cpp StockNode.h StockList.h StockList.cpp Market.h Market.cpp MarketTester.cpp
	g++ -ggdb -o MarketTester Stock.cpp StockList.cpp Market.cpp MarketTester.cpp

clean:
	rm StockTester1 StockTester2 StockTester3 StockListTester StockListTester2 MarketTester
