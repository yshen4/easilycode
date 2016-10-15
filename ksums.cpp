#include "algorithms.h"

using namespace std;

/*
 * o(n)
 *
 * */
vector<int> twoSums(vector<int> data, int target) {
    unordered_map<int, int> index;
    int i = 0;
    for(vector<int>::iterator iter = data.begin(); iter != data.end(); iter++) 
        index[*iter] = i++;

    vector<int> result;
    for(vector<int>::iterator iter = data.begin(); iter != data.end(); iter++) {
        int v = target - *iter;
        if (index.find(v)!= index.end()) {
            result.push_back(index[*iter]);
            result.push_back(index[v]);
            break;
        }
    }

    return result;
}

vector<vector<int> > threeSums(vector<int> data, int target) {
    vector<vector<int> > results;

    for(int i=0; i<data.size(); ++i) {
        int v = target - data[i];

        vector<int> rt = twoSums(data, v);
        if (rt.size() == 2 && rt[0] != i && rt[1] != i) {
            vector<int> result;
            result.push_back(data[i]);
            result.push_back(data[rt[0]]);
            result.push_back(data[rt[1]]);
            sort(result.begin(), result.end());
            if (/*results.size() == 0 ||*/
                find(results.begin(), results.end(), result) == results.end())
                results.push_back(result);
        }
    }
    return results;
}

int main(void) {
    int data2[] = {2, 7, 11, 15};
    vector<int> vdata2(data2, data2 + 4);
    vector<int> result = twoSums(vdata2, 13);
    for(int i=0; i< result.size(); ++i)
        cout<<result[i]<<endl;

    int data3[] = {-1, 0, 1, 2, -1, -4};
    vector<int> vdata3(data3, data3+6);
    vector<vector<int> > results = threeSums(vdata3, 0);
    for(int i=0; i < results.size(); ++i) {
        cout<<"(";
        for(int j=0; j < results[i].size(); ++j)
            cout<<results[i][j]<<",";
        cout<<"\b)"<<endl;
    }
}


