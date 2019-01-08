#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int n; // so luong cau hoi trong bo de thi

struct dethi{
	string a,b,c,d, question, answer;
};
vector <dethi> cauhoi;

void ReadQuestionFromFile();
void OutputQuestion(); 
bool check( dethi &q); 
void chon();

int main()
{
//	menu();
	chon();
//	tinhdiem();
//	system("pause");
}
//------------------------------------------------------------------
// ham doc cau hoi tu file
void ReadQuestionFromFile( ifstream &read, vector <dethi> &cauhoi){
	read >> n;
	string temp;
	getline(read, temp);
	cauhoi.resize(n);
	for ( int i = 0; i < n; i++){
		getline(read, cauhoi[i].question);
		getline(read, cauhoi[i].a);
		getline(read, cauhoi[i].b);
		getline(read, cauhoi[i].c);
		getline(read, cauhoi[i].d);
		getline(read, cauhoi[i].answer);
	}
}
//------------------------------------------------------------------
// ham xuat ra cau tra loi tren nan hinh cmd
void OutputQuestion(vector <dethi> &cauhoi){
	int scores = 0;
	for ( int i = 0; i < cauhoi.size(); i++){
		cout << cauhoi[i].question << endl;
		cout << cauhoi[i].a << endl;
		cout << cauhoi[i].b << endl;
		cout << cauhoi[i].c << endl;
		cout << cauhoi[i].d << endl;
		if ( check (cauhoi[i]) == true ){
			cout << "\tTrue" << endl;
			scores++;
		}
		else{
			cout << "\tFalse" << endl;
			cout << "\tCorrect answer: " << cauhoi[i].answer << endl;
		}
	}
	cout << "\t\tCongratulation :))) ==>>> Your scores is: " << scores << endl;
}
//------------------------------------------------------------------
// ham kiem tra cau tra loi co dung hay khong.
bool check(dethi &q){
	int scores = 0;
	string answer_player;
	cout << "Your answer is: ";
	cin >> answer_player;
	if( answer_player  == q.answer )
		return true;
	else
		return false;
}
//------------------------------------------------------------------
// ham menu bo de
void menu(){
	cout << "\t0. Thoat nha ...!" << endl;
	cout << "\t1. Bo de 1: cau hoi ve dong vat" << endl;
	cout << "\t2. Bo de 2: cau hoi ve Bac Ho" << endl << endl;
}
//------------------------------------------------------------------
// ham select de lua chon bo de minh muon lam.
void chon(){
	menu();
	vector <dethi> cauhoi;
	ifstream read;
	int select;
	cout << "\t\tYour select is: ";
	cin >> select;
	switch(select){
		case 0:
			return;
		case 1:
			system("cls");
			read.open("bode1_bai3.txt", ios::in);
			ReadQuestionFromFile(read, cauhoi);
			OutputQuestion(cauhoi);
			chon();
			break;
		case 2:
			system("cls");
			read.open("bode2_bai3.txt", ios::in);
			ReadQuestionFromFile(read, cauhoi);
			OutputQuestion(cauhoi);
			chon();
			break;
			///
		default:
			cout << "Sai cu phap" << endl;
			exit(0);
			break;
	}
}

