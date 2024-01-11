#include <iostream>
#include "Cases.h"
#include "Sorting.h"
#include "callSorts.h"
using namespace std;

int main()
{
    int test=100000;
        int* arr = new int[test];int* arr1 = new int[test];int* arr2 = new int[test];int* arr3 = new int[test];
        int* arr4 = new int[test];int* arr5 = new int[test];int* arr6 = new int[test];int* arr7 = new int[test];

    //int arr[test],arr1[test],arr2[test],arr3[test],arr4[test],arr5[test],arr6[test],arr7[test];
    Heap bestheap,aveheap,worseheap;
    
        cout<<"---------------------\nBEST CASES\n---------------------\n";
    fillArrBest(arr, test,"Bubble");
    callBubble(arr,test);
    
    fillArrBest(arr1,test,"Selection");
    callSelection(arr1,test);
    
    fillArrBest(arr2, test,"Insertion");
    callInsertion(arr2,test);

    fillArrBest(arr3, test,"Quick");
    callQuick(arr3,test,3);

    fillArrBest(arr4, test,"Merge");
    callMerge(arr4,test);

    fillArrBest(arr5,test,"Heap");
    cout<<"---------------------\nHeapSort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    bestheap.printArray(arr5,test);
    bestheap.buildMaxHeap(arr5,test);
    auto start1 = high_resolution_clock::now();
    bestheap.ascendingHeapSort(arr5,test);
    auto stop1 = high_resolution_clock::now();
    auto elapsed1 = duration_cast<milliseconds>(stop1 - start1);

    cout << "sorted array: " << endl;
    bestheap.printArray(arr5,test);
    cout << endl;
    cout << "Runtime: " << elapsed1.count() << " milliseconds. " << endl;
    
    
    fillArrBest(arr6, test, "Counting");
    callCounting(arr6,test);

    fillArrBest(arr7, test,"Radix");
    callRadix(arr7,test);
    
    
    cout<<"---------------------\nAVERAGE CASES\n---------------------\n";
    
    fillArrAve(arr, test);
    callBubble(arr,test);
    
    fillArrAve(arr1,test);
    callSelection(arr1,test);
    
    fillArrAve(arr2, test);
    callInsertion(arr2,test);

    fillArrAve(arr3, test);
    callQuick(arr3,test,2);

    fillArrAve(arr4, test);
    callMerge(arr4,test);

    fillArrAve(arr5,test);
    cout<<"---------------------\nHeapSort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    aveheap.printArray(arr5,test);
    aveheap.buildMaxHeap(arr5,test);
    auto start = high_resolution_clock::now();
    aveheap.ascendingHeapSort(arr5,test);
    auto stop = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(stop - start);

    cout << "sorted array: " << endl;
    aveheap.printArray(arr5,test);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
    
    
    fillArrAve(arr6, test);
    callCounting(arr6,test);

    fillArrAve(arr7, test);
    callRadix(arr7,test);
    
    
     cout<<"---------------------\nWorst CASES\n---------------------\n";
    fillArrWorst(arr, test,"Bubble");
    callBubble(arr,test);
    
    fillArrWorst(arr1,test,"Selection");
    callSelection(arr1,test);
    
    fillArrWorst(arr2, test,"Insertion");
    callInsertion(arr2,test);

    fillArrWorst(arr3, test,"Quick");
    callQuick(arr3,test,1);

    fillArrWorst(arr4, test,"Merge");
    callMerge(arr4,test);

    fillArrWorst(arr5,test,"Heap");
    cout<<"---------------------\nHeapSort:\n---------------------\n";
    cout << "Unsorted array: " << endl;
    worseheap.printArray(arr5,test);
    worseheap.buildMaxHeap(arr5,test);
    auto start2 = high_resolution_clock::now();
    worseheap.ascendingHeapSort(arr5,test);
    auto stop2 = high_resolution_clock::now();
    auto elapsed2 = duration_cast<milliseconds>(stop2 - start2);

    cout << "sorted array: " << endl;
    worseheap.printArray(arr5,test);
    cout << endl;
    cout << "Runtime: " << elapsed.count() << " milliseconds. " << endl;
    
    
    fillArrWorst(arr6, test, "Counting");
    callCounting(arr6,test);

    fillArrWorst(arr7, test,"Radix");
    callRadix(arr7,test);
    
   // printArray(arr6,test);
    
    /*
    auto start = high_resolution_clock::now();                              // clock start
    insertionSort(arr,test);//Insert sorting function call here
    auto stop = high_resolution_clock::now();                      // end clock
    auto duration = duration_cast<milliseconds>(stop - start);                    // calculate run time
    printArray(arr,test);
    cout<<"Insertion Sort took: "<< duration.count() <<" milliseconds\n\n";

    fillArrAve(arr1, test);
    printArray(arr1,test);

    auto start1 = high_resolution_clock::now();                              // clock start
    quickSort(arr1,0,test-1,1);
    auto stop1 = high_resolution_clock::now();                      // end clock
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);                    // calculate run time
    printArray(arr1,test);
    cout<<"Quicksort took: "<< duration1.count() <<" milliseconds\n\n";

    fillArrAve(arr2, test);
    printArray(arr2,test);

    auto start2 = high_resolution_clock::now();                              // clock start
    mergeSort(arr2,0,test-1);
    auto stop2 = high_resolution_clock::now();                      // end clock
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);                    // calculate run time
    printArray(arr2,test);
    cout<<"Mergesort took: "<< duration2.count() <<" milliseconds\n\n";

    fillArrAve(arr3, test);
    printArray(arr3,test);

    auto start3 = high_resolution_clock::now();                              // clock start
    selectionSort(arr3,test);
    auto stop3 = high_resolution_clock::now();                      // end clock
    auto duration3 = duration_cast<milliseconds>(stop3 - start3);                    // calculate run time
    printArray(arr3,test);
    cout<<"Selection took: "<< duration3.count() <<" milliseconds\n\n";

    fillArrAve(arr4,test);
    heap1.buildMaxHeap(arr4,test);
    heap1.printArray(arr4,test);

    auto start4 = high_resolution_clock::now();                              // clock start
    heap1.ascendingHeapSort(arr4,test);
    auto stop4 = high_resolution_clock::now();                      // end clock
    auto duration4 = duration_cast<milliseconds>(stop4 - start4);                    // calculate run time
    cout<<endl;
    heap1.printArray(arr4,test);
    cout<<"\nHeapsort took: "<< duration4.count() <<" milliseconds\n\n";

    fillArrAve(arr4, test);
    printArray(arr4,test);

    auto start5 = high_resolution_clock::now();                              // clock start
    countingSort(arr4,test);
    auto stop5 = high_resolution_clock::now();                      // end clock
    auto duration5 = duration_cast<milliseconds>(stop5 - start5);                    // calculate run time
    printArray(arr4,test);
    cout<<"Counting sort took: "<< duration5.count() <<" milliseconds\n\n";

    fillArrAve(arr5, test);
    printArray(arr5,test);

    auto start6 = high_resolution_clock::now();                              // clock start
    radixSort(arr5,test);
    auto stop6 = high_resolution_clock::now();                      // end clock
    auto duration6 = duration_cast<milliseconds>(stop6 - start6);                    // calculate run time
    printArray(arr5,test);
    cout<<"Radix sort took: "<< duration6.count() <<" milliseconds\n\n";

    fillArrAve(arr6, test);
    printArray(arr6,test);

    auto start7 = high_resolution_clock::now();                              // clock start
    bubbleSort(arr6,test);
    auto stop7 = high_resolution_clock::now();                      // end clock
    auto duration7 = duration_cast<milliseconds>(stop7 - start7);                    // calculate run time
    printArray(arr6,test);
    cout<<"Bubblesort took: "<< duration7.count() <<" milliseconds\n\n";

	*/
    return 0;
}
