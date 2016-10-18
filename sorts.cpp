/*

g++ -g sorts.cpp binaryheap.c -std=c++0x

*/
#include "algorithms.h"
#include "basics.h"

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

static int reverse_compare(int a, int b) {
    return b - a;
}

int heap_sort(int *data, int n, int (*fcomp)(int a, int b)) {
    binaryheap_t *heap = binaryheap_new(data, n, fcomp, false);
    int i = n;
    while(--i >= 0) {
        data[i] = binaryheap_popmax(heap);
    }
    binaryheap_delete(&heap);
}

/*
 Quick sort:
 1. Shuffle
 2. Partition
 3. sort

Several improvements:
 1. When hi - lo < CUTOFF(10), use insert_sort
 2. Random shuffle
 3. Better pivot: m = median3(lo, (lo+hi)/2, hi); swap(data, lo, m);
 4. 3-way partition: <, =, > for duplcicates 
*/
int shuffle(int *data, int n) {
    srand( time(NULL) );
    
    for(int i = n - 1; i > 0; --i) {
	int j = rand() % (i + 1);
	swap(data, j, i); 
    }
}

int partition(int *data, int lo, int hi, int (*fcomp)(int a, int b)) {
    int i = lo, j = hi + 1;
    while(true) {
	while ( fcomp(data[++i], data[lo]) < 0)
	    if (i == hi) break;
	while ( fcomp(data[lo], data[--j]) < 0)
	    if (j == lo) break;

 	if (i >= j) break;
	swap(data, i, j);
    }
    swap(data, lo, j);
    return j;
}

void sort(int *data, int lo, int hi, int (*fcomp)(int a, int b)) {
    if (lo >= hi) return;
    int j = partition(data, lo, hi, fcomp);
    sort(data, lo, j - 1, fcomp);
    sort(data, j + 1, hi, fcomp);
}

void sort_3way(int *data, int lo, int hi, int (*fcomp)(int a, int b)) {
    if (lo >= hi) return;

    int lt = lo, gt = hi;
    int v = data[lo];
    int i = lo; 
    while(i <= gt) {
	int c = fcomp(data[i], v);
	if (c < 0) swap(data, lt++, i++);
	else if (c > 0) swap(data, i, gt--);
	else ++i;
    }
    sort_3way(data, lo, lt - 1, fcomp);
    sort_3way(data, gt + 1, hi, fcomp);
}

void quick_sort(int *data, int n, int (*fcomp)(int a, int b)) {
    shuffle(data, n);
    if (!fcomp) fcomp = [](int a, int b)->int { return a - b; }; 

    //sort(data, 0, n-1, fcomp);
    sort_3way(data, 0, n-1, fcomp);
}

int quick_select(int *data, int n, int k, int (*fcomp)(int a, int b)) {
    if (!fcomp) fcomp = [](int a, int b)->int { return a - b; };

    int lo = 0, hi = n - 1;
    while(lo < hi) {
	int j = partition(data, lo, hi, fcomp);
 	if (j == k) return data[k];
	else if (j < k) lo = j + 1;
	else hi = j - 1;
    }
    return data[k];
}

int main(int argc, char *argv[]) {
    int data[] = {3, 6, 6, 1, -1, 7, 9, 5, 8, 0, -10, 9};
    int n = sizeof(data)/sizeof(int);
    if (argc != 2) {
	cout<<"Usage: " <<argv[0] <<" #num" <<endl
	    <<"Where #num =\t1 (bubble sort)" <<endl
	    <<"\t\t2 (insert sort)" <<endl
	    <<"\t\t3 (selection sort)" <<endl
	    <<"\t\t4 (merge sort)" <<endl
	    <<"\t\t5 (heap sort asc)" <<endl
	    <<"\t\t6 (heap sort desc)" <<endl
	    <<"\t\t7 (quick sort asc)" <<endl
	    <<"\t\t8 (quick sort des)" <<endl;
	return -1;
    }

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
    case '5':
        heap_sort(data, n, NULL);
	break;
    case '6':
        heap_sort(data, n, &reverse_compare);
	break;
    case '7':
        quick_sort(data, n, NULL);
	break;
    case '8':
        quick_sort(data, n, &reverse_compare);
	break;
    case '9':
        cout<<quick_select(data, n, 3, NULL)<<endl;
	break;
    case 'A':
        cout<<quick_select(data, n, 3, &reverse_compare)<<endl;
	break;
    default: 
	cout<<argv[1]<<" isn't supported"<<endl;
	break;
    }
    cout<<"[";
    for_each(data, data+n, [](int &v) {
	cout<<v<<", ";
    });
    cout<<"\b\b]"<<endl;
}
