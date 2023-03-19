#include <iostream>
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include <fstream>

using namespace std;
ifstream in("teste.in");

// quicksort2//
const int MAXN = 1000;

int q[MAXN];
int dr[MAXN];
int st[MAXN];
int mij[MAXN];
int n;

void qquicksort(int spos, int dpos)
{
    if (spos >= dpos)
        return;
    int m = 0, s = 0, d = 0;

    srand(time(0));
    int index_p = rand() % (dpos - spos + 1) + spos;
    int p = q[index_p];

    for (int i = spos; i <= dpos; i++)
    {
        if (q[i] > p)
            dr[d++] = q[i];
        if (q[i] < p)
            st[s++] = q[i];
        if (q[i] == p)
            mij[m++] = q[i];
    }
    int k = 0;
    for (int i = spos; i < spos + s; i++)
    {
        q[i] = st[k++];
    }
    k = 0;
    for (int i = spos + s; i < spos + s + m; i++)
    {
        q[i] = mij[k++];
    }
    k = 0;
    for (int i = spos + s + m; i < spos + s + d + m; i++)
    {
        q[i] = dr[k++];
    }
    qquicksort(spos, spos + s - 1);
    qquicksort(spos + s + m, dpos);
}
// quicksort//
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
///////////////////////
/// mergesort//
////////////////////////
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
/////////////////
////shellsort/////
///////////////
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
////////////////////////
/// Radixsort/////
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
/////
/// selectionsort
void selectionsort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(v[i], v[min_idx]);
        }
    }
}
/////////
void verificare(int v[], int n)
{
    int ok = 1;
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] < v[i])
        {
            cout << "vector nu e sortat corect";
            ok = 0;
            break;
        }
    }
    if (ok == 1)
        cout << "sortare buna" << endl;
}
//////////////////////////

int main()
{
    // random vector//////////////////////

    srand(time(0));
    int T, N, Nmax;
    in >> T;
    
    for (int i = 0; i < T; i++)
    {   cout << "t=" << i+1 << endl;
        in >> N >> Nmax;
        int Ncpy = N;

        int v1[N];
        int v2[N];
        int v3[N];
        int v4[N];
        int v5[N];
        cout << "vector initial" << endl;
        for (int j = 0; j < N; j++)
        {
            int random_num = rand() % Nmax + 1;
            // cout << random_num << " ";
            /////vectori
            q[j] = random_num;
            v1[j] = random_num;
            v2[j] = random_num;
            v3[j] = random_num;
            v4[j] = random_num;
            v5[j] = random_num;
        }
        cout << endl;
        // clock_t start = clock(); 
        
        // selectionsort(v1, N);
        // clock_t finish = clock();
        // double doneTime1 = double(finish-start)/double(CLOCKS_PER_SEC/1000); 
        clock_t start2 = clock(); 
        // radixsort(v2, N, 16);
         clock_t finish2 = clock();
        double doneTime2 = double(finish2-start2)/double(CLOCKS_PER_SEC/1000); 
        clock_t start3 = clock(); 
        // shellsort(v3, N);
         clock_t finish3 = clock();
        double doneTime3 = double(finish3-start3)/double(CLOCKS_PER_SEC/1000); 
        clock_t start4 = clock(); 
        // mergesort(v4, N);
         clock_t finish4 = clock();
        double doneTime4 = double(finish4-start4)/double(CLOCKS_PER_SEC/1000); 
        clock_t start5 = clock(); 
        quicksort(v5, N);
         clock_t finish5 = clock();
        double doneTime5 = double(finish5-start5)/double(CLOCKS_PER_SEC/1000); 
        clock_t start6 = clock(); 
        // qquicksort(0, N - 1);
         clock_t finish6 = clock();
        double doneTime6 = double(finish6-start6)/double(CLOCKS_PER_SEC/1000); 
        // cout << "vector sortat cu selection sort in " <<endl;
        // for (int i = 0; i < Ncpy; i++)
        // {
        //     cout << v1[i] << " ";
        // }
        // cout<<endl;
        // verificare(v1, N);
        // cout << endl;
        // cout << "vector sortat cu radixsort" << endl;
        // for (int i = 0; i < Ncpy; i++)
        // {
        //     cout << v2[i] << " ";
        // }
        // cout<<endl;
        // verificare(v2, N);
        // cout << endl;
        // cout << "vector sortat cu shell sort" << endl;
        // for (int i = 0; i < Ncpy; i++)
        // {
        //     cout << v3[i] << " ";
        // }
        // cout<<endl;
        // verificare(v3, N);
        // cout << endl;
        // cout << "vector sortat cu merge sort" << endl;
        // for (int i = 0; i < Ncpy; i++)
        // {
        //     cout << v4[i] << " ";
        // }
        // cout<<endl;
        // verificare(v4, N);
        // cout << endl;
        // cout << "vector sortat cu quick sort" << endl;
        // for (int i = 0; i < Ncpy; i++)
        // {
        //     cout << v5[i] << " ";
        // }
        // cout<<endl;
        // verificare(v5, N);
        // cout << endl;
        // cout << "vector sortat cu quick sort alta implementare" << endl;
        // for (int i = 0; i < Ncpy; i++)
        // {
        //     cout << q[i] << " ";
        // }
        // cout<<endl;
        
        // verificare(q, N);
        // cout << endl;
        // cout<<"Selection sort a durat: "<<doneTime1<<"ms"<<endl;
        // cout<<"Radix sort a durat: "<<doneTime2<<"ms"<<endl;
        // cout<<"shell sort a durat: "<<doneTime3<<"ms"<<endl;
        // cout<<"Merge sort a durat: "<<doneTime4<<"ms"<<endl;
        cout<<"Quicksort 1 a durat: "<<doneTime5<<"ms"<<endl;
        // cout<<"Quicksort 2  a durat: "<<doneTime6<<"ms"<<endl;
    }
    //////////////////////////////////////

    return 0;
}
