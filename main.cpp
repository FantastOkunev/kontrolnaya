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
        len = N;
        array = new int[N];
        for (int i = 0; i < N; i++)
        {
            array[i] = arr[i];
        }
    }

    void delete_all()
    {
        delete[] array;
        array = nullptr;
        len = 0;
    }
    ~CData()
    {
        delete_all();
    }
    CData(const CData &other)
    {
        array = new int[other.len];
        len = other.len;
        for (int i = 0; i < len; i++)
        {
            array[i] = other.array[i];
        }
    }
    CData(CData &&other)
    {
        array = other.array;
        len = other.len;
        other.array = nullptr;
        other.len = 0;
    }
    CData &operator=(const CData &other)
    {
        delete_all();
        array = new int[other.len];
        len = other.len;
        for (int i = 0; i < len; i++)
        {
            array[i] = other.array[i];
        }
        return *this;
    }
    CData &operator=(CData &&other)
    {
        delete_all();
        array = other.array;
        len = other.len;
        other.array = nullptr;
        other.len = 0;
        return *this;
    }
    void output()
    {
        for (int i = 0; i < len; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    virtual void sort() = 0;
};

class CData0 : public CData
{
public:
    CData0(int N, int *arr) : CData(N, arr) {}
    CData0(const CData &other) : CData(other) {}
    void sort() {}
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
    int len = max(first.len, second.len);
    int *array = new int[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = 0;
    }
    for (int i = 0; i < first.len; i++)
    {
        array[i] += first.array[i];
    }
    for (int i = 0; i < second.len; i++)
    {
        array[i] += second.array[i];
    }
    return CData0(len, array);
}

CData *get_CData(char *str, char **new_str)
{
    int I, n, k, len_arr = 0, size_arr = 4;
    char *s = new char[64];
    int *arr = new int[size_arr], *tmp_arr = nullptr;
    if (sscanf(str, "%s%n", s, &n) != 1)
    {
        delete[] s;
        return nullptr;
    }

    str += n;
    if (strlen(s) == 7 and s[5] == '0')
        I = 0;
    else
    {
        I = 1;
    }
    while (sscanf(str, "%d%n", &k, &n) == 1)
    {
        str += n;
        if (len_arr == size_arr)
        {
            size_arr *= 2;
            tmp_arr = new int[size_arr];
            for (int i = 0; i < len_arr; i++)
            {
                tmp_arr[i] = arr[i];
            }
            delete[] arr;
            arr = tmp_arr;
            tmp_arr = nullptr;
        }
        arr[len_arr] = k;
        len_arr++;
    }
    if (len_arr == 0)
    {
        delete[] arr;
        delete[] s;
        return nullptr;
    }
    CData *ret = nullptr;
    if (I)
    {
        ret = new CData1(len_arr, arr);
    }
    else
    {
        ret = new CData1(len_arr, arr);
    }
    delete[] arr;
    delete[] s;
    *new_str = str;
    return ret;
}

int main()
{
    int len_arr = 0, size_arr = 8, len_str = 32 * 32;
    CData **arr = new CData *[size_arr], **tmp_arr = nullptr;
    CData *buf = nullptr;
    char *str = new char[len_str];
    ifstream fin("1.txt");
    fin.getline(str, len_str - 1);
    while ((buf = get_CData(str, &str)))
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
    for (int i = 0; i < len_arr; i++)
    {
        arr[i]->output();
    }

    return 0;
}