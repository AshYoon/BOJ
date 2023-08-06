#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE (10)

typedef int Element;
typedef struct {
	Element queue[MAX_SIZE];
	int front, rear, size;

}Queue;


void init(Queue* q);
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enQueue(Queue* q, Element data);
Element deQueue(Queue* q);
Element peep(Queue* q);

#endif