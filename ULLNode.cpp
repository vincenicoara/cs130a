#include <iostream>
#include "tester.h"

ULLNode::ULLNode(){
	this->data = 0;
	this->next = NULL;
}
ULLNode::ULLNode(int i){
	this->data = i;
	this->next = NULL;
}
/*
ULLNode::~ULLNode(){
	this->data = 0;
	this->next = NULL;
}
*/
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
