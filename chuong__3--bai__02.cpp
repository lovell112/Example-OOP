#include <iostream>
using namespace std;

class animal {
    int age;
    int sex;
    float weight;
public:
    animal(int a = 0,  float w = 0, int s = 0) {
        age = a;
        weight = w;
        sex = s;
    }
    animal(const animal &a) {
        age = a.age;
        weight = a.weight;
        sex = a.sex;
    }
    virtual ~animal() {
        cout << "Dong vat bi huy" << endl;
    }
    animal& operator=(const animal& a) {
        if (this != &a) {
            age = a.age;
            weight = a.weight;
            sex = a.sex;
        }
        return *this;
    }
    void set(int a = 0, float w = 0, int s = 0) {
        age = a;
        weight = w;
        sex = s;
    }
    void an() {
        cout << "con vat dang an\n";
    }
    void print() {
        cout << "Day la chi so cua con vat:\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Sex: " << ((sex != 1) ? "male\n" : "female\n");
    }

};

class elephant : public animal {
    int root;
public:
    elephant(int a = 0, float w = 0, int s = 0, int r = 0): animal(a, w, s), root(r) {}
    void print() {
        animal::print();
        cout << "Giong loai: Voi\n";
        cout << "Root: " << ((root == 1) ? "Chau Phi\n" : "Chau A\n");
    }
    void set(int a = 0, float w = 0, int s = 0, int r = 0) {
        animal::set(a, w, s);
        root = r;
    }
    void an() {
        cout << "Voi dang an co\n";
    }
    ~elephant() {
        cout << "Voi da qua doi\n";
    }
};



int main() {
    elephant e(5,5.5,0, 0);
    e.print();
    e.an();
    return 0;
}