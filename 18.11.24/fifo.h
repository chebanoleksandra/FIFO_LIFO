#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T value;
	Node* next;
	Node() : value(0), next(nullptr) {}
	Node(T value) : value(value), next(nullptr) {}
};

template<typename T>
class ForwardList
{
	Node<T>* head;
	Node<T>* tail;
	void clear() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* temp = current->next;
			delete current;
			current = temp;
		}
		head = nullptr;
		tail = nullptr;
	}
public:
	ForwardList() : head(nullptr), tail(nullptr) {};
	void push_back(T value)
	{
		Node<T>* new_node = new Node<T>(value);
		if (tail) {
			tail->next = new_node;
		}
		else {
			head = new_node;
		}
		tail = new_node;
	}
	void print() const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	T pop_front() {
		if (head == nullptr) {
			return;
		}
		T value = head->value;
		Node<T>* temp = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		delete temp;
		return value;
	}

	T front() const {
		if (head == nullptr) {
			return;
		}
		return head->value;
	}
	Node<T>* GetHead()
	{
		return head;
	}
	Node<T>* GetTail()
	{
		return tail;
	}
	bool empty() const {
		return head == nullptr;
	}
	~ForwardList()
	{
		clear();
	}
};

template<typename T>
class Fifo {
	ForwardList<T> list;

public:
	Fifo() {}
	void Push(T value) {
		list.push_back(value);
	}
	T Pop() {
		return list.pop_front();
	}
	T Top() {
		return list.front();
	}
	bool Empty() const {
		return list.empty();
	}
	void Print() const {
		list.print();
	}
};
