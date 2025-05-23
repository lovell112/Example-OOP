#include <iostream>
#include <cmath>
using namespace std;

class TamGiac {
protected:
    float a, b, c;

public:
    TamGiac() : a(0), b(0), c(0) {}
    TamGiac(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    void setA(float value) { a = value; }
    void setB(float value) { b = value; }
    void setC(float value) { c = value; }

    bool kiemtratamgiac() const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    float tinhchuvi() const {
        if (!kiemtratamgiac()) {
            cout << "Cac canh khong tao thanh tam giac hop le!" << endl;
            return -1;
        }
        return a + b + c;
    }

    float tinhdientich() const {
        if (!kiemtratamgiac()) {
            cout << "Cac canh khong tao thanh tam giac hop le!" << endl;
            return -1;
        }
        float p = tinhchuvi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    friend ostream& operator<<(ostream& os, const TamGiac& tg) {
        os << "Canh a: " << tg.a << ", canh b: " << tg.b << ", canh c: " << tg.c << endl;
        return os;
    }

    friend istream& operator>>(istream& is, TamGiac& tg) {
        cout << "Nhap canh a: ";
        is >> tg.a;
        cout << "Nhap canh b: ";
        is >> tg.b;
        cout << "Nhap canh c: ";
        is >> tg.c;
        return is;
    }
};

class TamGiacDeu : public TamGiac {
public:
    TamGiacDeu() : TamGiac(0, 0, 0) {}
    TamGiacDeu(float canh) : TamGiac(canh, canh, canh) {}

    float getCanh() const { return a; }
    void setCanh(float value) { a = b = c = value; }

    friend ostream& operator<<(ostream& os, const TamGiacDeu& tgd) {
        os << "Tam giac deu co canh: " << endl;
        os << static_cast<const TamGiac&>(tgd);
        if (tgd.kiemtratamgiac()) {
            os << "Chu vi: " << tgd.tinhchuvi() << endl;
            os << "Dien tich: " << tgd.tinhdientich() << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, TamGiacDeu& tgd) {
        float canh;
        cout << "Nhap do dai canh cua tam giac deu: ";
        is >> canh;
        tgd.setCanh(canh);
        return is;
    }
};

int main() {
    TamGiacDeu m;
    cin >> m;
    cout << m;

    return 0;
}
