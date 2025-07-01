Gc = gcc
Sources = main.o Add_To_CSV.o Bin_Search_Tree.o Bin_Tree.o Create_And_Print_List.o Linear_Search.o To_Lower.o Red_Black_Tree.o 
all: base 

base: $(Sources)
		$(Gc) $(Sources) -o base 

main.o: main.c
		$(Gc) -c main.c

Bin_Search_Tree.o: Bin_Search_Tree.c
		$(Gc) -c Bin_Search_Tree.c

Bin_Tree.o: Bin_Tree.c
		$(Gc) -c Bin_Tree.c

Create_And_Print_List.o: Create_And_Print_List.c
		$(Gc) -c Create_And_Print_List.c
	
Linear_Search.o: Linear_Search.c
		$(Gc) -c Linear_Search.c

To_Lower.o: To_Lower.c
		$(Gc) -c To_Lower.c

Red_Black_Tree.o: Red_Black_Tree.c
		$(Gc) -c Red_Black_Tree.c

Add_To_CSV.o: Add_To_CSV.c
		$(Gc) -c Add_To_CSV.c

clean:
		rm -rf *.o base