#include <iostream>
#include "buffer.h"

struct ringBuffer {
    int sizeBuffer;
    int value;
};

int ost(int a, int b){
    int res;
    if(a<0) {
        while(a < 0) {
            a += b;
            res = a;
        }
        res++;
    } else {
        while(a >= 0) {
            res = a;
            a -= b;
        }
    }

    return res;
}


ringBuffer *initRBuffer(int sizeBuffer) {
    return new ringBuffer{sizeBuffer, 0};
}

int sizeRBuffer(ringBuffer *arr) {
    return arr->sizeBuffer;
}


int getRBuffer(ringBuffer *arr, int index) {
    return arr[ost(index,sizeRBuffer(arr))].value;
}

void setRBuffer(ringBuffer *arr, int index, int value) {
    arr[ost(index,sizeRBuffer(arr))].value = value;
}

void insertRBuffer(ringBuffer *arr, int value) {
    arr[sizeRBuffer(arr)].value = value;
    (*arr).sizeBuffer = sizeRBuffer(arr) + 1;
}

void cleanRBuffer(ringBuffer *arr) {
    delete[] arr;
}

int indexRBuffer(ringBuffer *arr, int value) {
    int result = -1;
    for(int i = 0; i < sizeRBuffer(arr); i++) {
        if(getRBuffer(arr, i) == value) {
            result = i;
        }
    }
    return result;
}

int *indexRBuffers(ringBuffer *arr, int value, int *t) {
    (*t) = 0;
    for(int i = 0; i < sizeRBuffer(arr); i++) {
        if(getRBuffer(arr, i) == value) {
            (*t) = (*t) + 1;
        }
    } 
    std::cout << (*t);
    if((*t) != 0) {
        int *result = new int(*t);
        int sch = 0;
        for(int i = 0; i < sizeRBuffer(arr); i++) {
            if(getRBuffer(arr, i) == value) {
                result[sch] = i;
                sch++;
            }
        }
        for(int i = 0; i < (*t); i++) {
            std::cout << result[i] << " ";
        }
        return result;
    }
    
    return NULL;
}

int deleteRBuffer(ringBuffer *arr, int value) {
    int dataIndex = indexRBuffer(arr, value);
    if (dataIndex != -1) {
        for (int i = dataIndex; i < sizeRBuffer(arr) - 1; i++) {
            arr[i].value = arr[i + 1].value;
        }
        arr[sizeRBuffer(arr) - 1].value = 0;
        (*arr).sizeBuffer = sizeRBuffer(arr) - 1;
    }

    return dataIndex;
}

void deleteAllRBuffer(ringBuffer *arr, int value) {
    int dataIndex = indexRBuffer(arr, value);
    while (dataIndex != -1) {
        for (int i = dataIndex; i < sizeRBuffer(arr) - 1; i++) {
            arr[i].value = arr[i + 1].value;
        }
        arr[sizeRBuffer(arr) - 1].value = 0;
        (*arr).sizeBuffer = sizeRBuffer(arr) - 1;

        dataIndex = indexRBuffer(arr, value);
    }
}
