GC=gcc
Sources = main.o Comparison.o Create_List.c Heap_Sort.o Print_Massive.o Quick_Sort.o Run_Sort.o Selection_Sort.o 

all: base

base: $(Sources)
	$(GC) $(Sources) -o base

main.o: main.c
	$(GC) -c main.c

Comparison.o: Comparison.c
	$(GC) -c Comparison.c

Create_List.o: Create_List.c
	$(GC) -c Create_List.c

Heap_Sort.o: Heap_Sort.c
	$(GC) -c Heap_Sort.c

Print_Massive.o: Print_Massive.c 
	$(GC) -c Print_Massive.c

Quick_Sort.o: Quick_Sort.c
	$(GC) -c Quick_Sort.c

Run_Sort.o: Run_Sort.c
	$(GC) -c Run_Sort.c

Selection_Sort.o: Selection_Sort.c
	$(GC) -c Selection_Sort.c

clean:
	rm -rf *.o base