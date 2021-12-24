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
    
    
    //main menu
    int pilihan = 0;
    char menu;
    
    create_list(RS);

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
                delete_ruangan(RS);
                break;
            case 3:
                //[3] Tambah Pasien *ini harus tau ke ruang mana
                add_N_pasien(RS);
                break;
            case 4:
                //[4] Proses Pasien 
                /* code */
                break;
            case 5:
                //[5] Cari Dokter berdasarkan spesialisasi
                /* code */
                break;
            case 6:
                //[6] Cari Pasien berdasarkan umur
                /* code */
                break;
            case 7:
                //[7] Jumlah Semua Pasien saat ini
                /* code */
                break;
            case 8:
                //[8] Show Data Ruangan Tertentu 
                /* code */
                break;
            case 9:
                //[9] Show Data Keseluruhan RS
                /* code */
            case 0:
                //[0] EXIT
                break;
            default:
                break;
        }
        cout << "\n Kembali ke menu utama (Y/N) : ";
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
