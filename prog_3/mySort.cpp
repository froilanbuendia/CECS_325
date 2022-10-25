// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 3 – Sort Race)
// Due Date 10/3/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

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
            arr[k] = L[f];
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
        mergeSort(arr, m + 1, r);
        _mergeSort(arr, l, m, r);
        
	}

}




int main(int argc, char* argv[])
{
    if (argc < 3)
	{
		cout << "Please include input filename and output filename in param list.\n";
		cout << "Example:\n";
		cout << "     % mySort numbers.txt mySorted.txt\n";
		exit(EXIT_SUCCESS);
	}


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

    cout << "Starting merge sort with "<<MAX<<" items\n";
	mergeSort(v, 0, MAX - 1);	// call the mergesort
    cout << "Ending merge sort\n";

        fout.open(argv[2], ios::out | ios::trunc);
        for (int i = 0; i < count; i++)
		fout << v[i]<<endl;


        fout.close();
	    fin.close();
        return 0;
 
}

