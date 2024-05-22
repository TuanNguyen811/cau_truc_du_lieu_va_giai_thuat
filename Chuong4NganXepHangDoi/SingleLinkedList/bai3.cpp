#include <iostream>
#include <string>

using namespace std;
struct node
{   
    string maSoSinhVien;
    string maMonHoc;
    float diem;
    node *next;
};
class QuanLyDiemSinhVien{
private:
    node *danhSachDiemSinhVien;
public:
    QuanLyDiemSinhVien(){
        danhSachDiemSinhVien=NULL;
    }
    node* taoNodeMoi(string maSoSinhVien, string maMonHoc,float diem){
        node*temp=new node;
        temp->maSoSinhVien=maSoSinhVien;
        temp->maMonHoc=maMonHoc;
        temp->diem=diem;
        temp->next=NULL; // Cập nhật con trỏ next
        return temp;
    }
    void duyetDanhSach(){
        node* temp=danhSachDiemSinhVien;
        while (temp!=NULL)
        {
            cout <<"MSSV: "<<temp->maSoSinhVien<<endl;
            cout <<"Ma mon hoc: "<< temp->maMonHoc<<endl;
            cout <<"Diem: "<<temp->diem<<endl;
            temp=temp->next;
        }
    }
     void chienCuoi(){
        string maSoSinhVien;
        string maMonHoc;
        float diem;
        node *temp, *s;
        cout <<"MSSV: ";
        getline(cin,maSoSinhVien);
        cout <<"Ma mon hoc: ";
        getline(cin,maMonHoc);
        cout <<"Diem: ";
        cin>>diem;
        cin.ignore();
        temp= taoNodeMoi(maSoSinhVien,maMonHoc,diem);

        if (danhSachDiemSinhVien==NULL){
            danhSachDiemSinhVien=temp;
        }else{
            s=danhSachDiemSinhVien;
            while (s->next!=NULL){
                s=s->next;
            }
            s->next=temp;
        }  
    }
};
int main(){
    QuanLyDiemSinhVien quanLySinhVien;
    int luaChon;
    do
    {
        cout <<"-----------------------------\n";
        cout <<"1. Them sinh vien\n";
        cout <<"2. Duyet danh sach sinh vien\n";
        cout <<"3. 5 sinh vien co diem cao nhat\n";
        cout <<"0. Thoat\n";
        cout <<"-----------------------------\n";

        cin>>luaChon;
        cin.ignore();             

        switch (luaChon)
        {
        case 1:{
            char luachon1;
            do
            {
                quanLySinhVien.chienCuoi();
                cout <<"Nhap tiep sinh vien? (y/n): ";
                cin>>luachon1;
                cin.ignore();
            } while (luachon1!='n');
            break;
        }
        case 2:{
            quanLySinhVien.duyetDanhSach();
            break;
        }
        case 3:{
        }
        default:
            break;
        }
    } while (luaChon!=0);
    
    return 0;
}