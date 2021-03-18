#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

class Base
{
public:
    int *arr = nullptr;
    int N = 0;

protected:
    void delete_all()
    {
        delete[] arr;
        arr = nullptr;
    }
    int delete_max()
    {
        if (N == 0)
            return 1;
        int imax = 0;
        for (int i = 0; i < N; i++)
        {
            if (!comprasion(arr[imax], arr[i]))
            {
                imax = i;
            }
        }
        for (int i = imax; i < N - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        N--;
        return 0;
    }
    virtual bool comprasion(int first, int second)
    {
        if (first > second)
            return 1;
        else
            return 0;
    }

public:
    Base(int N_)
    {
        N = N_;
        arr = new int[N_];
        for (int i = 0; i < N; i++)
        {
            arr[i] = rand() % 100;
        }
    }
    virtual ~Base()
    {
        delete_all();
    }
    Base(const Base &other)
    {
        N = other.N;
        arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    Base(Base &&other)
    {
        N = other.N;
        arr = other.arr;
        other.arr = nullptr;
    }
    Base &operator=(const Base &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete_all();
        N = other.N;
        arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }
    Base operator+(const Base &other)
    {
        int N_sum = min(N, other.N);
        Base sum(N_sum);
        for (int i = 0; i < N_sum; i++)
        {
            sum.arr[i] = arr[i] + other.arr[i];
        }
        return sum;
    }
    Base operator-(const Base &other)
    {
        int N_sum = min(N, other.N);
        Base sum(N_sum);
        for (int i = 0; i < N_sum; i++)
        {
            sum.arr[i] = arr[i] - other.arr[i];
        }
        return sum;
    }
    Base &operator++(void)
    {
        delete_max();
        return *this;
    }
    Base operator++(int)
    {
        Base tmp(*this);
        delete_max();
        return tmp;
    }
};

class Child : public Base
{
public:
    Child(int N_) : Base(N_) {}
    ~Child() {}
    Child(const Base &other) : Base(other) {}
    bool comparison(int first, int second)
    {
        if (first >= second)
            return 1;
        else
            return 0;
    }
};
ostream &operator<<(ostream &cout, const Base &vec)
{
    for (int i = 0; i < vec.N; i++)
    {
        cout << vec.arr[i] << " ";
    }
    return cout;
}

int main()
{
    srand(clock() * time(NULL));
    Child vec1(5), vec2(6);
    Child vec3(vec1 + vec2);
    cout << vec1 << endl
         << vec2 << endl
         << vec3 << endl;
    vec3++;
    vec3++;
    vec3++;
    vec3++;
    vec3++;
    vec3++;
    cout << vec3 << endl;

    Base *v = new Child(Base(5) + Child(Base(7)) + Child(5)++ + ++Base(5));
    cout << *v;
    delete v;
}