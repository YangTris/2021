#include <iostream>
using namespace std;

void inArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void outArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int LinearSearch(int a[], int n, int x)
{
    int i = 0;
    a[n] = x;
    while (a[i] != x)
        i++;
    if (i == n)
        return -1;
    return i;
}

void SelectionSort(int a[], int n)
{
    int min, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        if (min != i)
            swap(a[min], a[i]);
    }
}

void InsertionSort(int a[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > x))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void ExchangeSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[j] < a[i])
                swap(a[i], a[j]);
}

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

void ShakerSort(int a[], int n)
{
    int i;
    int left, right, k;
    left = 0;
    right = n - 1;
    k = n - 1;
    while (left < right)
    {
        for (i = right; i > left; i--)
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        left = k;
        for (i = left; i < right; i++)
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        right = k;
    }
}

void merge(int a[], int i, int mid, int j)
{
    // Merges the 2 sorted sub-arrays a[i..mid] and
    // a[mid+1..j] into one sorted sub-array a[i..j]

    int *temp = new int[j - i + 1];        // temp storage
    int left = i, right = mid + 1, it = 0; //left chay ben trai right chay ben phai it chay cho temp
    // it = next index to store merged item in temp[]
    // Q: What are left and right?                      //left la dau right la cuoi

    while (left <= mid && right <= j) //left right con ptu -> so sanh
    {                                 // output the smaller
        if (a[left] <= a[right])
            temp[it++] = a[left++];
        else
            temp[it++] = a[right++];
    }
    // Copy the remaining elements into temp. Q: Why?   //de duoc mang moi da sap xep
    while (left <= mid) //right da duoc sort het ma left con ptu
        temp[it++] = a[left++];
    while (right <= j) //left da duoc sort het ma right con ptu
        temp[it++] = a[right++];
    // Q: Will both the above while statements be executed? //duoc thuc thi khi 1 ben mang da het ptu

    // Copy the result in temp back into
    // the original array a
    for (int k = 0; k < it; k++) //gan toan bo mang temp da dc sap xep vao mang a
        a[i + k] = temp[k];
}
void mergeSort(int a[], int i, int j) //i chi so dau tien, j chi so cuoi de dam bao mang ko trong
{
    // to sort data from a[i] to a[j], where i<j
    if (i < j)
    {                             // Q: What if i >= j?    //mang co it hon 2ptu -> khong can sap xep
        int mid = (i + j) / 2;    // divide
        mergeSort(a, i, mid);     // recursion              //a[i-mid]
        mergeSort(a, mid + 1, j); //a[mid+1-j]
        merge(a, i, mid, j);      //conquer: merge a[i..mid] and
                                  //a[mid+1..j] back into a[i..j]                   //gop 2 mang da sap xep thanh 1 mang da sap xep
    }
}
void swap(int a[], int b, int c)
{
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

int partition(int a[], int i, int j) //tim ptu pivot ben trai la nho hon pivot ben phai la lon hon pivot
{
    // partition data items in a[i..j]
    int p = a[i];                    // p is the pivot, the ith item
    int m = i;                       // Initially S1 and S2 are empty      //m la vi tri S1 cach giua S2 ma S1,S2 chua co ptu nen m = gtri dau tien
    for (int k = i + 1; k <= j; k++) //chay nhung ptu sau pivot
    {                                //process unknown region       //tim S1,S2
        if (a[k] < p)
        {                  // case 2: put a[k] to S1
            m++;           // tang mang S1 len 1 don vi
            swap(a, k, m); //hoan vi a[k] voi a[m]
        }
        else
        {          // case 1: put a[k] to S2. Do nothing!    //k tu tang len 1 -> Do nothing
        }          // else part should be removed since it is empty
    }              // sau khi tim dc tat ca ptu S1 va S2
    swap(a, i, m); // put the pivot at the right place                  // hoan vi ptu a[i] voi a[m] de dua m ve vi tri giua
    return m;      // m is the pivot’s final position                   //luc nay vtri pivot =m
}

void quickSort(int a[], int i, int j) //khai bao mang a ptu voi i la chi so dau tien, j la chi so cuoi cung dung de sap xep mang a tu i->j
{
    if (i < j)
    {                                      // Q: What if i >= j?                 //Neu mang co 1 ptu ko can sap xep mang 0 co ptu -> ket thuc
        int pivotIdx = partition(a, i, j); //khai bao gtri pivotIdx la ham partition co gia tri tra ve la m voi nhung ptu nho hon no nam tren trai nhung ptu lon hon no nam ben phai
        quickSort(a, i, pivotIdx - 1);     //a[dau-m]   thuc hien cho den khi no con 1 ptu hoac 0 con ptu nao thi ket thuc
        quickSort(a, pivotIdx + 1, j);     //a[m+1-het]
        // No conquer part! Why?                    // mang da dc sap xep tu a[i-j]
    }
}
/*
void radixSort(int a[], int n, int d)
{
    // Sorts n d-digit numeric strings in the array.
    for (j = d down to 1)
    {                                         // for digits in last position to 1st position
        initialize 10 groups(queues) to empty // Q: why 10 groups?

            for (i = 0 through n - 1){
                k = jth digit of array[i] place array[i] at the end of group k} Replace array with all items in group 0,
            followed by all items in group 1, and so on.
    }
}
*/
int getDigit(int a[], int n)
{
    int temp_Max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > temp_Max)
            temp_Max = a[i];
    int count = 0;
    while (temp_Max > 0)
    {
        temp_Max /= 10;
        count++;
    }
    return count;
}
void radixSort(int a[], int n)
{
    int digit = getDigit(a, n);
    int arr[10][n];
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int div = 1;
    int t, index_a = 0;
    while (digit > 0)
    {
        for (int i = 0; i < n; i++)
        {
            t = (a[i] / div) % 10;
            arr[t][count[t]] = a[i];
            count[t]++;
        }

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < count[i]; j++)
                a[index_a++] = arr[i][j];
        //reset mang
        for (int i = 0; i < 10; i++)
            count[i] = 0;

        div *= 10;
        digit--;
        index_a = 0;
    }
}

int main()
{
    int n;
    cout << "Input n:";
    cin >> n;
    int *a = new int[n];
    inArr(a, n);
    //    InsertionSort(a, n);
    //    del(n, a);
    //    SelectionSort(a, n);
    //    BubbleSort(a, n);
    //    ExchangeSort(a, n);
    //    ShakerSort(a, n);
    int i = 0, j = n - 1;
    //int mid = (i + j) / 2;
       mergeSort(a, i, j);
    // quickSort(a, i, j);
    //    adixSort(a,n);
    outArr(a, n);
    delete[] a;
    return 0;
} //5 2 3 2 4 1 0 -4 2 3
