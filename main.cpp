#include "rumahsakit.h"

/*
=====================
KELOMPOK 4
===== Anggota-1 =====
Name    : Talitha Nabila
NIM     : 1301204516
===== Anggota-2 =====
Name    : Shidqi Fadhlurrahman Yusri
NIM     : 1301204256
=====================
*/

int main(){
    //list & data
    mll RS;
    ListChild PAS;
    
    //main menu
    int pilihan = 0;
    char menu;
    
    //input
    string namaDokter, namaPasien, spesialisasi;
    adr_pasien P;
    
    //create list
    create_list(RS);
    create_list_child(PAS);

    /* add contoh data disini pake hardcode :
        1. RUANGAN
        insertLast_ruangan(RS, newElm_ruangan(data_ruangan(dokter,spesialisasi,waktu)))
        2. PASIEN
        insertNew_pasien(RS, R, newElm_pasien(data_pasien(nama,idPasien,keluhan,umur)))
    */

    pilihan = selectMenu();
    while (pilihan != 0){
        switch (pilihan){
            case 1:
                //[1] Tambah Ruangan
                add_N_ruangan(RS);
                break;
            case 2:
                //[2] Hapus Ruangan (Dokter Umum gk bisa di delete)
                cout << "\nMasukkan nama dokter yang akan dihapus : ";
                cin >> namaDokter;
                delete_ruangan(RS,namaDokter);
                break;
            case 3:
                //[3] Tambah Pasien *ini harus tau ke ruang mana
                add_N_pasien(RS, PAS);
                break;
            case 4:
                //[4] Proses Pasien 
                cout << "\nMasukkan spesialisasi dokter untuk proses pasien : ";
                cin >> spesialisasi;
                proses_pasien(RS, search_ruangan(RS, spesialisasi),P);
                break;
            case 5:
                //[5] Cari Dokter berdasarkan spesialisasi
                cout << "\nMasukkan spesialisasi dokter : ";
                cin >> spesialisasi;
                search_ruangan(RS, spesialisasi);
                break;
            case 6:
                //[6] Cari Pasien berdasarkan nama
                cout <<  "\nMasukkan nama pasien : ";
                cin >> namaPasien;
                if (search_pasien(PAS, namaPasien) == NIL){
                    cout << "\nPasien Tidak ditemukan";
                } else {
                    cout << "\nPasien ditemukan";
                }
                break;
            case 7:
                //[7] Jumlah Semua Pasien saat ini
                cout << "\nTotal jumlah semua Pasien saat ini adalah " << jumlah_semuaPasien(RS) << " pasien";
                break;
            case 8:
                //[8] Show Data Ruangan
                showData_Dokter(RS);
                break;
            case 9:
                //[9] Show Data Keseluruhan RS
                showData_RS(RS);
                break;
            case 0:
                //[0] EXIT
                break;
            default:
                break;
        }
        cout << "\nKembali ke menu utama (Y/N) : ";
        cin >> menu;
        if (menu == 'Y'){
            //CLEAR SCREEN
            system("cls");
            pilihan = selectMenu();
        } else {
            //EXIT
            pilihan = 0;
        }
    }
    cout << "\n\nAnda Telah Keluar dari Menu\n\n";
    return 0;
}
