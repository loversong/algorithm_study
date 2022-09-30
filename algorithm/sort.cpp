#include <iostream>
#include <vector>
#include <cmath>

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
        std::swap(A[i], A[temp]);
    }
}

template<typename T>
void insert_sort(T A[], int len){
    for (int i=1;i<len-1;i++){
        int j = i;
        while (j>=0 && A[j+1]<A[j]){
            std::swap(A[j], A[j+1]);
            j--;
        }
    }
}

int get_shell_step(int n){
    int l = n % 2;
    int m = n / 2;
    int ret;
    if (l==0)
        ret = 9*std::pow(4,m) - 9*std::pow(2,m) + 1;
    else
        ret = std::pow(2,m+2)*(std::pow(2,m+2)-3) + 1;
    return ret;
}

template<typename T>
void shell_sort(T A[], int len){
    std::vector<int> step;
    int n = 0;
    int temp = 0;
    do{
        temp = get_shell_step(n);
        step.push_back(temp);
        n++;
    }
    while (temp < len);
    for (int i=step.size()-1;i>=0;i--){
        int h = step[i];
        for (int i=1;i<len-h;i++){
            int j = i;
            while (j>=0 && A[j+h]<A[j]){
                std::swap(A[j], A[j+h]);
                j--;
            }
        }
    }
}

template<typename T>
void merge_sort(T A[], int len){
    T *a = A;
    T *b = new T[len];
    for (int seg=1;seg<len;seg+=seg){
        for (int low=0;low<len;low+=seg+seg){
            int mid = std::min(low+seg, len);
            int high = std::min(low+seg+seg, len);
            int k = low;
            int cur1 = low;
            int cur2 = mid;
            while (cur1<mid && cur2<high)
                b[k++] = a[cur1]<a[cur2] ? a[cur1++] : a[cur2++];
            while (cur1<mid)
                b[k++] = a[cur1++];
            while (cur2<high)
                b[k++] = a[cur2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a!=A){
        for (int i=0;i<len;i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

template<typename T>
int quick_sort_partition(T A[] , int low, int high){
    int pivot = A[low];
    while (low < high){
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

template<typename T>
void quick_sort(T A[], int low, int high){
    if (low < high){
        int pivot = quick_sort_partition(A, low, high);
        quick_sort(A, low, pivot-1);
        quick_sort(A, pivot+1, high);
    }
}

template<typename T>
void quick_sort(T A[], int len){
    quick_sort(A, 0, len-1);
}


int main(int argc, char const *argv[])
{
    int a[] = {1,23,3,21,45,5};
    int len = (int) sizeof(a) / sizeof(a[0]);
    quick_sort(a, len);
    for (int i=0;i<6;i++){
        std::cout << a[i] << std::endl;
    }
    return 0;
}
