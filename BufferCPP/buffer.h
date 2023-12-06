#ifndef BUFFER_H
#define BUFFER_H

#include <vector>

// Non-resizeable buffer
struct ringBuffer;

int ost(int a, int b);
ringBuffer *initRBuffer(int sizeBuffer);
int sizeRBuffer(ringBuffer *arr);
void insertRBuffer(ringBuffer *arr, int value);
void cleanRBuffer(ringBuffer *arr);
int indexRBuffer(ringBuffer *arr, int value, int *t);
int *indexRBuffers(ringBuffer *arr, int value, int *t);
int deleteRBuffer(ringBuffer *arr, int value);
void deleteAllRBuffer(ringBuffer *arr, int value);
int getRBuffer(ringBuffer *arr, int index);
void setRBuffer(ringBuffer *arr, int index, int value);

#endif