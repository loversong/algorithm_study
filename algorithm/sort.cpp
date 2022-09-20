#include <iostream>

template<typename T>
void bubble_sort(T A[], int len){
    for (int i=len-1;i>0;i--)
        for (int j=0;j<i;j++)
            if (A[j] > A[j+1])
                std::swap(A[j], A[j+1]);
}

template<typename T>
void select_sort(T A[], int len){
    for (int i=0;i<len-1;i++){
        int temp = i;
        for (int j=i;j<len;j++)
            if (temp > A[j])
                temp = j;
        std::swap(A[i], A[temp])
    }
}

template<typename T>
void insert_sort(T A[], int len){
    for (int i=1;i<len-1;i++){
        int j = i;
        while (j>=0 && A[j+1]<A[j]){
            std::swap(A[j], A[j+1])
            j--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1,23,3,21,45,5};
    int len = (int) sizeof(a) / sizeof(a[0]);
    insert_sort(a, len);
    for (int i=0;i<6;i++){
        std::cout << a[i] << std::endl;
    }
    return 0;
}
