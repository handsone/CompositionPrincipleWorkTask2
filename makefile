main.o:  task2.h main.c task2.c
	gcc main.c  task2.c -o main -lm `pkg-config --cflags --libs gtk+-3.0` ; ./main
