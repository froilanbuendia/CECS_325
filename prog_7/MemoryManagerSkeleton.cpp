#include "MemoryManager.h"

#include <iomanip>
#include <iostream>
using namespace std;

namespace MemoryManager
{
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT 
	//
	// This is the only static memory that you may use, no other global variables may be
	// created, if you need to save data make it fit in MM_pool
	//
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT


	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];

	// I have provided this tool for your use
	void memView(int start, int end)
	{

		const unsigned int SHIFT = 8;
		const unsigned int MASK = 1 << SHIFT - 1;

		unsigned int value;	// used to facilitate bit shifting and masking

		cout << endl; // start on a new line
		cout << "               Pool                     Unsignd  Unsigned " << endl;
		cout << "Mem Add        indx   bits   chr ASCII#  short      int    " << endl;
		cout << "-------------- ---- -------- --- ------ ------- ------------" << endl;

		for (int i = start; i <= end; i++)
		{
			cout << (long*)(MM_pool + i) << ':';	// the actual address in hexadecimal
			cout << '[' << setw(2) << i << ']';				// the index into MM_pool

			value = MM_pool[i];
			cout << " ";
			for (int j = 1; j <= SHIFT; j++)		// the bit sequence for this byte (8 bits)
			{
				cout << ((value & MASK) ? '1' : '0');
				value <<= 1;
			}
			cout << " ";

            if (MM_pool[i] < 32)   // non-printable character so print a blank
            	cout << '|' << ' ' << "| (";	
            else                    // characger is printable so print it
				cout << '|' << *(char*)(MM_pool + i) << "| (";		// the ASCII character of the 8 bits (1 byte)

			cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")";	// the ASCII number of the character

			cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")";	// the unsigned short value of 16 bits (2 bytes)
			cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")";	// the unsigned int value of 32 bits (4 bytes)

																				//  cout << (*(unsigned int*)(MM_pool+i)) << "|";	// the unsigned int value of 32 bits (4 bytes)

			cout << endl;
		}
	}

	// Initialize set up any data needed to manage the memory pool
	void initializeMemoryManager(void)
	{

		int freeHead = 0; // starting index of the freelist
		int inUseHead = 2; // starting index of the inUselist
		int usedHead = 4; // starting index for the used list - deallocated memory

		int nextLink = 2; // offset index of the next link
		int prevLink = 4; // offset index for the prev link

		*(unsigned short*)(MM_pool + freeHead) = 6; // freelist starts at byte 6
		*(unsigned short*)(MM_pool + inUseHead) = 0;	// nothing in the inUse list yet
		*(unsigned short*)(MM_pool + usedHead) = 0; // nothing in the used list yet

	}

	// return a pointer inside the memory pool
	void* allocate(int aSize)
	{
		// If no chunk can accommodate aSize call onOutOfMemory()
		if ((int)(*(unsigned short*)(MM_pool)) + aSize + 6 > 65536)
			onOutOfMemory();
		// TBD 
		// need to see where our free space is
		// grab free head
		// auto free_index = *(unsigned short*)(MM_pool + 0);
		// auto inuse_index = *(unsigned short*)(MM_pool + 2);
		int size = aSize + 6; 
		int old_free = (int)(*(unsigned short*)(MM_pool));
		int old_inuse = (int)(*(unsigned short*)(MM_pool + 2));
		int next_free = (int)(*(unsigned short*)(MM_pool)) + size;
		//*(unsigned short*)MM_pool = (free_index + aSize + 6); // memory allocated for free memory
		int prev = old_inuse + 4;

		int curr_next = old_free + 2;
		int curr_prev = old_free + 4;

		int inuse = (int)*(unsigned short*)(MM_pool + 2);

		*(unsigned short*)(MM_pool + 2) = old_free;
		*(unsigned short*)(MM_pool) = next_free; 

		if (old_free != 6){
			*(unsigned short*)(MM_pool + prev) = old_free;
		}
		*(unsigned short*)(MM_pool + curr_next) = old_inuse;
		*(unsigned short*)(MM_pool + curr_prev) = 0;

		*(unsigned short*)(MM_pool + old_free) = aSize;

		*(unsigned short*)(MM_pool + next_free) = MM_POOL_SIZE - next_free;

		// freeMemory();
		// inUseMemory();
		return (void*)(MM_pool + *(unsigned short*)MM_pool - aSize);
	
		// *(unsigned short*)MM_pool = (free_index - aSize - 4); // memory allocated for inUse memory
		// return pointer to start of data
	}

	// Free up a chunk previously allocated
	void deallocate(void* aPointer)
	{
		// TBD
		int size = MM_pool[((char*)aPointer - MM_pool) - 6] + 6;
		int index = (char*)aPointer - MM_pool - 6;
		int curr_d = index;
		int free = 0;
		int inuse = 2;
		int used = 4; 

		int next = 2;
		int prev = 4;

		// int old_used = *(unsigned short*)(MM_pool + 4);
		// int used_index = 4;
		// (int)(*(unsigned short*)(used_index + 4));
		// usedMemory();

		int prevN = *(unsigned short*)(MM_pool + curr_d + next);
		int nextN = *(unsigned short*)(MM_pool + curr_d + prev);

		*(unsigned short*)(MM_pool + prevN + prev) = nextN;
		*(unsigned short*)(MM_pool + nextN + next) = prevN;

		int old_used = *(unsigned short*)(MM_pool + used);

		*(unsigned short*)(MM_pool + curr_d + prev) = 0;
		*(unsigned short*)(MM_pool + curr_d + next) = old_used;

		*(unsigned short*)(MM_pool + old_used + prev) = curr_d;
		*(unsigned short*)(MM_pool + used) = curr_d;
	}

	int size(void *ptr)
	{
		// TBD
		return sizeof(&ptr);
	}
	
	//---
	//--- support routines
	//--- 

	// Will scan the memory pool and return the total free space remaining
	int freeMemory(void)
	{
		//TBD
		// freememory head index - size of MMpool
		// (int&)freeMemory = ;
		int free = 0;
		// int size = *(unsigned short*)&MM_pool[cur];
		// int next = *(unsigned short*)&MM_pool[cur + 2];
		// int prev = *(unsigned short*)&MM_pool[cur + 4];
		// // *(unsigned short*)(MM_pool + next_free) = MM_POOL_SIZE - next_free;
		// while (cur != 0){
		// 	cur = next;
		// 	next = *(unsigned short*)&MM_pool[cur+2];
		// 	prev = *(unsigned short*)&MM_pool[cur+4];
		// }
		return MM_POOL_SIZE - *(unsigned short*)(MM_pool + free);
	}


	// Will scan the memory pool and return the total used memory - memory that has been deallocated
	int usedMemory(void)
	{
		//TBD
		int cur = 0;
		// int size = *(unsigned short*)&MM_pool[cur];
		int next = *(unsigned short*)(MM_pool + 4);
		// int prev = *(unsigned short*)&MM_pool[cur+4];
		while (next > 0)
		{
			cur = cur + *(unsigned short*)(MM_pool + next) + 6;
			// size = *(unsigned short*)&MM_pool[cur];
			next = *(unsigned short*)(MM_pool + next + 2);
			// prev = *(unsigned short*)&MM_pool[cur+4];
		}
		return cur;
	}

	// Will scan the memory pool and return the total in use memory - memory being curretnly used
	int inUseMemory(void)
	{
		//TBD
		// int cur = 0;
		// // int size = *(unsigned short*)&MM_pool[cur];
		// int next = *(unsigned short*)&MM_pool[cur+2];
		// // int prev = *(unsigned short*)&MM_pool[cur+4];
		// while (next != 0)
		// {
		// 	cur = *(unsigned short*)&MM_pool[next + 4];
		// 	// size = *(unsigned short*)&MM_pool[cur];
		// 	next = *(unsigned short*)&MM_pool[cur+2];
		// 	// prev = *(unsigned short*)&MM_pool[cur+4];
		// }
		// return cur;
		int total = MM_POOL_SIZE - freeMemory() - 6;
		return total - usedMemory();
	}

	// helper function to see the InUse list in memory
	void traverseInUse()
	{
		int cur = *(unsigned short*)&MM_pool[2];
		int size = *(unsigned short*)&MM_pool[cur];
		int next = *(unsigned short*)&MM_pool[cur+2];
		int prev = *(unsigned short*)&MM_pool[cur+4];
		cout << "\nTraversing InUse Memory....";
		cout << "\n      InUse Head:"<<cur;
		while (cur != 0)
		{
			cout << "\n        Index:"<<cur<<" Size:"<<size<<" Next:"<<next<<" Prev:"<<prev;
			cur = next;
			size = *(unsigned short*)&MM_pool[cur];
			next = *(unsigned short*)&MM_pool[cur+2];
			prev = *(unsigned short*)&MM_pool[cur+4];
			// cout <<"here";
		}
	}

	//Helper function to see the Used list in memory
	void traverseUsed()
	{
		int cur = *(unsigned short*)&MM_pool[4];
		int size = *(unsigned short*)&MM_pool[cur];
		int next = *(unsigned short*)&MM_pool[cur+2];
		int prev = *(unsigned short*)&MM_pool[cur+4];
		cout << "\nTraversing Used Memory....";
		cout << "\n      Used Head:"<<cur;
		while (cur != 0)
		{
			cout << "\n        Index:"<<cur<<" Size:"<<size<<" Next:"<<next<<" Prev:"<<prev;
			cur = next;
			size = *(unsigned short*)&MM_pool[cur];
			next = *(unsigned short*)&MM_pool[cur+2];
			prev = *(unsigned short*)&MM_pool[cur+4];
			// cout << "here";
		}
		
	}


	// this is called from Allocate if there is no more memory availalbe
	void onOutOfMemory(void)
  	{
    	std::cout << "\nMemory pool out of memory\n" << std::endl;
    	std::cout << "\n---Press \"Enter\" key to end program---:";

		cin.get();

    	exit( 1 );
  }
}
