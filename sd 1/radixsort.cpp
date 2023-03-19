#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
ifstream in("algsort.in");
ofstream out("algsort.out");
void radixsort(int v[], int n, int base)
{
    int max = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= base)
    {
        int output[n];
        int count[base] = {0};

        for (int i = 0; i < n; i++)
        {
            int digit = (v[i] / exp) % base;
            count[digit]++;
        }

        for (int i = 1; i < base; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (v[i] / exp) % base;
            output[count[digit] - 1] = v[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++)
        {
            v[i] = output[i];
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
    radixsort(v, n, 16);
    for (int i = 0; i < n; i++)
    {
        out << v[i] << " ";
    }
}
