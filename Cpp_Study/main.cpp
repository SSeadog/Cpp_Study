#include <iostream>
using namespace std;

class CMyData
{
public:
    int GetData() { return m_nData; }

    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
    void SetData(int nParam)
    {
        if (nParam < 0)
            SetData(0);

        if (nParam > 10)
            SetData(10);
    }
};

int main(void)
{
    CMyData a;
    a.SetData(-10);
    cout << a.GetData() << endl;

    CMyDataEx b;
    b.SetData(15);
    cout << b.GetData() << endl;

    return 0;
}