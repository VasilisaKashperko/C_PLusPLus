#pragma once
struct list {
	int n;
	list* next;
};

struct Queue {
	list* begin, * end;
	int size;
};

Queue* create();
void adding(Queue* queue, int n);
int del(Queue* queue);
int empty(Queue* queue);
void allqueue(Queue* queue);
int clear(Queue* queue);
int show(Queue* queue);
int min(Queue* queue);
int max(Queue* queue);
int length(Queue* queue);

