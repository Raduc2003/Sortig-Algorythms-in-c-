#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
ifstream in("algsort.in");
ofstream out("algsort.out");
void shellsort(int v[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int gaura = v[i];
            for (int j = i; j >= gap && v[j - gap] > gaura; i -= gap)
            {
                v[j] = v[j - gap];
                v[i] = gaura;
            }
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
    shellsort(v, n);
    for (int i = 0; i < n; i++)
    {
        out << v[i] << " ";
    }
}
