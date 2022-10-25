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
int main(int argc, char* argv[])
{
	const int MAX = 1000000;
  	ofstream fout;
	ifstream fin;
	int n;
	int v[MAX];
	int count = 0;
	int order = 1;
	fin.open(argv[1]);
	int low = 0;
	int num= 0;
	while (fin >> n )
	{
		v[count++] = n;	// insert a number into the arary and increase the index
	}

	for (int high = 1; high < MAX; high++){
		//checks to see if current index is greater than lower index
		if (v[high] >= v[low]){
			// increments number of elements if in order
			order++;
			low++;
		}else{
			// loop will stop and show the indexes that are out of order
			num++;
			cout << "First: " << v[low] << endl;
			cout << "Second: " <<  v[high] << endl;
			cout << "Number of elements sorted: " << order << endl;
			cout << "Sorted: False" << endl;
			return false;
		}
	}
	cout << "Number of elements sorted: " << order << endl;
	cout << "Sorted: True" << endl;
	fin.close();
	return true;

    return 0;
 
}
