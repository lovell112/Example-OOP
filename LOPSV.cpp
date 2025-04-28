#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Nguoi {
protected:
    string hoTen;
    int namSinh;
    string queQuan;
public:
    Nguoi() : hoTen(""), namSinh(0), queQuan("") {}
    Nguoi(string ht, int ns, string qq) : hoTen(ht), namSinh(ns), queQuan(qq) {}
    ~Nguoi() {}
    void nhap() {
        getline(cin, hoTen);
        cin >> namSinh;
        cin.ignore();
        getline(cin, queQuan);
    }
    void xuat() const {
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Nam Sinh: " << namSinh << endl;
        cout << "Que quan: " << queQuan << endl;
    }
    string getHoTen() const { return hoTen; }
    int getNamSinh() const { return namSinh; }
    string getQueQuan() const { return queQuan; }

    void setHoTen(string ht) { hoTen = ht; }
    void setNamSinh(int ns) { namSinh = ns; }
    void setQueQuan(string qq) { queQuan = qq; }
};

class SinhVien : public Nguoi {
private:
    string khoa;
    float diem[100];
    int soMon;
public:
    SinhVien() : Nguoi(), khoa(""), soMon(0) {}
    SinhVien(string ht, int ns, string qq, string k, float d[], int sm) : Nguoi(ht, ns, qq), khoa(k), soMon(sm) {
        for (int i = 0; i < soMon; i++) {
            diem[i] = d[i];
        }
    }
    ~SinhVien() {}
    float tinhDiemTrungBinh() const {
        if (soMon == 0) return 0;
        float tong = 0;
        for (int i = 0; i < soMon; i++) {
            tong += diem[i];
        }
        return tong / soMon;
    }

    string getKhoa() const { return khoa; }
    int getSoMon() const { return soMon; }
    float getDiem(int i) const { return diem[i]; }

    void setKhoa(string k) { khoa = k; }
    void setSoMon(int sm) { soMon = sm; }
    void setDiem(int i, float d) { diem[i] = d; }

    friend istream& operator>>(istream& in, SinhVien& sv) {
        getline(in, sv.hoTen);
        in >> sv.namSinh;
        in.ignore();
        getline(in, sv.queQuan);
        getline(in, sv.khoa);
        sv.soMon = 0;
        float temp;
        while (in >> temp) {
            sv.diem[sv.soMon++] = temp;
        }
        in.clear();
        in.ignore();
        return in;
    }


    friend ostream& operator<<(ostream& out, const SinhVien& sv) {
        out << "Ho Ten: " << sv.hoTen << endl;
        out << "Nam Sinh: " << sv.namSinh << endl;
        out << "Que quan: " << sv.queQuan << endl;
        out << "Khoa: " << sv.khoa << endl;
        out << "Diem cac mon: ";
        for (int i = 0; i < sv.soMon; i++) {
            out << sv.diem[i] << " ";
        }
        out << endl;
        out << "Diem trung binh: " << fixed << setprecision(2) << sv.tinhDiemTrungBinh() << endl;
        return out;
    }
};

int main() {
    SinhVien sv;
    cin >> sv;
    cout << sv;
    return 0;
}
