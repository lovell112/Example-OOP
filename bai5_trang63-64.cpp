#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x;
    int y;
    friend class TamGiac;
public:
    Point () {
        x = 0;
        y = 0;
    };
    Point (int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print_point() {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

class TamGiac {
private:
    Point A, B, C;
public:
    TamGiac () {};
    ~TamGiac () {};

    void set(int x1, int y1, int x2, int y2, int x3, int y3) {
        A = Point(x1,y1);
        B = Point(x2,y2);
        C = Point(x3,y3);
    }
    //khoang cach
    float distance(const Point& p1, const Point& p2) const {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        return sqrt(dx * dx + dy * dy);
    }
    //chu vi
    float perimeter() const {
        float AB = distance(A, B);
        float BC = distance(B, C);
        float CA = distance(C, A);
        float sum = AB + BC + CA;
        return sum;
    }
    //dien tich
    float area_calculation() const {
        float area = 0.5 * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
        return area;
    }

    void print() {
        cout << "Tam giac co 3 dinh:" << endl;
        cout << "A"; A.print_point(); cout << endl;
        cout << "B"; B.print_point(); cout << endl;
        cout << "C"; C.print_point(); cout << endl;
        cout<<"Chu vi tam giac: "<<perimeter()<<endl;
        cout<<"Dien tich tam giac: "<<area_calculation()<<endl;
        int type = classify();
        cout<<"thuoc tam giac: ";
        switch(type) {
            case 0: cout << "Tam giac thuong"; break;
            case 1: cout << "Tam giac vuong"; break;
            case 2: cout << "Tam giac can"; break;
            case 3: cout << "Tam giac vuong can"; break;
            case 4: cout << "Tam giac deu"; break;
        }
    }

    int classify() {
        float AB = distance(A, B);
        float BC = distance(B, C);
        float CA = distance(C, A);
        //tam giac deu
        if (fabs(AB - BC) < 1e-6 && fabs(BC - CA) < 1e-6) {
            return 4;
        }
        // Tam giac vuong can
        else if ((fabs(AB*AB + BC*BC - CA*CA) < 1e-6 && AB == BC) ||
              (fabs(BC*BC + CA*CA - AB*AB) < 1e-6 && BC == CA) ||
              (fabs(CA*CA + AB*AB - BC*BC) < 1e-6 && AB == CA)) {
            return 3;
        }
        // Tam giac vuong
        else if (fabs(AB*AB + BC*BC - CA*CA) < 1e-6 ||
            fabs(BC*BC + CA*CA - AB*AB) < 1e-6 ||
            fabs(CA*CA + AB*AB - BC*BC) < 1e-6) {
            return 1;
        }
        // Tam giac cân
        else if (fabs(AB - BC) < 1e-6 || fabs(BC - CA) < 1e-6 || fabs(CA - AB) < 1e-6) {
            return 2;
        }
        //tam giac thuong
        else {
            return 0;
        }
    }
};

int main() {
    TamGiac tam_giac1;
    tam_giac1.set(0, 0, 2, 0, 1,1.73205);
    tam_giac1.print();
    return 0;
}