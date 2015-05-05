all:
	g++ mainFunc.cpp ULLNode.cpp -o main 


	
void ULL::Insert(int j){
	ULLNode *newNode = new ULLNode();
	newNode->data = j;

	if (this->next == NULL){
		this->next = newNode;
		newNode->next = NULL;
		return;
	}
	ULLNode *p = this->next;

	this->next = newNode;
	newNode->next = p;
}

int ULL::DeleteMin(){
	if (this->next == NULL) return this->data;

	ULLNode *p = this;
	int min = p->data;

	while (p->next != NULL){
		if (p->data < min)
			min = p->data;
		p = p->next;
	}
	return min;
}
