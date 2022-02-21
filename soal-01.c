/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : -
*Hari dan Tanggal : Selasa, 22 Januari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 200

char encryptedText[MAX_STRING];
char plainText[MAX_STRING];
char key[MAX_STRING];

/*
    Deskripsi fungsi: mengambil data pesan terenskripsi dan key dan menyimpannya pada variabel encryptedText dan key
*/
void getData(){
    // Deklarasi pointer file
    FILE *filePointer ;
     
    // Deklarasi variabel
    char filename[MAX_STRING];
    char buffer[MAX_STRING];

    // Input nama file
    printf("Masukkan nama file: ");
    scanf("%s", filename);
 
    // Membuka file untuk dibaca
    filePointer = fopen(filename, "r") ;
     
    // Mengecek apakah file kosong atau tidak
    if ( filePointer == NULL )
    {
        // Apabila file kosong
        printf( "File gagal dibuka." ) ;
    }
    else
    {
        // Apabila file berisi data
        // Mengambil data key
        fgets (encryptedText, MAX_STRING, filePointer);

        fgets (key, MAX_STRING, filePointer); 

        // Menutup file
        fclose(filePointer);
    }

    return;
}

/*
    Deskripsi fungsi: mendekripsi pesan dan menyimpannya pada variabel plainText
*/
void xorDecrypt(char encrypt[MAX_STRING], char key[MAX_STRING]){
    int i = 0;
    int lenKey;
    lenKey = strlen(key);

    while(encryptedText[i] != '\0' && encryptedText[i] != '\n'){
        plainText[i] = encryptedText[i] ^ key[i%lenKey];
        i++;
    }


    plainText[i] = '\0';

    return;
}

int main(){
    getData();

    xorDecrypt(encryptedText, key);

    printf("%s", plainText);
    return 0;
}
