#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class polynomial {
    int n;
    int size;
    float* data;
public:
    polynomial(int _n = 0, int val = 0) {
        n = _n;
        size = n + 1;
        if (size > 0) {
            data = new float[size];
            for (int i = 0; i < size; i++)
                data[i] = val;
        } else 
            data = nullptr;
    }
    polynomial(const polynomial& other){
        n = other.n;
        size = other.size;
        if(size>0) {
            data = new float[size];
            for(int i = 0; i < size; i++)
                data[i] = other.data[i];
        } else {
            data = nullptr;
        }
        
    }
    ~polynomial() {
        delete[] data;
    }
    friend istream& operator>>(istream& is, polynomial& param) {
        for (int i = 0; i < param.size; i++)
            is >> param.data[i];
        return is;
    }
    friend ostream& operator<<(ostream& os, polynomial param) {
        bool flag = 0; // để xuất dấu +
        for (int i = param.size - 1; i >= 0; i--) {
            if (param.data[i]==0) continue; 
            if (flag && param.data[i]>0) os << "+";
            flag = 1;
            if (i==0) os << fixed << setprecision(1) << param.data[i];
            else if (i==1 && param.data[i]!=1) os << fixed << setprecision(1) << param.data[i] << "x";
            else if (i==1 && param.data[i]==1) os << "x";
            else if (i!=1 && param.data[i]==1) os << "x^" << i;
            else os << fixed << setprecision(1) << param.data[i] << "x^" << i;
        }
        return os;
    }
    polynomial operator=(const polynomial& other){
        if (data!=nullptr)
            delete[] data;
        n = other.n;
        size = other.size;
        if(size>0) {
            data = new float[size];
            for(int i = 0; i < size; i++)
                data[i] = other.data[i];
        } else {
            data = nullptr;
        }
    }
    void input() {
        cin >> *this;
    }
    void print() {
        cout << *this;
    }
    float calculate(int val) {
        int result = 0;
        for (int i = 0; i <= n; i++)
            result += pow(val, i) * data[i];
        return result;
    }
    friend polynomial operator+(polynomial param_1, polynomial param_2) {
        polynomial result(max(param_1.n, param_2.n));
        for (int i = 0; i < result.size; i++) {
            if (i <= (min(param_1.n, param_2.n)))
                result.data[i] = param_1.data[i] + param_2.data[i];
            else
                result.data[i] += (param_1.n>param_2.n?param_1.data[i]:param_2.data[i]);
        }
        return result;
    }
    friend polynomial operator-(polynomial param_1, polynomial param_2) {
        for (int i = 0; i < param_2.size; i++)
            param_2.data[i] = -param_2.data[i];
        return param_1 + param_2;
    }
    friend polynomial operator*(polynomial param_1, polynomial param_2) {
        polynomial result(param_1.n+param_2.n);
        for (int i = 0; i < param_1.size; i++) {
            for (int j = 0; j < param_2.size; j++) {
                result.data[i+j] += (param_1.data[i] * param_2.data[j]);
            }
        }
        return result;
    }


// (x^4 + x^5 ) * (x^9 + x )

    float& operator[](int index) {
        return data[index];
    }
    polynomial operator++() {
        polynomial result(this->size+1);
        result[0] = 0;
        for (int i = 1; i < result.size; i++)
            result[i] = this->data[i-1];
        return result;
    } // x^2 + x^3 => x^3 + x^4
    polynomial operator--() {
        polynomial result(this->n - 1);
        result[0] = this->data[0] + this->data[1];
        for (int i = 1; i < result.n; i++) {
            result[i] = this->data[i+1];
        }
        return result;
    }
    polynomial derivative() {
        int resultSize = n - 1;
        if(resultSize==0)
            return polynomial(1, 0);
        polynomial result(resultSize);
        for (int i = 0; i <= result.n; i++)
            result.data[i] = data[i+1] * (i+1); 
        return result;
    }
    polynomial primative() {
        polynomial result(n+1);
        for (int i = 1; i < result.size; i++) {
            result[i] = data[i-1]/i;
        }
        return result;
    }
    double integral(double a, double b) {
        return primative().calculate(b) - primative().calculate(a);
    }
};

int main() {
    int n;
    cin >> n;
    polynomial fx(n);
    cin >> fx;
    cout << fx << endl;
    cout << fx.primative() << endl;
    cout << fx.integral(1, 2);

    // cout << fx.derivative();
    // int m;
    // cin >> m;
    // polynomial gx(m);
    // cin >> gx;
    // cout << gx << endl;
    // cout << fx - gx;
    return 0;
}