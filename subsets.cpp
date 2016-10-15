#include <iostream>
#include <vector>

using namespace std;
void _subsets(vector<int> &s, int end, vector<vector<int> > &results) {
    vector<int> result;
    if ( end <= 0) {
        results.push_back(result);
        return;
    }

    _subsets(s, end - 1, results);
    vector<vector<int> > new_results;
    for(vector<vector<int> >::iterator v_iter = results.begin(); v_iter != results.end(); v_iter++){
        vector<int> nv;
        nv.assign(v_iter->begin(), v_iter->end());
        nv.push_back(s[end - 1]);
        new_results.push_back(nv); 
    }
    results.insert(results.end(), new_results.begin(), new_results.end());
}

vector<vector<int> > subsets(vector<int> &s) {
    vector<vector<int> > results;
    _subsets(s, s.size(), results);
    return results;
}

int main(void) {
    int data[] = {1, 2, 3, 4};
    vector<int> v1(data, data+4);
    vector<vector<int> > results = subsets(v1);

    for(vector<vector<int> >::iterator v_iter = results.begin(); v_iter != results.end(); v_iter++) {
        cout<<"[";
        for(vector<int>::iterator n_iter = v_iter->begin(); n_iter != v_iter->end(); n_iter++) {
            cout<<*n_iter<<", ";
        }
        cout<<"\b\b]"<<endl;
    }
}
