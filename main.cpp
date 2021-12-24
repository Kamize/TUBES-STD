#include "rumahsakit.h"

int main(){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */

    //list & data
    mll RS;
    
    
    //main menu
    int pilihan = 0;
    char menu;
    
    create_list(RS);
    pilihan = selectMenu();
    while (pilihan != 0){
        switch (pilihan){
            case 1:
                //[1] Tambah Ruangan
                /* code */
                break;
            case 2:
                //[2] Hapus Ruangan (Dokter Umum gk bisa di delete)
                /* code */
                break;
            case 3:
                //[3] Tambah Pasien *ini harus tau ke ruang mana
                /* code */
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
                //[7] Jumlah Pasien saat ini
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
