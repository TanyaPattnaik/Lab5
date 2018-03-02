#include<iostream>
	#include "SLList.h"
	
	using namespace std;
	
	void swap(int a[], int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	
	class QuickSort {
		public:
		void sort(int unsort[], int start, int end);
		int* sort(int unsort[], int length);
		void sort(SLList unsorted, int start, int end);
		SLList sort(SLList unsorted);
	};
	
	void QuickSort::sort(int unsort[], int start, int end) {
		if (end <= 1)
			return;
	
		int x = unsort[start + rand()%end];
		int p=start-1, j=start, q=start+end;
	
		while (j < q) {
			if (unsort[j] < x) {
				swap(unsort, j++, ++p);
			} else if (unsort[j] > x) {
				swap(unsort, j, --q);
			} else {
				j++;
			}
		}
	
		sort(unsort, start, p-start+1);
		sort(unsort, q, end-(q-start));
	}
	
	int* QuickSort::sort(int unsort[], int length) {
		int* sorted = new int[length];
		for (int i=0; i<length; ++i) {
			sorted[i] = unsort[i];
		}
	
		sort(sorted, 0, length);
	
		return sorted;
	}
	
	void QuickSort::sort(SLList unsorted, int start, int end) {
		if (end <= 1)
			return;
	
		int x = unsorted.get(start + rand()%end + 1);
		int p = start-1, j=start, q=start+end;
	
		while (j < q) {
			if (unsorted.get(j+1) < x) {
				unsorted.swap((j++)+1, 1+(++p));
			} else if (unsorted.get(j+1) > x) {
				unsorted.swap(j+1, 1+(--q));
			} else {
				++j;
			}
		}
	
		sort(unsorted, start, p-start+1);
		sort(unsorted, q, end-(q-start));
	}
	
	SLList QuickSort::sort(SLList unsorted) {
		SLList sort;
		for (int i=1; i<=unsorted.countItems(); ++i) {
			sort.insert(unsorted.get(i));
		}
	
		sort(sort, 0, sort.countItems());
	
		return sort;
	}
	
	int main() {
		SLList l1;
		l1.insert(5);
		l1.insert(4);
		l1.insert(2);
		l1.insert(0);
		l1.insert(9);
		l1.insert(8);
		l1.insert(4);
		l1.insert(1);
		l1.insert(2);
	
		QuickSort ar;
		(ar.sort(l1)).display();
	
		return 0;
	}

