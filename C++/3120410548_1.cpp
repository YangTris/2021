#include <iostream>
using namespace std;

void inArr(int a[], int n) //hàm inArr dùng để nhập giá trị cho các phần tử trong mảng
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ptu a[" << i << "]: ";
        cin >> a[i];
    }
}

void outArr(int a[], int n) // hàm outArr dùng để xuất giá trị các phần tử trong mảng
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void merge(int a[], int i, int mid, int j)
{
    int *temp = new int[j - i + 1];        //khởi tạo mảng temp
    int left = i, right = mid + 1, it = 0; //left chạy mảng bên trái, right chạy mảng bên phải và it chạy cho mảng temp

    while (left <= mid && right <= j) //left right vẫn còn phần tử -> thực hiện so sánh, sắp xếp
    {
        if (a[left] <= a[right]) //sắp xếp từ bé đến lớn
            temp[it++] = a[left++];
        else
            temp[it++] = a[right++];
    }

    while (left <= mid) //mảng phải đã được sắp xếp mà mảng trái còn phần tử
        temp[it++] = a[left++];
    while (right <= j) //mảng trái đã được sắp xếp mà mảng phải còn phần tử
        temp[it++] = a[right++];
    // Cả 2 vòng lặp trên chỉ được thực thi khi 1 bên mảng đã hết phần tử

    for (int k = 0; k < it; k++) //gắn toàn bộ mảng temp đã được sắp xếp vào mảng a
        a[i + k] = temp[k];
}

void mergeSort(int a[], int i, int j) //i chỉ số đầu tiên, j chỉ số cuối cùng để đảm bảo mảng không trống
{
    if (i < j) //nếu i>=j thì mảng có ít hơn 2 phần tử nên không cần sắp xếp
    {
        int mid = (i + j) / 2;
        mergeSort(a, i, mid);     //mảng trái a[i-mid]
        mergeSort(a, mid + 1, j); //mảng phải a[mid+1-j]
        merge(a, i, mid, j);      //gộp 2 mảng đã sắp xếp thành 1 mảng đã sắp xếp
    }
}

int main()
{
    int a[100]; //khởi tạo mảng a có 100 phần tử
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    inArr(a, n);            //nhập giá trị cho các phần tử
    mergeSort(a, 0, n - 1); //thực thi thuật toán
    outArr(a, n);           //in các giá trị
    return 0;
}