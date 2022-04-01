#include <iostream>
#include <functional>
using namespace std;
using Callback = function<void()>;
class test
{
private:
    int a;
    Callback testa;

public:
    test(int b):a(b){}

    void setCallback(Callback cb)
    {
        testa = cb;
    }
    void Ho()
    {
        testa();
    }
};


int main()
{
    test A(10);

    A.setCallback([](){
        cout<<"nihao"<<endl;
    });
    A.Ho();
    return 0;
}