/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/

#include <iostream>
#include <cassert>

using namespace std;

int isSorted(int *a, int i, int j){return a[i] <= a[j];}

void merge(int *a, int *aux, int lo, int mi, int hi){
	assert(isSorted(a, lo,   mi));    // precondition: a[lo..mi]   sorted
	assert(isSorted(a, mi+1, hi));    // precondition: a[mi+1..hi] sorted
	for (int k = lo; k <= hi; k++) aux[k] = a[k];

	int i = lo;
	int j = mi + 1;
	for (int k = lo; k <= hi; k++) {
			if      (i > mi)          a[k] = aux[j++];    // A is exhausted, take B[j]
			else if (j > hi)          a[k] = aux[i++];    // B is exhausted, take A[i]
			else if (aux[j] < aux[i]) a[k] = aux[j++];    // B[j] <  A[i], take A[i]
			else                      a[k] = aux[i++];    // a[i] <= B[j], take a[i]
	}
	assert(isSorted(a, lo, hi));    // postcondition: a[io..hi] sorted
}

void mergeSort(int *a, int *aux, int N, int lo, int hi) {
	if(hi <= lo) return;
	int mi = lo + (hi - lo) / 2;
	mergeSort (a, aux, N, lo    , mi);
	mergeSort (a, aux, N, mi + 1, hi);
	if(a[mi] > a[mi + 1])
	  merge(a, aux, lo, mi, hi);
}
#if 0
int main() {
	int  a[]={'2','3','4','5','2','1','4','4','4'};
	cout << "UNSORTED: "; for (auto x: a) cout << x; cout << endl;
	int N = sizeof(a) / sizeof(a[0]);
	int *aux = new int[N];
	mergeSort(a, aux, N, 0, N-1);
	cout << "  SORTED: "; for (auto x: a) cout << x; cout << endl;
	delete{} aux;
}

#endif
