#include <iostream>
#include "buffer.h"

struct ringBuffer {
    int sizeBuffer;
    int *value;
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
    ringBuffer *buf = new ringBuffer();
    buf->sizeBuffer = sizeBuffer;
    buf->value = new int[sizeBuffer];
    return buf;
}

int sizeRBuffer(ringBuffer *arr) {
    return arr->sizeBuffer;
}


int getRBuffer(ringBuffer *arr, int index) {
    if (index >= 0) {
        return arr->value[ost(index,sizeRBuffer(arr))];
    } else {
        return -1;
    }
}

void setRBuffer(ringBuffer *arr, int index, int value) {
    if (index >= 0) {
        arr->value[ost(index,sizeRBuffer(arr))] = value;
    }
}

ringBuffer *insertRBuffer(ringBuffer **arr, int value) {
    ringBuffer *buf = new ringBuffer();
    buf->sizeBuffer = sizeRBuffer(*arr) + 1;
    buf->value = new int[sizeRBuffer(*arr) + 1];
    for(int i=0; i<sizeRBuffer(*arr); i++) {
        setRBuffer(buf, i, getRBuffer(*arr, i));
    }
    cleanRBuffer(*arr);
    setRBuffer(buf, sizeRBuffer(buf) - 1, value);
    return buf;
}

void cleanRBuffer(ringBuffer *arr) {
    delete[] arr->value;
    delete arr;
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

int find(ringBuffer *arr, int value) {
    int t = 0;
    for(int i = 0; i < sizeRBuffer(arr); i++) {
        if(getRBuffer(arr, i) == value) {
            t++;
        }
    } 
    return t;
}

int *indexRBuffers(ringBuffer *arr, int value) {
    int t = find(arr, value);
    //std::cout << t << std::endl;
    int *result = new int[t];
    if(t != 0) {
        int sch = 0;
        for(int i = 0; i < sizeRBuffer(arr); i++) {
            if(getRBuffer(arr, i) == value) {
                result[sch] = i;
                sch++;
            }
        }
        // for(int i = 0; i < t; i++) {
        //     std::cout << result[i] << " ";
        // }
    }
    return result;
}

int deleteRBuffer(ringBuffer **arr, int value) {
    int dataIndex = indexRBuffer(*arr, value);
    if (dataIndex != -1) {
        ringBuffer *buf = new ringBuffer();
        buf->sizeBuffer = sizeRBuffer(*arr) - 1;
        buf->value = new int[sizeRBuffer(*arr) - 1];
        for (int i = 0; i < sizeRBuffer(*arr) - 1; i++) {
            if(i >= dataIndex) {
                setRBuffer(buf, i, getRBuffer(*arr, i+1));
            } else {
                setRBuffer(buf, i, getRBuffer(*arr, i));
            }
        }
        cleanRBuffer(*arr);
        *arr = new ringBuffer();
        (*arr)->sizeBuffer = sizeRBuffer(buf);
        (*arr)->value = new int[sizeRBuffer(buf)];
        for (int i = 0; i < sizeRBuffer(buf); i++) {
            setRBuffer(*arr, i, getRBuffer(buf, i));
        }
        cleanRBuffer(buf);
    }

    return dataIndex;
}

int deleteAllRBuffer(ringBuffer **arr, int value) {
    int dataIndex = indexRBuffer(*arr, value);
    if(dataIndex == -1) {
        return dataIndex;
    }
    while (dataIndex != -1) {
        deleteRBuffer(arr, value);
        dataIndex = indexRBuffer(*arr, value);
    }

    return 1;
}
