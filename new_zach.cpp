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
            mas[i][rand() % N] = 0;
        }
    }

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
            cout << mas[i];
            cout << endl;
        }
    }

    virtual CData &operator~() = 0;
};

class CData0 : public CData
{
public:
    CData0() : CData() {}
    CData0(const CData &other) : CData(other) {}
    CData &operator~()

    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mas[i][j] != '\n')
                {
                    mas[i][j] = '~';
                    break;
                }
            }
        }
        return *this;
    }
};

void vec_output(CData **vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "vec[" << i << "] = {" << endl;
        (**vec).output();
        cout << "}" << endl;
    }
}

class CData1 : public CData
{
public:
    CData1() : CData() {}
    CData1(const CData &other) : CData(other) {}
    CData &operator~()

    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (mas[j][i] != '\n')
                {
                    mas[j][i] = '~';
                    break;
                }
            }
        }

        return *this;
    }
};

int main()
{
    CData **vec = nullptr;
    int n = rand() % 2 + 1;
    int i;
    srand(time(0));
    vec = new CData *[n];
    for (int i = 0; i < n; i++)
    {
        if (rand() % 2)
        {
            vec[i] = new CData0;
        }
        else
        {
            vec[i] = new CData1;
        }
    }
    CData *tmp = vec[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        vec[i] = vec[i - 1];
    }
    vec[0] = tmp;
    vec_output(vec, n);
    for (i = 0; i < n; i++)
    {
        ~(*(vec[i]));
    }
    vec_output(vec, n);
    vec_output(vec, n);
    delete[] vec;
    return 0;
}
