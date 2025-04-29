#include <bits/stdc++.h>
using namespace std;
//KHAI BAO LOP SOCAN7
class Socan7 {
    int a; 
    int b; 
public:    
    //ktao - huy
    Socan7 (int, int);
    Socan7 (const Socan7 &);
    ~Socan7();
    //get - set
    int getA();
    void setA(int);
    int getB();
    void setB(int);
    //hotro
    void nhap();
    void xuat();
    //nhap xua qua tai toan tu
    friend istream& operator >> (istream& is, Socan7& p);
    friend ostream& operator << (ostream& os, Socan7 p);
    //hotro
    //phép +
    friend Socan7 operator + (const Socan7& p, const Socan7& e);
    //phép -
    friend Socan7 operator - (const Socan7& p, const Socan7& e);
    //đổi dấu
    friend Socan7 operator-(const Socan7& x);
    friend Socan7 operator * (const Socan7& p, const Socan7& e);
};
//DINH NGHIA HAM TP LOP SOCAN7
Socan7 :: Socan7 (int x = 0, int y = 0){
    a = x;
    b = y;
}
Socan7 :: Socan7(const Socan7 &n){
    a = n.a;
    b = n.b;
}
Socan7 :: ~Socan7(){}
int Socan7 :: getA(){
    return a;
}
void Socan7 :: setA(int t){
    a = t;
}
int Socan7 :: getB(){
    return b;
}
void Socan7 :: setB(int t){
    b = t;
}
void Socan7 :: nhap(){
    cin >> a;
    cin >> b;
}
void Socan7 :: xuat(){
    if (b == 0){
        cout << a << endl;
    }else if (a == 0){
        cout << b << "√7" << endl;
    }else if (b > 0){
        cout << a << "+" << b << "√7" << endl;
    }else {
        cout << a << b << "√7" << endl;
    }
}
istream& operator >> (istream& is, Socan7& p){
    is >> p.a;
    is >> p.b;
    return is;
}
ostream& operator << (ostream& os, Socan7 p){
    if (p.b == 0){
        os << p.a << endl;
    }else if (p.a == 0){
        os << p.b << "√7" << endl;
    }else if (p.b > 0){
        os << p.a << "+" << p.b << "√7" << endl;
    }else {
        os << p.a << p.b << "√7" << endl;
    }
    return os;
}
Socan7 operator + (const Socan7& p, const Socan7& e){
    return Socan7(p.a + e.a, p.b + e.b);
}
Socan7 operator - (const Socan7& p, const Socan7& e){
    return Socan7(p.a - e.a, p.b - e.b);
}
Socan7 operator - (const Socan7& x) {
    return Socan7(-x.a, -x.b);
}
//phép * 
    /*
    p = a + bv7
    e = c + dv7
    p * e = (a + bv7)(c + dv7) = (ac + 7bd) + (ad + bc)v7
*/
Socan7 operator * (const Socan7& p, const Socan7& e) { 
    int new_a = p.a * e.a + 7 * p.b * e.b;
    int new_b = p.a * e.b + p.b * e.a;
    return Socan7(new_a, new_b);
}

int main (){
    Socan7 a, b;
    cout << a;
    cin >> a >> b;
    cout << a + b;
    cout << a - b;
    cout << a * b;
    cout << -a;
    cout << -b;
    
    Socan7 c(a), d(0, 9);
    c.xuat();
    d.xuat();
    Socan7 e = c + d;
    Socan7 f = c - d;
    Socan7 g = c * d;
    e.xuat();
    f.xuat();
    g.xuat();
    
    Socan7 j;
    j.nhap();
    (-j).xuat();
    j.xuat();
    return 0;
}