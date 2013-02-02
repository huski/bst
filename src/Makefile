EXEC=bst
OBJS=BinarySearchTree.o bst.o

default: $(EXEC)

$(EXEC): $(OBJS)
	g++ -o $(EXECPATH)/$@ $(OBJS)

%.o: %.cpp
	g++ -O3 -Wall -fmessage-length=0 -o $@ -c $<

clean:
	rm -rf $(OBJS) $(EXECPATH)/$(EXEC)
