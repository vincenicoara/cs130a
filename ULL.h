#ifndef ULL_H
#define ULL_H 
#include "MultiSet.h"

class ULL: public MultiSet{
private:
	ULLNode* first;
public:
	ULL();
	void insert(int);
	int deleteMin(int);
	void deleteAll();
	int WhoAmI(){return 2;}
};

#endif