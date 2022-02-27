#include <iostream>
#include <string.h>
#include <vector>
#define MAX 100

using namespace std;

struct DV {
    int sothedv;
    string tendangvien;
    int Namvaodang;
    string chucvudang;
    double luong;
    double dangphi;
    double tienphucap;
    double phaidong;
};

struct CB {
    string TenCB;
    string Diachi;
    int sodangvien;
    double tongLuong;
    double TongDangPhithu;
    double Chibogiulai;
    double Nopcaptren;
    DV dv[MAX];
};

CB input()
{
    CB cb;
    cout << "Ten chi bo: "; cin >> cb.TenCB;
    cout << "so dang vien: "; cin >> cb.sodangvien;
    cout << "Dia chi:: "; cin >> cb.Diachi;
    cout << "tong luong: "; cin >> cb.tongLuong;
    cout << "tong dang phi thu: "; cin >> cb.TongDangPhithu;
    cb.Chibogiulai = 0.3 * cb.TongDangPhithu;
    cb.Nopcaptren = 0.7 * cb.TongDangPhithu;
    cout << "Nhap ds dang vien: " << endl;

    vector<DV> dv(cb.sodangvien);
    for (int i = 0; i < cb.sodangvien; i++) {
        cout << "dang vien thu " << i << endl;
        cout << "so the: "; cin >> dv.at(i).sothedv;
        cout << "ten dang vien: "; cin >> dv.at(i).tendangvien;
        cout << "nam vao dang: "; cin >> dv.at(i).Namvaodang;
        cout << "chuc vu: "; cin >> dv.at(i).chucvudang;
        cout << "luong: "; cin >> dv.at(i).luong;
        dv.at(i).dangphi = 0.1 * dv.at(i).luong;
        if (dv.at(i).chucvudang == "BiThu") {
            dv.at(i).tienphucap = 0.005 * dv.at(i).luong;
        }
        else if (dv.at(i).chucvudang == "PBThu") {
            dv.at(i).tienphucap = 0.0025 * dv.at(i).luong;
        }
        else if (dv.at(i).chucvudang == "Uyvien ") {
            dv.at(i).tienphucap = 0.0015 * dv.at(i).luong;
        }
        else if (dv.at(i).chucvudang == "DV") {
            dv.at(i).tienphucap = 0;
        }
        cb.dv[i] = dv.at(i);
    }
    return cb;
}

void output(CB cb)
{
    cout << "ten chi bo: " << cb.TenCB << endl;
    cout << "so luong dang vien: " << cb.sodangvien << endl;
    cout << "dia chi" << cb.Diachi << endl;
    cout << "Tong Dang phi thu" << cb.TongDangPhithu << endl;
    cout << "chi phi giu lai: " << cb.Chibogiulai << endl;
    cout << "nop cap tren: " << cb.Nopcaptren << endl;
    cout << "thong tin cac dang vien: " << endl;
    for (int i = 0; i < cb.sodangvien; i++) {
        cout << "thong tin dang vien thu " << i << endl;
        cout << "====ma the dang vien: " << cb.dv[i].sothedv << endl;
        cout << "====ten dang vien: " << cb.dv[i].tendangvien << endl;
        cout << "====nam vao dang: " << cb.dv[i].Namvaodang << endl;
        cout << "====chuc vu: " << cb.dv[i].chucvudang << endl;
        cout << "====dang phi: " << cb.dv[i].dangphi << endl;
        cout << "====tien phu cap: " << cb.dv[i].tienphucap << endl;
    }
}
int main()
{
    int n;
    cout << "nhap so chi bo: "; cin >> n;
    CB chibo[MAX];
    int x;
    do {
        cout << "=======================================" << endl;
        cout << "0: thoat khoi chuong trinh" << endl;
        cout << "1: nhap cac chi bo" << endl;
        cout << "2: In danh sach dang vien" << endl;
        cout << "nhap x: "; cin >> x;
        cout << "=======================================" << endl;
        switch(x) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "nhap thong tin chi bo thu " << i << endl;
                    chibo[i] = input();
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    output(chibo[i]);
                }
                break;
        }
    } while (x != 0);

    CB cb;

    return 0;
}
