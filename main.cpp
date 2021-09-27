#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <string>

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
    virtual ~CData()
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
        array =
            other.array;
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
    static int comp(const void *arg1, const void *arg2)
    {
        int a = abs(*(int *)arg1), b = abs(*(int *)arg2), aa = 0, bb = 0;
        while (a)
        {
            aa *= 10;
            aa += a % 10;
            a /= 10;
        }
        while (b)
        {
            bb *= 10;
            bb += b % 10;
            b /= 10;
        }
        if (aa == bb)
            return 0;
        if (aa > bb)
            return -1;
        else
            return 1;
    }
};

class CData0 : public CData
{
public:
    CData0(int N, int *arr) : CData(N, arr) {}
    CData0(const CData &other) : CData(other) {}
    void sort()
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - 1 - i; j++)
            {
                if (comp(&array[j], &array[j + 1]) > 0)
                {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }
};

class CData1 : public CData
{
public:
    CData1(int N, int *arr) : CData(N, arr) {}
    CData1(const CData &other) : CData(other) {}

    void sort()
    {
        qsort(array, len, sizeof(int), comp);
    }
};

CData0 operator+(const CData &first, const CData &second)
{
    int max_len = max(first.len, second.len), len = 0;
    int *arr = new int[max_len];
    CData1 a(first), b(second);
    a.sort();
    b.sort();
    int res;
    for (int i = 0, j = 0; i < a.len and j < b.len;)
    {
        if ((res = CData::comp(&a.array[i], &b.array[j])) == 0)
        {
            arr[len] = a.array[i];
            len++;
            i++;
            j++;
        }
        else if (res > 0)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    CData1 sum(len, arr);
    delete[] arr;
    return sum;
}

CData *get_CData(char *str, char **new_str)
{
    int I, n, k, len_arr = 0, size_arr = 4;
    char *s = new char[64];
    int *arr = new int[size_arr], *tmp_arr = nullptr;
    if (sscanf(str, "%s%n", s, &n) != 1)
    {
        delete[] s;
        delete[] arr;
        return nullptr;
    }

    str += n;
    if (strlen(s) == 6 and s[5] == '0')
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
        ret = new CData0(len_arr, arr);
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
    char *old_str = str;
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
    cout << endl;
    for (int i = 0; i < len_arr; i++)
    {
        arr[i]->sort();
    }

    for (int i = 0; i < len_arr; i++)
    {
        arr[i]->output();
    }
    cout << endl;

    CData *tmp = arr[len_arr - 1];
    for (int i = len_arr - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;

    for (int i = 0; i < len_arr; i++)
    {
        arr[i]->output();
    }

    cout << endl;
    CData1 sum(*arr[0]);
    for (int i = 0; i < len_arr; i++)
    {
        sum = sum + *arr[i];
    }
    sum.output();

    for (int i = 0; i < len_arr; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    delete[] old_str;
    return 0;
}