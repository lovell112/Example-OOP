#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class DIEM{
    int n;
    float arr[10];
public:
    //get-set
    void setN(int value){ n=value;}
    int getN()  { return n;}
    float& operator[](int index){return arr[index];}
    //ktao
    DIEM(int _n=3, float _arr[]=new float[3] {1,2,3}){
        n=_n;
        for(int i=0; i<n; i++) arr[i]= _arr[i];
    }
    DIEM(const DIEM &d){
        n=d.n;
        for(int i=0; i<n; i++) arr[i]= d.arr[i];
    }
    //nhap-xuat
    friend istream& operator>>(istream &is, DIEM &d){
        d.n=0;
        while( cin >> d.arr[ d.n ]) d.n++;
        return is;
    }
    friend ostream& operator<<(ostream &os, DIEM d){
        for( int i = 0; i<d.n; i++) os << d.arr[i]<<" ";
        os<<endl;
        return os;
    }
    //ham bo tro
    float DTB(){
        float tong=0;
        for(int i=0; i<n; i++) tong+=arr[i];
        return tong/n;
    }
};

class SV{
    DIEM d;
    string hoten, mssv;
public:
    //get-set
    DIEM getD(){    return d; }//bổ sung thêm
    string getHoTen(){ return hoten; }
    string getMssv(){ return mssv; }
    //ktao
    SV (const SV &s){ mssv = s.mssv; hoten = s.hoten; d = s.d; }
    SV (string _hoten="hoten", string _mssv="mssv", DIEM _d= DIEM()){
        hoten=_hoten; mssv=_mssv;   d= _d;
    }
    friend istream& operator >>(istream &is, SV &s){
        getline(is, s.hoten);
        is>> s.mssv;
        is>> s.d;
        return is;
    }
    friend ostream& operator <<(ostream &os, SV s){
        os<<"Ho Ten: "<< s.hoten <<endl;
        os<<"Ma Sinh Vien: "<< s.mssv<<endl;
        os<<"DTB: "<<fixed << setprecision(1) << s.d.DTB()<<endl;
        return os;
    }
};

class MangSinhVien{
    int slpt;
    SV a[10];
public:
    //get-set
    SV& operator[](int i){ return a[i]; }
    //ktao
    MangSinhVien(){ slpt = 0; }
    MangSinhVien(int _slpt , SV _a[]){
        slpt= _slpt;
        for(int i=0; i<slpt; i++) a[i]=_a[i];
    }
    MangSinhVien(const MangSinhVien &m){
        slpt= m.slpt;
        for(int i=0; i<slpt; i++) a[i]=m.a[i];
    }
    //nhap-xuat
    friend istream& operator>>(istream& in, MangSinhVien &m){
        in >> m.slpt; in.ignore();
        for(int i=0; i< m.slpt; i++){
            //in.ignore();
            in >> m.a[i];
            in.clear();
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, MangSinhVien m){
         for(int i=0; i< m.slpt; i++){
            out << m.a[i] <<endl;
        }
        return out;
    }
    //ham bo tro
    int iMaxDTB(){
        int imax= 0; 
        for(int i=1; i< slpt; i++)
            if( a[i].getD().DTB() > a[imax].getD().DTB()) imax= i;
        return imax;    
    }
};

int main(){
    MangSinhVien m;
    cin >> m;
    cout<< m [ m.iMaxDTB()]; 
    //cin >> a >> b;
    return 0;
}