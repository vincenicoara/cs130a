#include <iostream>
#include <string>
#include "tester.h"

using namespace std;



/************************ULL NODE****************************************/

ULLNode::ULLNode(){
	this->data = 0;
	this->next = NULL;
}
ULLNode::ULLNode(int i){
	this->data = i;
	this->next = NULL;
}
ULLNode::~ULLNode(){
	this->data = 0;
	this->next = NULL;
}
ULLNode* ULLNode::getNext(){
	return this->next;
}
int ULLNode::getData(){
	return this->data;
}
void ULLNode::setNext(ULLNode* j){
	this->next = j;
}
void ULLNode::setData(int j){
	this->data = j;
}

/************************ULL********************************/

ULL::ULL(){
	this->first = NULL;
}

ULL::~ULL(){
	this->deleteAll();
	this->first = NULL;
}


ULLNode* ULL::getFirst(){
	return this->first;
}

void ULL::setFirst(ULLNode *a){
	this->first = a;
}

void ULL::insert(int a){
	ULLNode* p = new ULLNode(a);
	if (this->first == NULL){
		this->first = p;
		return;
	}
	p->setNext(this->first);
	this->first = p;
}
int ULL::deleteMin(){
	if (this->first == NULL) return 0;

	ULLNode *p = this->first;
	int smallest = p->getData();
	int i = 0;

	while (p != NULL){
		if (p->getData() < smallest)
			smallest = p->getData();
		i++;
		p = p->getNext();
	}

	p = this->first;
	ULLNode *temp;

	for (int j = 0; j = i -1; j++){
		p = p->getNext();
	}
	temp = p->getNext();
	p->setNext(temp->getNext());
	delete temp;
	return smallest;
}

void ULL::deleteAll(){
	if (this->first == NULL) return;

	ULLNode *p = this->first;
	ULLNode *temp;

	while (p!= NULL){
		temp = p;
		p = p->getNext();
		delete temp;
	}
}

void ULL::printAll(){
	ULLNode *p = this->first;
	while (p != NULL){
		cout << p->getData() << endl;
		p = p->getNext();
	}
}
/************************TRIE*************************************/
bool Trie::CheckTrie(int* count)                                   //*****
      { // USE THIS PROCEDURE DIRECTLY IN YOUR CODE                //*****
        // IF YOU HAVE DIFFERENT CLASS NAMES, FUNCTIONS OR VALUES  //*****
        // YOU NEED TO CHANGE THEM HERE TOO.                       //*****
        int countl;                                                //*****
        bool result;                                               //*****
        result = root->CheckTrie(&countl);                         //*****
        *count=countl;                                             //*****
        return result;                                             //*****
      }  

bool TrieNode::CheckTrie(int* pcount)                              //*****
      { // USE THIS PROCEDURE DIRECTLY IN YOUR CODE                //*****
        // IF YOU HAVE DIFFERENT CLASS NAMES, FUNCTIONS OR VALUES  //*****
        // YOU NEED TO CHANGE THEM HERE TOO.                       //*****
        bool           result;                                     //*****
        int            i,countl,countll;                           //*****
        countl= *pcount;                                           //*****
        result=true;                                               //*****
        if (GetPtr2MS() != 0) *pcount++;                           //*****
        for(i=0; i<TrieMaxElem; i++)                               //*****
           {if(GetPtr(i)!=0)                                       //*****
             if(!GetPtr(i)->CheckTrie(pcount)) {return false;}     //*****
           }                                                       //*****
        if(countl == *pcount) return false;                        //*****
        return true;                                               //*****
      }  

bool BasicTrieNode::CheckTrie(int* pcount)                         //*****
      {if(ptr2ms == 0) {return false;}                             //*****
       *pcount++;                                                  //*****
       return true;                                                //*****
      }    


/************************Main Function********************************/

int main(int argc, char **argv){
	int b, c, d, e;
	cin >> b >> c >> d; 
	cout << "inserted!" << endl;

	ULL *y = new ULL();


	y->insert(b);
	y->insert(c);
	y->insert(d);

	cout << "Added in array!" << endl;

	//cout << y->deleteMin() << endl; 
	//cout << y->deleteMin() << endl;
	//cout << y->deleteMin() << endl;
	y->printAll();

	delete y;

	cout << "Deleted!" << endl;

	y->printAll();

	//y->printAll();

	cout << "Outputted!" << endl;



	return 0; 

}