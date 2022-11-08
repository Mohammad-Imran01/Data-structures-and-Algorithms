#include <iostream>
#include <algorithm>
using namespace std;

bool descsortsec(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

struct poly{
    int n;
    pair<int, int> *term;
    poly(): n { 0 }, term { NULL } {}
    poly (int terms) {
        n = terms;
        term = new pair<int, int>[n];
    }
};
void read (poly& p) {
    cout << "Enter " << p.n << " Ceoffs and exponentials: \n";
    for (int i = 0 ;i < p.n; i++) {
        cin >> p.term[i].first >> p.term[i].second;
    }
}
void print (const poly& p) {
    for(int i = 0; i < p.n; i++) {
        cout << p.term[i].first << "x^" << p.term[i].second << " ";  
    }
    cout << endl;
}
poly add (poly& p1, poly& p2) {
    sort(p1.term, p1.term + p1.n, descsortsec);
    sort(p2.term, p2.term + p2.n, descsortsec);
    poly sum(p2.n + p1.n);
    
    int i{}, j {}, k{};

    while (i < p1.n && j < p2.n) {
        if (p1.term[i].second > p2.term[j].second) {
            sum.term[k++] = p1.term[i++];
        } else if (p1.term[i].second < p2.term[j].second) {
            sum.term[k++] = p2.term[j++];
        } else {
            sum.term[k].first = p1.term[i].first + p2.term[j++].first;
            sum.term[k++].second = p1.term[i++].second;
        }
    }
    for(; i < p1.n; i++) sum.term[k++] = p1.term[i];
    for(; j < p2.n; j++) sum.term[k++] = p2.term[j];
    sum.n = k;
    return sum;
}

int main () {
    poly p1(3), p2(2);
    read (p1), read (p2);
    poly sum = add(p1, p2);
    print (sum);

    return 0;
}