Tum:derleme calistirma	

derleme:

	g++ -I ./include/ -o ./lib/AvlTreeList.o -c ./src/AvlTreeList.cpp
	g++ -I ./include/ -o ./lib/AvlTreeListNode.o -c ./src/AvlTreeListNode.cpp
	g++ -I ./include/ -o ./lib/AvlTreeNode.o -c ./src/AvlTreeNode.cpp
	g++ -I ./include/ -o ./lib/AvlTree.o -c ./src/AvlTree.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./lib/StackList.o -c ./src/StackList.cpp
	g++ -I ./include/ -o ./lib/StackListNode.o -c ./src/StackListNode.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/AvlTreeNode.o ./lib/Stack.o ./lib/StackNode.o ./lib/StackList.o ./lib/StackListNode.o ./lib/AvlTree.o ./lib/AvlTreeList.o ./lib/AvlTreeListNode.o ./src/Test.cpp
	
	
calistirma:
	./bin/Test