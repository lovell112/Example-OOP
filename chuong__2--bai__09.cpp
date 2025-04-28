#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    // Hàm khởi tạo mặc định
    Stack() {
        // Không cần làm gì thêm, vector tự động khởi tạo
    }

    // Hàm khởi tạo sao chép (copy constructor)
    Stack(const Stack& other) {
        elements = other.elements;
    }

    // Hàm khởi tạo với vector ban đầu
    Stack(const vector<T>& initElements) {
        elements = initElements;
    }

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
        cout << "Xep tu day len dinh: ";
        for (const auto& x : elements) {
            cout << x << " ";
        }
        cout << "\n";
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
    Stack<int> s1, s2;

    cin >> s1;

    cout << "So luong phan tu: " << s1.size() << "\n";

    s1.push(99);
    cout << s1 << "\n";

    s1.take();
    cout << s1 << "\n";

    s1.clear();
    cout << s1 << "\n";

    // Test constructor từ vector
    vector<int> v = {1, 2, 3};
    Stack<int> s3(v);
    cout << "Stack s3: " << s3 << "\n";

    // Test copy constructor
    Stack<int> s4(s3);
    cout << "Stack s4 (copy từ s3): " << s4 << "\n";

    cout << "So sanh s1 < s2: " << (s1 < s2 ? "Dung" : "Sai") << "\n";

    return 0;
}