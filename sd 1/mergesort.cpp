#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
ifstream in("algsort.in");
ofstream out("algsort.out");
void merge(int v[], int st, int dr, int mij)
{
    int i = st;
    int j = mij + 1;
    int k = 0;
    int aux[dr - st + 1];
    while (i <= mij && j <= dr)
    {
        if (v[i] < v[j])
        {
            aux[k++] = v[i++];
        }
        else
        {
            aux[k++] = v[j++];
        }
    }
    while (i <= mij)
    {
        aux[k++] = v[i++];
    }
    while (j <= dr)
    {
        aux[k++] = v[j++];
    }
    for (int i = 0; i < k; i++)
    {
        v[st + i] = aux[i];
    }
}

void recurs(int v[], int st, int dr)
{
    if (st < dr)
    {
        int m = st + (dr - st) / 2;
        recurs(v, st, m);
        recurs(v, m + 1, dr);
        merge(v, st, dr, m);
    }
}
void mergesort(int v[], int n)
{
    recurs(v, 0, n - 1);
}

int main()
{
    int v[500001], n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in >> v[i];
    }
    mergesort(v, n);
    for (int i = 0; i < n; i++)
    {
        out << v[i] << " ";
    }
}
