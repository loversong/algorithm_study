#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <malloc.h>
#include <stdio.h>


template<class T>
class PriorityQueue
{
private:
    int capacity = 100;
    int size;
    T* data;
public:
    PriorityQueue();
    ~PriorityQueue();
    int get_size();
    bool is_full();
    bool is_empty();
    void push(T key);
    T top();
    T pop();
    void increase_key(int index, T newkey);
    void clear();
};

template<class T>
PriorityQueue<T>::PriorityQueue()
{
    data = (T*) malloc((capacity + 1)*sizeof(T));
    if (!data){
        perror("Fail to allocate.");
        return;
    }
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
    while (!is_empty())
        pop();
}

template<class T>
int PriorityQueue<T>::get_size(){
    return size;
}

template<class T>
bool PriorityQueue<T>::is_full(){
    return (size==capacity);
}

template<class T>
bool PriorityQueue<T>::is_empty(){
    return (size==0);
}

template<class T>
void PriorityQueue<T>::push(T key){
    if (is_empty()){
        data[0] = key;
        size = 1;
        return;
    }
    if (is_full()){
        perror("Full already!");
        return;
    }
    data[size] = key;
    int index = size;
    size++;
    int dad = 0;
    while (index>0 && data[dad]<data[index]){
        dad = int(index/2);
        std::swap(data[dad], data[index]);
        index = dad;
    }
    return;
}

template<class T>
T PriorityQueue<T>::top(){
    if (is_empty()){
        perror("Empty queue.");
        T temp;
        return temp;
    }
    return data[0];
}

template<class T>
T PriorityQueue<T>::pop(){
    if (is_empty()){
        perror("Empty queue.");
        T temp;
        return temp;
    }
    T first = data[0];
    data[0] = data[size-1];
    int dad = 0;
    int son = 1;
    while (son < size){
        if (son+1<size && data[son]<data[son+1])
            son++;
        if (data[dad]>data[son])
            return first;
        else{
            std::swap(data[dad], data[son]);
            dad = son;
            son = dad*2+1;
        }
    }
    size--;
    return first;
}

template<class T>
void PriorityQueue<T>::increase_key(int index, T newkey){
    if (data[index]>=newkey)
        return;
    if (index<2 || index>size-1)
        return;
    data[index] = newkey;
    int dad = 0;
    while (index>0 && data[dad]<data[index]){
        dad = int(index/2);
        std::swap(data[dad], data[index]);
        index = dad;
    }
    return;
}

template<class T>
void PriorityQueue<T>::clear(){
    while (!is_empty())
        pop();
    return;
}

int main(){
    PriorityQueue<int> q;
    q.push(12);
    q.push(23);
    q.push(4);
    q.increase_key(2,1);
    int c = q.pop();
    q.pop();
    std::cout << q.pop() << std::endl;
}