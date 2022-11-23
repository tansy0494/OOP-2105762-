#include <iostream>
using namespace std;
//  constructor and destructor
class Value
{
public:
    int a;
    Value()
    {
        a = 5;
        cout << "\nDefault Constructor value: " << a;
    }
    Value(int x)
    {
        a = x;
        cout << "\nParameterised Constructor value: " << a;
    }
    ~Value()
    {
        static int c;
        c++;
        cout << "\nDestructor called "<<c;
    }
};
// Operator overloading 
class compare_string
{
private:
    string x;
public:
    void get_Value()
    {
        cout << "\nEnter string :";
        getline(cin, x);
    }
    int operator==(compare_string &m)
    {
        if (x == m.x)
            return 1;
        else
            return 0;
    }
};
// Function overloading 
void Calc(int a)
{
    cout << "\nCube : " << a * a* a;
}
void Calc(int a, int b)
{
    cout << "\nMultiplication : " << a * b;
}
// Inheritance and virtual function
class Base
{
protected:
    int a;
public:
    Base()
    {
        a=15;
    }
    virtual void Show_Value() = 0;
};
class Base1 : virtual public Base
{
protected:
    int b;
public:
    Base1()
    {
        b = 26;
    }
};
class Derived : virtual public Base
{
protected:
    int c;
public:
    Derived()
    {
        c = 2;
    }
};
class Derived1 : public Base1, public Derived
{
protected:
    int d;
public:
    Derived1()
    {
        d = 4;
    }
    void Show_Value()
    {
        cout << "\nA: " << a;
        cout << "\nB: " << b;
        cout << "\nC: " << c;
        cout << "\nD: " << d;
    }
};
// Template 
template <class T>
class Template
{
public:
    T *a;
    void BubbleSort(T *x, int n)
    {
        a=x;
        int i, j;
        T temp;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        cout << "\nSorted Array: ";
        for (i = 0; i < n; i++)
        cout << a[i]<<"\t";
    }
};
int main()
{
    int ch;
    while (1)
    {
        cout << "\n1.Constructor and Destructor";
        cout << "\n2.Operator Overloading";
        cout << "\n3.Function Overloading";
        cout << "\n4.Inheritance";
        cout << "\n5.Template";
        cout << "\n6.Quit"<<endl;
        cout << "Enter choice: ";
        cin >> ch;
        if (ch == 1)
        {
            Value s1, s2(10), s3(s1);
        }
        else if (ch == 2)
        {
            compare_string s1, s2;
            cout << "\nFirst string: ";
            s1.get_Value();
            cout << "\nSecond string: ";
            s2.get_Value();
            if (s1 == s2)
                cout << "\nStrings are equal";
            else
                cout << "\nStrings are unequal";
        }
        else if (ch == 3)
        {
            int x, a, b;
            cout << "Enter number to find square: ";
            cin >> x;
            cout << "Enter two numbers to find sum: ";
            cin >> a >> b;
            Calc(x);
            Calc(a, b);
        }
        else if (ch == 4)
        {
            Derived1 d;
            cout << "\nValue at classes hierarchically: ";
            d.Show_Value();
        }
        else if (ch == 5)
        {
            int a[5];
            cout << "\nEnter 5 numbers to carry out bubble sort: ";
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
            Template<int> t;
            t.BubbleSort(a, 5);
        }
        else if (ch == 6)
        {
            exit(0);
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }
    }
    return 0;
}
