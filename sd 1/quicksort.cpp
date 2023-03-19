#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
ifstream in("algsort.in");
ofstream out("algsort.out");
int partitie(int v[], int st, int dr)
{
    srand(time(0));
    int pivot_index = rand() % (dr - st + 1) + st;
    int pivot = v[pivot_index]; 
    swap(v[pivot_index], v[dr]);

    // partitionare in functie de pivot
    int j = dr - 1;
    int i = st;
    while (i <= j)
    {
        if (v[i] <= pivot)
            i++;
        else if (v[j] >= pivot)
            j--;
        else
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    swap(v[i], v[dr]);

    return i;
}
void recur(int v[], int st, int dr)
{
    if (st < dr)
    {
        int index_pivot = partitie(v, st, dr);
        recur(v, st, index_pivot - 1);
        recur(v, index_pivot + 1, dr);
    }
}
void quicksort(int v[], int N)
{
    recur(v, 0, N - 1);
}
int main()
{
    int v[500001], n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in >> v[i];
    }
    quicksort(v, n);
    for (int i = 0; i < n; i++)
    {
        out << v[i] << " ";
    }
}
