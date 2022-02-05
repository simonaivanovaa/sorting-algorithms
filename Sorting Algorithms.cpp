#include <iostream>

template <typename T>
void InsertionSort(T* array, int n){
    for (int i = 0; i < n; ++i){
        T key = array[i];
        int index = i - 1;

        while (index >= 0 && array[index] > key){
            array[index + 1] = array[index];
            index--;
        }

        if (index != i - 1) 
            array[index + 1] = key;
        
    }
}

template <typename T>
void swap(T* first, T* second){
    T temp = *first;
    *first = *second;
    *second = temp;
}

template <typename T>
void BubbleSort(T* array, int n){
    bool isSwapped = true;

    for (int i = 0; i < n && isSwapped; i++){
        isSwapped = false;
        for (int j = 1; j < n; ++j){
            if (array[j - 1] > array[j]){
                swap(&array[j - 1], &array[j]);
                isSwapped = true;
            }
        }
    }
}

template <typename T>
void SelectionSort(T* array, int n){
    for (int i = 0; i < n; ++i){
        int minIndex = i;
        for (int j = i + 1; j < n; ++j){
            if (array[j] < array[minIndex])            
                minIndex = j;
        }

        if (minIndex != i)
            swap(&array[i], &array[minIndex]);
    }
}

template <typename T>
void merge(T* array1, int n1, T* array2, int n2){
    int size = n1 + n2;
    T* array = new T[size];
    int index = 0, index1 = 0, index2 = 0;

    while (index1 < n1 && index2 < n2){
        if (array1[index1] <= array2[index2]){
            array[index++] = array1[index1++];
        }
        else{
            array[index++] = array2[index2++];
        }
    }

    while (index1 < n1){
        array[index++] = array1[index1++];
    }

    while (index2 < n2){
        array[index++] = array2[index2++];
    }

    for (int i = 0; i < size; i++){
        array1[i] = array[i];
    }

    delete[] array;
}

template <typename T>
void MergeSort(T* array, int n){
    if (n <= 1)   
        return;   

    int mid = n / 2;
    MergeSort(array, mid);
    MergeSort(array + mid, n - mid);
    merge(array, mid, array + mid, n - mid);
}


template <typename T>
int Partition(T* array, int n){
    int pivotId = n / 2;
    T pivot = array[pivotId];
    int left = 0, right = n - 1;
    int index = left;

    while (index <= right){
        if (array[index] < pivot){
            std::swap(array[left++], array[index++]);
        }
        else if (array[index] > pivot){
            std::swap(array[index], array[right--]);
        }
        else{
            index++;
        }
    }

    return right;
}

template <typename T>
void QuickSort(T* array, int n){
    if (n <= 1)   
        return;
   
    int pivotIndex = Partition(array, n);
    QuickSort(array, pivotIndex);
    QuickSort(array + pivotIndex + 1, (n - pivotIndex - 1));
}

template <typename T>
void print(T* array, int size){

    for (int i = 0; i < size; ++i){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

}
const int SIZE = 10;


int main(){
    int array[SIZE] = { 2,4,5,2,4,6,8,-16,7,9 };

    //BubbleSort(array, SIZE);
    //SelectionSort(array, SIZE);
    //InsertionSort(array, SIZE);
    //QuickSort(array, SIZE);
    MergeSort(array, SIZE);

    print(array, SIZE);

    return 0;

}

