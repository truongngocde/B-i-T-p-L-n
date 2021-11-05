#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Xe{
	protected:
		string HoTenNguoiThue;
		float SoGioThue;
	public:
		virtual void NhapThongTin();
		virtual void XuatThongTin();
};
void Xe::NhapThongTin(){
	while(getchar() != '\n');   // Xoa bo nho dem
	cout<<"\nNhap ho ten nguoi thue: ";
	fflush(stdin);
	getline(cin, this->HoTenNguoiThue);
	cout<<"\nNhap so gio thue: ";
	cin>>this->SoGioThue;
}
void Xe::XuatThongTin(){
	cout<<"Ho ten nguoi thue: "<<HoTenNguoiThue<<endl;
	cout<<"So gio thue: "<<SoGioThue<<endl;
}

class XeDap:public Xe{
	public:
		void NhapThongTin();
		void XuatThongTin();
		float TinhTienThueXe();
		
};
float XeDap::TinhTienThueXe(){
	return 10000 + ((this->SoGioThue - 1) * 8000);
}

class XeMay:public Xe{
	private:
		int LoaiXe;
		string BienSo;
	public:
		void NhapThongTin();
		void XuatThongTin();
		float TinhTienThueXe();
};
void XeMay::NhapThongTin(){
	Xe::NhapThongTin();
	cout<<"Nhap loai xe can thue(100-250cc): ";
	cin>>this->LoaiXe;
	cout<<"Nhap bien so: ";
	fflush(stdin);
	getline(cin, this->BienSo);
}
void XeMay::XuatThongTin(){
	Xe::XuatThongTin();
	cout<<"Loai xe can thue: "<<LoaiXe<<endl;
	cout<<"Bien so: "<<BienSo<<endl;
}
float XeMay::TinhTienThueXe(){
	float s=0;
	if(LoaiXe == 100){
		s=150000;	
	}else{
		s=200000;
	}
	return s + ((SoGioThue - 1) * 100000);
}
// Xuat tat ca thong tin thue xe
void XuatTatCaThongTin(XeDap ds_xd[], int n, XeMay ds_xm[], int m){
	int dem=0;
	//Xuat danh sach xe dap
	cout<<"\n\n\t\t DANH SACH THUE XE DAP\n";
	for(int i=0;i<n;i++){
		cout<<"\n\tThong tin thue xe dap thu"<<dem+1<<endl;
		ds_xd[i].XuatThongTin();
		cout<<"\nTien thue: "<<ds_xd[i].TinhTienThueXe();
	}
	//Xuat danh sach xe may
	cout<<"\n\n\t\t DANH SACH THUE XE MAY\n";
	for(int i=0;i<m;i++){
		cout<<"\n\tThon tin thue xe may thu"<<dem+1<<endl;
		ds_xm[i].XuatThongTin();
		cout<<"\nTien thue: "<<ds_xm[i].TinhTienThueXe();
	}
}
// Tinh tong tien thue xe
float TinhTongTienThueXe(XeDap ds_xd[], int n, XeMay ds_xm[], int m){
	float tong=0;
	//Duyet danh sach xe dap
	for(int i=0;i<n;i++){
		tong += ds_xd[i].TinhTienThueXe();
	}
	//Duyet danh sach xe may
	for(int i=0;i<m;i++){
		tong += ds_xm[i].TinhTienThueXe();
	}
	return tong;
}
// Ham quan ly cac loai xe 
void Menu(XeDap ds_xd[], int n, XeMay ds_xm[], int m){
	int luachon;
	while(true){
		cout<<"\n\n\t\t====== QUAN LY XE THUE ======";
		cout<<"\n\t1.Nhap danh sach thue xe dap va xe may: ";
		cout<<"\n\t2.Xuat tat ca thong tin thue xe:";
		cout<<"\n\t3.Tinh tong so tien cho thue xe dap va xe may:";
		cout<<"\n\t4.Xuat tat ca cac thong tin lien quan den viec thue xe dap:";
		cout<<"\n\t5.Tinh tong so tien thue xe may loai 250cc:";
		cout<<"\n\t0.Ket thuc";
		cout<<"\n\n\t\t ==============END============";
		
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		
		if(luachon == 1){
			int chon;
			while(true){
				system("cls");
				cout<<"\n1.Thue xe dap:";
				cout<<"\n2.Thue xe may:";
				cout<<"\n0.Ket thuc";
				
				cout<<"\nBan thue xe gi?";
				cin>>chon;
				if(chon==1){
					XeDap xd;
					cout<<"\n\n\t\t NHAP THONG TIN XE DAP\n";
					xd.NhapThongTin();
					ds_xd[n] = xd;
					n++;
				}else if(chon==2){
					XeMay xm;
					cout<<"\n\n\t\t NHAP THONG TIN XE MAY\n";
					xm.NhapThongTin();
					ds_xm[m] = xm;
					m++;	
				}else{
					break;
				}
			}
			
		}else if(luachon==2){
			XuatTatCaThongTin(ds_xd, n, ds_xm, m);
			system("pause");
		}
		else if(luachon==3){
			cout<<"\nTONG TIEN THUE XE: "<<TinhTongTienThueXe(ds_xd,n,ds_xm,m);
			system("pause");
		}
	}
}


int main(){
	XeDap ds_xd[100];
	int n=0;
	XeMay ds_xm[100];
	int m=0;
	Menu(ds_xd, n, ds_xm, m);
	
	system("pause");
	return 0;
}

