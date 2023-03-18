#ifndef PEMBIMBING_H_INCLUDED
#define PEMBIMBING_H_INCLUDED

#include <iostream>

using namespace std;
#define next(p) p->next
#define prev(p) p->prev
#define nama(p) p->nama
#define bobot(p) p->bobot
#define pointerDosen(p) p->pointerDosen
#define pointerMahasiswa(p) p->pointerMahasiswa
#define first(L) (L).first
#define last(L) (L).last
#define nil NULL

typedef struct mahasiswa *adrM;

struct mahasiswa{
	string nama;
	int bobot;
	adrM next;
};

typedef struct dosen *adrD;

struct dosen{
	string nama;
	int bobot;
	adrD next;
};

typedef struct relasi *adrR;

struct relasi{
	adrR next;
	adrR prev;
	adrM pointerMahasiswa;
	adrD pointerDosen;
};

struct listMahasiswa{
	adrM first;
	adrM last;
};

struct listDosen{
	adrD first;
	adrD last;
};

struct listRelasi{
	adrR first;
	adrR last;
};

void createListMahasiswa(listMahasiswa &L);
void createListDosen(listDosen &L);
void createListRelasi(listRelasi &L);
adrM alokasiMahasiswa(string nama, int bobot);
adrD alokasiDosen(string nama, int bobot);
adrR alokasiRelasi(adrM pointerMahasiswa, adrD pointerDosen);
void insertFirstMahasiswa(listMahasiswa &L, adrM p);
void insertFirstDosen(listDosen &L, adrD p);
void insertFirstRelasi(listRelasi &L, adrR p);
adrM findMahasiswa(listMahasiswa L, string nama);
adrD findDosen(listDosen L, string nama);
void showBimbinganDosen(listDosen LD, listMahasiswa LM, listRelasi LR, string nama);
void deleteDosenandRelasi(listDosen &LD, listRelasi &LR, string nama, adrD &pc);
void disconnectRelasi(listRelasi &LR, listDosen LD, listMahasiswa LM, string namaDosen, string namaMahasiswa);
void showAll(listDosen LD, listMahasiswa LM, listRelasi LR);
void showBimbinganDosen(listDosen LD, listMahasiswa LM, listRelasi LR, string nama);
void showMostBimbingan(listDosen LD, listMahasiswa LM, listRelasi LR);
void showBimbinganTunggal(listDosen LD, listMahasiswa LM, listRelasi LR);
int menu();
#endif // PEMBIMBING_H_INCLUDED
