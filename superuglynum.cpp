#include <vector>
#include <iostream>

using namespace std;

class superUglyNumber {
private:
    int purgeFactor(int d, int f) {
        while( d % f == 0) d = d / f;
        return d;
    }
    
    int isUgly(int d, vector<int>& primes) {
        for(vector<int>::iterator iter = primes.begin(); iter != primes.end(); iter++) {
            d = purgeFactor(d, *iter);
        }
        
        return d == 1 ? 1 : 0;
    }
    
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = 0, rt = 0, v = 1;
        while(k < n) {
            if (isUgly(v, primes)) {
                rt = v;
                ++k;
            }
            ++v;
        }
        
        return rt;
    }
};

int main(void) {
    superUglyNumber sun;
    int data[] = {2, 7, 13, 19};
    vector<int> primes(data, data+4);

    cout << "1th super ugly number: "<<sun.nthSuperUglyNumber(1, primes)<<endl;
    cout << "5th super ugly number: "<<sun.nthSuperUglyNumber(5, primes)<<endl;
    cout << "10th super ugly number: "<<sun.nthSuperUglyNumber(9, primes)<<endl;
    cout << "12th super ugly number: "<<sun.nthSuperUglyNumber(12, primes)<<endl;

    int data2[] = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
    vector<int> primes2(data, data+30);
    cout << "1000th super ugly number: "<<sun.nthSuperUglyNumber(1000, primes2)<<endl;
    //cout << "10000th super ugly number: "<<sun.nthSuperUglyNumber(10000, primes2)<<endl;
    //cout << "100000th super ugly number: "<<sun.nthSuperUglyNumber(100000, primes2)<<endl;
}



