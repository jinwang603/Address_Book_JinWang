Address_Book_JinWang:Address_book.o main.o
	g++ Address_book.o main.o -o Address_Book_JinWang

Address_book.o:Address_book.cpp Address_book.h
	g++ -c Address_book.cpp -o Address_book.o
main.o:main.cpp Address_book.h
	g++ -c main.cpp -o main.o
clean:
	rm -rf *.o Address_Book_JinWang
