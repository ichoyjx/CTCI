#include <stdio.h>

void GenKnuth(int m, int n) {
    for(int i=0; i<n; ++i) {
        if((bigrand()%(n-i)) < m) {
            cout<<i<<endl;
            --m;
        }
    }
}

void GenSets(int m, int n) {
    set<int> s;
    while(s.size() < m)
        s.insert(bigrand() % n);
    set<int>::iterator i;
    for(i=s.begin(); i!=s.end(); ++i)
        cout<<*i<<endl;
}

void GenShuf(int m, int n) {
    int x[n];
    for(int i=0; i<n; ++i)
        x[i] = i;
    for(int i=0; i<m; ++i) {
        int j = randint(i, n-1);
        swap(x[i], x[j]);
    }
    sort(x, x+m);
    for(int i=0; i<m; ++i)
        cout<<x[i]<<endl;
}

int main () {

  return 0;
}
