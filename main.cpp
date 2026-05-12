#include <iostream>
#include <vector>
using namespace std;

// class induk
class user {
protected:
    static int globalId;

public:
    int id;
    string nama;
    string email;

    // constructor
    user(string pNama, string pEmail)
        : nama(pNama), email(pEmail) {
        generateId();
    }

    // function generate id
    void generateId() {
        globalId++;
        id = globalId;
    }
};

// inisialisasi static variable
int user::globalId = 0;


// class turunan admin
class admin : public user {
public:
    admin(string pNama, string pEmail)
        : user(pNama, pEmail) {
    }

    // menampilkan semua member
    void showAllMember(vector<class member*> daftarMember);

    // mengubah status member
    void toggleActivationMember(class member* mbr);
};


// class turunan member
class member : public user {
public:
    bool status;

    member(string pNama, string pEmail, bool pStatus)
        : user(pNama, pEmail), status(pStatus) {
    }

    // menampilkan profile
    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;

        if (status == true) {
            cout << "Status : Aktif" << endl;
        }
        else {
            cout << "Status : Nonaktif" << endl;
        }

        cout << endl;
    }
};


// implementasi function admin
void admin::showAllMember(vector<member*> daftarMember) {
    cout << "===== DAFTAR MEMBER =====" << endl;

    for (int i = 0; i < daftarMember.size(); i++) {
        cout << "ID    : " << daftarMember[i]->id << endl;
        cout << "Nama  : " << daftarMember[i]->nama << endl;
        cout << "Email : " << daftarMember[i]->email << endl;

        if (daftarMember[i]->status == true) {
            cout << "Status: Aktif" << endl;
        }
        else {
            cout << "Status: Nonaktif" << endl;
        }

        cout << endl;
    }
}

// implementasi toggle status
void admin::toggleActivationMember(member* mbr) {
    mbr->status = !mbr->status;

    cout << mbr->nama << " berhasil diubah statusnya menjadi ";

    if (mbr->status == true) {
        cout << "Aktif" << endl;
    }
    else {
        cout << "Nonaktif" << endl;
    }

    cout << endl;
}


// main program
int main() {

    // membuat admin
    admin admin1("Hana", "hana@gmail.com");

    // membuat member
    member* member1 = new member("Andi", "andi@gmail.com", true);
    member* member2 = new member("Budi", "budi@gmail.com", false);

    // vector daftar member
    vector<member*> daftarMember;

    daftarMember.push_back(member1);
    daftarMember.push_back(member2);

    // tampil semua member
    admin1.showAllMember(daftarMember);

    // tampil profile member
    member1->showProfile();

    // ubah status member
    admin1.toggleActivationMember(member2);

    // tampil ulang semua member
    admin1.showAllMember(daftarMember);

    
    delete member1;
    delete member2;

    return 0;
}
