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

    // CData(string line)
    // {
    //     int tmp;
    //     char *str
    //             line >>
    //         tmp;
    //     cout << "tmp = " << tmp << endl;
    // }

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

void vec_output(vector<CData *> vec)
{
    unsigned int i;
    for (i = 0; i < vec.size(); i++)
    {
        cout << "vec[" << i << "] = {" << endl;
        vec[i]->output();
        cout << "}" << endl;
    }
    cout << endl;
}

int main()
{
    string line;
    ifstream in("1.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
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

    cout << endl
         << endl;
    unsigned int i;
    vector<CData *> vec;
    vec.resize(rand() % 5 + 1);
    for (i = 0; i < vec.size(); i++)
    {

        vec[i] = new CData0(rand() % 4 + 1);
    }
    vec_output(vec);
    CData *tmp = vec[vec.size() - 1];
    for (i = vec.size() - 1; i > 0; i--)
    {
        vec[i] = vec[i - 1];
    }
    vec[0] = tmp;
    vec_output(vec);
    // for (i = 0; i < vec.size(); i++)
    // {
    //     rand();
    // }
    // vec_output(vec);

    return 0;
}
