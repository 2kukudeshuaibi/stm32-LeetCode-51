#include <iostream>
using namespace std;

class Tdate
{
private:
    int Year;
    int Month;
    int Day;
public:
    Tdate(int y = 0, int m = 0, int d = 0)
    {
        Year = y;
        Month = m;
        Day = d;
    }
    void print()
    {
        cout << Day << '/' << Month << '/' << Year << endl;
    }
};

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    cin >> year >> month >> day;
    Tdate d(year, month, day);
    d.print();
    return 0;
}