debug:
	./program.out -d

run:
	./program.out

build: main.o linked_list_func.o interact_ll.o main.h 
	rm *.out ; gcc main.o linked_list_func.o interact_ll.o -o program.out && rm *.o  

helper_ll.o: main.h
	gcc -c helper_ll.c

linked_list_func.o: main.h
	gcc -c linked_list_func.c
	
main.o: main.h
	gcc -c main.c

