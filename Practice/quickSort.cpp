#include <stdio.h>

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

void quickSort(int start, int end, int* arr) {
    int i = start, j = end, pivot = arr[(i+j)/2];
    while(i <= j) {
        while(arr[i] > pivot) i++;
        while(arr[j] < pivot) j--;
        if(i <= j) {
            swap(arr[i++], arr[j--]);
        }
    }
    if(i < end) quickSort(i, end, arr);
    if(j > start) quickSort(start, j, arr);
}

int main() {
    int arr[7] =  {3,9, 4, 3 , 1,6, 0};
    quickSort(0, 6, arr);
    return 0;
}