#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

class CData
{
public:
    vector<vector<int>> matrix;

protected:
public:
    CData()
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

    virtual CData &operator-=(int a) = 0;
};

class CData0 : public CData
{
public:
    CData0() : CData() {}
    CData0(const CData &other) : CData(other) {}
    CData0 &operator-=(int a)
    {
    }
};

class CData1 : public CData
{
public:
    CData1() : CData() {}
    CData1(const CData &other) : CData(other) {}

    CData1 &operator-=(int a)
    {
    }
};

int main()
{

    return 0;
}