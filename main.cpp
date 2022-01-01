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
    adr_ruangan R;
    
    //create list
    create_list(RS);
    create_list_child(PAS);

    /* add contoh data disini pake hardcode :
        1. RUANGAN
        insertLast_ruangan(RS, newElm_ruangan(data_ruangan(dokter,spesialisasi,waktu)))
        2. PASIEN
        insertNew_pasien(RS, R, newElm_pasien(data_pasien(nama,idPasien,keluhan,umur)))
    */

    //INSERT RUANGAN
    insertLast_ruangan(RS, newElm_RumahSakit(data_ruangan("Dhaifa","Dokter Gigi","08:00-16:00")));
    insertLast_ruangan(RS, newElm_RumahSakit(data_ruangan("Nanditya","Dokter Umum","08:00-16:00")));
    
    //INSERT PASIEN
    P = newElm_pasien(data_pasien("Henry",123456,"DBD",16));
    insertLast_pasien(PAS, P);
    insertNew_pasien(RS, search_ruangan(RS,"Dokter Umum"), P);

    P = newElm_pasien(data_pasien("Betty",123467,"Sakit gigi",20));
    insertLast_pasien(PAS, P);
    insertNew_pasien(RS, search_ruangan(RS,"Dokter Gigi"), P);

    P = newElm_pasien(data_pasien("Andra",123458,"Sesak napas",54));
    insertLast_pasien(PAS, P);
    insertNew_pasien(RS, search_ruangan(RS,"Dokter Umum"), P);
    
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
                spesialisasi = selectSpesialisasi();
                proses_pasien(RS, search_ruangan(RS, spesialisasi),P);
                break;
            case 5:
                //[5] Cari Dokter berdasarkan spesialisasi
                cout << "\nMasukkan spesialisasi dokter : ";
                spesialisasi = selectSpesialisasi();
                // scanf("%*[^\n]\n", spesialisasi);
                // getline(cin, spesialisasi);
                // cin >> spesialisasi;
                
                if (search_ruangan(RS, spesialisasi) == NIL){
                    cout << "\nDokter Tidak ditemukan";
                } else {
                    cout << "\nDokter ditemukan";
                    R = search_ruangan(RS, spesialisasi);
                    cout << "\n===== Data Dokter =====";
                    cout << "\nNama Dokter \t: " << info(R).dokter;
                    cout << "\nSpesialisasi \t: " << info(R).spesialisasi;
                    cout << "\nWaktu Kerja \t: " << info(R).waktu;
                }
                break;
            case 6:
                //[6] Cari Pasien berdasarkan nama
                cout <<  "\nMasukkan nama pasien : ";
                cin >> namaPasien;
                if (search_pasien(PAS, namaPasien) == NIL){
                    cout << "\nPasien Tidak ditemukan";
                } else {
                    cout << "\nPasien ditemukan";
                    P = search_pasien(PAS, namaPasien);
                    cout << "\n======== Data Pasien ========";
                    cout << "\nNama pasien \t: " << info(P).nama;
                    cout << "\nID pasien \t: " << info(P).idPasien;
                    cout << "\nKeluhan pasien \t: " << info(P).keluhan;
                    cout << "\nUmur pasien \t: " << info(P).umur;
                }
                break;
            case 7:
                //[7] Jumlah Semua Pasien saat ini
                cout << "\nTotal jumlah semua Pasien saat ini adalah " << jumlah_semuaPasien(RS) << " pasien";
                break;
            case 8:
                //[8] Show Data Ruangan
                showData_Dokter(RS);
                showData_Pasien(PAS);
                break;
            case 9:
                //[9] Show Data Keseluruhan RS
                showData_RS(RS);
                break;
            default:
                break;
        }
        cout << "\n\nKembali ke menu utama (Y/N) : ";
        cin >> menu;
        if (menu == 'Y' || menu == 'y'){
            //CLEAR SCREEN
            // system("cls");
            pilihan = selectMenu();
        } else {
            //EXIT
            pilihan = 0;
        }
    }
    cout << "\n\nAnda Telah Keluar dari Menu\n\n";
    return 0;
}
