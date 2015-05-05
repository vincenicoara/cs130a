class TrieNode: public BasicTrieNode{
private:
	BasicTrieNode *ptr[TrieMaxElem];
public:
	int WhoAmI() {return(1);}
	bool CheckTrie(int*);
};