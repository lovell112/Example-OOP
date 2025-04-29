#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    // Hàm khởi tạo mặc định
    Stack() {}

    // Hàm khởi tạo sao chép 
    Stack(const Stack& other) {
        elements = other.elements;
    }

    // Hàm khởi tạo với vector ban đầu (khởi tạo phần tử)
    Stack(const vector<T>& initElements) {
        elements = initElements;
    }

    // Hàm Hủy ( ko có gì)
    ~Stack() {}

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

    // đếm số phần tửtử
    size_t size() const {
        return elements.size();
    }
    
    // làm trống ngăn
    void clear() {
        elements.clear();
    }

    void print() const {
        cout << "Xep tu day len dinh: ";
        for (const auto& x : elements) {
            cout << x << " ";
        }
        cout << "\n";
    }

    // Hàm get: lấy phần tử tại vị trí index
    T getElement(int index) const {
        if (index >= 0 && index < elements.size()) {
            return elements[index];
        } else {
            throw out_of_range("Chi so khong hop le trong Stack");
        }
    }

    // Hàm set: gán giá trị mới cho phần tử tại index
    void setElement(int index, T value) {
        if (index >= 0 && index < elements.size()) {
            elements[index] = value;
        } else {
            throw out_of_range("Chi so khong hop le trong Stack");
        }
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream& out, const Stack& stack) {
        out << "Stack [";
        for (size_t i = 0; i < stack.elements.size(); ++i) {
            out << stack.elements[i];
            if (i != stack.elements.size() - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    // Toán tử nhập
    friend istream& operator>>(istream& in, Stack& stack) {
        int n;
        T val;
        cout << "Nhap so luong phan tu: ";
        in >> n;
        cout << "Nhap " << n << " phan tu:\n";
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
    Stack<int> s;

    cout << "=== Khoi tao Stack ===\n";
    vector<int> init = {5, 10, 15};
    for (int val : init) {
        s.push(val);
    }
    cout << "Stack ban dau: " << s << "\n";

    cout << "\n=== Them phan tu ===\n";
    s.push(20);
    cout << "Sau khi push 20: " << s << "\n";

    cout << "\n=== Lay phan tu (pop) ===\n";
    s.take();
    cout << "Sau khi pop: " << s << "\n";

    cout << "\n=== Lay phan tu tai chi so 1 ===\n";
    try {
        int value = s.getElement(1);
        cout << "Phan tu tai chi so 1: " << value << "\n";
    } catch (const out_of_range& e) {
        cout << "Loi: " << e.what() << "\n";
    }

    cout << "\n=== Thay doi gia tri tai chi so 0 ===\n";
    try {
        s.setElement(0, 99);
        cout << "Sau khi set: " << s << "\n";
    } catch (const out_of_range& e) {
        cout << "Loi: " << e.what() << "\n";
    }

    cout << "\n=== So sanh voi Stack khac ===\n";
    vector<int> otherInit = {1, 2};
    Stack<int> s2(otherInit);
    cout << "Stack s2: " << s2 << "\n";
    cout << (s < s2 ? "Stack s < s2" : "Stack s >= s2") << "\n";

    cout << "\n=== Lam rong Stack ===\n";
    s.clear();
    cout << "Stack sau khi clear: " << s << "\n";

    cout << "\n=== Ket thuc chuong trinh ===\n";

    return 0;
}

