#include "algorithms.h"

using namespace std;

/*
 * {1, 2, 3, ..., n}, all combination of k elements
 **/
void combine_k(int n, int k, vector<vector<int> > &results) {
    if (k <= 0) return; 
    if (n <= k) {
	vector<int> comb(n);
	iota(comb.begin(), comb.end(), 1);
        results.push_back(comb);
	return;
    }

    combine_k(n - 1, k, results);
    vector<vector<int> > n_combs;
    for(vector<vector<int> >::iterator c_iter= results.begin(); c_iter != results.end(); c_iter++) {
	for(int i=0; i<k; ++i) {
	    vector<int> comb(c_iter->begin(), c_iter->end());
	    comb[i] = n;
	    n_combs.push_back(comb);
	}
    }
    results.insert(results.end(), n_combs.begin(), n_combs.end());
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > results;
    combine_k(n, k, results);
    return results; 
}

int main(void) {
    vector<vector<int> > results = combine(4, 2);

    for(vector<vector<int> >::iterator v_iter = results.begin(); v_iter != results.end(); v_iter++) {
        cout<<"[";
        for(vector<int>::iterator n_iter = v_iter->begin(); n_iter != v_iter->end(); n_iter++) {
            cout<<*n_iter<<",";
        }
        cout<<"\b]"<<endl;
    }
}

