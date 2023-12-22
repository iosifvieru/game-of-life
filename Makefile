main: main.o functii.o
	gcc -Wall main.o functii.o -o main

main.o: header.h
	gcc -c -Wall main.c

functii.o: header.h
	gcc -c -Wall functii.c

clean:
	rm *.o
	rm main
