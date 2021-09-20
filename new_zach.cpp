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
        matrix.resize(2);
        matrix[0].resize(2);
        matrix[1].resize(2);
    }
    virtual ~CData()
    {
    }
    CData(const CData &other)
    {
        matrix.resize(other.matrix.size());
        for (unsigned int i = 0; i < matrix.size(); i++)
        {
            matrix[i].resize(other.matrix[i].size());
            for (unsigned int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    CData(CData &&other)
    {
        matrix.resize(other.matrix.size());
        for (unsigned int i = 0; i < matrix.size(); i++)
        {
            matrix[i].resize(other.matrix[i].size());
            for (unsigned int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    CData &operator=(const CData &other)
    {
        matrix.resize(other.matrix.size());
        for (unsigned int i = 0; i < matrix.size(); i++)
        {
            matrix[i].resize(other.matrix[i].size());
            for (unsigned int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }
    CData &operator=(CData &&other)
    {
        matrix.resize(other.matrix.size());
        for (unsigned int i = 0; i < matrix.size(); i++)
        {
            matrix[i].resize(other.matrix[i].size());
            for (unsigned int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }
    void output()
    {
        for (unsigned int i = 0; i < matrix.size(); i++)
        {
            for (unsigned int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
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
        matrix[0][0] -= a;
        return *this;
    }
};

class CData1 : public CData
{
public:
    CData1() : CData() {}
    CData1(const CData &other) : CData(other) {}

    CData1 &operator-=(int a)
    {
        matrix[0][0] += a;
        return *this;
    }
};

int main()
{
    CData0 a;
    CData1 b;
    a -= 1;
    a.output();
    b -= 1;
    b.output();
    CData0 c;
    c = b;
    c.output();
    return 0;
}