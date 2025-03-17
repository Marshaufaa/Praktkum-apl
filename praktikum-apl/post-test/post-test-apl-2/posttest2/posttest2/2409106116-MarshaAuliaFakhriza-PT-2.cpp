//
//  main.cpp
//  posttest2
//
//  Created by marsha aufa on 17/03/25.
//


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string sandal[5] = {"Sandal Jepit", "Sandal Gunung", "Sandal Kulit", "Sandal Rumah", "Sandal Sport"};
    int harga[5] = {20000, 50000, 75000, 30000, 60000};
    int stok[5] = {10, 5, 8, 15, 7};

    int pilihan;
    do {
        int totalHarga = 0;

        cout << "\n=== MENU TRANSAKSI ===" << endl;
        cout << "1. Lihat Daftar Sandal" << endl;
        cout << "2. Beli Sandal" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\n=== DAFTAR SANDAL ===" << endl;
            cout << left << setw(5) << "No" << setw(15) << "Nama" << setw(10) << "Harga" << setw(10) << "Stok" << endl;
            cout << "-----------------------------------------" << endl;
            
            for (int i = 0; i < 5; i++) {
                cout << left << setw(5) << i + 1 << setw(15) << sandal[i] << "Rp " << setw(8) << harga[i] << setw(10) << stok[i] << endl;
            }
        }
        else if (pilihan == 2) {
            char beliLagi;
            do {
                int nomor, jumlah;
                
                cout << "\n=== PILIH SANDAL ===" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << i + 1 << ". " << sandal[i] << " - Rp " << harga[i] << " (Stok: " << stok[i] << ")" << endl;
                }

                cout << "Pilih nomor sandal: ";
                cin >> nomor;
                nomor--;

                if (nomor < 0 || nomor >= 5) {
                    cout << "Nomor tidak valid!" << endl;
                    continue;
                }

                cout << "Masukkan jumlah yang ingin dibeli: ";
                cin >> jumlah;

                if (jumlah <= 0 || jumlah > stok[nomor]) {
                    cout << "Jumlah tidak valid atau stok tidak mencukupi!" << endl;
                    continue;
                }

                totalHarga += harga[nomor] * jumlah;
                stok[nomor] -= jumlah;

                cout << "Sandal " << sandal[nomor] << " sebanyak " << jumlah << " berhasil ditambahkan ke transaksi." << endl;

                cout << "Ingin membeli sandal lagi? (y/n): ";
                cin >> beliLagi;

            } while (beliLagi == 'y' || beliLagi == 'Y');

            cout << "\n=== TOTAL TRANSAKSI ===" << endl;
            cout << "Total yang harus dibayar: Rp " << totalHarga << endl;
            cout << "=========================" << endl;
        }
        else if (pilihan == 3) {
            cout << "Terima kasih telah berbelanja!" << endl;
        }
        else {
            cout << "Pilihan tidak valid! Silakan pilih lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
