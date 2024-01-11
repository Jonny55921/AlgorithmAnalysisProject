#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <iostream>
#include<chrono>
#include <cmath>

using namespace std::chrono;			//shortcut to not type std::chrono::
using namespace std;
void insertionSort(int arr[],int size)
{
    int i,data,j;
    for(i=1; i<size;i++)
    {
        data = arr[i];
        j=i-1;

    while(j>=0 && arr[j]>data)
    {
        arr[j+1]=arr[j];
        j=j-1;
    }
        arr[j+1]=data;
    }
}
int partition(int arr[], int low, int high, int pivotChoice) {
    int pivot;
    if (pivotChoice == 1) {
        pivot = arr[low];
    } else if (pivotChoice == 2) {
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[low]);
        pivot = arr[low];
    } else if (pivotChoice == 3) {
        int mid = low + (high - low) / 2;
        if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) {
            pivot = arr[mid];
            swap(arr[mid], arr[low]);
        } else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) {
            pivot = arr[low];
        } else {
            pivot = arr[high];
            swap(arr[high], arr[low]);
        }
    }

    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int pivotChoice) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, pivotChoice);
        quickSort(arr, low, pivotIndex - 1, pivotChoice);
        quickSort(arr, pivotIndex + 1, high, pivotChoice);
    }
}
void merge(int array[], int left, int middle, int right) {
    int subL = middle - left + 1;
    int subR = right - middle;

    int subArrL[subL];
    for (int i = 0; i < subL; i++) { subArrL[i] = array[left + i]; }

    int subArrR[subR];
    for (int i = 0; i < subR; i++) { subArrR[i] = array[middle + i + 1]; }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = left;

    while (leftIndex < subL && rightIndex < subR) {
        if (subArrL[leftIndex] <= subArrR[rightIndex]) {
            array[mergedIndex] = subArrL[leftIndex];
            leftIndex++;
        }
        else {
            array[mergedIndex] = subArrR[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < subL) {
        array[mergedIndex] = subArrL[leftIndex];
        mergedIndex++;
        leftIndex++;
    }

    while (rightIndex < subR) {
        array[mergedIndex] = subArrR[rightIndex];
        mergedIndex++;
        rightIndex++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void selectionSort(int arr[], int n)
{
    int min_in;
    for(int i=0;i<n;i++)
    {
        min_in = i;
        for(int j=i+1;j<n;j++)
            if (arr[j] < arr[min_in])
                min_in = j;
        swap(arr[i],arr[min_in]);
    }
}

class Heap
{
public:
//int Arr[];
//Heap();
void printArray(int Arr[],int n){
    cout<<"[";
    for(int i=0;i<25;i++)
    {
        cout<< Arr[i] << ",";
    }
    cout<<"]\n";
}
//Max heap
int parent(int i){
    return (i-1)/2;
    }
int left(int i){
    return (2*i + 1);
    }
int right(int i){
    return (2*i + 2);
    }
void modifyValMax (int Arr[], int i,int val){
    Arr[i] = val;
    while (i>1 && Arr[parent(i)]<Arr[i]){
        std::swap(Arr[i],Arr[parent(i)]);
        i = parent(i);
    }
}
void insert_value_maxHeap (int Arr[], int val, int& n){
    n++;
    Arr[n - 1] = val;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(Arr, i, n);
    }
}
void max_heapify(int Arr[], int i,int n) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l < n && Arr[l] > Arr[largest]) {
        largest = l;
    }
    if (r < n && Arr[r] > Arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(Arr[i], Arr[largest]);
        max_heapify(Arr, largest, n);
    }
}
//Needed to create two seperate functions to avoid overlapping calls in int main() while reprelcating sample output
int Maximum (int Arr[]){
    return Arr[0];
}
void extract_maximum (int Arr[], int& n){
    Arr[0] = Arr[n - 1];
    n--;
    max_heapify(Arr, 0, n);
}
void ascendingHeapSort(int Arr[], int n){
    buildMaxHeap(Arr, n);
    for (int i = n - 1; i > 0; i--) {
        std::swap(Arr[0], Arr[i]);
        max_heapify(Arr, 0, i);
    }
}
void buildMaxHeap(int Arr[], int n){
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(Arr, i, n);
    }
}
};

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size) {
    int max = findMax(arr, size);
    int* output = new int[size];
    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] output;
    delete[] count;
}

void countingSortRadix(int arr[], int n, int exp)
{

	// Output array
	int* output = new int[n];
	int i, count[10] = { 0 };

	// Store count of occurrences
	// in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[],
	// so that arr[] now contains sorted
	// numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixSort(int arr[], int n)
{
	int m = findMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSortRadix(arr, n, exp);
}

void bubbleSort(int arr[], int n) { //bubble sort algorithm, O(n^2).
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; //early break check if array is already sorted.
    }
}

#endif // SORTING_H_INCLUDED
