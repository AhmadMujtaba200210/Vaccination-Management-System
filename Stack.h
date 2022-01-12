#pragma once
#include<iostream>
using namespace std;
struct Node {
	char data = 'a';
	Node* next = NULL;

};

struct stack {
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
			return '\0';
		}
		else {
			Node* temp = top;
			top = top->next;
			return temp->data;
		}
	}

	char* makeReverse(string str) {
		//string str2;
		int j = 0; int i;
		for (i = 0; i < str.length(); i++) {
			push(str[i]); j++;
		}
		char str2[20];
		for (i = 0; i < j; i++) {
			str2[i] = pop();
		}
		str2[i] = '\0';
		return str2;
	}


	void display() {
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

};
