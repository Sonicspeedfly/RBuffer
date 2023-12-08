#ifndef BUFFER_H
#define BUFFER_H

#include <vector>

// Non-resizeable buffer
struct ringBuffer;

int ost(int a, int b);
ringBuffer *initRBuffer(int sizeBuffer);
int sizeRBuffer(ringBuffer *arr);
ringBuffer *insertRBuffer(ringBuffer **arr, int value);
void cleanRBuffer(ringBuffer *arr);
int find(ringBuffer *arr, int value);
int indexRBuffer(ringBuffer *arr, int value, int *t);
int *indexRBuffers(ringBuffer *arr, int value);
int deleteRBuffer(ringBuffer **arr, int value);
int deleteAllRBuffer(ringBuffer **arr, int value);
int getRBuffer(ringBuffer *arr, int index);
void setRBuffer(ringBuffer *arr, int index, int value);

#endif