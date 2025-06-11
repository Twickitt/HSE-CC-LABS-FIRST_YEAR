Gc = gcc
Sources = main.o Bin_Search_Tree.o Create_List.o Free_Tree.o Insertation_In_Tree.o Linear_Search.o Print_List.o To_Lower.o Bin_Search_Tree_With_Any_Case.o Linear_Search_With_Any_Case.o Red_Black_Tree.o
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

Insertation_In_Tree.o: Insertation_In_Tree.c
		$(Gc) -c Insertation_In_Tree.c
	
Linear_Search.o: Linear_Search.c
		$(Gc) -c Linear_Search.c

Bin_Search_Tree_With_Any_Case.o: Bin_Search_Tree_With_Any_Case.c
		$(Gc) -c Bin_Search_Tree_With_Any_Case.c

Linear_Search_With_Any_Case.o: Linear_Search_With_Any_Case.c
		$(Gc) -c Linear_Search_With_Any_Case.c

Print_List.o: Print_List.c
		$(Gc) -c Print_List.c

To_Lower.o: To_Lower.c
		$(Gc) -c To_Lower.c

Red_Black_Tree.o: Red_Black_Tree.c
		$(Gc) -c Red_Black_Tree.c

clean:
		rm -rf *.o base