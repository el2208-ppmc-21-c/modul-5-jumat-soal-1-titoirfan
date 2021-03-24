/*  EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul            : 5
*   Percobaan        : -
*   Hari dan Tanggal : -
*   Nama (NIM)       : - 
*   Asisten (NIM)    : -
*   Nama File        : -
*   Deskripsi        : 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Masukkan variabel global di sini

// Fungsi isPrivateAddr (WAJIB DIPAKAI)
int isPrivateAddr(...., ....)
{

    // Implementasi Fungsi Anda (anda dapat mengubah isi basis dan rekurens)

    // Basis
    if (....)
    {
        return ....;
    }

    // Rekurens
    else
    {
        return isPrivateAddr(...., strlen(....));
    }
}

int main()
{
    // Inisialisasi variabel lokal fungsi utama

    // Input user
    printf("Masukkan Alamat IP yang ingin diperiksa: ");
    scanf(...., ....);

    // Catatan: fungsi isPrivateAddr memiliki return value
    isPrivateAddr(...., strlen(....));

    // Jika IP valid
    printf("Alamat IP %s adalah alamat IP private.", ....);

    // Jika IP tidak valid
    printf("Alamat IP %s bukan alamat IP private.", ....);

    return 0;
}
