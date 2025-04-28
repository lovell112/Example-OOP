#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void print_point() {
        cout << "(" << x << "," << y << ")";
    }
    int getX() const { return x; }
    int getY() const { return y; }
};

class TamGiac {
private:
    Point A, B, C;
public:
    TamGiac() {}
    ~TamGiac() {}
    void set(int x1, int y1, int x2, int y2, int x3, int y3) {
        A = Point(x1, y1);
        B = Point(x2, y2);
        C = Point(x3, y3);
    }
    float distance(const Point& p1, const Point& p2) const {
        int dx = p2.getX() - p1.getX();
        int dy = p2.getY() - p1.getY();
        return sqrt(dx * dx + dy * dy);
    }
    float perimeter() const {
        float AB = distance(A, B);
        float BC = distance(B, C);
        float CA = distance(C, A);
        return AB + BC + CA;
    }
    float area_calculation() const {
        float area = 0.5 * abs(A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()));
        return area;
    }
    friend ostream& operator<<(ostream& os, const TamGiac& tg) {
        os << "Tam giac co 3 dinh:\n";
        os << "A"; tg.A.print_point(); os << "\n";
        os << "B"; tg.B.print_point(); os << "\n";
        os << "C"; tg.C.print_point(); os << "\n";
        os << "Chu vi tam giac: " << tg.perimeter() << "\n";
        os << "Dien tich tam giac: " << tg.area_calculation() << "\n";
        os << "thuoc tam giac: ";
        switch (tg.classify()) {
            case 0: os << "Tam giac thuong"; break;
            case 1: os << "Tam giac vuong"; break;
            case 2: os << "Tam giac can"; break;
            case 3: os << "Tam giac vuong can"; break;
            case 4: os << "Tam giac deu"; break;
        }
        return os;
    }
    int classify() {
        float AB = distance(A, B);
        float BC = distance(B, C);
        float CA = distance(C, A);
        if (fabs(AB - BC) < 1e-6 && fabs(BC - CA) < 1e-6) {
            return 4;
        }
        else if ((fabs(AB*AB + BC*BC - CA*CA) < 1e-6 && fabs(AB - BC) < 1e-6) ||
                 (fabs(BC*BC + CA*CA - AB*AB) < 1e-6 && fabs(BC - CA) < 1e-6) ||
                 (fabs(CA*CA + AB*AB - BC*BC) < 1e-6 && fabs(CA - AB) < 1e-6)) {
            return 3;
        }
        else if (fabs(AB*AB + BC*BC - CA*CA) < 1e-6 ||
                 (fabs(BC*BC + CA*CA - AB*AB) < 1e-6) ||
                 (fabs(CA*CA + AB*AB - BC*BC) < 1e-6)) {
            return 1;
        }
        else if (fabs(AB - BC) < 1e-6 || fabs(BC - CA) < 1e-6 || fabs(CA - AB) < 1e-6) {
            return 2;
        }
        else {
            return 0;
        }
    }
};

int main() {
    TamGiac tam_giac1;
    tam_giac1.set(0, 0, 2, 0, 1, 1);
    cout << tam_giac1;
    return 0;
}
