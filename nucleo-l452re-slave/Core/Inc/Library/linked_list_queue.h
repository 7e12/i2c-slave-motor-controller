/**
 * @author:  7e12
 * @file:    linked_list_queue.h
 * @date:    19 Jul 2021
 * @version: v1.0.0
 * @brief:   Linked-list queue
**/

#ifndef _LINKED_LIST_QUEUE_H_
#define _LINKED_LIST_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-defined macros
#define STRING_DATA_SIZE 1024

// Struct data type definitions for the following usage
typedef struct LLQueue      LLQueueTypeDef;
typedef struct LLQueueNode  LLQueueNodeTypeDef;
typedef struct LLQueueData  LLQueueDataTypeDef;

// Linked list queue
struct LLQueue {
    LLQueueNodeTypeDef *front, *rear;
};

// Linked list queue node to store a queue entry
struct LLQueueNode {
    LLQueueNodeTypeDef *next;
    LLQueueDataTypeDef *data;
};

// Linked list queue data defined by user
struct LLQueueData {
    int motorIndex;
	int runMode;
    unsigned long stepNumber;
    int revNumber;
    int runDirection;
    unsigned long runPeriod;
};

// For everywhere usage
LLQueueTypeDef* createLLQueue(void);
int isEmpty(LLQueueTypeDef *queue);
void enQueue(LLQueueTypeDef *queue, LLQueueDataTypeDef *data);
void deQueue(LLQueueTypeDef *queue);

#endif /* _LINKED_LIST_QUEUE_H_ */
