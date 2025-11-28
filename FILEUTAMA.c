#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ------------------------------
// TEMPAT MENYIMPAN BELANJAAN
// ------------------------------
char namaBarang[100][100];
int hargaBarang[100];
int jumlahBarang = 0;

void tambahBelanja(const char *nama, int harga){
    strcpy(namaBarang[jumlahBarang], nama);
    hargaBarang[jumlahBarang] = harga;
    jumlahBarang++;
}

void cetakStruk(){
    printf("\n===== STRUK PEMBELIAN =====\n");

    int total = 0;
    for(int i = 0; i < jumlahBarang; i++){
        printf("%d. %s - Rp %d\n", i+1, namaBarang[i], hargaBarang[i]);
        total += hargaBarang[i];
    }

    printf("----------------------------\n");
    printf("TOTAL HARGA: Rp %d\n", total);
    printf("===== TERIMA KASIH =====\n");
    exit(0);
}
// ------------------------------



int tampilkanMenu(){
    int pilihanbesar;
    printf("=== Menu Utama ===\n");
    printf("1. Kulkas\n");
    printf("2. Mesin Cuci\n");
    printf("3. AC\n");
    printf("4. TV\n");
    printf("5. Kompor Listrik\n");
    printf("6. Keluar\n");
    printf("Masukkan pilihan Anda (1-6): ");
    scanf("%d", &pilihanbesar);
    return pilihanbesar;
}

int SubKulkas(){
    char pilihan;
    printf("Berikut pilihan kulkas yang dapat anda pilih:\n");
    printf("Jenis Kulkas:\n"
        "a. Kulkas 1 Pintu\n"
        "b. Kulkas 2 Pintu\n"
        "c. Kulkas Side by Side\n"
        "d. Kulkas French Door\n"
        "e. Kulkas Mini\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 3000000;
        printf("Harga Kulkas 1 Pintu: %d\n", harga);
        tambahBelanja("Kulkas 1 Pintu", harga);

    } else if(pilihan == 'b' ){
        harga = 5000000;
        printf("Harga Kulkas 2 Pintu: %d\n", harga);
        tambahBelanja("Kulkas 2 Pintu", harga);

    } else if(pilihan == 'c'){
        harga = 8000000;
        printf("Harga Kulkas Side by Side: %d\n", harga);
        tambahBelanja("Kulkas Side by Side", harga);

    } else if(pilihan == 'd'){
        harga = 12000000;   
        printf("Harga Kulkas French Door: %d\n", harga);
        tambahBelanja("Kulkas French Door", harga);

    } else if(pilihan == 'e'){
        harga = 150000;
        printf("Harga Kulkas Mini: %d\n", harga);
        tambahBelanja("Kulkas Mini", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubKulkas();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan kulkas lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubKulkas();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int SubCuci(){
    char pilihan;
    printf("Berikut pilihan mesin cuci yang dapat anda pilih:\n");
    printf("Jenis Mesin Cuci:\n"
            "a. Mesin Cuci Top Loading\n"
            "b. Mesin Cuci Front Loading\n"
            "c. Mesin Cuci Semi Automatic\n"
            "d. Mesin Cuci Portable\n"
            "e. Mesin Cuci Twin Tub\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 2500000;
        printf("Harga Mesin Cuci Top Loading: %d\n", harga);
        tambahBelanja("Mesin Cuci Top Loading", harga);

    } else if(pilihan == 'b'){
        harga = 4000000;
        printf("Harga Mesin Cuci Front Loading: %d\n", harga);
        tambahBelanja("Mesin Cuci Front Loading", harga);

    } else if(pilihan == 'c'){
        harga = 1500000;
        printf("Harga Mesin Cuci Semi Automatic: %d\n", harga);
        tambahBelanja("Mesin Cuci Semi Automatic", harga);

    } else if(pilihan == 'd'){
        harga = 1000000;   
        printf("Harga Mesin Cuci Portable: %d\n", harga);
        tambahBelanja("Mesin Cuci Portable", harga);

    } else if(pilihan == 'e'){
        harga = 1800000;
        printf("Harga Mesin Cuci Twin Tub: %d\n", harga);
        tambahBelanja("Mesin Cuci Twin Tub", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubCuci();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan mesin cuci lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubCuci();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int SubAc(){
    char pilihan;
    int harga;
    printf("Berikut pilihan AC yang dapat anda pilih:\n");
    printf("Jenis AC:\n"
            "a. AC Split\n"
            "b. AC Window\n"
            "c. AC Portable\n"
            "d. AC Central\n"
            "e. AC Ducted\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);

    if(pilihan == 'a'){
        harga = 3500000;
        printf("Harga AC Split: %d\n", harga);
        tambahBelanja("AC Split", harga);

    } else if(pilihan == 'b'){
        harga = 2500000;
        printf("Harga AC Window: %d\n", harga);
        tambahBelanja("AC Window", harga);

    } else if(pilihan == 'c'){
        harga = 3000000;
        printf("Harga AC Portable: %d\n", harga);
        tambahBelanja("AC Portable", harga);

    } else if(pilihan == 'd'){
        harga = 15000000;   
        printf("Harga AC Central: %d\n", harga);
        tambahBelanja("AC Central", harga);

    } else if(pilihan == 'e'){
        harga = 12000000;
        printf("Harga AC Ducted: %d\n", harga);
        tambahBelanja("AC Ducted", harga);


    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubAc();
    }
    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan AC lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubAc();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return 1;
}

int SubTV(){

    char pilihan;
    int harga;
    printf("Berikut pilihan TV yang dapat anda pilih:\n");
    printf("Jenis TV:\n"
            "a. LED TV\n"
            "b. OLED TV\n"
            "c. QLED TV\n"
            "d. Smart TV\n"
            "e. 4K TV\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);

    if(pilihan == 'a'){
        harga = 4000000;
        printf("Harga LED TV: %d\n", harga);
        tambahBelanja("LED TV", harga);

    } else if(pilihan == 'b'){
        harga = 10000000;
        printf("Harga OLED TV: %d\n", harga);
        tambahBelanja("OLED TV", harga);

    } else if(pilihan == 'c'){
        harga = 8000000;
        printf("Harga QLED TV: %d\n", harga);
        tambahBelanja("QLED TV", harga);

    } else if(pilihan == 'd'){
        harga = 6000000;   
        printf("Harga Smart TV: %d\n", harga);
        tambahBelanja("Smart TV", harga);

    } else if(pilihan == 'e'){
        harga = 12000000;
        printf("Harga 4K TV: %d\n", harga);
        tambahBelanja("4K TV", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubTV();
    }
    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan TV lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubTV();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

}

int SubKompor(){
    char pilihan;
    int harga;
    printf("Berikut pilihan Kompor Listrik yang dapat anda pilih:\n");
    printf("Jenis Kompor Listrik:\n"
           "a. Kompor Induksi\n"
           "b. Kompor Halogen\n"
           "c. Kompor Keramik\n"
           "d. Kompor Listrik Portable\n"
           "e. Kompor Listrik Tanam\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik K untuk pesan Kompor Listrik lagi\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);

    if(pilihan == 'a'){
        harga = 2000000;
        printf("Harga Kompor Induksi: %d\n", harga);
        tambahBelanja("Kompor Induksi", harga);

    } else if(pilihan == 'b'){
        harga = 1500000;
        printf("Harga Kompor Halogen: %d\n", harga);
        tambahBelanja("Kompor Halogen", harga);

    } else if(pilihan == 'c'){
        harga = 1800000;
        printf("Harga Kompor Keramik: %d\n", harga);
        tambahBelanja("Kompor Keramik", harga);

    } else if(pilihan == 'd'){
        harga = 1000000;   
        printf("Harga Kompor Listrik Portable: %d\n", harga);
        tambahBelanja("Kompor Portable", harga);

    } else if(pilihan == 'e'){
        harga = 2500000;
        printf("Harga Kompor Listrik Tanam: %d\n", harga);
        tambahBelanja("Kompor Listrik Tanam", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubKompor();
    }
    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan Kompor Listrik lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubKompor();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }
}

int main(){
    int pilihanbesar = tampilkanMenu();

    switch(pilihanbesar){
        case 1: SubKulkas(); break;
        case 2: SubCuci(); break;
        case 3: SubAc(); break;
        case 4: SubTV(); break;
        case 5: SubKompor(); break;
        case 6: cetakStruk(); break;

        default:
            printf("Pilihan tidak valid.\n");
    }

    return 0;
}
