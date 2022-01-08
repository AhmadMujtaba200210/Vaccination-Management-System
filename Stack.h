#pragma once
#include<iostream>
using namespace std;
struct Node {
	char data;
	Node* next = NULL;

};
struct Stack {
private:
	Node* top = NULL;

	Node* createNode(char c) {
		Node* ptr = new Node();
		ptr->data = c;
		return ptr;
	}
	Node* findSTop() {
		Node* temp = top;
		while (temp != NULL) {
			if (temp->next == top) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
public:
	void push(char c) {
		Node* ptr = createNode(c);
		if (top == NULL) {
			ptr->next = top;
			top = ptr;
			return;
		}
		else {
			ptr->next = top;
			top = ptr;
		}

	}

	char pop() {
		if (top == NULL) {
			cout << "Stack is empty!" << endl;
		}
		else {
			Node* temp = top;
			top = top->next;
			return temp->data;
		}
	}
	void makeReverse(string str) {
		for (int i = 0; i < str.length(); i++) {
			push(str[i]);
		}
	}


	void display() {
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}


};

//int main() {
//	Stack s;
//	string str = "Faizan";
//	for (int i = 0; i < str.length(); i++) {
//		s.push(str[i]);
//	}
//	s.display();
//
//	cout << "\n";
//	str = "aaasad";
//	for (int i = str.length() - 1; i >= 0; i--)
//	{
//		str[i] = s.pop();
//	}
//	cout << str;
//}