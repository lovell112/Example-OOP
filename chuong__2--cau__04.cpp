#include <bits/stdc++.h>
using namespace std;
//KHAI BÁO LỚP POINT
class Point {
    int x, y;
public:
    //ktao - huy
    Point (int , int);
    Point(const Point&);
    ~Point ();
    //get - set
    int getX();
    void setX(int);
    int getY();
    void setY(int);
    //ho tro
    void Set (int x, int y);
    friend istream& operator>>(istream&, Point&);
    friend ostream& operator<<(ostream&, Point);
};
//DINH NGHIA HAM THANH PHAN LOP POINT
Point :: Point(int a = 0, int b = 0){
    x = a;
    y = b;
}
Point::Point(const Point& p) {
    x = p.x;
    y = p.y;
}
Point :: ~Point(){}
int Point :: getX() { 
    return x; 
}
void Point :: setX(int t)  { 
    x = t; 
}
int Point :: getY() { 
    return y;
}
void Point :: setY(int t) { 
    y = t;
}
istream& operator >> (istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, Point p) {
    os << "(" << p.x << "; " << p.y << ")";
    return os;
}
//KHAI BÁO LỚP LINE
class Line {
    Point A, B;
public:
    //ktao - huy
    Line(int , int , int , int );
    Line(const Line&);
    ~Line();
    //get - set
    Point getA();
    void setA(Point);
    Point getB();
    void setB(Point);
    //ho tro
    void set(int, int, int, int);
    float tinhDoDai (); 
    void Print();
    void xuatPhuongTrinh(); 
    //nhap - xuat
    friend istream& operator>>(istream&, Line&);
    friend ostream& operator<<(ostream&, Line);
};
//DINH NGHIA HAM TP LOP LINE
//ham ktao
Line :: Line(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0) {
        A.setX(a1);
        A.setY(a2);
        B.setX(b1);
        B.setY(b2);
}
//ham ktao sao chep
Line :: Line(const Line& n) {
     A = n.A;
     B = n.B;
}
//ham huy
Line :: ~Line(){}
//ham get - set A
Point Line :: getA () {
    return A;
}
void Line :: setA (Point t) {
    A = t;
}
//ham get - set B
Point Line :: getB () {
    return B;
}
void Line :: setB (Point t) {
    B = t;
}
//ham set xac dinh doan thang
void Line :: set(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0){
    A.setX (x1);
    A.setY (y1);
    B.setX (x2);
    B.setY (y2);
}
//ham tinh do dai
float Line :: tinhDoDai (){ // d = can bacc 2 ((x2 - x1)^2 + (y2 - y1)^2)
    return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
}
//ham in diem
void Line :: Print(){
    cout << "Diem A(" << A.getX() << "; " << A.getY() << ")" << endl;
    cout << "Diem B(" << B.getX() << "; " << B.getY() << ")" << endl;
}
//ham xuat phuong trinh 
void Line :: xuatPhuongTrinh(){ /*
                                ax+by+c=0:
                                    a = y2 - y1
                                    b = x1 - x2
                                    c = x1*y2 - y1*x2
                                */
    int a, b, c;
    a = B.getY() - A.getY();
    b = A.getX() - B.getX();
    c = A.getX() * B.getY() - A.getY() * B.getX();
    cout << "Phuong trinh duong thang: ";
    bool daIn = false; // đánh dấu đã in cái gì chưa

    if (a != 0) {
        if (a == 1){
            cout << "x";
        }else if (a == -1){
            cout  << "-x";
        }
        else{
            cout << a << "x";
        }
        daIn = true;
    }

    if (b != 0) {
        if (daIn) {
            if (b == 1){
                cout << "+y";
            }else if (b == -1){
                cout << "-y";
            }else{
                cout << (b > 0 ? "+" : "-");
                cout << abs(b) << "y";
            }
        } else {
            cout << b << "y";
        }
        daIn = true;
    }

    if (c != 0) {
        if (daIn) {
            cout << (c > 0 ? "+" : "-");
            cout << abs(c);
        } else {
            cout << c;
        }
        daIn = true;
    }

    if (!daIn) {
        cout << "0"; // nếu a = b = c = 0
    }

    cout << "=0" << endl;
}

istream& operator >> (istream& is, Line& l) {
    is >> l.A;
    is >> l.B;
    return is;
}

ostream& operator << (ostream& os, Line l) {
    os << "Diem A" << l.A << endl;
    os << "Diem B" << l.B << endl;
    os << "Do dai doan thang AB la: " << fixed << setprecision(2) << l.tinhDoDai() << endl;
    int a = l.B.getY() - l.A.getY();
    int b = l.A.getX() - l.B.getX();
    int c = l.A.getX() * l.B.getY() - l.A.getY() * l.B.getX();
    os << "Phuong trinh duong thang: "; 
    bool daIn = false; // đánh dấu đã in cái gì chưa

    if (a != 0) {
        if (a == 1){
            os << "x";
        }else if (a == -1){
            os << "-x";
        }
        else{
            os << a << "x";
        }
        daIn = true;
    }

    if (b != 0) {
        if (daIn) {
            if (b == 1){
                os << "+y";
            }else if (b == -1){
                os << "-y";
            }else{
                os << (b > 0 ? "+" : "-");
                os << abs(b) << "y";
            }
        } else {
            os << b << "y";
        }
        daIn = true;
    }

    if (c != 0) {
        if (daIn) {
            os << (c > 0 ? "+" : "-");
            os << abs(c);
        } else {
            os << c;
        }
        daIn = true;
    }

    if (!daIn) {
        os << "0"; // nếu a = b = c = 0
    }

    os << "=0" << endl;

    return os;
}

int main () {
    Line a;
    cout << a;
    cin >> a;
    cout << a;
    Line b;
    b.set(7, 8, 9, 10);
    b.Print();
    cout << fixed << setprecision(2) << b.tinhDoDai() << endl;
    b.xuatPhuongTrinh();
    Line c;
    cin >> c;
    cout << c;
    Line d(10, 11, 12, 13);
    cout << d;
    return 0;
}
