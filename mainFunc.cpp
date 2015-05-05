#include <iostream>
#include "tester.h"


using namespace std;

int main(int argc, char **argv){
	
	string x = "cat";
	string y = "bunny";


	Trie *trie = new Trie();

	trie->Create(x);
	trie->Create(y);

	trie->Insert(x, 5);
	trie->Insert(x, 4);
	trie->Insert(x, 5);

	trie->Create(x);

	trie->Insert(x, 2);
	trie->Insert(x, 1);
	trie->Insert(x, 0);



	trie->Insert(y, 12);
	trie->Insert(y, 56);
	trie->Insert(y, 456);
	trie->Insert(y, 1);

	cout << "created!" << endl;

	trie->DeleteAll(x);

	cout << "y: ";

	trie->printAllElements(y);

	cout << endl << "x: " << endl;
	trie->printAllElements(x);

	cout << endl;

	return 0; 

}