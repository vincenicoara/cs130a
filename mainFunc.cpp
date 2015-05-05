#include <iostream>
#include <string>
#include "tester.h"


using namespace std;

int main(int argc, char **argv){
	
	string x = "cat";
	string y = "bunny";


	Trie *trie = new Trie();

	trie->Create(x);
	trie->Create(x);
	trie->Create(x);



	trie->Insert(x, 5);
	trie->Insert(x, 4);
	trie->Insert(x, 5);
	trie->Insert(x, 4);






	cout << "created!" << endl;

	//trie->PrintMin(x);

	trie->printAllElements(y);

	//trie->CountN();


	//if (trie->Member(x) && trie->Member(y))
	//	cout << "its in!" << endl;

	cout << endl;

	return 0; 

}