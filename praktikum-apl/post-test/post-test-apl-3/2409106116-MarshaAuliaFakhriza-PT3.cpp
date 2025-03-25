//
//  main.cpp
//  posttest2
//
//  Created by marsha aufa on 17/03/25.
//


#include <iostream>
#include <string>

using namespace std;

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
            int percobaanLogin = 0;
            bool loginBerhasil = false;
            
            while (percobaanLogin < 3 && !loginBerhasil) {
                string username, password;
                cout << "\n----- LOGIN (Percobaan " << percobaanLogin + 1 << "/3) -----" << endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                
                for (int i = 0; i < jumlahPengguna; i++) {
                    if (username == daftarPengguna[i].username && password == daftarPengguna[i].password) {
                        sudahLogin = true;
                        usernameSaatIni = daftarPengguna[i].username;
                        roleSaatIni = daftarPengguna[i].role;
                        loginBerhasil = true;
                        break;
                    }
                }
                
                if (loginBerhasil) {
                    cout << "Login berhasil sebagai " << roleSaatIni << "!" << endl;
                } else {
                    percobaanLogin++;
                    if (percobaanLogin < 3) {
                        cout << "Login gagal! Username atau password salah." << endl;
                    } else {
                        cout << "Anda telah gagal login 3 kali. Kembali ke menu utama." << endl;
                    }
                }
            }
            
            if (sudahLogin) {
                int menuLogin;
                do {
                    cout << "\n----- MENU " << roleSaatIni << " -----" << endl;
                    
                    if (roleSaatIni == "admin") {
                        cout << "1. Lihat Daftar Sandal" << endl;
                        cout << "2. Tambah Sandal" << endl;
                        cout << "3. Edit Sandal" << endl;
                        cout << "4. Hapus Sandal" << endl;
                        cout << "5. Logout" << endl;
                        cout << "Pilihan: ";
                        cin >> menuLogin;
                        
                        if (menuLogin == 1) {
                            cout << "\nDaftar Sandal:" << endl;
                            cout << "--------------------------------" << endl;
                            cout << "No | Nama         | Harga  | Stok" << endl;
                            cout << "--------------------------------" << endl;
                            
                            for (int i = 0; i < jumlahSandal; i++) {
                                cout << i+1 << "  | " 
                                     << daftarSandal[i].nama << "    | " 
                                     << daftarSandal[i].harga << "  | " 
                                     << daftarSandal[i].stok << endl;
                            }
                        }
                        else if (menuLogin == 2) {
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
                        else if (menuLogin == 3) {
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
                        else if (menuLogin == 4) {
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
                        else if (menuLogin == 5) {
                            sudahLogin = false;
                            cout << "Berhasil logout!" << endl;
                        }
                        else {
                            cout << "Pilihan tidak valid!" << endl;
                        }
                    }
                    else if (roleSaatIni == "pembeli") {
                        cout << "1. Lihat Daftar Sandal" << endl;
                        cout << "2. Beli Sandal" << endl;
                        cout << "3. Logout" << endl;
                        cout << "Pilihan: ";
                        cin >> menuLogin;
                        
                        if (menuLogin == 1) {
                            cout << "\nDaftar Sandal:" << endl;
                            cout << "--------------------------------" << endl;
                            cout << "No | Nama         | Harga  | Stok" << endl;
                            cout << "--------------------------------" << endl;
                            
                            for (int i = 0; i < jumlahSandal; i++) {
                                cout << i+1 << "  | " 
                                     << daftarSandal[i].nama << "    | " 
                                     << daftarSandal[i].harga << "  | " 
                                     << daftarSandal[i].stok << endl;
                            }
                        }
                        else if (menuLogin == 2) {
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
                                    int total = daftarSandal[nomorSandal-1].harga * jumlahBeli;
                                    
                                    cout << "Berhasil membeli " << jumlahBeli << " " 
                                         << daftarSandal[nomorSandal-1].nama << endl;
                                    cout << "Total harga: Rp " << total << endl;
                                }
                            }
                        }
                        else if (menuLogin == 3) {
                            sudahLogin = false;
                            cout << "Berhasil logout!" << endl;
                        }
                        else {
                            cout << "Pilihan tidak valid!" << endl;
                        }
                    }
                    
                } while (sudahLogin && ((roleSaatIni == "admin" && menuLogin != 5) || (roleSaatIni == "pembeli" && menuLogin != 3)));
            }
        }
        else if (pilihan == 2) {
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
        else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
        
    } while (pilihan != 3);
    
    return 0;
}
