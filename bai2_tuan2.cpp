#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

typedef struct nhanvien{
	char nhanvienID[4], hoten[20];
	int tuoi, luong;
};
nhanvien nv[10];

vector <nhanvien> dsNV;
bool themNV(nhanvien nv);
void inNV(nhanvien nv);
void inDSNV();
nhanvien NhapNVtuBP();
bool xoaNV(char* nvID);
void editNV(nhanvien nvSua);
bool search_nvID(char *nvMA);

int main(){
	nhanvien nv1,nv2;
	strcpy(nv1.nhanvienID,"001");
	strcpy(nv1.hoten,"Nguyen Van A");
	nv1.tuoi=30;
	nv1.luong=30000;
	strcpy(nv2.nhanvienID,"002");
	strcpy(nv2.hoten,"Nguyen Van B");
	nv2.tuoi=35;
	nv2.luong=34000;
	themNV(nv1);
	themNV(nv2);
	cout << "\t\tThong tin nhan vien ban dau" << endl;
	inDSNV();
	
	//in ds nhan vien sau khi them
	cout << "\t\tThong tin nhan vien can them" << endl;
	nhanvien nv3=NhapNVtuBP();
	themNV(nv3);
	cout << "\t\tDanh sach nhan vien sau khi da them 1 nhan vien." << endl;
	inDSNV();
	
	//in ds nhan vien sau khi xoa
	cout << "\t\tDanh sach nhan vien sau khi da xoa 1 nhan vien." << endl;
	xoaNV("002");
	inDSNV();
	
	///in ds nhan vien sau khi da edit
	cout << "\t\tNhap thong tin nhan vien can edit." << endl;
	nhanvien nvSua=NhapNVtuBP();
	editNV(nvSua);
	cout<<"\t\t Danh sach nhan vien sau khi edit:\n";
	inDSNV();
	
	//tim thong tin nhanvien bang manv
	search_nvID("123");
}
// them nhan vien vao danh sach
bool themNV(nhanvien nv){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		if(strcmp(nv.nhanvienID,dsNV[i].nhanvienID)==0)
			return false;
	dsNV.push_back(nv);
	return true;
}
//in ra thong tin cua 1 nhan vien i
void inNV(nhanvien nv){
//	cout << "\t\tthong tin nhan vien." << endl;
	cout <<"maNV: "<< nv.nhanvienID << endl;
	cout <<"tenNV: "<<nv.hoten  << endl;
	cout <<"tuoiNV: "<<nv. tuoi << endl;
	cout <<"luongNV: "<< nv.luong << endl;
	cout << "---------------------"<< endl;
}
// in ra danh sach thong tin nhan vien tu ham inNV
void inDSNV(){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		inNV(dsNV[i]);
}
// nhap thong tin nhan vien tu ban phim
nhanvien NhapNVtuBP(){
	nhanvien nv;
//	cout << "\t\tnhap thong tin nhan vien can them." << endl;
	cout<<"Nhap ma nv:";fflush(stdin);
	gets(nv.nhanvienID);
	cout<<"Nhap ten nv:";fflush(stdin);
	gets(nv.hoten);
	cout<<"Nhap tuoi nv:";
	cin>>nv.tuoi;
	cout<<"Nhap luong nv:";
	cin>>nv.luong;
	cout << "----------------------"<< endl<<endl;
	return nv;
}
//xoa di thong tin 1 nhan vien
bool xoaNV(char* nvID){
		int size=dsNV.size();
		int vtxoa=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvID,dsNV[i].nhanvienID)==0){
			vtxoa=i;
			break;
		}
		if(vtxoa!=-1){
			dsNV.erase(dsNV.begin()+vtxoa);
			return true;
		}
		return false;
}
// chinh sua thong tin nhan vien
void editNV(nhanvien nvSua){
		int size=dsNV.size();
		int vtedit=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvSua.nhanvienID,dsNV[i].nhanvienID)==0){
			vtedit=i;
			break;
		}
	if(vtedit!=-1){	
		strcpy(dsNV[vtedit].nhanvienID,nvSua.nhanvienID);
			strcpy(dsNV[vtedit].hoten,nvSua.hoten);
			dsNV[vtedit].tuoi=nvSua.tuoi;
			dsNV[vtedit].luong=nvSua.luong;
	}
}

bool search_nvID(char* nvMA){
		int size=dsNV.size();
		int vt_search=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvMA,dsNV[i].nhanvienID)==0){
			vt_search=i;
			cout << "\t\tThong tin nhan vien can tim la:" << endl;
			inNV(dsNV[i]);
			break;
			return true;
		}
		return false;
}
