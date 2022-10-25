// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 4 – Sorting Contest Threading)
// Due Date (10/19/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from
 // any other source. I further certify that I typed each and every line of code in this program.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
// Create a structure to pass parameters to print_message in pthread_create
struct sort{
    int *arr;// integer array
    int min; // min
    int max; // max
};

void _mergeSort(int arr[], int l, int m, int r){
    // initializies temp arrays from left to mid and mid to right
    int l_m = m - l + 1;
    int m_r = r - m;
    int L[l_m];
    int R[m_r];
    // copies element from original array to the array from left to mid
    for (int i = 0; i < l_m; i++){
        L[i] = arr[l + i];
    }
    // copies elements from original array to the array from mid to right
    for (int j = 0; j < m_r; j++){
        R[j] = arr[m + 1 + j];
    }
    int f = 0;
    int s = 0;
    int k = l;
    // merges left to mid array and mid to right array to the original array
    while (f < l_m && s < m_r){
        if (L[f] <= R[s]){
            arr[k] = L[f];
            f++;
        }else{
            arr[k] = R[s];
            s++;
        }
        k++;
    }
    // merges what is left over 
    while (f < l_m || s < m_r){
        if (f < l_m){
            arr[k]= L[f];
            f++; 
            k++;
        }else if (s < m_r){
            arr[k] = R[s];
            s++; 
            k++;
        }
    }
    
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r){
		int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        _mergeSort(arr, l, m, r);
	}
}

// void method passing to mergeSort
void* mergesort(void* v)
{
    sort *A = (sort *)v;
    int l = A -> min;
    int r = A -> max - 1;

    mergeSort(A -> arr, l, r);
    
    return NULL;
}

int main(int argc, char* argv[])
{
    const int MAX = 1000000;
    ofstream fout;
    ifstream fin;
    int n;
    int v[MAX];
    int count = 0;
    fin.open(argv[1]);
    while (fin >> n )
	{
		v[count++] = n;	// insert a number into the arary and increase the index
	}

    sort argList[8]; // array of arguments to pass to each thread

    for (int i=0; i<8; i++){
        int idx = 125000 * i;
        argList[i].arr = &v[idx];
        argList[i].min = 0;
        argList[i].max = 125000;
    }
    //initilizes the threads and arguments
    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7;
    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7;
    /* Create independent threads each of which will execute function */
    cout << "Starting merge sort with "<<MAX<<" items\n";
    iret0 = pthread_create( &thread0, NULL, mergesort, (void*)&argList[0]);
    iret1 = pthread_create( &thread1, NULL, mergesort, (void*)&argList[1]);
    iret2 = pthread_create( &thread2, NULL, mergesort, (void*)&argList[2]);
    iret3 = pthread_create( &thread3, NULL, mergesort, (void*)&argList[3]);
    iret4 = pthread_create( &thread4, NULL, mergesort, (void*)&argList[4]);
    iret5 = pthread_create( &thread5, NULL, mergesort, (void*)&argList[5]);
    iret6 = pthread_create( &thread6, NULL, mergesort, (void*)&argList[6]);
    iret7 = pthread_create( &thread7, NULL, mergesort, (void*)&argList[7]);

    // join the threads
    pthread_join( thread0, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    pthread_join( thread3, NULL);
    pthread_join( thread4, NULL);
    pthread_join( thread5, NULL);
    pthread_join( thread6, NULL);
    pthread_join( thread7, NULL);

    // merges the threads together
    _mergeSort(argList[0].arr, 0, 125000-1, 250000-1);
    _mergeSort(argList[2].arr, 0, 125000-1, 250000 - 1);
    _mergeSort(argList[4].arr, 0, 125000-1, 250000-1);
    _mergeSort(argList[6].arr, 0, 125000-1, 250000-1);
    _mergeSort(argList[0].arr, 0, 250000-1, 500000-1);
    _mergeSort(argList[4].arr, 0, 250000-1, 500000-1);
    _mergeSort(argList[0].arr, 0, 500000-1, 1000000-1);

    cout << "Ending merge sort\n";
    fout.open(argv[2], ios::out | ios::trunc);
    for (int i = 0; i < count; i++) {
        fout << v[i]<<endl;
    }


    fout.close();
    fin.close();

 return 0;
}