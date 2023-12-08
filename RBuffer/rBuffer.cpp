#include <iostream>
#include "buffer.h"
#define INFO "0.Закончить работу с кольцевым буффером и выйти из программы.\n1.Вывести кольцевой буффер.\n2.Вывести элемент из кольцевого буффера по индексу.\n3.Изменить элемент из кольцевого буффера по индексу.\n4.Добавить элемент в кольцевой буффер.\n5.Удалить эелемент из кольцевого буффера.\n6.Удалить элемент и похожие элементы из кольцевого буффера.\n7.Вывести индекс элемента.\nВыберите действие над кольцевым буффером: "
#define ERROR_TEXT "Некорректный ввод данных!"

using namespace std;

void menu(ringBuffer *arr);

int main()
{setlocale(0,"");
    ringBuffer *rBuffer = NULL;
    int bufSize, a;
    bool isError = false;

    cout<<"Инициализируйте кольцевой буффер, для это введите его размер: ";
    if(cin>>bufSize && bufSize > 0) {
        rBuffer = initRBuffer(bufSize);
        cout<<"Заполните кольцевой буффер элементами: "<< endl;
        for(int i = 0; i < bufSize && !isError; i++){
            if(cin>>a) {
                setRBuffer(rBuffer, i, a);
            } else {
                isError = true;
            }
        }
    } else {
        isError = true;
    }

    if(!isError) {
        menu(rBuffer);
    } else {
        cout<<ERROR_TEXT<<endl;
    }
    return 0;
}

void menu(ringBuffer *arr) {
    //system("clear");
    int command;
    int a, value, foundV, foundI, t = 0;
    bool isError = false;
    cout<<INFO;
    while(cin>>command && command != 0) {
        if(command == 1) {
            for(int i=0; i < sizeRBuffer(arr); i++) {
                cout<<getRBuffer(arr, i)<<" ";
            }
        } else if (command == 2) {
            cout<<"Введите номер элемента, который нужно вывести: ";
            if(cin>>a) {
                a--;
                cout<<getRBuffer(arr, a);
            } else {
                isError = true;
            }
        } else if (command == 3) {
            cout<<"Введите номер элемента: ";
            if(cin>>a) {
                cout<<"На какое значение поменять: ";
                if(cin>>value) {
                    a--;
                    foundV = getRBuffer(arr, a);
                    foundI = ost(a,sizeRBuffer(arr));
                    setRBuffer(arr, a, value);
                    cout<<"Элемент "<<foundV<<" под индексом "<<foundI<<" был изменён на "<<getRBuffer(arr, a);
                } else {
                    isError = true;
                }

            } else {
                isError = true;
            }
        } else if (command == 4) {
            cout<<"Введите значение нового элемента: ";
            if(cin>>value) {
                arr = insertRBuffer(&arr, value);
                cout<<"Элемент "<<value<<" был добавлен в кольцевой буфер";
            } else {
                isError = true;
            }
        } else if (command == 5) {
            cout<<"Введите значение элемента, который нужно удалить: ";
            if(cin>>value) {
                foundI = deleteRBuffer(&arr, value);
                if(foundI == -1) {
                   cout<<"Элемент "<<value<<" не был найден";
                } else {
                    cout<<"Элемент "<<value<<" под индексом "<<foundI<<" был удалён из кольцевого буфера";
                }
            } else {
                isError = true;
            }
        } else if (command == 6) {
            cout<<"Введите значение элемента, который нужно удалить: ";
            if(cin>>value) {
                t = find(arr, value);
                int *delInd = new int[t];
                delInd = indexRBuffers(arr, value);
                deleteAllRBuffer(&arr, value);
                if(t == 0) {
                     cout<<"Элемент "<<value<<" не был найден";
                } else {
                    cout<<"Элементы "<<value<<" под индексом ";
                    for(int i=0; i<t; i++) {
                        cout<<delInd[i]<<" ";
                    }
                    cout<<"были удалёны из кольцевого буфера";
                }
                t=0;
                if(delInd != NULL) {
                    delete[] delInd;
                }
            } else {
                isError = true;
            }
        } else if (command == 7) {
            cout<<"Введите значение элемента, индекс которого нужно вывести: ";
            if(cin>>value) {
                t = find(arr, value);
                int *delInd = new int[t];
                delInd = indexRBuffers(arr, value);
                if(t == 0) {
                    cout<<"Элемент "<<value<<" не был найден";
                } else {
                    for(int i=0; i<t; i++) {
                        cout<<delInd[i]<<" ";
                    }
                }
                t=0;
                if(delInd != NULL) {
                    delete[] delInd;
                }
            } else {
                isError = true;
            }
        } else {
            cout<<"Была введена неизвестная команда!";
        }
        if(isError) {
            cout<<ERROR_TEXT<<endl;
        } else {
            cout<<endl;
        }
    }
    if(arr != NULL) {
        cleanRBuffer(arr);
    }
}
