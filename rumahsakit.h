#ifndef RUMAHSAKIT_H_INCLUDED
#define RUMAHSAKIT_H_INCLUDED
#include <iostream>
#include <stdlib.h>

/*
Name : Talitha Nabila
NIM : 1301204516
*/

using namespace std;

#define info(P) (P) -> info
#define next(P) (P) -> next
#define nextPasien(P) (P) -> nextPasien
#define first(L) ((L).first)
#define head(L) ((L).head)
#define tail(L) ((L).tail)
#define NIL NULL

// [PARENT] DLL untuk dokter spesialis
typedef struct rumahSakit *adr_ruangan;

struct ruangan{
    string dokter, spesialisasi, waktu;
};

struct rumahSakit{
    ruangan info;
    adr_ruangan next, prev;
    adr_pasien nextPasien;
};

struct mll{
    adr_ruangan first;
}

// [CHILD] SLL / Queue untuk pasien
typedef struct antrian *adr_pasien;

struct pasien {
    string nama, idPasien, keluhan;
    int umur;
};

struct antrian {
    pasien info;
    adr_pasien next,head,tail;
};

//contract function [INSERT DATA] / CREATE
void create_list(mll &RS);
ruangan data_ruangan(string dokter, string spesialisasi, string waktu);
adr_ruangan newElm_ruangan(ruangan info);
pasien data_pasien(string nama, string idPasien, string keluhan, int umur);
adr_pasien newElm_pasien(pasien info);
void insertLast_ruangan(mll &RS, adr_ruangan R);

//ENQUEUE
void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P);

//DEQUEUE
void proses_pasien(mll &RS, adr_ruangan R, adr_pasien P);

//DELETE
void deleteFirst_ruangan(mll &RS, adr_ruangan R);
void deleteLast_ruangan(mll &RS, adr_ruangan R);
void deleteAfter_ruangan(mll &RS, adr_ruangan R);
void delete_ruangan(mll &RS);

//SHOW
void showData_RS(mll RS);

//SEARCH
adr_pasien search_pasien(mll RS, string nama_pasien);

#endif // RUMAHSAKIT_H_INCLUDED
