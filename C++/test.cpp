#include <iostream>
using namespace std;
void inArr(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Input a[" << i << "][" << j << "]:";
			cin >> a[i][j];
		}
	}
}
void outArr(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int dcp(int **a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i][i];
	}
	return sum;
}
int dcc(int **a, int n)
{
	int sum = 0;
	int i = 0, j = n - 1;
	while (i < n)
	{
		sum += a[i][j];
		i++;
		j--;
	}
	return sum;
}
void ziczag1(int **a, int n)
{
	int pos = n - 1;
	for (int i = 1; i < n; i += 2)
	{
		for (int j = 0; j < n / 2; j++)
		{
			swap(a[i][j], a[i][pos]);
			pos--;
		}
		pos = n - 1;
	}
}
void Arr1(int **a, int n, int b[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i * n + j] = a[i][j];
		}
	}
}
void ziczag2(int **a, int n, int b[])
{
	int i = 0, j = 0;
	int pos = 1;
	Arr1(a, n, b);
	while (i < n - 1 || j < n - 1)
	{
		if (j == n - 1)
			i++;
		else
			j++;
		swap(a[i][j], b[pos]);
		pos++;
		while (i < n - 1 && j > 0)
		{
			i++;
			j--;
			swap(a[i][j], b[pos]);
			pos++;
		}
		if (i == n - 1)
			j++;
		else
			i++;
		swap(a[i][j], b[pos]);
		pos++;
		while (i > 0 && j < n - 1)
		{
			i--;
			j++;
			swap(a[i][j], b[pos]);
			pos++;
		}
	}
}
void menu()
{
	cout << "---------------------------------------" << endl;
	cout << "1. Tong duong cheo chinh" << endl;
	cout << "2. Tong duong cheo phu" << endl;
	cout << "3. Mang ziczag 1" << endl;
	cout << "4. Mang ziczag 2" << endl;
	cout << "Input <0 || >4 to close program" << endl;
}
int main()
{
	int n;
	cout << "Input n: ";
	cin >> n;
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	int b[n * n];

	inArr(a, n);
	int k;
	menu();
	cout << "Input your chose:";
	cin >> k;
	while (k > 0 && k <= 4)
	{
		switch (k)
		{
		case 1:
			cout << dcc(a, n) << endl;
			break;
		case 2:
			cout << dcp(a, n) << endl;
			break;
		case 3:
			ziczag1(a, n);
			outArr(a, n);
			break;
		case 4:
			ziczag2(a, n, b);
			outArr(a, n);
			break;
		default:
			break;
		}
		menu();
		cout << "Input your chose:";
		cin >> k;
	}
	cout << "Program close!";
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}