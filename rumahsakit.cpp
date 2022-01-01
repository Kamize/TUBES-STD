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

void create_list_child(ListChild &PAS) {
    /*
    IS : -
    FS : membuat list kosong.
    */
    first(PAS) = NIL;
}

ruangan data_ruangan(string dokter, string spesialisasi, string waktu){
    /*
    IS : menerima data string nama dokter,spesialisasi, dan waktu kerja.
    FS : mengembalikan data dalam bentuk structure ruangan.
    */
    ruangan data;
    data.dokter = dokter;
    data.spesialisasi = spesialisasi;
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
    nextAntrian(R) = NIL;
    return R;
}

infoPasien data_pasien(string nama, int idPasien, string keluhan, int umur){
    /*
    IS : menerima data string nama, idPasien, keluhan, dan integer umur.
    FS : mengembalikan data dalam bentuk structure pasien.
    */
    infoPasien data;
    data.nama = nama;
    data.idPasien = idPasien;
    data.keluhan = keluhan;
    data.umur = umur;
    return data;
}

adr_pasien newElm_pasien(infoPasien info){
    /*
    IS : menerima data pasien.
    FS : mengembalikan pointer elemen pasien baru.
    */
    adr_pasien P = new elmPasien;
    info(P) = info;
    next(P) = NIL;
    return P;
}

adr_antrian newElm_antrian() {
    /*
    IS : -
    FS : mengembalikan pointer elemen baru. 
    */
    adr_antrian P;

    P = new list_antrian;
    next(P) = NIL;
    pasien(P) = NIL;
    return P;
}

void insertLast_ruangan(mll &RS, adr_ruangan R){
    /*
    IS : menerima list yang mungkin kosong dan pointer elemen ruangan baru.
    FS : mengembalikan list dengan elemen ruangan yang telah dimasukkan di akhir list.
    */
    if (first(RS) == NIL){
        first(RS) = R;
        last(RS) = R;
    } else {
        next(last(RS)) = R;
        prev(R) = last(RS);
        last(RS) = R;
    }
}

void insertLast_pasien(ListChild &PAS, adr_pasien P) {
    /*
    IS : menerima list yang mungkin kosong dan pointer elemen ruangan baru.
    FS : mengembalikan list dengan elemen pasien yang telah dimasukkan di akhir list child.
    */
    if (first(PAS) == NIL) {
        first(PAS) = P;
    } else {
        adr_pasien Q;
        Q = first(PAS);
        while (next(Q) != NIL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P){
    /*
    IS : menerima list yang mungkin kosong, pointer ruangan, dan pointer elemen pasien baru.
    FS : mengembalikan list dengan ruangan yang telah ditambahkan elemen pasien di akhir (ENQUEUE).
    */
    adr_antrian A, S;

    S = newElm_antrian();

    A = nextAntrian(R);
    if (A == NIL){
        A = S;
        pasien(S) = P;
    } else {
        while (next(A) != NIL) {
            A = next(A);
        }
        next(A) = S;
        pasien(S) = P;
    }
}

void proses_pasien(mll &RS, adr_ruangan R, adr_pasien &P){
    /*
    IS : menerima list yang mungkin kosong, pointer ruangan dan pointer elemen pasien.
    FS : mengembalikan list dengan pasien ruangan yang telah diproses (DEQUEUE).
    */
    adr_antrian A, S;

    S = nextAntrian(R);
    A = next(S);
    nextAntrian(R) = A;
    next(S) = NIL;
    P = pasien(S);
    pasien(S) = NIL;
    
}

void add_N_ruangan(mll &RS){
    /*
    IS : menerima list dan input nilai jumlah data (N) yang ingin diinputkan berupa integer.
    FS : list yang telah berisi N data ruangan.
    */
    ruangan ruang;
    adr_ruangan R;
    int N;
    cout << "Banyak data ruangan yang ingin dimasukkan : ";
    cin >> N;
    int i = 1;
    while (i < (N+1)) {
        cout << endl << "\n===== Data Ruangan no. " << i << "=====";
        cout << "\nNama Dokter \t: ";
        cin >> ruang.dokter;
        ruang.spesialisasi = selectSpesialisasi();
        cout <<"\nWaktu Kerja\t: ";
        cin >> ruang.waktu;
        insertLast_ruangan(RS, newElm_RumahSakit(ruang));
        i++;
    }
    cout << endl;
}

void add_N_pasien(mll &RS, ListChild &PAS){
    /*
    IS : menerima list dan input nilai jumlah data (N) yang ingin diinputkan berupa integer.
    FS : list dengan elemen ruangan yang telah berisi N data pasien.
    */
    
    adr_ruangan R;
    adr_pasien P;
    adr_antrian S;
    string dokter;
    infoPasien pas;
    int N;

    cout << "\nMasukkan banyaknya inputan : ";
    cin >> N;
    int i = 1;
    while (i < N+1) {
        cout << endl << "\n=== Masukkan Data Pasien " << i << " ===";
        cout << "\nID Pasien \t:";
        cin >> pas.idPasien;
        cout << "\nNama \t: ";
        cin >> pas.nama;
        cout << "\nUmur \t: ";
        cin >> pas.umur;
        cout << "\nKeluhan \t: ";
        cin >> pas.keluhan;
        P = newElm_pasien(pas);
        showData_Dokter(RS);
        cout << "\nSpesialisasi Dokter yang diinginkan : ";
        dokter = selectSpesialisasi();
        R = search_ruangan(RS, dokter);
        cout << "1234567" <<endl;
        //ERROR HANDLING
        if (R == NIL){
            cout << "\n. . . Spesialisasi Dokter tidak ditemukan.";
            cout << "\nData pasien " << i << " gagal diinput.";
        } else {
            cout << "1234567" <<endl;
            insertLast_pasien(PAS, P);
            cout << "1234567" <<endl;
            insertNew_pasien(RS, R, P);
            cout << "1234567" <<endl;
            cout << "\nData pasien " << i << " berhasil diinput";
        }
        i++;
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
    adr_antrian A, B;
    adr_pasien P;

    U = search_ruangan(RS, "Dokter Umum");

    S = first(RS);
    while (S != NIL) {
        if (info(S).dokter == dokter) {
            if (info(S).spesialisasi != "Dokter Umum") {
                if (nextAntrian(S) != NIL) {
                    A = nextAntrian(S);
                    while (A != NIL) {
                        proses_pasien(RS, S, P);
                        insertNew_pasien(RS, U, P);
                        A = next(A);
                    }
                    break;
                }
            } else {
                cout << "\nDokter Umum tidak dapat dihapus!" << endl;
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
            adr_antrian P = nextAntrian(R);
            int j = 1;
            if (P != NIL) {
                while (P != NIL) {
                    cout << "\n PASIEN ANTRIAN KE-" << j;
                    cout << "\n Nama Pasien \t:" << info(pasien(P)).nama;
                    cout << "\n ID \t\t:" << info(pasien(P)).idPasien;
                    cout << "\n Keluhan \t\t:" << info(pasien(P)).keluhan;
                    cout << "\n Umur \t\t:" << info(pasien(P)).umur;
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
            R = next(R);
            i++;
        }
        cout << "\n\n============================= ";
    } else {
        cout << "\nData Rumah Sakit Kosong" << endl;
    }
}

void showData_Pasien(ListChild PAS){
    /*
    IS : menerima list yang mungkin kosong.
    FS : menampilkan list child.
    */
    adr_pasien P = first(PAS);
    int i = 1;
    if (P != NIL){
        while (P != NIL) {
            cout << "\nPasien " << i ;
            cout << "\nNama pasien \t: " << info(P).nama;
            cout << "\nID pasien \t: " << info(P).idPasien;
            cout << "\nKeluhan pasien \t: " << info(P).keluhan;
            cout << "\nUmur pasien \t: " << info(P).umur;
            P = next(P);
            i++;
        }
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

adr_pasien search_pasien(ListChild PAS, string nama){
    /*
    IS : menerima list yang mungkin kosong dan nama pasien.
    FS : mengembalikan pointer yang menunjukkan data pasien berdasarkan nama.
    */

    adr_pasien P;
    P = first(PAS);
    while (P != NIL) {
        if (info(P).nama == nama) {
            return P;
        }
        P = next(P);
    }
    return NIL;
}

int jumlah_pasienRuangan(mll RS, adr_ruangan R){
    /*
    IS : menerima list yang mungkin kosong.
    FS : mengembalikan nilai jumlah pasien dalam suatu ruangan.
    */
    adr_antrian P;
    int jumlah = 0;
    P = nextAntrian(R);
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
    int jumlah = 0;
    R = first(RS);
    while (R != NIL) {
        jumlah = jumlah + jumlah_pasienRuangan(RS, R);
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
    cout <<"\n [2] Hapus ruangan berdasarkan nama dokter";
    cout <<"\n [3] Tambah data pasien";
    cout <<"\n [4] Proses pasien";
    cout <<"\n [5] Cari dokter berdasarkan spesialisasi";
    cout <<"\n [6] Cari Pasien berdasarkan nama";
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

string selectSpesialisasi(){
    cout << "\n [1] Dokter Umum";
    cout << "\n [2] Dokter Gigi";
    cout << "\n [3] Dokter Anak";
    cout << "\n [4] Dokter THT";
    cout << "\n Spesialisasi \t: ";
    int input;
    cin >> input;
    switch (input)
        {
        case 1:
            return "Dokter Umum";
            break;
        case 2:
            return "Dokter Gigi";
            break;
        case 3:
            return "Dokter Anak";
            break;
        case 4:
            return "Dokter THT";
            break;
        default:
            cout << "Inputan tidak sesuai, spesialisasi dijadikan Umum" << endl;
            return "Dokter Umum";
            break;
        }
}