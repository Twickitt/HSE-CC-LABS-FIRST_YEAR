Gc = gcc
Sources = main.o Bin_Search_Tree.o Create_List.o Free_Tree.o Insertation_Of_Tree.o Linear_Search.o Print_List.o To_Lower.o Wrappers.o

all: base 

base: $(Sources)
		$(Gc) $(Sources) -o base 

main.o: main.c
		$(Gc) -c main.c

Bin_Search_Tree.o: Bin_Search_Tree.c
		$(Gc) -c Bin_Search_Tree.c

Create_List.o: Create_List.c
		$(Gc) -c Create_List.c

Free_Tree.o: Free_Tree.c
		$(Gc) -c Free_Tree.c

Insertation_Of_Tree.o: Insertation_Of_Tree.c
		$(Gc) -c Insertation_Of_Treeq.c
	
Linear_Search.o: Linear_Search.c
		$(Gc) -c Linear_Search.c

Print_List.o: Print_List.c
		$(Gc) -c Print_List.c

To_Lower.o: To_Lower.c
		$(Gc) -c To_Lower.c

Wrappers.o: Wrappers.c
		$(GC) -c Wrappers.c

clean:
		rm -rf *.o base