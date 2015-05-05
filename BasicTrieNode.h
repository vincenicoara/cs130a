class BasicTrieNode {
private:
	MultiSet *ptr2ms;
	int number;
public:
	virtual int WhoAmI() {return(0);}
	virtual bool CheckTrie(int*);
};