#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <random>
#include <string>

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
        matrix[0][0] = 1;
        matrix[1][0] = -1;
    }
    CData(unsigned int k)
    {
        matrix.resize(k);
        for (unsigned int i = 0; i < k; i++)
        {
            matrix[i].resize(rand() % 5);
            for (unsigned int j = 0; j < matrix[i].size(); j++)
            {
                matrix[i][j] = rand() % k;
            }
        }
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
    CData0(unsigned int k) : CData(k) {}
    CData0(const CData &other) : CData(other) {}
    CData0 &operator-=(int a)

    {
        unsigned int i = 0, j = 0;
        while (i < matrix[0].size())
        {
            if (matrix[0][i] == a)
            {
                i++;
            }
            else
            {
                matrix[0][j] = matrix[0][i];
                j++;
                i++;
            }
        }
        matrix[0].resize(j);
        return *this;
    }
};

class CData1 : public CData
{
public:
    CData1() : CData() {}
    CData1(const CData &other) : CData(other) {}
    CData1(unsigned int k) : CData(k) {}
    CData1 &operator-=(int a)
    {
        for (unsigned int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == a)
            {
                for (unsigned int j = 0; j < matrix[i].size() - 1; j++)
                {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i].resize(matrix[i].size() - 1);
            }
        }
        return *this;
    }
};

int main()
{
    int len_str = 32 * 32;
    CData **arr = new CData *[size_arr], **tmp_arr = nullptr;
    string sss;
    char *str = new char[len_str];
    char *old_str = str;
    ifstream fin("1.txt");
    fin.getline(str, len_str - 1);
    sss = str;
    while ((buf = get_CData(sss)))
    {
        if (len_arr == size_arr)
        {
            size_arr *= 2;
            tmp_arr = new CData *[size_arr];
            for (int i = 0; i < len_arr; i++)
            {
                tmp_arr[i] = arr[i];
            }
            delete[] arr;
            arr = tmp_arr;
            tmp_arr = nullptr;
        }
        arr[len_arr] = buf;
        len_arr++;
    }
    fin.close();
    CData0 a(3);
    CData1 b;
    a.output();
    cout << endl;
    a -= 1;
    a.output();
    cout << endl
         << "--------";
    cout << endl;
    b.output();
    cout << endl;
    b -= -1;
    b.output();
    return 0;
}
