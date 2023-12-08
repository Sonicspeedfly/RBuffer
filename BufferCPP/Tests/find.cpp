#include <iostream>
#include "buffer.h"

using namespace std;

int main()
{
    ringBuffer *rBuffer = initRBuffer(10);
    //test init RBuffer
    if(sizeRBuffer(rBuffer) != 10) {
        cout << "Error size!";
        cleanRBuffer(rBuffer);
        return 1;
    }

    for(int i=0; i < sizeRBuffer(rBuffer); i++) {
        setRBuffer(rBuffer, i, (i+1)*(i+1));
    }

    // for(int i=0; i < sizeRBuffer(rBuffer); i++) { 
    //     cout << getRBuffer(rBuffer, i) << " ";
    // }

    for(int i=0; i < sizeRBuffer(rBuffer); i++) {
       if(getRBuffer(rBuffer, i) != (i+1)*(i+1)) {
           cout << "Error value!";
           cleanRBuffer(rBuffer);
           return 1;
       }
    }

    //test RBuffer
    if(getRBuffer(rBuffer, 23) != 16) {
       cout << "Error value!";
       cleanRBuffer(rBuffer);
       return 1;
    }

    setRBuffer(rBuffer, 23, 0);

    if(getRBuffer(rBuffer, 23) != 0) {
       cout << "Error value!";
       cleanRBuffer(rBuffer);
       return 1;
    }

    //insert into RBuffer test
    rBuffer = insertRBuffer(&rBuffer, 5);
    if(sizeRBuffer(rBuffer) != 11) {
       cout << "Error size!";
       cleanRBuffer(rBuffer);
       return 1;
    }
    if(getRBuffer(rBuffer, 10) != 5) {
       cout << "Error value!";
       cleanRBuffer(rBuffer);
       return 1;
    }


    //delete value from RBuffer test
    if(!deleteRBuffer(&rBuffer, 100)) {
       cout << "Error value!";
       cleanRBuffer(rBuffer);
       return 1;
    }
    if(deleteRBuffer(&rBuffer, 100) != -1) {
       cout << "Error value!";
       cleanRBuffer(rBuffer);
       return 1;
    }
    if(sizeRBuffer(rBuffer) != 10) {
       cout << "Error value!";
       cleanRBuffer(rBuffer);
       return 1;
    }


    //find all index
    rBuffer = insertRBuffer(&rBuffer, 49);
    int n = find(rBuffer, 49);
    int *f = indexRBuffers(rBuffer, 49);
    for(int i=0; i<n; i++) {
        if(f[i] != 6 && f[i] != 10) {
            cout << i+1 << ". Error index!";
            cleanRBuffer(rBuffer);
            return 1;
        }
    }

}
