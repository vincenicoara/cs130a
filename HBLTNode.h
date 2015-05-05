class HBLTNode {
private:
	int data;
	int h;
	HBLTNode *leftchild;
	HBLTNode *rightchild;
public:
	void Insert( int );
	int DeleteMin( int );
};
