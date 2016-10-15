#include <iostream>
#include <math.h>

using namespace std;

int find_kth(const int *data1, int n1, const int *data2, int n2, int k) {
    if (k == 1) return data1[0] < data2[0]? data1[0] : data2[0];
    if (data1[0] > data2[n2-1]) return k <= n2 ? data2[k-1] : data1[k - n2];
    if (data1[n1-1] < data2[0]) return k <= n1 ? data1[k-1] : data2[k - n1];
    if (n1 > n2) return find_kth(data2, n2, data1, n1, k);

    int x1 = min(k/2, n1), x2 = k - x1;
    if (data1[x1-1] == data2[x2-1]) return data1[x1-1];
    else if (data1[x1-1] < data2[x2-1]) return find_kth(data1+x1, n1 - x1, data2, n2, x2);
    else return find_kth(data1, n1, data2 + x2, n2 - x2, x1);
}

int main(void) {
    int data1[] = {1, 3, 4, 5, 6, 7, 8, 9};
    int n1 = sizeof(data1)/sizeof(int);
    int data2[] = {2, 10, 14, 15, 16, 17, 18, 19};
    int n2 = sizeof(data2)/sizeof(int);

    cout<<"2nd elements (2): "<<find_kth(data1, n1, data2, n2, 2)<<endl; 
    cout<<"1nd elements (1): "<<find_kth(data1, n1, data2, n2, 1)<<endl; 
    cout<<"10nd elements (10): "<<find_kth(data1, n1, data2, n2, 10)<<endl; 
    cout<<"16nd elements (16): "<<find_kth(data1, n1, data2, n2, 16)<<endl; 
    cout<<"9nd elements (9): "<<find_kth(data1, n1, data2, n2, 9)<<endl; 
}
