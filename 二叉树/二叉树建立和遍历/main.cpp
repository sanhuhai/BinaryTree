#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct Node {
	char data;
	struct Node* letfchild, * rightchild;
}Node ,*TNode;

class Tree
{
public:
	Tree();
	~Tree();
	void createBinaryTree(TNode &T);
	void preorderTraversal(TNode &T);
	void inorderTraversal(TNode &T);
	void postorderTraversal(TNode &T);
	void levelTraversal(TNode T);
	void nonRecuision(TNode T);

	TNode root ;
};

Tree::Tree()
{
	root = new Node;
}

Tree::~Tree()
{
}

void Tree::createBinaryTree(TNode &T) {
	char data;
	cin >> data;
	if (data == '#') {
		T = NULL;
	}
	else {
		T->data = data;
		T->letfchild = new Node;
		T->rightchild = new Node;
		createBinaryTree(T->letfchild);
		createBinaryTree(T->rightchild);
	}
}

void Tree::preorderTraversal(TNode &T) {
	if (T) {
		cout << T->data << " ";
		preorderTraversal(T->letfchild);
		preorderTraversal(T->rightchild);
	}
}

void Tree::inorderTraversal(TNode& T) {
	if (T) {
		inorderTraversal(T->letfchild);
		cout << T->data << " ";
		inorderTraversal(T->rightchild);
	}
}

void Tree::postorderTraversal(TNode& T) {
	if (T) {
		postorderTraversal(T->letfchild);
		postorderTraversal(T->rightchild);
		cout << T->data << " ";
	}
}

void Tree::levelTraversal(TNode T) {
	queue<TNode> QT;
	QT.push(T);
	while (!QT.empty()&&T) {
		cout << T->data << " ";
		if (T->letfchild) QT.push(T->letfchild);
		if (T->rightchild)QT.push(T->rightchild);
		QT.pop();
		if (!QT.empty()) T = QT.front();
	}
	putchar(10);
}

void Tree::nonRecuision(TNode T) {
	stack <TNode> S;
	while (!S.empty()||T) {
		while (T) {
			cout << T->data << " ";
			S.push(T);
			T = T->letfchild;
		}
		if (!S.empty()) {
			T = S.top();
			S.pop();
			T = T->rightchild;
		}
		
	}
}

int main() {
	Tree T;
	T.createBinaryTree(T.root);
	T.preorderTraversal(T.root);
	putchar(10);
	T.inorderTraversal(T.root);
	putchar(10);
	T.postorderTraversal(T.root);
	putchar(10);
	T.levelTraversal(T.root);
	T.nonRecuision(T.root);
	return 0;

}