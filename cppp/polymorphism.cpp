#include <iostream>
using namespace std;
class complexadd
{
    private:
    int real;
    int img;

public:
    complexadd(int im, int re)
    {
        real = re;
        img = im;
    }
      complexadd operator + (int aimg,int areal/* complexadd &obhj*/)
    {
        complexadd result;
            result.aimg = img + obhj.img;
            result.areal = real + obhj.real;
        return result;
        
        
    }
    void display()
    {
        cout << real << "+i" << img;
    }
};
int main()
{
    complexadd a(2, 3);
    complexadd b(4, 3);
    complexadd c = a + b;
    c.display();
    return 0;
}