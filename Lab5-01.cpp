#include<iostream>
	#include "SLList.h"
	
	using namespace std;
	
	class BubbleSort {
		public:
			int* sort(int unsort[], int length);
			SLList sort(SLList unsort);
			
	};
	
	int* BubbleSort::sort(int unsort[], int length) {
		int* sorted = new int[length];
		for (int i=0; i<length; ++i) {
			sorted[i] = unsort[i];
		}
	
		bool flag=true;
		while (flag) {
			flag = false;
			for (int i=0; i<length; ++i) {
				if (sorted[i] > sorted[i+1]) {
					int temp = sorted[i];
					sorted[i] = sorted[i+1];
					sorted[i+1] = temp;
					flag = true;
				}
			}
		}
	
		return sorted;
	}
	
	SLList BubbleSort::sort(SLList unsort) {
		SLList sortedll;
		for (int i=1; i<=unsort.countItems(); ++i) {
			sortedll.insert(unsort.get(i));
		}
	
		bool flag=true;
		while (flag) {
			flag = false;
			for (int i=1; i<sortedll.countItems(); ++i) {
				if (sortedll.get(i) > sortedll.get(i+1)) {
					sortedll.swap(i, i+1);
					flag = true;
				}
			}
		}
	
	
		return sortedll;
	}
	
	int main() {
		SLList l1;
		l1.insert(5);
		l1.insert(4);
		l1.insert(1);
		l1.insert(8);
		l1.insert(7);
		l1.insert(0);
		l1.insert(10);
		l1.insert(3);
		l1.insert(9);
		l1.insert(12);
	
		l1.display();
		l1.swap(1,l1.countItems());
		l1.display();
	
		BubbleSort obj; (obj.sort(l1)).display();
	
		return 0;
	}

