// Truong Ngoc De 6151071041
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class GiangVien{
	protected:
		string hoten;
		int tuoi;
		float luong;
	public:
		GiangVien();
		~GiangVien();
		virtual void nhap();
		virtual void xuat();
		virtual void tinhluong()=0;
		float getLuong();
};
GiangVien::GiangVien(){
	hoten="";
	tuoi=0;
	luong=0;
}
GiangVien::~GiangVien(){}
void GiangVien::nhap(){
	cout<<"Nhap ho ten giang vien: ";
	fflush(stdin);
	getline(cin, this->hoten);
	cout<<"Nhap tuoi: ";
	cin>>this->tuoi;
}
void GiangVien::xuat(){
	cout<<"Ho ten Giang Vien: "<<hoten<<endl;
	cout<<"Tuoi: "<<tuoi<<endl;
}
float GiangVien::getLuong(){
	return this->luong;
}
class GiangVienCoHuu:public GiangVien{
	private:
		float hesoluong, thamnien;
	public:
		GiangVienCoHuu();
		~GiangVienCoHuu();
		void nhap();
		void xuat();
		void tinhluong();
};
GiangVienCoHuu::GiangVienCoHuu(){
	hesoluong=0;
	thamnien=0;
}
GiangVienCoHuu::~GiangVienCoHuu(){}
void GiangVienCoHuu::nhap(){
	GiangVien::nhap();
	cout<<"Nhap he so luong: ";
	cin>>this->hesoluong;
	cout<<"Nhap tham nien: ";
	cin>>this->thamnien;
}
void GiangVienCoHuu::xuat(){
	GiangVien::xuat();
	cout<<"He so luong: "<<hesoluong<<endl;
	cout<<"Tham nien: "<<thamnien<<endl;
	this->tinhluong();
	cout<<"Luong: "<<luong<<endl;
}
void GiangVienCoHuu::tinhluong(){
	luong = (this->hesoluong*1600) + (this->thamnien*500);
}
class GiangVienThinhGiang:public GiangVien{
	private:
		int SoTiet;
	    float DonGia;
	
	public:
	    void nhap();
	    void xuat();
	    void tinhluong();
};
void GiangVienThinhGiang::nhap(){
	GiangVien::nhap();
	cout<<"Nhap so tiet: ";
	cin>>this->SoTiet;
	cout<<"Nhap don gia: ";
	cin>>this->DonGia;
}
void GiangVienThinhGiang::xuat(){
	GiangVien::xuat();
	cout<<"So tiet: "<<SoTiet<<endl;
	cout<<"Don gia: "<<DonGia<<endl;
	this->tinhluong();
	cout<<"Luong: "<<luong<<endl;
}
void GiangVienThinhGiang::tinhluong(){
	this->luong = (SoTiet*DonGia);
}
class QuanLyGiangVien{
	private:
		// Ap dung cac cau truc du lieu
	    vector<GiangVien *> GV;
	    
	public:
	    void NhapDS(){
	    	GiangVien *gv;
	    	int n, m;
	    	cout<<"Nhap so luong giang vien co huu: ";
	    	cin>>n;
	    	for(int i=0;i<n;i++){
	    		gv=new GiangVienCoHuu;
	    		gv->nhap();
	    		GV.push_back(gv);
			}
			cout<<"Nhap so luong giang vien thinh giang: ";
	    	cin>>m;
	    	for(int i=0;i<m;i++){
	    		gv=new GiangVienThinhGiang;
	    		gv->nhap();
	    		GV.push_back(gv);
			}	
		}
	    void XuatDS(){
	    	cout<<"*****Danh sach giang vien*****"<<endl;
	    	for(int i=0;i<this->GV.size();i++){
	    		this->GV.at(i)->xuat();

			}
		}
	    void SapXepLuongTangDan(){
	    	for(int i=0;i<GV.size()-1;i++){
	    		for(int j=i+1;j<GV.size();j++){
	    			if(GV.at(i)->getLuong() > GV.at(j)->getLuong()){
	    				GiangVien *t = GV.at(i);
	    				GV.at(i)=GV.at(j);
	    				GV.at(j)=t;
					}
				}
			}
			XuatDS();
		}
	    void LuongLonNhat(){
	    	GiangVien *max = GV.at(0);
	    	for(int i=1;i<GV.size();i++){
	    		if(GV.at(i)->getLuong() > max->getLuong())
	    			max = GV.at(i);
			}
			cout<<endl<<"Giang vien co luong cao nhat: "<<endl;
			max->xuat();
		}
	    void TongLuong(){
	    	float tong = 0;
	    	for(int i=0;i<GV.size();i++){
	    		tong+=GV.at(i)->getLuong();
			}
			cout<<endl<<"Tong luong giang vien: "<<setprecision(2)<<fixed<<tong<<endl;
		}
};

int main(){
	QuanLyGiangVien a;
	a.NhapDS();
	a.XuatDS();
	a.SapXepLuongTangDan();
	a.LuongLonNhat();
	a.TongLuong();
}



	

