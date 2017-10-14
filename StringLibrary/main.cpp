#include <cstdio>
#include "string.h"


void message(const char* s)
{
	puts(s);
	fflush(stdout);
}


int main()
{
	string a = "efg";
	string b;// = "asd";
	a.swap(b);
	message(a);
	message(b);



	/*string line = "This words sentence has wo lots of words in it.";
	char c = 'i';
	printf("letter found at pos: %d\n", line.char_find(c));
	string word = "words";
	printf("word in line present at %d \n", line.find(word));
	string hello = "	hello	 World! d ear	";
	message("before reverse: ");
	message(hello);
	printf("length: %d\n", hello.length());
	hello.reverse_words();
	message("after reverse: ");
	message(hello);
	printf("length: %d", hello.length());*/
	/*string h = hello;
	h += hello;
	message(h);
	char cb = hello[1];
	char* c = "Paraag";
	printf("%c", c[0]);*/
	while (!getchar());
	return 1;
}