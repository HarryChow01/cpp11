
#include <iostream>
using namespace std;

class CBase1 {
};

class CBase2 : public CBase1 {
};

class CBase3 {
public:
    CBase3(void);
    virtual ~CBase3(void);
private:
    int   a;
    char *p;
};
class CBase4 : public CBase3 {
public:
    CBase4(void);
    ~CBase4(void);
    virtual void test();
private:
    int b;
};
class CBase5 {
public:
    virtual void test(){}
};
class CBase6 : public CBase1, public CBase5{

};
class CBase7 {

};

class CBase8 {

};

class CBase9 {
	int a;
	char b;
};

int main() {
    cout<<"sizeof(CBase1)"<<sizeof(CBase1)<<endl;
    cout<<"sizeof(CBase2)"<<sizeof(CBase2)<<endl;
    cout<<"sizeof(CBase3)"<<sizeof(CBase3)<<endl;
    cout<<"sizeof(CBase4)"<<sizeof(CBase4)<<endl;
    cout<<"sizeof(CBase5)"<<sizeof(CBase5)<<endl;
    cout<<"sizeof(CBase6)"<<sizeof(CBase6)<<endl;
    cout<<"sizeof(CBase7)"<<sizeof(CBase7)<<endl;
    cout<<"sizeof(CBase8)"<<sizeof(CBase8)<<endl;
    cout<<"sizeof(CBase9)"<<sizeof(CBase9)<<endl;

}






