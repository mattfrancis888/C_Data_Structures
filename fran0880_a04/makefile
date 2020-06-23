a4q1.exe : a4q1.o mystring.o myword.o
	gcc a4q1.o mystring.o myword.o -o a4q1.exe

a4q1.o : a4q1.c
	gcc -c a4q1.c

myword.o : myword.h myword.c
	gcc -c myword.c -o myword.o

mystring.o : mystring.h mystring.c
	gcc -c mystring.c -o mystring.o

test:
	a4q1 textdata.txt result.txt common-english-words.txt
clean :
	rm a4q1.o mystring.o myword.o