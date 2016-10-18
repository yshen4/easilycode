#include "algorithms.h"

using namespace std;

/* Swap ith and jth elements in array data*/
void swap(int *data, int i, int j) {
    int t = data[i];
    data[i] = data[j];
    data[j] = t;
}
/*
 * O(n^2), in place, stable
 */
void bubble_sort(int *data, int n) {
    bool swapped = false;
    do {
        swapped = false;
        for(int i = 1; i < n; ++i) {
	    if (data[i-1] > data[i]) {
		swapped = true;
		swap(data, i-1, i);
	    }
	}
    } while(swapped);
}

/*
 * O(n^2), 
 */
void insert_sort(int *data, int n) {
    for(int i = 1; i < n; ++i) {
	for(int j = i; j > 0; --j) {
	    if (data[j-1] > data[j]) {
		swap(data, j - 1, j);
	    }
	    else break; //in order
	}
    }
}

/*
 * O(n^2)
 */
void selection_sort(int *data, int n) {
    for(int i = 0; i < n - 1; ++i) {
	int min = i;
	for(int j = i + 1; j < n; ++j) {
	    if (data[min] > data[j]) min = j;
	}
	if (min != i) swap(data, i, min);
    }
}

/*
 * merge sort
 */
void merge(int *A, int s, int m, int e, int *B) {
    int ai = s, bi = m;
    for(int k = s; k < e; ++k) {
	if (ai < m &&	//more in first half
	   (bi >= e ||  //no more in second half
	    A[ai] < A[bi]))  //it is smaller
	    B[k] = A[ai++];
	else
	    B[k] = A[bi++];
    }
}

//DFS
void split_n_merge(int *B, int s, int e, int *A) {
    if (e - s < 2) return;

    int m = (e + s)/2;
    split_n_merge(A, s, m, B);
    split_n_merge(A, m, e, B);
    merge(B, s, m, e, A);
}

void merge_sort(int *data, int n) {
    int *cpy = (int *)calloc(n, sizeof(int));
    copy_n(data, n, cpy);

    split_n_merge(cpy, 0, n, data);

    free(cpy);
}

int main(int argc, char *argv[]) {
    int data[] = {3, 6, 6, 1, -1, 7, 9, 5, 8, 0, -10, 9};
    int n = sizeof(data)/sizeof(int);
    switch(argv[1][0]) {
    case '1':
        bubble_sort(data, n);
	break;
    case '2':
        insert_sort(data, n);
	break;
    case '3':
        selection_sort(data, n);
	break;
    case '4':
        merge_sort(data, n);
	break;
    default: 
	cout<<argv[1]<<" isn't supported"<<endl;
	break;
    }
    for_each(data, data+n, [](int &v) {
	cout<<v<<", ";
    });
    cout<<"\b\b"<<endl;
}
