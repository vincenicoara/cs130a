#ifndef ULLNODE_H
#define ULLNODE_H 

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

#endif