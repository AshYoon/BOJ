#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "binaryTreePointer.h"
#define MAX_SIZE (10)

typedef int Element;
//typedef Node TreeElement;

typedef struct {
	TreeElement queue[MAX_SIZE];
	int front, rear, size;
}Queue;



void init(Queue* q);
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enQueue(Queue* q, TreeElement data);
TreeElement deQueue(Queue* q);
//TreeElement peep(Queue* q);

#endif