#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <random>

using namespace std;

#define N 3

class CData
{
public:
    char mas[N][N];

public:
    CData()
    {
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
                mas[i][j] = 'a';
            }
        }
    }

    //skfs
    CData(const CData &other)
    {
        for (unsigned int i = 0; i < N; i++)
        {
            for (unsigned int j = 0; j < N; j++)
            {
                mas[i][j] = other.mas[i][j];
            }
        }
    }

    virtual ~CData()
    {
    }
    void output()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << mas[i][j] << " ";
            }
            cout << endl;
        }
    }

    virtual CData &operator~() = 0;
    // virtual void operator!();
};

class CData0 : public CData
{
public:
    CData0() : CData() {}
    CData0(const CData &other) : CData(other) {}
    // void operator!()

    // {
    // }
    CData &operator~()

    {
        cout << "";
        return *this;
    }
};

class CData1 : public CData
{
public:
    CData1() : CData() {}
    CData1(const CData &other) : CData(other) {}
    // void operator!()

    // {
    // }
    CData &operator~()

    {
        cout << "";
        return *this;
    }
};

int main()
{
    CData0 a;
    a.output();
    return 0;
}
