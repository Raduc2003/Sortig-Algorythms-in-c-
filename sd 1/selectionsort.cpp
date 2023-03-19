#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
ifstream in("algsort.in");
ofstream out("algsort.out");
void selectionsort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(v[i], v[min_idx]);
        }
    }
}
int main()
{
    int v[500001], n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in >> v[i];
    }
    selectionsort(v, n);
    for (int i = 0; i < n; i++)
    {
        out << v[i] << " ";
    }
}
