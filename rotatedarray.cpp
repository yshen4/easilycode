#include <iostream>

using namespace std;

/*
 * data is sorted, without duplicates in data
 *
 * */
int findValueInRotatedSortedArray(const int *data, const int n, const int v) {
    int high = n - 1, low = 0;

    while( low < high) {
        int mid = (low + high)/2;
        cout<<"l: "<<low<<", m: "<<mid<<", h: "<<high<<endl;
        if (data[mid] == v) return mid;

        if (data[low] < data[high]) {//monolithic
            if (data[mid] < v) low = mid + 1; 
            else high = mid - 1;
        }
        else {
            if (data[mid] < v) {
                if(data[high] < v) high = mid - 1; 
                else low = mid + 1;
            }
            else {
                if(v < data[low]) low = mid + 1; 
                else high = mid - 1;
            }
        }
    }

    if (low == high && data[low] == v) return low;
    return -1;
}

/*
 * data is sorted, with duplicates in data
 *
 * */
int findValueInRotatedSortedArrayWithDuplicates(const int *data, const int n, const int v) {
    int high = n - 1, low = 0;

    while( low < high) {
        int mid = (low + high)/2;
        cout<<"l: "<<low<<", m: "<<mid<<", h: "<<high<<endl;
        if (data[mid] == v) return mid;

        if (data[low] == data[high]) 
            ++low;
        else if (data[low] < data[high]) {//monolithic
            if (data[mid] < v) low = mid + 1; 
            else high = mid - 1;
        }
        else {
            if (data[mid] < v) {
                if(data[high] == v) return high;
                if(data[high] < v) high = mid - 1; 
                else low = mid + 1;
            }
            else {
                if(data[low] == v) return low;
                if(v < data[low]) low = mid + 1; 
                else high = mid - 1;
            }
        }
    }

    if (low == high && data[low] == v) return low;
    return -1;
}

int main(void) {
    int data[] = {6, 7, 8, 9, 10, -1, 0, 2, 4, 5};
    int n = sizeof(data) / sizeof(int);

    cout<<"Index of -1 in the data: "<<findValueInRotatedSortedArrayWithDuplicates(data, n, -1)<<endl;
    cout<<"Index of 6 in the data: "<<findValueInRotatedSortedArrayWithDuplicates(data, n, 6)<<endl;
    cout<<"Index of 7 in the data: "<<findValueInRotatedSortedArrayWithDuplicates(data, n, 7)<<endl;
    cout<<"Index of 5 in the data: "<<findValueInRotatedSortedArrayWithDuplicates(data, n, 5)<<endl;
    cout<<"Index of 10 in the data: "<<findValueInRotatedSortedArray(data, n, 10)<<endl;

    int dupl[] = {6, 6, 8, 10, 10, -1, -1, 2, 4, 5, 6};
    int k = sizeof(data) / sizeof(int);

    cout<<"Index of -1 in the data: "<<findValueInRotatedSortedArray(data, n, -1)<<endl;
    cout<<"Index of 6 in the data: "<<findValueInRotatedSortedArray(data, n, 6)<<endl;
    cout<<"Index of 7 in the data: "<<findValueInRotatedSortedArray(data, n, 8)<<endl;
    cout<<"Index of 5 in the data: "<<findValueInRotatedSortedArray(data, n, 5)<<endl;
    cout<<"Index of 10 in the data: "<<findValueInRotatedSortedArray(data, n, 10)<<endl;
}
