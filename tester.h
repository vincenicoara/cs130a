#ifndef TESTER_H
#define TESTER_H
#include <string>

using namespace std;

const int StrMaxElem = 81;
const int TrieMaxElem = 26;

class MultiSet{
private:
	int number; // # of elements in the multiset
	MultiSet* ptr2previousVersion;
public:
	MultiSet();
	virtual int WhoAmI() {return 1;}
	MultiSet * getptr2prev();
	void setptr2prev(MultiSet *);
	int getNumber();
	void numberPlus();
	void numberMinus();
	int addNumberElements(int i){number += i; return number;}
};

class ULLNode {
private:
	int data;
	ULLNode *next;
public:
	ULLNode();
	ULLNode(int);
	ULLNode* getNext();
	int getData();
	void setNext(ULLNode*);
	void setData(int);
};

class ULL: public MultiSet{
private:
	ULLNode* first;
public:
	ULL();
	~ULL();
	ULLNode* getFirst();
	void setFirst(ULLNode*);
	void insert(int);
	void deleteValue(int);
	void deleteAllValues(int);
	int deleteMin();
	int deleteMax();
	void deleteAll();
	int minElem();
	int maxElem();
	void printAll();
	void printNumberElements();
	void printMin();
	void printMax();
	int distance(int k);
	void append(ULLNode*);
	int WhoAmI(){return 2;}
};

class BasicTrieNode {
private:
    MultiSet   *ptr2ms;
    int        number;
public:
	BasicTrieNode() {ptr2ms = 0; number=0;}
 	virtual int WhoAmI() {return(0);}
 	virtual bool CheckTrie(int*);                                
 	virtual void SetPtr(int i, BasicTrieNode* j){}
 	virtual BasicTrieNode* GetPtr(int i) {}
 	void SetPtr2MS(MultiSet* ptr) {ptr2ms = ptr;}
 	MultiSet* GetPtr2MS() {return ptr2ms;}
 	void numberPlus() {number++;}
 	void numberMinus() {number--;}
 	void addNumberMultiSets(int i) {number + i;}
 	int getNumberMultiSets(){return number;}
 	bool containsMultiSet(){
  		if (ptr2ms == NULL) return false;
  		else return true;
	}
};

class TrieNode:  public BasicTrieNode{
private:
  	BasicTrieNode* ptr[TrieMaxElem];
public:
  	TrieNode()
  		{BasicTrieNode();
    	int i;
    	for (i=0; i < TrieMaxElem; i++)
      		SetPtr(i,0);
  		}
  	int WhoAmI() {return(1);}
  	bool CheckTrie(int*);                                
  	void SetPtr(int i, BasicTrieNode* j) {ptr[i]=j;}
  	BasicTrieNode* GetPtr(int i) {return ptr[i];}
};

class Trie {
private:
    BasicTrieNode *root;
    //bool Delete(char x[], int i, TrieNode *current );
  	bool CheckTrieNodeEmpty(TrieNode *current);
  	int CountN(BasicTrieNode*);
public:
	Trie() ;
  	void Create(string);
  	void Insert(string x, int);
  	void Merge(string, string);
  	void DeleteElem(string x, int);
  	void DeleteMax(string x);
  	void PrintMax(string x);
  	void PrintMin(string x);
  	void PrintNum(string x);
  	void Dist(string x, int k);
  	void CountN();
  	bool Member(string x);
  	void Delete(string x);
  	void DeleteAll(string x);
  	void deleteRec(string x);
  	void deleteAllRec(string x);
    bool CheckTrie(int*);
    BasicTrieNode* pointerToWord(string x); 
    void printAllElements(string x);
    bool containsMultiset(BasicTrieNode *);                               
};



#endif