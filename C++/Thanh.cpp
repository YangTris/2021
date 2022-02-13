#include <iostream>
using namespace std;

void ngayTiepTheo(int ngay, int thang, int nam)
{
    if (ngay == 31)
    {
        if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10)
        {
            thang++;
            ngay = 1;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        if (thang == 12)
        {
            nam++;
            thang = 1;
            ngay = 1;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
    }
    if (ngay == 30)
    {
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        {
            thang++;
            ngay = 1;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
    }
    if (thang == 2)
    {
        if (nam % 400 == 0 && ngay == 29) //nam nhuan
        {
            thang++;
            ngay = 1;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        if (nam % 4 == 0 && nam % 100 != 0 && ngay == 29) //nam nhuan
        {
            thang++;
            ngay = 1;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        if (ngay == 28)
        {
            ngay = 1;
            thang++;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
    }
    ngay++;
    cout << ngay << "/" << thang << "/" << nam;
    return;
}

void ngayTruoc(int ngay, int thang, int nam)
{
    if (ngay == 1)
    {
        if (thang == 1)
        {
            ngay = 31;
            thang = 12;
            nam--;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        thang--;
        if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10)
        {
            ngay = 31;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        {
            ngay = 30;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        if (nam % 400 == 0)
        {
            ngay = 29;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
        if (nam % 4 == 0 && nam % 100 != 0 && ngay == 29)
        {
            ngay = 28;
            cout << ngay << "/" << thang << "/" << nam;
            return;
        }
    }
    ngay--;
    cout << ngay << "/" << thang << "/" << nam;
    return;
}
int main()
{
    int ngay, thang, nam;
    cout << "Nhap ngay, thang, nam: ";
    cin >> ngay >> thang >> nam;
    cout << "Ngay tiep theo= ";
    ngayTiepTheo(ngay, thang, nam);
    cout << endl;
    cout << "Ngay truoc= ";
    ngayTruoc(ngay, thang, nam);
}