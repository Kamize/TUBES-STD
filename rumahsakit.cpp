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
    last(RS) = NIL;
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

adr_ruangan newElm_RumahSakit(ruangan info){
    /*
    IS : menerima data ruangan.
    FS : mengembalikan pointer elemen ruangan baru. 
    */
    adr_ruangan R = new rumahSakit;
    info(R) = info;
    next(R) = NIL;
    prev(R) = NIL;
    nextPasien(R) = NIL;
    tail(R) = NIL;
    return R;
}

pasien data_pasien(string nama, int idPasien, string keluhan, int umur){
    /*
    IS : menerima data string nama, idPasien, keluhan, dan integer umur.
    FS : mengembalikan data dalam bentuk structure pasien.
    */
    pasien data;
    data.nama = nama;
    data.idPasien = idPasien;
    data.keluhan = keluhan;
    data.umur = umur;
    return data;
}

adr_pasien newElm_pasien(pasien info){
    /*
    IS : menerima data pasien.
    FS : mengembalikan pointer elemen pasien baru.
    */
    adr_pasien P = new antrian;
    info(P) = info;
    next(P) = NIL;
    return P;
}

void insertLast_ruangan(mll &RS, adr_ruangan R){
    /*
    IS : menerima list yang mung kosong dan pointer elemen ruangan baru.
    FS : mengembalikan list dengan elemen ruangan yang telah dimasukkan di akhir list.
    */
    if (first(RS) == NIL){
        first(RS) = R;
    } else {
        next(last(RS)) = R;
        prev(R) = last(RS);
    }
}

void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P){
    /*
    IS : menerima list yang mungkin kosong, pointer ruangan, dan pointer elemen pasien baru.
    FS : mengembalikan list dengan ruangan yang telah ditambahkan elemen pasien di akhir (ENQUEUE).
    */
    if (first(RS) != NIL){
        if (nextPasien(R) == NIL){
            nextPasien(R) = P;
            tail(R) = P;
        } else {
            next(tail(R)) = P;
            tail(R) = P;
        }
    }
}

void proses_pasien(mll &RS, adr_ruangan R, adr_pasien &P){
    /*
    IS : menerima list yang mungkin kosong, pointer ruangan dan pointer elemen pasien.
    FS : mengembalikan list dengan pasien ruangan yang telah diproses (DEQUEUE).
    */
    if (next(nextPasien(R)) == NIL) {
        P = nextPasien(R);
        nextPasien(R) = NIL;
        tail(R) = NIL;
    } else {
        P = nextPasien(R);
        nextPasien(R) = next(P);
        next(P) = NIL;
    }
}

void add_N_ruangan(mll &RS){
    /*
    IS : menerima list dan input nilai jumlah data (N) yang ingin diinputkan berupa integer.
    FS : list yang telah berisi N data ruangan.
    */
    ruangan ruang;
    adr_ruangan R;
    int N, spesialisasi;
    int i = 1;
    cout << "Banyak data ruangan yang ingin dimasukkan : ";
    cin >> N;
    while (i < (N+1)) {
        cout << "\n\n===== Data Ruangan no. " << i << "=====";
        cout << "\nNama Dokter \t: ";
        getline(cin, ruang.dokter);
        cout << "\nSpesialisasi \t: ";
        cout << "\t [1] Dokter Umum" << endl;
        cout << "\t [2] Dokter Gigi" << endl;
        cout << "\t [3] Dokter Anak" << endl;
        cout << "\t [4] Dokter THT" << endl;
        cin >> spesialisasi;
        switch (spesialisasi)
        {
        case 1:
            ruang.spesialisasi = "Dokter Umum";
            break;
        case 2:
            ruang.spesialisasi = "Dokter Gigi";
            break;
        case 3:
            ruang.spesialisasi = "Dokter Anak";
            break;
        case 4:
            ruang.spesialisasi = "Dokter THT";
            break;
        default:
            cout << "Inputan tidak sesuai, spesialisasi dijadikan Umum" << endl;
            ruang.spesialisasi = "Dokter Umum";
            break;
        }
        cout << "\nWaktu Kerja\t: ";
        getline(cin, ruang.waktu);
        insertLast_ruangan(RS, newElm_RumahSakit(ruang));
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
    adr_ruangan R;
    adr_pasien P;
    string dokter;
    pasien pas;
    int n;

    cout << "Masukkan banyaknya inputan : ";
    cin >> n;
    cout << "Masukkan Data Pasien : " << endl;
    for (int i = 1; i < n+1; i++) {
        cout << "ID Pasien";
        cin >> pas.idPasien;
        cout << "Nama : ";
        cin >> pas.nama;
        cout << "Umur : ";
        cin >> pas.umur;
        cout << "Keluhan : ";
        cin >> pas.keluhan;
        P = newElm_pasien(pas);
        showData_Dokter(RS);
        cout << "Spesialisasi Dokter yang di inginkan : ";
        cin >> dokter;
        R = search_ruangan(RS, dokter);
        insertNew_pasien(RS, R, P);
    }

}

void deleteFirst_ruangan(mll &RS, adr_ruangan &R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan list yang telah didelete datanya di bagian awal.
    */
    if (next(first(RS)) == NIL) { // Jika di list hanya 1 ruangan
        R = first(RS);
        first(RS) = NIL;
        last(RS) = NIL;
    } else {
        R = first(RS);
        first(RS) = next(R);
        next(R) = NIL;
        prev(first(RS)) = NIL;
    }
}

void deleteLast_ruangan(mll &RS, adr_ruangan &R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan list yang telah didelete datanya di bagian akhir.
    */
    R = last(RS);
    last(RS) = prev(R);
    prev(R) = NIL;
    next(last(RS)) = NIL;
}

void deleteAfter_ruangan(mll &RS, adr_ruangan prec, adr_ruangan &R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan list yang telah didelete setelah ruangan tertentu.
    */
    R = next(prec);
    next(prec) = next(R);
    prev(next(R)) = prec;
    prev(R) = NIL;
    next(R) = NIL;
}

void delete_ruangan(mll &RS, string dokter){
    /*
    IS : menerima list yang mungkin kosong.
    FS : delete data berdasarkan inputan user.
    */
    // ketentuan : dokter umum tidak bisa dihapus
    adr_ruangan S, R, U;
    adr_pasien P;
    U = first(RS);
    while (U != NIL) {
        if (info(U).spesialisasi == "Dokter Umum") {
            break;
        }
        U = next(U);
    }
    S = first(RS);
    while (S != NIL) {
        if (info(S).dokter == dokter) {
            if (info(S).spesialisasi != "Dokter Umum") {
                if (nextPasien(S) != NIL) {
                    while (nextPasien(S) != NIL) {
                        proses_pasien(RS, S, P);
                        insertNew_pasien(RS, U, P);
                    }
                    break;
                }
            } else {
                cout << "Dokter Umum tidak dapat dihapus!" << endl;
                break;
            }
        }
        S = next(S);
    }
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
            cout << "\n===== Jumlah Pasien : " << jumlah_pasienRuangan(RS, R) << " =====";
            adr_pasien P = nextPasien(R);
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

void showData_Dokter(mll RS) {
    adr_ruangan R;
    R = first(RS);
    int i = 1;
    if (first(RS) != NIL) {
        while (R != NIL) {
            cout << "\n===== Ruangan " << i <<" =====";
            cout << "\nNama Dokter \t: " << info(R).dokter;
            cout << "\nSpesialisasi \t: " << info(R).spesialisasi;
            cout << "\nWaktu Kerja \t: " << info(R).waktu;
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
    adr_ruangan R;
    R = first(RS);
    while (R != NIL) {
        if (info(R).spesialisasi == spesialisasi) {
            return R;
        }
        R = next(R);
    }
    return NIL;
}

adr_pasien search_pasien(mll RS, int umur){
    /*
    IS : menerima list yang mungkin kosong dan umur pasien.
    FS : mengembalikan pointer yang menunjukkan data pasien berdasarkan umur.
    */
}

int jumlah_pasienRuangan(mll RS, adr_ruangan R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan nilai jumlah pasien dalam suatu ruangan.
    */
    adr_pasien P;
    int jumlah = 0;
    P = nextPasien(R);
    while (P != NIL) {
        jumlah++;
        P = next(P);
    }
    return jumlah;
}

int jumlah_semuaPasien(mll RS){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan nilai jumlah pasien.
    */
    adr_ruangan R;
    adr_pasien P;
    int jumlah = 0;
    R = first(RS);
    while (R != NIL) {
        P = nextPasien(R);
        while (P != NIL) {
            jumlah++;
            P = next(P);
        }
        R = next(R);
    }
    return jumlah;
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