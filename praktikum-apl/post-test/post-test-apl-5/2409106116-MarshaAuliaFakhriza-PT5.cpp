#include <iostream>
#include <string>

using namespace std;

// struct
struct Sandal {
    string nama;
    int harga;
    int stok;
};

struct Pengguna {
    string username;
    string password;
    string role;
};

// Deklarasi Function
void tampilkanDaftarSandal(Sandal daftarSandal[], int jumlahSandal);
void tambahSandal(Sandal daftarSandal[], int &jumlahSandal);
void editSandal(Sandal daftarSandal[], int jumlahSandal);
void hapusSandal(Sandal daftarSandal[], int &jumlahSandal);
void beliSandal(Sandal daftarSandal[], int jumlahSandal);
bool login(Pengguna daftarPengguna[], int jumlahPengguna, string &usernameSaatIni, string &roleSaatIni, int percobaanLogin = 0);
void daftar(Pengguna daftarPengguna[], int &jumlahPengguna);
void menuAdmin(Sandal daftarSandal[], int &jumlahSandal, bool &sudahLogin);
void menuPembeli(Sandal daftarSandal[], int jumlahSandal, bool &sudahLogin);
void cetakBaris(int jumlah, char karakter = '-');
int hitungTotalBelanja(int harga, int jumlah);
int hitungTotalBelanja(int harga, int jumlah, float diskon);
void updateStokSandal(Sandal &sandal, int jumlahBaru);
void lihatDetailSandal(Sandal *ptrSandal);


// Function
void updateStokSandal(Sandal &sandal, int jumlahBaru) {
    cout << "\n----- UPDATE STOK SANDAL -----" << endl;
    cout << "Sandal: " << sandal.nama << endl;
    cout << "Stok Saat Ini: " << sandal.stok << endl;
    cout << "Stok Baru: " << jumlahBaru << endl;
    
    sandal.stok = jumlahBaru;
    cout << "Stok berhasil diperbarui!" << endl;
}

void lihatDetailSandal(Sandal *ptrSandal) {
    cout << "\n----- DETAIL SANDAL -----" << endl;
    cout << "Nama: " << ptrSandal->nama << endl;
    cout << "Harga: Rp " << ptrSandal->harga << endl;
    cout << "Stok: " << ptrSandal->stok << " pasang" << endl;
    
    if (ptrSandal->stok > 10) {
        cout << "Status: Stok Banyak" << endl;
    } else if (ptrSandal->stok > 5) {
        cout << "Status: Stok Cukup" << endl;
    } else if (ptrSandal->stok > 0) {
        cout << "Status: Stok Hampir Habis" << endl;
    } else {
        cout << "Status: Stok Habis" << endl;
    }
}

bool login(Pengguna daftarPengguna[], int jumlahPengguna, string &usernameSaatIni, string &roleSaatIni, int percobaanLogin) {
    if (percobaanLogin >= 3) {
        cout << "Anda telah gagal login 3 kali. Kembali ke menu utama." << endl;
        return false;
    }
    
    string username, password;
    cout << "\n----- LOGIN (Percobaan " << percobaanLogin + 1 << "/3) -----" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    
    for (int i = 0; i < jumlahPengguna; i++) {
        if (username == daftarPengguna[i].username && password == daftarPengguna[i].password) {
            usernameSaatIni = daftarPengguna[i].username;
            roleSaatIni = daftarPengguna[i].role;
            return true;
        }
    }
    
    cout << "Login gagal! Username atau password salah." << endl;
    
    return login(daftarPengguna, jumlahPengguna, usernameSaatIni, roleSaatIni, percobaanLogin + 1);
}

void daftar(Pengguna daftarPengguna[], int &jumlahPengguna) {
    if (jumlahPengguna < 5) {
        cout << "\n----- DAFTAR AKUN -----" << endl;
        cout << "Username: ";
        cin >> daftarPengguna[jumlahPengguna].username;
        cout << "Password: ";
        cin >> daftarPengguna[jumlahPengguna].password;
        daftarPengguna[jumlahPengguna].role = "pembeli";
        
        jumlahPengguna++;
        cout << "Pendaftaran berhasil! Silakan login." << endl;
    }
    else {
        cout << "Maaf, jumlah pengguna sudah maksimal!" << endl;
    }
}

void cetakBaris(int jumlah, char karakter) {
    for (int i = 0; i < jumlah; i++) {
        cout << karakter;
    }
    cout << endl;
}

int hitungTotalBelanja(int harga, int jumlah) {
    return harga * jumlah;
}

int hitungTotalBelanja(int harga, int jumlah, float diskon) {
    float total = harga * jumlah;
    return total - (total * diskon);
}

void tampilkanDaftarSandal(Sandal daftarSandal[], int jumlahSandal) {
    cout << "\nDaftar Sandal:" << endl;
    cetakBaris(32);
    cout << "No | Nama         | Harga  | Stok" << endl;
    cetakBaris(32);
    
    for (int i = 0; i < jumlahSandal; i++) {
        cout << i+1 << "  | " 
             << daftarSandal[i].nama << "    | " 
             << daftarSandal[i].harga << "  | " 
             << daftarSandal[i].stok << endl;
    }
}

void tambahSandal(Sandal daftarSandal[], int &jumlahSandal) {
    if (jumlahSandal < 5) {
        cout << "\nTambah Sandal:" << endl;
        cout << "Nama sandal: ";
        cin.ignore();
        getline(cin, daftarSandal[jumlahSandal].nama);
        cout << "Harga: ";
        cin >> daftarSandal[jumlahSandal].harga;
        cout << "Stok: ";
        cin >> daftarSandal[jumlahSandal].stok;
        jumlahSandal++;
        cout << "Sandal berhasil ditambahkan!" << endl;
    } else {
        cout << "Maaf, kapasitas sandal sudah penuh!" << endl;
    }
}

void editSandal(Sandal daftarSandal[], int jumlahSandal) {
    int nomorEdit;
    cout << "\nEdit Sandal:" << endl;
    cout << "Masukkan nomor sandal yang akan diedit (1-" << jumlahSandal << "): ";
    cin >> nomorEdit;
    
    if (nomorEdit < 1 || nomorEdit > jumlahSandal) {
        cout << "Nomor sandal tidak valid!" << endl;
    } else {
        cout << "Edit sandal " << daftarSandal[nomorEdit-1].nama << endl;
        cout << "Nama baru: ";
        cin.ignore();
        getline(cin, daftarSandal[nomorEdit-1].nama);
        cout << "Harga baru: ";
        cin >> daftarSandal[nomorEdit-1].harga;
        cout << "Stok baru: ";
        cin >> daftarSandal[nomorEdit-1].stok;
        cout << "Sandal berhasil diupdate!" << endl;
    }
}

void hapusSandal(Sandal daftarSandal[], int &jumlahSandal) {
    int nomorHapus;
    cout << "\nHapus Sandal:" << endl;
    cout << "Masukkan nomor sandal yang akan dihapus (1-" << jumlahSandal << "): ";
    cin >> nomorHapus;
    
    if (nomorHapus < 1 || nomorHapus > jumlahSandal) {
        cout << "Nomor sandal tidak valid!" << endl;
    } else {
        cout << "Anda yakin ingin menghapus sandal " << daftarSandal[nomorHapus-1].nama << "? (y/n): ";
        char konfirmasi;
        cin >> konfirmasi;
        
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            for (int i = nomorHapus-1; i < jumlahSandal-1; i++) {
                daftarSandal[i] = daftarSandal[i+1];
            }
            jumlahSandal--;
            cout << "Sandal berhasil dihapus!" << endl;
        } else {
            cout << "Penghapusan dibatalkan." << endl;
        }
    }
}

void beliSandal(Sandal daftarSandal[], int jumlahSandal) {
    int nomorSandal, jumlahBeli;
    cout << "\nBeli Sandal:" << endl;
    cout << "Nomor sandal yang dibeli (1-" << jumlahSandal << "): ";
    cin >> nomorSandal;
    
    if (nomorSandal < 1 || nomorSandal > jumlahSandal) {
        cout << "Nomor sandal tidak valid!" << endl;
    }
    else {
        cout << "Jumlah yang dibeli: ";
        cin >> jumlahBeli;
        
        if (jumlahBeli <= 0) {
            cout << "Jumlah tidak valid!" << endl;
        }
        else if (jumlahBeli > daftarSandal[nomorSandal-1].stok) {
            cout << "Stok tidak cukup!" << endl;
        }
        else {
            daftarSandal[nomorSandal-1].stok -= jumlahBeli;
            
            int total;
            if (jumlahBeli > 3) {
                total = hitungTotalBelanja(daftarSandal[nomorSandal-1].harga, jumlahBeli, 0.1);
                cout << "Berhasil membeli " << jumlahBeli << " " 
                     << daftarSandal[nomorSandal-1].nama << endl;
                cout << "Total harga setelah diskon 10%: Rp " << total << endl;
            } else {
                total = hitungTotalBelanja(daftarSandal[nomorSandal-1].harga, jumlahBeli);
                cout << "Berhasil membeli " << jumlahBeli << " " 
                     << daftarSandal[nomorSandal-1].nama << endl;
                cout << "Total harga: Rp " << total << endl;
            }
        }
    }
}

void menuAdmin(Sandal daftarSandal[], int &jumlahSandal, bool &sudahLogin) {
    int menuLogin;
    do {
        cout << "\n----- MENU ADMIN -----" << endl;
        cout << "1. Lihat Daftar Sandal" << endl;
        cout << "2. Tambah Sandal" << endl;
        cout << "3. Edit Sandal" << endl;
        cout << "4. Hapus Sandal" << endl;
        cout << "5. Update Stok (Address-of)" << endl;
        cout << "6. Lihat Detail Sandal (Dereference)" << endl;
        cout << "7. Logout" << endl;
        cout << "Pilihan: ";
        cin >> menuLogin;
        
        switch (menuLogin) {
            case 1:
                tampilkanDaftarSandal(daftarSandal, jumlahSandal);
                break;
            case 2:
                tambahSandal(daftarSandal, jumlahSandal);
                break;
            case 3:
                editSandal(daftarSandal, jumlahSandal);
                break;
            case 4:
                hapusSandal(daftarSandal, jumlahSandal);
                break;
            case 5: {
                int nomorSandal, stokBaru;
                tampilkanDaftarSandal(daftarSandal, jumlahSandal);
                cout << "Pilih nomor sandal yang akan diupdate stoknya (1-" << jumlahSandal << "): ";
                cin >> nomorSandal;
                
                if (nomorSandal < 1 || nomorSandal > jumlahSandal) {
                    cout << "Nomor sandal tidak valid!" << endl;
                } else {
                    cout << "Masukkan jumlah stok baru: ";
                    cin >> stokBaru;
                    
                    if (stokBaru < 0) {
                        cout << "Stok tidak boleh negatif!" << endl;
                    } else {
                        updateStokSandal(daftarSandal[nomorSandal-1], stokBaru);
                    }
                }
                break;
            }
            case 6: {
                int nomorSandal;
                tampilkanDaftarSandal(daftarSandal, jumlahSandal);
                cout << "Pilih nomor sandal untuk melihat detail (1-" << jumlahSandal << "): ";
                cin >> nomorSandal;
                
                if (nomorSandal < 1 || nomorSandal > jumlahSandal) {
                    cout << "Nomor sandal tidak valid!" << endl;
                } else {
                    lihatDetailSandal(&daftarSandal[nomorSandal-1]);
                }
                break;
            }
            case 7:
                sudahLogin = false;
                cout << "Berhasil logout!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (sudahLogin && menuLogin != 7);
}

void menuPembeli(Sandal daftarSandal[], int jumlahSandal, bool &sudahLogin) {
    int menuLogin;
    do {
        cout << "\n----- MENU PEMBELI -----" << endl;
        cout << "1. Lihat Daftar Sandal" << endl;
        cout << "2. Beli Sandal" << endl;
        cout << "3. Lihat Detail Sandal (Dereference)" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilihan: ";
        cin >> menuLogin;
        
        switch (menuLogin) {
            case 1:
                tampilkanDaftarSandal(daftarSandal, jumlahSandal);
                break;
            case 2:
                beliSandal(daftarSandal, jumlahSandal);
                break;
            case 3: {
                int nomorSandal;
                tampilkanDaftarSandal(daftarSandal, jumlahSandal);
                cout << "Pilih nomor sandal untuk melihat detail (1-" << jumlahSandal << "): ";
                cin >> nomorSandal;
                
                if (nomorSandal < 1 || nomorSandal > jumlahSandal) {
                    cout << "Nomor sandal tidak valid!" << endl;
                } else {
                    lihatDetailSandal(&daftarSandal[nomorSandal-1]);
                }
                break;
            }
            case 4:
                sudahLogin = false;
                cout << "Berhasil logout!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (sudahLogin && menuLogin != 4);
}

// Main
int main() {
    Sandal daftarSandal[5] = {
        {"Sandal Jepit", 20000, 10},
        {"Sandal Gunung", 50000, 5},
        {"Sandal Kulit", 75000, 8},
        {"Sandal Rumah", 30000, 15},
        {"Sandal Sport", 60000, 7}
    };
    
    Pengguna daftarPengguna[5];
    daftarPengguna[0] = {"MarshaAuliaFakhriza", "2409106116", "admin"}; 
    
    int jumlahPengguna = 1;
    int jumlahSandal = 5;
    
    bool sudahLogin = false;
    string usernameSaatIni, roleSaatIni;
    
    int pilihan;
    
    do {
        cout << "\n===== SISTEM PENJUALAN SANDAL =====" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            sudahLogin = login(daftarPengguna, jumlahPengguna, usernameSaatIni, roleSaatIni);
            
            if (sudahLogin) {
                cout << "Login berhasil sebagai " << roleSaatIni << "!" << endl;
                
                if (roleSaatIni == "admin") {
                    menuAdmin(daftarSandal, jumlahSandal, sudahLogin);
                } else if (roleSaatIni == "pembeli") {
                    menuPembeli(daftarSandal, jumlahSandal, sudahLogin);
                }
            }
        }
        else if (pilihan == 2) {
            daftar(daftarPengguna, jumlahPengguna);
        }
        else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
        
    } while (pilihan != 3);
    
    return 0;
}