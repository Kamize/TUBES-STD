#ifndef RUMAHSAKIT_H_INCLUDED
#define RUMAHSAKIT_H_INCLUDED
#include <iostream>
#include <string>

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
#define pasien(P) (P) -> pasien
#define nextAntrian(P) (P) -> nextAntrian
#define first(L) ((L).first)
#define last(L) ((L).last)
#define tail(L) (L) -> tail
#define NIL NULL

// [PARENT] DLL untuk dokter spesialis
typedef struct rumahSakit *adr_ruangan;
typedef struct list_antrian *adr_antrian;

struct ruangan{
    string dokter, spesialisasi, waktu;
};

struct rumahSakit{
    ruangan info;
    adr_ruangan next, prev;
    adr_antrian nextAntrian;
};

struct mll{
    adr_ruangan first, last;
};

// [CHILD] SLL / Queue untuk pasien
typedef struct elmPasien *adr_pasien;

struct infoPasien {
    string nama, keluhan;
    int umur, idPasien;
};

struct elmPasien {
    infoPasien info;
    adr_pasien next;
};

struct ListChild
{
    adr_pasien first;
};

struct list_antrian
{
    adr_pasien pasien;
    adr_antrian next;
};

// info(pasien(P)).

//contract function [INSERT DATA] / CREATE
void create_list(mll &RS);
void create_list_child(ListChild &PAS);
ruangan data_ruangan(string dokter, string spesialisasi, string waktu);
adr_ruangan newElm_RumahSakit(ruangan info);
infoPasien data_pasien(string nama, int idPasien, string keluhan, int umur);
adr_pasien newElm_pasien(infoPasien info);
adr_antrian newElm_antrian();
void insertLast_ruangan(mll &RS, adr_ruangan R);
void insertLast_pasien(ListChild &PAS, adr_pasien P);


//ENQUEUE
void insertNew_pasien(mll &RS, adr_ruangan R, adr_pasien P);

//DEQUEUE
void proses_pasien(mll &RS, adr_ruangan R, adr_pasien &P);

//INPUT N DATA
void add_N_ruangan(mll &RS);
void add_N_pasien(mll &RS, ListChild &PAS); //tanyain di ruangan mana dulu

//DELETE
void deleteFirst_ruangan(mll &RS, adr_ruangan &R);
void deleteLast_ruangan(mll &RS, adr_ruangan &R);
void deleteAfter_ruangan(mll &RS, adr_ruangan prec, adr_ruangan &R);
void delete_ruangan(mll &RS, string dokter);

//SHOW
void showData_RS(mll RS);
void showData_Dokter(mll RS);
void showData_Pasien(ListChild PAS);

//SEARCH
adr_ruangan search_ruangan(mll RS, string spesialisasi);
adr_pasien search_pasien(ListChild PAS, string nama);

//HITUNG JUMLAH
int jumlah_pasienRuangan(mll RS, adr_ruangan R);
int jumlah_semuaPasien(mll RS);

//MENU
int selectMenu();
string selectSpesialisasi();

#endif // RUMAHSAKIT_H_INCLUDED
