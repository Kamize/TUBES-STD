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

void create_list(mll &RS){
    /*
    IS : -
    FS : membuat list kosong.
    */
    first(RS) = NIL;
}

ruangan data_ruangan(string dokter, string spesialisasi, string waktu){
    /*
    IS : menerima data string nama dokter,spesialisasi, dan waktu kerja.
    FS : mengembalikan data dalam bentuk structure ruangan.
    */
    ruangan data;
    data.dokter = dokter;
    data.waktu = waktu;
    return data;
}

adr_ruangan newElm_ruangan(ruangan info){
    /*
    IS : menerima data ruangan.
    FS : mengembalikan pointer elemen ruangan baru. 
    */
    adr_ruangan R = new ruangan;
    info(R) = info;
    next(R) = NIL;
    nextPasien(R) = NIL;
    prev(R) = NIL;
    return R;
}

pasien data_pasien(string nama, string idPasien, string keluhan, int umur){
    /*
    IS : menerima data string nama, idPasien, keluhan, dan integer umur.
    FS : mengembalikan data dalam bentuk structure pasien.
    */
    pasien data;
    data.nama = nama;
    data.idPasien = idPasien;
    data.keluhan = keluhan;
    data.umur = umur;
    return pasien;
}

adr_pasien newElm_pasien(pasien info){
    /*
    IS : menerima data pasien.
    FS : mengembalikan pointer elemen pasien baru.
    */
    adr_pasien P = new adr_pasien;
    info(P) = info;
    next(P) = NIL;
    return P;
}

void insertLast_ruangan(mll &RS, adr_ruangan R){
    /*
    IS : menerima list yang mung kosong dan pointer elemen ruangan baru.
    FS : mengembalikan list dengan elemen ruangan yang telah dimasukkan di akhir list.
    */
    if (first(RS)==NIL){
        first(RS) = R;
    } else {
        adr_ruangan Q = first(RS);
        while(next(Q) != NIL) {
            Q = next(Q);
        }
        next(Q) = R;
    }
}

void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P){
    /*
    IS : menerima list yang mungkin kosong, pointer ruangan, dan pointer elemen pasien baru.
    FS : mengembalikan list dengan ruangan yang telah ditambahkan elemen pasien di akhir (ENQUEUE).
    */
    adr_pasien Q;
    if (first(RS) != NIL){
        if (nextPasien(R) == NIL){
            nextPasien(R) = P;
            head(Q) = P;
            tail(Q) = P;
        } else {
            next(tail(Q)) = P;
            tail(Q) = P;
        }
    }
}

void proses_pasien(mll &RS, adr_ruangan R, adr_pasien P){
    /*
    IS : menerima list yang mungkin kosong, pointer ruangan dan pointer elemen pasien.
    FS : mengembalikan list dengan pasien ruangan yang telah diproses (DEQUEUE).
    */
}

void add_N_ruangan(mll &RS){
    /*
    IS : menerima list dan input nilai jumlah data (N) yang ingin diinputkan berupa integer.
    FS : list yang telah berisi N data ruangan.
    */
    ruangan ruang;
    adr_ruangan R;
    int N;
    int i = 1;
    cout << "Banyak data ruangan yang ingin dimasukkan : ";
    cin >> N;
    while (i < (N+1)) {
        cout << "\n\n===== Data Ruangan no. " << i << "=====";
        cout << "\nNama Dokter \t: ";
        cin >> ruang.dokter;
        cout << "\nSpesialisasi \t: "; 
        cin >> ruang.spesialisasi;
        cout << "\nWaktu Kerja\t: ";
        cin >> ruang.waktu;
        insertLast_ruangan(RS, newElm_ruangan(ruang));
        i++;
    }
    cout << endl;
}

void add_N_pasien(mll &RS){
    /*
    IS : menerima list dan input nilai jumlah data (N) yang ingin diinputkan berupa integer.
    FS : list dengan elemen ruangan yang telah berisi N data pasien.
    */
    //tanya dulu mau disimpen di ruang mana pasiennya
}

void deleteFirst_ruangan(mll &RS, adr_ruangan R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan list yang telah didelete datanya di bagian awal.
    */
}

void deleteLast_ruangan(mll &RS, adr_ruangan R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan list yang telah didelete datanya di bagian akhir.
    */
}

void deleteAfter_ruangan(mll &RS, adr_ruangan R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan list yang telah didelete setelah ruangan tertentu.
    */
}

void delete_ruangan(mll &RS){
    /*
    IS : menerima list yang mungkin kosong.
    FS : delete data berdasarkan inputan user.
    */
    // ketentuan : dokter umum tidak bisa dihapus
}

void showData_RS(mll RS){
    /*
    IS : menerima list yang mungkin kosong.
    FS : menampilkan semua data di dalam rumah sakit.
    */
    adr_ruangan R = first(RS);
    int i = 1;
    if (R != NIL){
        while (R != NIL){
            cout << "\n===== Ruangan " << i <<" =====";
            cout << "\nNama Dokter \t: " << info(R).dokter;
            cout << "\nSpesialisasi \t: " << info(R).spesialisasi;
            cout << "\nWaktu Kerja \t: " << info(R).waktu;
            cout << "\n===== Jumlah Pasien : " << jumlah_pasienRuangan(RS) << " =====";
            adr_pasien P = nextPasien(P);
            int j = 1;
            if (P != NIL) {
                while (P != NIL) {
                    cout << "\n PASIEN ANTRIAN KE-" << j;
                    cout << "\n Nama Pasien \t:" << info(P).nama;
                    cout << "\n ID \t\t:" << info(P).idPasien;
                    cout << "\n Keluhan \t\t:" << info(P).keluhan;
                    cout << "\n Umur \t\t:" << info(P).umur;
                    P = next(P);
                    j++;
                }
            } else {
                cout << "\nTidak ada antrian pasien" << endl;
            }
            R = next(R);
            i++;
        }
    } else {
        cout << "\nData Rumah Sakit Kosong" << endl;
    }
}

adr_ruangan search_ruangan(mll RS, string spesialisasi){
    /*
    IS : menerima list yang mungkin kosong dan spesialisasi.
    FS : mengembalikan pointer yang menunjukkan ruangan berdasarkan spesialisasi.
    */
}

adr_pasien search_pasien(mll RS, int umur){
    /*
    IS : menerima list yang mungkin kosong dan umur pasien.
    FS : mengembalikan pointer yang menunjukkan data pasien berdasarkan umur.
    */
}

int jumlah_pasienRuangan(mll RS){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan nilai jumlah pasien dalam suatu ruangan.
    */
    
}

int jumlah_semuaPasien(mll RS){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan nilai jumlah pasien.
    */
    
}

int selectMenu(){
    /*
    IS : menampilkan menu kepada user.
    FS : meminta input integer kepada user.
    */
    cout <<"\n============ RUMAH SAKIT ABCDEF ============";
    cout <<"\n=================== Menu ===================";
    cout <<"\n [1] Tambah data ruangan";
    cout <<"\n [2] Hapus ruangan";
    cout <<"\n [3] Tambah data pasien";
    cout <<"\n [4] Proses pasien";
    cout <<"\n [5] Cari dokter berdasarkan spesialisasi";
    cout <<"\n [6] Cari Pasien berdasarkan umur";
    cout <<"\n [7] Jumlah semua pasien saat ini";
    cout <<"\n [8] Show Data Ruangan";
    cout <<"\n [9] Show All Data";
    cout <<"\n [0] EXIT ";
    cout <<"\n============================================";
    cout << "\n Select Menu : ";
    int input = 0;
    cin >> input;
    return input;
}