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
    char[N][N] mas;

public:
    CData()
    {
    }

    virtual ~CData()
    {
    }
    void output()
    {
    }

    virtual CData &operator-=(int a) = 0;
};

class CData0 : public CData
{
public:
    CData0() : CData() {}
    // CData0(unsigned int k) : CData(k) {}
    // CData0(const CData &other) : CData(other) {}
    void operator!()

    {
    }
    void operator~()

    {
    }
};

class CData1 : public CData
{
public:
    CData1() : CData() {}
    // CData1(const CData &other) : CData(other) {}
    // CData1(unsigned int k) : CData(k) {}
    void operator!()

    {
    }
    void operator~()

    {
    }
};

void vec_output()
{
}

int main()
{

    return 0;
}
