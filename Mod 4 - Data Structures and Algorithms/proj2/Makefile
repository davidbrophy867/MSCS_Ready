all:	TreeNodeTester StockTester4 StockTreeTester1 StockTreeTester2 RemoveTester1 RemoveTester2 RemoveTester3 RemoveTester4

TreeNodeTester:	Stock.h Stock.cpp StockTreeNode.h TreeNodeTester.cpp
	g++ -ggdb -o TreeNodeTester TreeNodeTester.cpp Stock.cpp

StockTester4:	StockTester4.cpp Stock.h Stock.cpp
	g++ -ggdb -o StockTester4 StockTester4.cpp Stock.cpp

StockTreeTester1:	StockTree.h StockTree.cpp StockTreeTester1.cpp Stock.h Stock.cpp
	g++ -ggdb -o StockTreeTester1 StockTree.cpp StockTreeTester1.cpp Stock.cpp

StockTreeTester2:	StockTree.h StockTree.cpp StockTreeTester2.cpp Stock.h Stock.cpp
	g++ -ggdb -o StockTreeTester2 StockTree.cpp StockTreeTester2.cpp Stock.cpp

RemoveTester1:	StockTree.h StockTree.cpp RemoveTester1.cpp Stock.h Stock.cpp
	g++ -ggdb -o RemoveTester1 StockTree.cpp RemoveTester1.cpp Stock.cpp

RemoveTester2:	StockTree.h StockTree.cpp RemoveTester2.cpp Stock.h Stock.cpp
	g++ -ggdb -o RemoveTester2 StockTree.cpp RemoveTester2.cpp Stock.cpp

RemoveTester3:	StockTree.h StockTree.cpp RemoveTester3.cpp Stock.h Stock.cpp
	g++ -ggdb -o RemoveTester3 StockTree.cpp RemoveTester3.cpp Stock.cpp

RemoveTester4:	StockTree.h StockTree.cpp RemoveTester4.cpp Stock.h Stock.cpp
	g++ -ggdb -o RemoveTester4 StockTree.cpp RemoveTester4.cpp Stock.cpp

DeleteTreeTester:	StockTree.h StockTree.cpp notes.cpp Stock.h Stock.cpp
		g++ -ggdb -o DeleteTreeTester StockTree.cpp notes.cpp Stock.cpp

clean:
	rm StockTreeTester1 StockTreeTester2 RemoveTester1 RemoveTester2 RemoveTester3 RemoveTester4
