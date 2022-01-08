//#pragma once
//#include"All_Classes.h"
//#include<iostream>
//using namespace std;
//class Node :public Member {
//public:
//	Node* next = NULL;
//	Node* prev = NULL;
//	string key;
//	Node(string str) :key(str), next(NULL), prev(NULL) {}
//	void createData() {
//		enterData();
//	}
//	string getKey() {
//		return key;
//	}
//};
//
//class LinkedList {
//protected:
//	Node* last = NULL;
//	Node* createNode(string key) {
//		Node* node = new Node(key);
//		return node;
//	}
//	Node* findPos(string key) {
//		Node* temp = last->next;
//		do {
//			if (temp->getKey() == key) {
//				return temp;
//			}
//			temp = temp->next;
//		} while (temp != last->next);
//		return NULL;
//
//	}
//public:
//	void insertAtStart(string key) {
//		if (last == NULL) {
//			Node* ptr = createNode(key);
//			last = ptr;
//		}
//		else if (last->next == NULL) {
//			Node* ptr = createNode(key);
//			last->next = ptr;
//			ptr->prev = last;
//			ptr->next = last;
//			last->prev = ptr;
//		}
//		else {
//			Node* ptr = createNode(key);
//			ptr->next = last->next;
//			ptr->prev = last;
//			last->next->prev = ptr;
//			last->next = ptr;
//		}
//	}
//	void insertAtEnd(string key) {
//		if (last == NULL) {
//			Node* ptr = createNode(key);
//			last = ptr;
//		}
//		else if (last->next == NULL) {
//			Node* ptr = createNode(key);
//			ptr->next = last;
//			last->prev = ptr;
//			ptr->prev = last;
//			ptr->next = last;
//			last = ptr;
//		}
//		else {
//			Node* ptr = createNode(key);
//			ptr->next = last->next;
//			last->next->prev = ptr;
//			ptr->prev = last;
//			last->next = ptr;
//			last = ptr;
//		}
//	}
//
//	void insertAtPos(string key) {
//		Node* pos = findPos(key);
//		if (pos == NULL) {
//			return;
//		}
//		else if (pos != NULL && (last->next == NULL)) {
//			insertAtEnd(key);
//		}
//		else if (pos != NULL) {
//			Node* ptr = createNode(key);
//			ptr->next = pos->next;
//			pos->next = ptr;
//			ptr->prev = pos;
//			ptr->next->prev = ptr;
//		}
//	}
//	void deleteAtFirst() {
//		if (last == NULL) { return; }
//		else {
//			last->next = last->next->next;
//			delete last->next->prev;
//			last->next->prev = last;
//		}
//	}
//	void deleteAtLast() {
//		if (last == NULL) {
//			return;
//		}
//		else {
//			Node* temp = last;
//			last->next->prev = last->prev;
//			last->prev->next = last->next;
//			last = last->prev;
//			delete temp;
//			temp = NULL;
//		}
//
//	}
//	void deleteAtPos(string key) {
//		Node* pos = findPos(key);
//		if (pos == NULL) {
//			return;
//		}
//		else if (pos->next == NULL) {
//			deleteAtLast();
//		}
//		else if (pos->prev == NULL) {
//			deleteAtFirst();
//		}
//		else if (pos != NULL) {
//			Node* Temp = pos;
//			pos->prev->next = pos->next;
//			pos->next->prev = pos->prev;
//			delete Temp;
//			Temp = NULL;
//		}
//	}
//	/*void display() {
//		Node* temp = last->next;
//		do {
//			cout << temp->getKey() << "->";
//			temp = temp->next;
//		} while (temp != last->next);
//		cout << "NULL" << endl;
//	}*/
//};