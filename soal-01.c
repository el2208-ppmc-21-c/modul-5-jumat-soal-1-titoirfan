/*  EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul            : 5
*   Percobaan        : -
*   Hari dan Tanggal : -
*   Nama (NIM)       : - 
*   Asisten (NIM)    : Andhika Rahadian (13218030)
*   Nama File        : -
*   Deskripsi        : Memvalidasi IP menggunakan konsep rekursi
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Inisialisasi Variabel Global
int octets[4];
int j = 0;

int isTitikExist(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            return 1;
        }
    }
    return 0;
}

int isPrivateAddr(char IPaddr[16], int len_IPaddr)
{

    int i = 0;
    int k = 0;

    // initialize parsedTemp setiap kali dipanggil
    char parsedTemp[3];
    for (k = 0; k < 3; k++)
    {
        parsedTemp[k] = '\0';
    }

    // Simpan Octet IP satu persatu ke octets
    while (IPaddr[i] != '.' && IPaddr[i] != '\0')
    {
        parsedTemp[i] = IPaddr[i];
        i++;
    }
    octets[j] = atoi(parsedTemp);
    j++;

    // Inisiasi ipTemp untuk menyimpan IP rekurens
    char ipTemp[16];

    // Fungsi Basis
    if (!isTitikExist(IPaddr))
    {
        // Memeriksa apakah IP valid dengan melihat tabel soal
        if (octets[0] == 10)
        {
            return 1;
        }
        else if (octets[0] == 192 && octets[1] == 168)
        {
            return 1;
        }
        else if (octets[0] == 172 && (octets[1] > 15 && octets[1] < 32))
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    // Rekurens
    else
    {
        /* Menyiapkan alamat IP rekurens untuk kebutuhan rekursif
           Misal IP 12.233.100.50 akan menjadi IP rekurensnya 233.100.50, dst sampai tidak ada komponen titik
        */
        for (k = i + 1; k < strlen(IPaddr); k++)
        {
            ipTemp[k - i - 1] = IPaddr[k];
        }

        // copy IP rekurens ke IPaddr
        strcpy(IPaddr, ipTemp);

        return isPrivateAddr(IPaddr, strlen(IPaddr));
    }
}
int main()
{
    char IPv4[16], IPv4_temp[16];

    // User memasukkan input alamat IP
    printf("Masukkan Alamat IP yang ingin diperiksa: ");
    scanf("%s", IPv4);

    // Untuk kebutuhan display output, karena variabel IPv4 akan dinamis pada fungsi rekursi
    strcpy(IPv4_temp, IPv4);

    // Jika IP valid retval = 1
    int retval = isPrivateAddr(IPv4, strlen(IPv4));

    // Cetak Output
    if (retval)
    {
        printf("Alamat IP %s adalah alamat IP private.", IPv4_temp);
    }
    else
    {
        printf("Alamat IP %s bukan alamat IP private.", IPv4_temp);
    }
    return 0;
}
