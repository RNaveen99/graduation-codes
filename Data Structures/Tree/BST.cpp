#include <iostream>
#include <queue>
using namespace std;
class node {
	public:
	int data;
	node * lchild;
	node * rchild;
	node(int ele, node * l = 0, node * r = 0) {
		data = ele;
		lchild = l;
		rchild = r;
	}
};

class BST {
	private :
		node * root;
		void preOrder(node *);
		void inOrder(node *);
		void postOrder(node *);
		int countLeaf(node *);
		int countNonLeaf(node *);
		node* BSTsearch(int, node *);
		int countHeight(node *);
		void getParent(int, node *&, node *&);
    	int getInorderSuccessorValue(node *&, node *&);
    	void deleteLeaf(node*&, node*&);
    	void deleteOneChildNode(node *&, node*&);
    	void deleteByCopy(node*&, node*&);
		
	public :
		BST() {
			root = 0;
		}
		void insert(int);
		void preOrder();	
		void inOrder();		
		void postOrder();		
		void levelOrder();	
		int countLeaf();
		int countNonLeaf();
		node* search(int);
		node* BSTsearch(int);
		int countHeight();
		void deleteNode(int);
		
};

//	insert element in BST
void BST :: insert(int ele) {
	node * p = new node(ele);
	if (root == 0) {
		root = p;
	}
	else {
		node * temp = root;
		node * fp = 0;
		while (temp != 0) {
			fp = temp;
			if (temp -> data > ele) {
				temp = temp -> lchild;
			}
			else {
				temp = temp -> rchild;
			}
		}
		if (fp -> data > ele) {
			fp -> lchild = p;
		}
		else {
			fp -> rchild = p;
		}
		
	}
}

//	preOrder Display for BST
void BST :: preOrder() {
	preOrder(root);
}

//	inOrder Display for BST
void BST :: inOrder() {
	inOrder(root);
}

//	postOrder Display for BST
void BST :: postOrder() {
	postOrder(root);
}

//	preOrder Overloaded for BST
void BST :: preOrder(node * root) {
	if (root == 0) {
		return;
	}
	cout << root -> data << "\t";
	preOrder(root -> lchild);
	preOrder(root -> rchild);
}

//	inOrder Overloaded for BST
void BST :: inOrder(node * root) {
	if (root == 0) {
		return;
	}
	inOrder(root -> lchild);
	cout << root -> data << "\t";
	inOrder(root -> rchild);
}

//	postOrder Overloaded for BST
void BST :: postOrder(node * root) {
	if (root == 0) {
		return;
	}
	postOrder(root -> lchild);
	postOrder(root -> rchild);
	cout << root -> data << "\t";
}

//	level order Display for BST
void BST :: levelOrder() {
	queue <node *> q;
	node * temp = 0;
	q.push(root);
	while (! q.empty()) {
		temp = q.front();
		cout << temp -> data << "\t";
		if (temp -> lchild) {
			q.push(temp -> lchild);
		}
		if (temp -> rchild) {
			q.push(temp -> rchild);
		}
		q.pop();
	}
}

//	Count no. of leaf nodes
int BST :: countLeaf() {
	return countLeaf(root);
}

//	Count no. of leaf nodes Overloaded
int BST :: countLeaf(node * temp) {
	if (temp == 0) {
		return 0;
	}
	if (temp -> lchild == 0 && temp -> rchild == 0) {
		return 1;
	}
	else {
		return countLeaf(temp -> lchild) + countLeaf(temp -> rchild);
	}
}

//	Count no. of non-leaf nodes
int BST :: countNonLeaf() {
	return countNonLeaf(root);
}

//	Count no. of non-leaf Overloaded
int BST :: countNonLeaf(node * temp) {
	if ((temp == 0) || (temp -> lchild == 0 && temp -> rchild == 0)) {
		return 0;
	}
	else if (temp -> lchild != 0 || temp -> rchild != 0) {
		return 1 + countNonLeaf(temp -> lchild) + countNonLeaf(temp -> rchild);
	}
}

//	search element in BST by iteration
node* BST :: search(int ele) {
	node * temp = root;
	bool flag = false;
	while (temp != 0 && !flag) {
		if (temp -> data == ele) {
			flag = true;
		}
		else if(temp -> data > ele){
			temp = temp -> lchild;
		}
		else if (temp -> data < ele) {
			temp = temp -> rchild;
		}
	}
	return temp;
}

//	search element in BST by Recursion
node * BST :: BSTsearch(int ele) {
	BSTsearch(ele, root);
}

//	search element in BST by Recursion Overloaded
node * BST :: BSTsearch(int ele, node * temp) {
	if (temp == 0) {
		return 0;
	}
	if (temp -> data == ele) {
		return temp;
	}
	else if (ele < temp -> data) {
		return BSTsearch(ele, temp -> lchild);
	}
	else {
		return BSTsearch(ele, temp -> rchild);
	}
}

//	count height of BST 
int BST :: countHeight() {
	return countHeight(root);
}

//	count height of BST overloaded
int BST :: countHeight(node * temp) {
	if (temp == 0) {
		return -1;
	}
	int lheight = countHeight(root -> lchild);
	int rheight = countHeight(root -> rchild);
	return 1 + (lheight > rheight ? lheight : rheight);
	
}


//--------------------------------------------------------------
//-------------------------------------------------------------
void BST :: getParent(int x, node *&prev, node *&p){
	while(p && p -> data != x){
		prev = p;
		if(x > p -> data)
			p = p -> rchild;
		else
			p = p -> lchild;
	}
}


int BST :: getInorderSuccessorValue(node* &prev, node* &p){
	prev = p;
	p = p -> rchild;
	while(p -> lchild){
		prev = p;
		p = p -> lchild;
	}
	return p -> data;
}

void BST :: deleteLeaf(node *&prev, node *&p){
	if(prev -> rchild == p)
		prev -> rchild = NULL;
	else
		prev -> lchild = NULL;
	delete p;
}

void BST :: deleteOneChildNode(node* &prev, node* &p){
	if(p -> rchild == NULL){
		if(prev -> rchild == p)
			prev -> rchild = p -> lchild;
		else
			prev -> lchild = p -> lchild;
	}
		
	else{
		if(prev -> rchild == p)
			prev -> rchild == p -> rchild;
		else
			prev -> lchild = p -> rchild;
	}
	delete p;
}

void BST :: deleteByCopy(node* &prev, node* &p){
	node *temp = p;
	temp -> data = getInorderSuccessorValue(prev, p);
	if(p -> rchild == NULL && p -> lchild == NULL)
		deleteLeaf(prev, p);
	else if(p -> rchild == NULL || p -> lchild == NULL)
		deleteOneChildNode(prev, p);	
}

//delete a node
void BST :: deleteNode(int x){
	node *p = root;
	node *prev = NULL;
	getParent(x, prev, p);
	
	if(!p)
		throw "Element not present in tree";
	else{
		if(p -> rchild == NULL && p -> lchild == NULL)
			deleteLeaf(prev, p);
		else if(p -> rchild == NULL || p -> lchild == NULL)
			deleteOneChildNode(prev, p);
		else
			deleteByCopy(prev, p);
	}
}




//---------------------------------------------------------------
//---------------------------------------------------





int main() {
	bool flag = true;
	BST b;
	while (flag) {
		cout << "\n1.Insert element" << endl;
		cout << "2.Pre-Order Display" << endl;
		cout << "3.In-Order Display" << endl;
		cout << "4.Post-Order Display" << endl;
		cout << "5.Level- Order Display " << endl;
		cout << "6.Count Leaf nodes " << endl;
		cout << "7.Count Non-Leaf nodes" << endl;
		cout << "8.Search element" << endl;
		cout << "9.Height of tree" << endl;
		cout << "10.Delete node" << endl;
		cout << "0.Exit" << endl;
		cout << "Enter option...";
		int opt;
		cin >> opt;
		switch(opt) {
			case 1: {
				cout << "Enter element.";
				int ele;
				cin >> ele;
				b.insert(ele);
				break;
			}
			case 2: {
				b.preOrder();
				break;
			}
			case 3: {
				b.inOrder();
				break;
			}
			case 4: {
				b.postOrder();
				break;
			}
			case 5: {
				b.levelOrder();
				break;
			}
			case 6: {
				cout << b.countLeaf();
				break;
			}
			case 7: {
				cout << b.countNonLeaf();
				break;
			}
			case 8: {
				cout << "\nEnter element to be searched : ";
				int ele;
				cin >> ele; 
				//node *temp = b.BSTsearch(ele);
				node * temp = b.search(ele);
				if (temp) {
					cout << "\nELement found";
				}
				else {
					cout << "\nElement not found\n";
				}
				break;
			}
			case 9: {
				cout << "Height = " << b.countHeight();
				break;
			}
			case 10: {
				cout << "Enter element to be deleted :";
				int ele;
				cin >> ele;
				b.deleteNode(ele);
				break;
			}
			case 0: {
				flag = false;
				break;
			}
		}
	}
}
