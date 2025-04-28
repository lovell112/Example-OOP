#include <bits/stdc++.h>
using namespace std;
int gcd (int a, int b){
    int r;
    while (b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//khai bao Phan so
class Ps{
    int tu, mau;
public:
    int getTu();
    void setTu(int x);
    int getMau();
    void setMau(int x);
    
    Ps(int _tu=0,int _mau = 1);//ham khoi tao
    Ps(const Ps &p);//ham sao chep
    ~Ps();//ham huy
    
    friend istream& operator>> (istream& is,Ps& p);
    friend ostream& operator<< (ostream& os,Ps p);
    
    Ps operator+ (Ps p);
    void RutGon();
    void set(Ps);
    Ps getPs();
};

//Khai bao hon so
class Hs: public Ps{
    int nguyen;
public:
    int getNguyen(); //getset
    void getNguyen(int x);
    
    Hs(int _nguyen = 0, int _tu = 0, int _mau = 1): Ps(_tu  , _mau){
        nguyen = _nguyen;
    } //ham khoi tao
    Hs(const Hs &h): Ps(h){
        nguyen = h.nguyen;
    } //ham sao chep
    ~Hs(){}; //ham huy
    
    friend istream& operator>> (istream& is,Hs& p);
    friend ostream& operator<< (ostream& os,Hs p);
    
    Hs operator+ (Hs h);
};

int main(){
    Hs h1, h2;
    cin >> h1 >> h2;
    Hs h = (h1+h2);
    h.RutGon();
    cout << h;
    return 0;
}

//dinh nghia ham thuoc lop Ps
int Ps::getTu()    {return tu; }
void Ps::setTu(int x) {tu = x; }
int Ps::getMau()   {return mau; }
void Ps::setMau(int x) {mau = x; }
    
Ps::Ps(int _tu, int _mau) {tu = _tu; mau = _mau; }
Ps::Ps(const Ps &p)            {tu = p.tu; mau = p.mau; }
Ps::~Ps(){}
    
istream& operator>> (istream& is,Ps& p){
    is >> p.tu >> p.mau;
    return is;
}
ostream& operator<< (ostream& os,Ps p){
    os << p.tu << "/" << p.mau << endl;
    return os;
}
 
Ps Ps::operator+ (Ps p){    // a*d+b*c chia cho b*d
    return Ps( tu*p.mau + p.tu*mau, mau*p.mau);
}
void Ps :: RutGon(){
    int uc = gcd(tu, mau);
    tu /= uc;
    mau /= uc;
}
void Ps :: set(Ps p){
    tu = p.tu;
    mau = p.mau;
}
Ps Ps :: getPs(){
    return Ps(tu, mau);
}
//dinh nghia ham thuoc lop Hs
int Hs::getNguyen() {return nguyen; } 
void Hs::getNguyen(int x) {nguyen = x; }
istream& operator>> (istream& is,Hs& h){
    int nguyen, tu, mau;
    is >> nguyen >> tu >> mau;
    if (nguyen < 0){
        tu *= -1;
    }
    h = Hs(nguyen,tu,mau);
    return is;
}
ostream& operator<< (ostream& os,Hs h){
    if (h.getMau() < 0) {
        h.setTu(h.getTu() * -1);
        h.setMau(h.getMau() * -1);
    }
     os << h.nguyen << " " << h.getTu() << "/" << h.getMau() << endl;
     return os;
}
    
Hs Hs::operator+ (Hs h){
    //return Hs( nguyen + h.nguyen, getTu()*h.getMau() + h.getTu()*getMau(), getMau()*h.getMau()); //tu mau la private nen phai goi qua get
    Hs kq;
    kq.nguyen = nguyen + h.nguyen;
    kq.set(getPs() + h.getPs());
    return kq;
}
