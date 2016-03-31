#include"Graph.h"
#include "Rect.h"
#include<iostream>
#pragma once
using namespace std;

typedef struct ListNode{
	Graph *data;
	ListNode* next;
	ListNode* front;

}*Node;

class MyList{
private:
	Node _head;
	int _size;
	int _next_count;
public:
	MyList();
	~MyList();
	int size();
	void add(Graph *p);
	void remove(Graph *p);
	void clear();
	Graph* get(int location);
	void swapwith_0(int location);

};

MyList::MyList(){
	printf("dodoodododod");
	_head = (Node)malloc(sizeof(ListNode));
	_head->next = (Node)malloc(sizeof(ListNode));
	_head->front = (Node)malloc(sizeof(ListNode));
	_head->data = (Graph*)malloc(sizeof(Graph));

	_size = 0;
	_next_count = 1;
}

MyList::~MyList(){
	printf("deaddeaddeaddead");
	Node temp;
	for (int i = 0; i < _size; i++){
		temp = _head;
		_head = _head->next;
		free(temp);

	}
	free(&_head);
}

int MyList::size(){
	return _size;
}

void MyList::add(Graph *p){
	Node temp;
	//初始化
	temp = (Node)malloc(sizeof(ListNode));
	temp->next = (Node)malloc(sizeof(ListNode));
	temp->front = (Node)malloc(sizeof(ListNode));
	temp->data = (Graph*)malloc(sizeof(Graph));
	//初始化结束
	temp->data = p;
	temp->next = _head->next;
	temp->front = _head;
	_head->next->front = temp;
	_head->next = temp;
	
	_size += 1;

}

void MyList::remove(Graph *p){
	Node temp;
	_size -= 1;
	temp = _head;
	for (int i = 0;i<_size; i++){
		if (temp->data == p){
			//remove temp
			temp->front->next = temp->next;
			temp->next->front = temp->front;
			free(temp);
		}
	}
}

Graph* MyList::get(int location){
	Node temp;
	temp = _head;
	for (int i = -1; i < location; i++){
		temp = temp->next;
		//cout << "loop location:" <<location<< "\n";
	}
	//cout << _size << "\n";
	return temp->data;
}


void MyList::swapwith_0(int location){
	Graph* p = get(location);
	remove(p);
	add(p);
}