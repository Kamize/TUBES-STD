#include "rumahsakit.h"

void create_list(mll &RS){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
    first(RS) = NIL;
}

ruangan data_ruangan(string dokter, string spesialisasi, string waktu){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
    ruangan data;
    data.dokter = dokter;
    data.spesialisasi = spesialisasi;
    data.waktu = waktu;
    return data;
}

adr_ruangan newElm_ruangan(ruangan info){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
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
    Name : Talitha Nabila
    NIM : 1301204516
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
    Name : Talitha Nabila
    NIM : 1301204516
    */
    adr_pasien P = new adr_pasien;
    info(P) = info;
    next(P) = NIL;
    return P;
}

void insertLast_ruangan(mll &RS, adr_ruangan R){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void proses_pasien(mll &RS, adr_ruangan R, adr_pasien P){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void deleteFirst_ruangan(mll &RS, adr_ruangan R){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void deleteLast_ruangan(mll &RS, adr_ruangan R){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void deleteAfter_ruangan(mll &RS, adr_ruangan R){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void delete_ruangan(mll &RS){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

void showData_RS(mll RS){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}

adr_pasien search_pasien(mll RS, string nama_pasien){
    /*
    Name : Talitha Nabila
    NIM : 1301204516
    */
}