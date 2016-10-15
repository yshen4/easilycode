#include "algorithms.h"

using namespace std;
void _subsets(vector<int> &s, int end, vector<vector<int> > &results) {
    vector<int> result;
    if ( end <= 0) {
        results.push_back(result);
        return;
    }

    int n_end = end - 1;
    while (n_end > 0 && s[n_end-1] == s[end-1]) --n_end;
    _subsets(s, n_end, results);
    vector<vector<int> > new_results;
    for(vector<vector<int> >::iterator v_iter = results.begin(); v_iter != results.end(); v_iter++){
        vector<int> nv;
        nv.assign(v_iter->begin(), v_iter->end());
        for(int i = n_end; i < end; ++i) {
            nv.push_back(s[end - 1]);
            new_results.push_back(nv); 
        }
    }
    results.insert(results.end(), new_results.begin(), new_results.end());
}

vector<vector<int> > subsets(vector<int> &s) {
    sort(s.begin(), s.end());
    vector<vector<int> > results;
    _subsets(s, s.size(), results);
    return results;
}

int main(void) {
    int data[] = {1, 2, 4, 2, 3, 4};
    vector<int> v1(data, data+6);
    vector<vector<int> > results = subsets(v1);

    for(vector<vector<int> >::iterator v_iter = results.begin(); v_iter != results.end(); v_iter++) {
        cout<<"[";
        for(vector<int>::iterator n_iter = v_iter->begin(); n_iter != v_iter->end(); n_iter++) {
            cout<<*n_iter<<", ";
        }
        cout<<"\b\b]"<<endl;
    }
}
