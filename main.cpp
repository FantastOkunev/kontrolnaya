#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

class Base
{
public:
    int *arr = nullptr;
    int N = 0;

private:
    void delete_all()
    {
        delete[] arr;
        arr = nullptr;
    }
    int delete_max()
    {
        if (N == 0)
            return 1;
        int imax = 0;
        for (int i = 0; i < N; i++)
        {
            if (!comprasion(arr[imax], arr[i]))
            {
                imax = i;
            }
        }
        for (int i = imax; i < N - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        N--;
    }
    virtual bool comprasion(int first, int second)
    {
        if (first > second)
            return 1;
        else
            return 0;
    }

public:
    Base(int N_)
    {
        N = N_;
        arr = new int[N_];
        for (int i = 0; i < N; i++)
        {
            arr[i] = rand() % 100;
        }
    }
    ~Base()
    {
        delete_all();
    }
};

class Child : Base
{
public:
    Child(int N_) : Base(N_) {}
    ~Child() {}
    bool comparison(int first, int second)
    {
        if (first >= second)
            return 1;
        else
            return 0;
    }
};
ostream &operator<<(ostream &cout, const Base &vec)
{
    for (int i = 0; i < vec.N; i++)
    {
        cout << vec.arr[i] << " ";
    }
    cout << endl;
    return cout;
}

int main()
{
    srand(clock() * time(NULL));
    Base vec(5);
    cout << vec;
}