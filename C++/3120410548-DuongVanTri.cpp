#include <iostream>
#include <math.h>
using namespace std;
//swap
void bai1(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}
//ptb2
float bai2(float a, float b, float c)
{
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				return -1; //pt vo so nghiem
			else
				return 0; //pt vo nghiem
		}
		else
			return -c / b; //nghiem duy nhat
	}
	else
	{
		float delta = b * b - 4 * a * c;
		if (delta > 0)
		{
			float x1 = (-b + sqrt(delta)) / (2 * a);
			float x2 = (-b - sqrt(delta)) / (2 * a);
			return 2;
		}
		if (delta == 0)
		{
			float x1 = -b / 2 * a;
			float x2 = x2;
			return 1 ;//pt co nghiem kep
		}
		else
			return 0; //pt vo nghiem
	}
	return 0;
}
//giai thua
int bai3(int n)
{
	if (n == 1)
		return 1;
	return n * bai3(n - 1);
}
// luy thua
int bai4(int n, int k)
{
	if (k == 0)
		return 1;
	return n * bai4(n, k - 1);
}
//tim ptu thu k
int bai5(int m[], int k, int n)
{
	if (k > n)
		return -1;
	return m[k - 1];
}
//sap xep tang dan
void bai6(int m[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (m[i] > m[j])
				swap(m[i], m[j]);
}
//snt
bool bai7(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}
//fibonanci
int bai8(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return bai8(n - 1) + bai8(n - 2);
}
int main()
{
	int n, k, m[1000];
	float a, b, c;
	int chose;
	cout << "Chose menu: ";
	cin >> chose;
	switch (chose)
	{
	case 1:
		cout << "Input a&b: ";
		cin >> a >> b;
		bai1(a, b);
		cout << "a=" << a << " b=" << b;
		break;
	case 2:
		cout << "Input a,b,c: ";
		cin >> a >> b >> c;
		cout << bai2(a, b, c);
		break;
	case 3:
		cout << "Input n: ";
		cin >> n;
		while (n < 1)
		{
			cout << "Input n again: ";
			cin >> n;
		}
		cout << bai3(n);
		break;
	case 4:
		cout << "Input n&k: ";
		cin >> n >> k;
		cout << bai4(n, k);
		break;
	case 5:
		cout << "Input n&k: ";
		cin >> n >> k;
		while (n < 0)
		{
			cout << "Input n again: ";
			cin >> n;
		}
		while (k > n || k < 1)
		{
			cout << "Input k again: ";
			cin >> k;
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Input a[" << i << "]: ";
			cin >> m[i];
		}
		cout << bai5(m, k,n);
		break;
	case 6:
		cout << "Input n: ";
		cin >> n;
		while (n < 0)
		{
			cout << "Input n again: ";
			cin >> n;
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Input a[" << i << "]: ";
			cin >> m[i];
		}
		bai6(m, n);
		break;
	case 7:
		cout << "Input n: ";
		cin >> n;
		cout << bai7(n);
		break;
	case 8:
		cout << "Input n: ";
		cin >> n;
		cout << bai8(n);
		break;
	default:
		cout << "Error!";
		break;
	}
	return 0;
}
