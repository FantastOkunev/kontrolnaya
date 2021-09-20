#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

class CData
{
public:
    int *array = nullptr;
    int len = 0;

protected:
public:
    CData(int N, int *arr)
    {
    }

    void delete_all()
    {
    }
    virtual ~CData()
    {
    }
    CData(const CData &other)
    {
    }
    CData(CData &&other)
    {
    }
    CData &operator=(const CData &other)
    {
    }
    CData &operator=(CData &&other)
    {
    }
    void output()
    {
    }

    virtual void sort() = 0;
    static int comp(const void *arg1, const void *arg2)
    {
    }
};

class CData0 : public CData
{
public:
    CData0(int N, int *arr) : CData(N, arr) {}
    CData0(const CData &other) : CData(other) {}
    void sort()
    {
    }
};

class CData1 : public CData
{
public:
    CData1(int N, int *arr) : CData(N, arr) {}
    CData1(const CData &other) : CData(other) {}

    void sort()
    {
    }
};

CData0 operator+(const CData &first, const CData &second)
{
}

int main()
{

    return 0;
}