#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Date{
	protected:
		int ngay, thang, nam;
	public:
		Date();
		~Date();
		void Nhap();
		void Xuat();
};
Date::Date(){
	ngay=0;
	thang=0;
	nam=0;
}
Date::~Date(){
	
}
void Date::Nhap(){
	cout<<"Nhap ngay: ";
	cin>>this->ngay;
	cout<<"Nhap thang: ";
	cin>>this->thang;
	cout<<"Nhap nam: ";
	cin>>this->nam;
}
void Date::Xuat(){
	cout<<"Ngay/Thang/Nam sinh: "<<this->ngay<<"/"<<this->thang<<"/"<<this->nam<<endl;
}
class Xe{
	protected:
		string HoTen;
		Date ngaysinh;
		int SoCMND;
		float SoGioThue;
		float SoTienThue;
	public:
		Xe();
		~Xe();
		virtual void NhapThongTin();
		virtual void XuatThongTin();
		virtual float TinhTienThueXe()=0;
		string GetHoTen();
		int GetSoCMND();
};
Xe::Xe(){
	HoTen="";
	SoCMND=0;
	SoGioThue=0;
}
Xe::~Xe(){
	
}
void Xe::NhapThongTin(){
//	while(getchar() != '\n');
	cout<<"Nhap ho ten nguoi thue: ";
	fflush(stdin);
	getline(cin, this->HoTen);
	cout<<"Nhap ngay sinh"<<endl;
	ngaysinh.Nhap();
	cout<<"Nhap So CMND: ";
	cin>>this->SoCMND;
}
void Xe::XuatThongTin(){
	cout<<"Ho ten nguoi thue: "<<HoTen<<endl;
	ngaysinh.Xuat();
	cout<<"So CMND: "<<SoCMND<<endl;
}
string Xe::GetHoTen(){
	return HoTen;
}
int Xe::GetSoCMND(){
	return SoCMND;
}
class XeDap:public Xe{
	public:
		void NhapThongTin();
		void XuatThongTin();
		float TinhTienThueXe();
		
};
void XeDap::NhapThongTin(){
	Xe::NhapThongTin();
	cout<<"Nhap so gio thue: ";
	cin>>this->SoGioThue;
}
void XeDap::XuatThongTin(){
	Xe::XuatThongTin();
	cout<<"So gio thue: "<<SoGioThue<<endl;
//	this->TinhTienThueXe();
//	cout<<"Tien thue xe: "<<SoTienThue<<endl;
}
float XeDap::TinhTienThueXe(){
	if(SoGioThue>=1){
		SoTienThue = 10000 + ((this->SoGioThue - 1) * 8000);
	}else{
		SoGioThue=0;
	}
	
}

class XeMay:public Xe{
	private:
		int PhanKhoi;
		string BienSo;
	public:
		XeMay();
		~XeMay();
		void NhapThongTin();
		void XuatThongTin();
		float TinhTienThueXe();
		int Getter_PhanKhoi();
		void Setter_PhanKhoi(int LOAIXE);
};
XeMay::XeMay(){
	PhanKhoi=0;
	BienSo="";
}
XeMay::~XeMay(){
	
}
void XeMay::NhapThongTin(){
	Xe::NhapThongTin();
	cout<<"Nhap phan khoi xe(100-250cc): ";
	cin>>this->PhanKhoi;
	cout<<"Nhap bien so: ";
	fflush(stdin);
	getline(cin, this->BienSo);
	cout<<"Nhap so gio thue xe: ";
	cin>>this->SoGioThue;
}
void XeMay::XuatThongTin(){
	Xe::XuatThongTin();
	cout<<"Xe phan khoi: "<<PhanKhoi<<"cc"<<endl;
	cout<<"Bien so: "<<BienSo<<endl;
//	this->TinhTienThueXe();
//	cout<<"Tien thue xe: "<<SoTienThue<<endl;
}
float XeMay::TinhTienThueXe(){
	if(0<PhanKhoi<=150){
		SoTienThue=20000 + ((this->SoGioThue - 1) * 10000);
	}else if(PhanKhoi == 150){
		SoTienThue=30000 + ((this->SoGioThue - 1) * 20000);
	}else{
		SoTienThue=0;
	}	
}
int XeMay::Getter_PhanKhoi(){
	return PhanKhoi;
}
void XeMay::Setter_PhanKhoi(int P){
	PhanKhoi = P;
}
void XuatThongTinThueXe(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m)
{
	int dem = 1;
	cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tTHONG TIN THUE XE DAP THU " << dem++ << endl;
		ds_xedap[i].XuatThongTin();
		cout << "Tien thue xe: " << (size_t)ds_xedap[i].TinhTienThueXe();

	}
	cout << "\n\n\t\t DANH SACH THUE XE MAY\n";
	for (int i = 0; i < m; i++)
	{
		cout << "\n\tTHONG TIN THUE MAY THU " << dem++ << endl;
		ds_xemay[i].XuatThongTin();
		cout << "Tien thue xe: " << (size_t)ds_xemay[i].TinhTienThueXe();
	}
}
float TinhTongTienThueXe(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m){
	float tong = 0;
	for (int i = 0; i < n; i++){		
		tong += ds_xedap[i].TinhTienThueXe();
	}
	for (int i = 0; i < m; i++){		
		tong += ds_xemay[i].TinhTienThueXe();
	}
	return tong;
}
void TimKiemThongTin(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m){
	string Ten;
	cout<<"\n\tNhap ten nguoi thue: "; 
	fflush(stdin); 
	getline (cin,Ten);
    for (int i=0; i<n; i++){
    	if (Ten == ds_xedap[i].GetHoTen()){
    		cout<<"\n\t___Nguoi thue can tim___ "<<endl;
			ds_xedap[i].XuatThongTin();
			cout << "Tien thue xe: " << (size_t)ds_xedap[i].TinhTienThueXe();
		}
	}
	for (int i=0; i<m; i++){
    	if (Ten == ds_xemay[i].GetHoTen()){
    		cout<<"\n\t___Nguoi thue can tim___ "<<endl;
			ds_xemay[i].XuatThongTin();
			cout << "Tien thue xe: " << (size_t)ds_xemay[i].TinhTienThueXe();
		}
	}
}
void SapXepThongTinTangDan(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			if(ds_xedap[i].TinhTienThueXe() > ds_xedap[j].TinhTienThueXe()){
				XeDap temp = ds_xedap[i];
    			ds_xedap[i] = ds_xedap[j];
    			ds_xedap[j] = temp;
			}		
		}
		for (int i=0; i<n; i++){
			cout<<"\n\tThông tin cua nguoi thue "<<i+1<<endl;
    		ds_xedap[i].XuatThongTin();
    		cout << "Tien thue xe: " <<ds_xedap[i].TinhTienThueXe();	
		}
		
	for(int i=0;i<m-1;i++)
		for(int j=i+1;j<m;j++){
			if(ds_xemay[i].TinhTienThueXe() > ds_xemay[j].TinhTienThueXe()){
				XeMay temp = ds_xemay[i];
    			ds_xemay[i] = ds_xemay[j];
    			ds_xemay[j] = temp;
			}		
		}
		for (int i=0; i<n; i++){
			cout<<"\n\tThông tin cua nguoi thue "<<i+1<<endl;
    		ds_xemay[i].XuatThongTin();
    		cout << "Tien thue xe: " <<ds_xemay[i].TinhTienThueXe();	
		}
}
void XoaThongTinThueXe(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m){
	string Ten;
	cout<<"Nhap ten ban muon xoa khoi danh sach: ";
	fflush(stdin);
	getline(cin, Ten);
	
	for (int i=0; i<m; i++){
    	if (Ten == ds_xedap[i].GetHoTen()){
    		for (int i=0; i<m-1; i++){
    			for(int j=i+1; j<m; j++){
    				ds_xedap[i] = ds_xedap[j];
				}
			}
		}
	}
	n--;
	
	for (int i=0; i<m; i++){
    	if (Ten == ds_xemay[i].GetHoTen()){
    		for (int i=0; i<m-1; i++){
    			for(int j=i+1; j<m; j++){
    				ds_xemay[i] = ds_xemay[j];
				}
			}
		}
	}
	m--;
}
void Menu(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m){
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\t\t ============== QUAN LY XE ==============";
		cout << "\n\n\t\t\t1. Nhap danh sach thue xe dap va xe may";
		cout << "\n\t\t\t2. Xuat tat ca thong tin thue xe";
		cout << "\n\t\t\t3. Tinh tong so tien cho thue xe dap va xe may";
		cout << "\n\t\t\t4. Xuat thong tin cho thue xe dap";
		cout << "\n\t\t\t5. Xuat thong tin cho thue xe may";
		cout << "\n\t\t\t6. Tinh tong so tien cho thue xe may loai 250 phan khoi";
		cout << "\n\t\t\t7. Tim mot thong tin thue xe theo ten";
		cout << "\n\t\t\t8. Sap xep thong tin tang dan theo so tien thue xe";
		cout << "\n\t\t\t9. Xoa mot thong tin thue xe theo ten";
		cout << "\n\t\t\t0. Ket thuc";
		cout << "\n\n\t\t\t\t ============== END ==============";

		cout << "\n\n\tNhap lua chon: ";
		cin >> luachon;
		
		if(luachon == 1){
			int chon;
			while(true){
				system("cls");
				cout<<"\n\n\t\t*****CHON XE BAN MUON THUE*****";
				cout<<"\n\t\t\t--1.Xe Dap--";
				cout<<"\n\t\t\t--2.Xe May--";
				cout<<"\n\t\t\t--0.Thoat--";	
				cout<<"\n\t\t*************************";
				cout<<"\n\tNhap loai xe muon thue --> ";
				cin>>chon;
				
				if(chon==1){
					XeDap x;
					cout<<"\n\n\t\t NHAP THONG TIN XE DAP\n";
					x.NhapThongTin();
					ds_xedap[n]=x;
					n++;
				}
				else if(chon==2){
					XeMay x;
					cout<<"\n\n\t\t NHAP THONG TIN XE MAY\n";
					x.NhapThongTin();
					ds_xemay[m]=x;
					m++;
				}else{
					break;
				}	
			}
		}else if(luachon == 2){
				XuatThongTinThueXe(ds_xedap, n, ds_xemay, m);
				system("pause");
		}else if(luachon == 3){
			cout << "\n\n\t\tTONG TIEN THUE XE: " << (size_t)TinhTongTienThueXe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 4){
			cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
			for (int i = 0; i < n; i++){
				cout << "\n\tTHONG TIN THUE XE DAP THU " << i + 1 << endl;
				ds_xedap[i].XuatThongTin();
				cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe();
			}
			system("pause");
		}
		else if (luachon == 5){
			cout << "\n\n\t\t DANH SACH THUE XE MAY\n";
			for (int i = 0; i < n; i++){
				cout << "\n\tTHONG TIN THUE XE MAY THU " << i + 1 << endl;
				ds_xemay[i].XuatThongTin();
				cout << "Tien thue xe: " << (size_t)ds_xemay[i].TinhTienThueXe();
			}
			system("pause");
		}
		else if (luachon == 6){
			int dem = 0;
			cout << "\n\n\t\t DANH SACH THUE XE MAY LOAI 250 PHAN KHOI\n";
			for (int i = 0; i < m; i++){
				if (ds_xemay[i].Getter_PhanKhoi() == 250){
					cout << "\n\tTHONG TIN THUE MAY THU " << ++dem << endl;
					ds_xemay[i].XuatThongTin();
					cout << "Tien thue xe: " << (size_t)ds_xemay[i].TinhTienThueXe();
				}				
			}
			system("pause");
		}
		else if(luachon == 7){
			TimKiemThongTin(ds_xedap, n, ds_xemay, m);
			cout<<"\n\tNhan phim bat ki de quay lai menu."<<endl;
			system("pause");
		}
		else if(luachon == 8){
			cout<<"\n\t--Sap xep thong tin tang dan theo so tien thue--"<<endl;
			SapXepThongTinTangDan(ds_xedap, n, ds_xemay, m);
			cout<<"\nNhan phím bat ky de quay lai menu\n";
			system("pause");
		}
		else if(luachon == 9){
			XoaThongTinThueXe(ds_xedap, n, ds_xemay, m);
			cout<<"\nDa xoa thanh cong."<<endl;
			cout<<"\nNhan phím bat ky de quay lai menu\n";
			system("pause");
		}
		else{
			break;
		}
	}
	
}
int main(){
	XeDap ds_xedap[100];
	int n=0;
	XeMay ds_xemay[100];
	int m=0;
	Menu(ds_xedap, n, ds_xemay, m);
	system("pause");
	return 0;
}
