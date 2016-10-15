#include <iostream>

using namespace std;
int purgeDuplicates(int *data, int n) {
    if (n == 0) return 0;

    int count = 0;
    for(int i = 1; i < n; ++i) {
        if (data[i] == data[count]) continue;
        data[++count] = data[i];
    }
    return count + 1;
}

int purgeKthDuplicates(int *data, int n, int k) {
    if (n <= k) return n;

    int count = k-1;
    for(int i = k; i < n; ++i) {
        if (data[i] == data[count - k + 1]) continue;
        data[++count] = data[i];
    }
    return count + 1;
}

int main(void) {
    int data[] = {-3, -2, -1, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 6, 7, 7, 7, 7, 8, 9};
    int n = sizeof(data) /sizeof(int);

    n = purgeKthDuplicates(data, n, 1);
    cout<<"purged 1st duplicated data: ";
    for(int i=0; i < n; ++i) {
        cout<<data[i]<<", ";
    }
    cout<<endl;

    int data2[] = {-3, -2, -1, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 6, 7, 7, 7, 7, 8, 9};
    n = sizeof(data2) /sizeof(int);

    n = purgeKthDuplicates(data2, n, 2);
    cout<<"purged 2nd duplicated data: ";
    for(int i=0; i < n; ++i) {
        cout<<data2[i]<<", ";
    }
    cout<<endl;

    int data3[] = {-3, -2, -1, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 6, 7, 7, 7, 7, 8, 9};
    n = sizeof(data3) /sizeof(int);

    n = purgeKthDuplicates(data3, n, 3);
    cout<<"purged 3rd duplicated data: ";
    for(int i=0; i < n; ++i) {
        cout<<data3[i]<<", ";
    }
    cout<<endl;
}
