#ifndef CALLSORTS_H_INCLUDED
#define CALLSORTS_H_INCLUDED

#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

void print(const int arr[], int n) //print elements of an array up to n elements.
{
	cout << "[";
	for (int i = 0; i < 25; i++)
	{
		cout << arr[i] << ",";
	}
	cout << "]\n";
}
void callBubble(int arr[], int n)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nBubblesort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    bubbleSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "Sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}
void callInsertion(int arr[], int n)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nInsertionsort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}
void callSelection(int arr[], int n)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nSelectionsort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    selectionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}
void callQuick(int arr[], int n, int choice)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nQuicksort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    quickSort(arr,0, n-1,choice);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}
void callMerge(int arr[], int n)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nMergesort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    mergeSort(arr,0, n-1);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}
void callCounting(int arr[], int n)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nCountingsort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    countingSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}
void callRadix(int arr[], int n)//helper function to call the sort, time it, and print first 100 elements.
{
    cout<<"---------------------\nRadixsort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    print(arr,n);
    auto start = high_resolution_clock::now();
    radixSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
}




#endif // CALLSORTS_H_INCLUDED
