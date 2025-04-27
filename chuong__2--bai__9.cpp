#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(T a) {
        elements.push_back(a);
    }
    
    void take() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Ngan Rong\n";
        }
    }

    size_t size() const {
        return elements.size();
    }

    void clear() {
        elements.clear();
    }

    void print() const {
        cout << "Xep tu day len dinh ";
        for (int x : elements) {
            cout << x << " ";
        }
        cout << "\n";
    }

    friend ostream& operator<<(ostream& out, const Stack& stack) {
        out << "Stack [";
        for (size_t i = 0; i < stack.elements.size(); ++i) {
            out << stack.elements[i];
            if (i != stack.elements.size() - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    friend istream& operator>>(istream& in, Stack& stack) {
        int n, val;
        cout << "nhap so luong phtu ";
        in >> n;
        cout << "nhap " << n << " phtu \n";
        for (int i = 0; i < n; ++i) {
            in >> val;
            stack.push(val);
        }
        return in;
    }

    bool operator<(const Stack& other) const {
        return this->size() < other.size();
    }
};

int main() {
    Stack<int> s1, s2;

    cin >> s1;

    cout << "so luong phtu " << s1.size() << "\n";

    s1.push(99);
    cout << s1 << "\n";

    s1.take();
    cout << s1 << "\n";

    s1.clear();
    cout << s1 << "\n";

    cout << "so sanh s1 < s2: " << (s1 < s2 ? "Đúng" : "Sai") << "\n";

    return 0;
}