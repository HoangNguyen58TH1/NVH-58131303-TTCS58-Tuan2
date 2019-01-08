#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std;

typedef struct nhanvien{
	char nhanvienID[4], hoten[20];
	int tuoi, luong;
};
nhanvien nv;

vector <nhanvien> dsNV;
char tenfile[12]="input2.txt";
//--------------------------------------------
//khai bao tat ca cac ham trong chuong trinh.
void showMenu();
void chon();
bool themNV(nhanvien nv);
void inNV(nhanvien nv);
void inDSNV();
nhanvien NhapNVtuBP();
void docfile(char* tenfile);// doc file
bool xoaNV(char* nvID);
void editNV(nhanvien nvEdit);
bool search_nvID(char *nvMA);
void ghifile(char* tenfile);// ghi file
//--------------------------------------------
//ham int main
int main()
{
	docfile(tenfile);
	cout << "\t\tThong tin nhan vien ban dau" << endl;
	inDSNV();
	///bat dau xu ly
	showMenu();
	chon();
	system("pause");
}
//--------------------------------------------
//doc file
void docfile(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::in);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			while(!file.eof())
			{	
				nhanvien nv;
				file.getline(nv.nhanvienID,4);
				file.getline(nv.hoten,21);
				file>>nv.tuoi;
				file>>nv.luong;
				dsNV.push_back(nv);	
				file.ignore();						
			}
			file.close();			
		}
}
//--------------------------------------------
// ham hien thi meunu
void showMenu()
{	
	cout << "1. Them 1 nhan vien. " << endl;
	cout << "2. Xoa 1 nhan vien. " << endl;
	cout << "3. Sua thong tin 1 nhan vien. " << endl;
	cout << "4. Tim kiem nhan vien theo ma so nhan vien. " << endl;
	cout << "5. Thoat. " << endl << endl;
}
//--------------------------------------------
// ham lua chon
void chon()
{
	nhanvien nv3, nvEdit;
	int select;
	cout << "Lua chon cua ban la: ";
	cin >> select;
	switch (select)
	{
		case 1:
			//nhap thong tin nhan vien de them vao
			cout << "\t\tThong tin nhan vien can them" << endl;
			nv3 = NhapNVtuBP();
			themNV(nv3);
			cout << "\t\tDanh sach nhan vien sau khi da them 1 nhan vien." << endl;
			inDSNV();
				chon();
				break;
		case 2:
			//in ds nhan vien sau khi xoa
			cout << "\t\tDanh sach nhan vien sau khi da xoa 1 nhan vien." << endl;
			xoaNV("002");
			inDSNV();
				chon();
				break;
		case 3:
			//in ds nhan vien sau khi da edit
			cout << "\t\tNhap thong tin nhan vien can edit." << endl;
			nvEdit=NhapNVtuBP();
			editNV(nvEdit);
			cout << "\t\t Danh sach nhan vien sau khi edit:\n";
			inDSNV();
				chon();
				break;
		case 4:
			//tim thong tin nhanvien bang manv
			search_nvID("123");
				chon();
				break;
		case 5:
			return;
		default:
//			system("cls");
			cout << "Sai cu phap" << endl;
//			showmenu();
			chon();
			break;
	}
}
//--------------------------------------------
// them nhan vien vao danh sach
bool themNV(nhanvien nv){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		if(strcmp(nv.nhanvienID,dsNV[i].nhanvienID)==0)
			return false;
	dsNV.push_back(nv);
	return true;
}
//--------------------------------------------
//in ra thong tin cua 1 nhan vien i
void inNV(nhanvien nv){
//	cout << "\t\tthong tin nhan vien." << endl;
	cout <<"maNV: "<< nv.nhanvienID << endl;
	cout <<"tenNV: "<<nv.hoten  << endl;
	cout <<"tuoiNV: "<<nv. tuoi << endl;
	cout <<"luongNV: "<< nv.luong << endl;
	cout << "---------------------"<< endl;
}
//--------------------------------------------
// in ra danh sach thong tin nhan vien tu ham inNV
void inDSNV(){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		inNV(dsNV[i]);
}
//--------------------------------------------
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
//--------------------------------------------
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
//--------------------------------------------
// chinh sua thong tin nhan vien
void editNV(nhanvien nvEdit){
		int size=dsNV.size();
		int vtedit=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvEdit.nhanvienID,dsNV[i].nhanvienID)==0){
			vtedit=i;
			break;
		}
	if(vtedit!=-1){	
		strcpy(dsNV[vtedit].nhanvienID,nvEdit.nhanvienID);
			strcpy(dsNV[vtedit].hoten,nvEdit.hoten);
			dsNV[vtedit].tuoi=nvEdit.tuoi;
			dsNV[vtedit].luong=nvEdit.luong;
	}
}
//--------------------------------------------
// ham tim kiem nhan vien theo ma nhan vien
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
//--------------------------------------------
//ham ghi file
void ghifile(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::out);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			int n=dsNV.size();
			for(int i=0;i<n-1;i++)
			{
				file<<dsNV[i].nhanvienID<<endl;
				file<<dsNV[i].hoten<<endl;
				file<<dsNV[i].tuoi<<endl;
				file<<dsNV[i].luong<<endl;				
			}
			file<<dsNV[n-1].nhanvienID<<endl;
			file<<dsNV[n-1].hoten<<endl;
			file<<dsNV[n-1].tuoi<<endl;
			file<<dsNV[n-1].luong;			
		}
}
