#ifndef RUMAHSAKIT_H_INCLUDED
#define RUMAHSAKIT_H_INCLUDED
#include <iostream>
#include <stdlib.h>

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

using namespace std;

#define info(P) (P) -> info
#define next(P) (P) -> next
#define prev(P) (P) -> prev
#define nextPasien(P) (P) -> nextPasien
#define first(L) ((L).first)
#define head(L) (L) -> head
#define tail(L) (L) -> tail
#define NIL NULL

// [PARENT] DLL untuk dokter spesialis
typedef struct rumahSakit *adr_ruangan;

struct ruangan{
    string dokter, spesialisasi, waktu;
};

struct rumahSakit{
    ruangan info;
    adr_ruangan next, prev;
    adr_pasien nextPasien, head, tail;
};

struct mll{
    adr_ruangan first;
};

// [CHILD] SLL / Queue untuk pasien
typedef struct antrian *adr_pasien;

struct pasien {
    string nama, idPasien, keluhan;
    int umur;
};

struct antrian {
    pasien info;
    adr_pasien next, head, tail;
};

//contract function [INSERT DATA] / CREATE
void create_list(mll &RS);
ruangan data_ruangan(string dokter, string spesialisasi, string waktu);
adr_ruangan newElm_RumahSakit(ruangan info);
pasien data_pasien(string nama, string idPasien, string keluhan, int umur);
adr_pasien newElm_pasien(pasien info);
void insertLast_ruangan(mll &RS, adr_ruangan R);


//ENQUEUE
void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P);

//DEQUEUE
void proses_pasien(mll &RS, adr_ruangan R, adr_pasien P);

//INPUT N DATA
void add_N_ruangan(mll &RS);
void add_N_pasien(mll &RS); //tanyain di ruangan mana dulu

//DELETE
void deleteFirst_ruangan(mll &RS, adr_ruangan R);
void deleteLast_ruangan(mll &RS, adr_ruangan R);
void deleteAfter_ruangan(mll &RS, adr_ruangan R);
void delete_ruangan(mll &RS);

//SHOW
void showData_RS(mll RS);

//SEARCH
adr_ruangan search_ruangan(mll RS, string spesialisasi);
adr_pasien search_pasien(mll RS, int umur);

//HITUNG JUMLAH
int jumlah_pasienRuangan(mll RS);
int jumlah_semuaPasien(mll RS);

//MENU
int selectMenu();

#endif // RUMAHSAKIT_H_INCLUDED
