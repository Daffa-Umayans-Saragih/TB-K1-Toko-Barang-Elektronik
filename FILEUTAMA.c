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
    printf("6. Lampu LED\n");
    printf("7. Kipas Angin Mini\n");
    printf("8. Senter LED\n");
    printf("9. Stop Kontak\n");
    printf("10. Speaker Portable\n");
    printf("11. SmartWatch\n");
    printf("12. Drone\n");
    printf("13. Tablet\n");
    printf("14. Monitor\n");
    printf("15. Wireless Earphone\n");
    printf("16. Laptop\n");
    printf("17. HandPhone\n");
    printf("18. blender\n");
    printf("19. Rice COoker\n");
    printf("20. Power Bank\n");
    printf("21. Cetak Struk\n");

    
    printf("Masukkan pilihan Anda (1-11): ");
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
    pilihan = tolower(pilihan);
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
    pilihan = tolower(pilihan);

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
    pilihan = tolower(pilihan);

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
    pilihan = tolower(pilihan);

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
    pilihan = tolower(pilihan);

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
        else {
            printf("Pilihan tidak valid.\n");
            main();
        }
    }
}

int SubLampu(){
    char pilihan;
    int harga;
    printf("Berikut pilihan Lampu LED yang dapat anda pilih:\n");
    printf("Jenis Lampu LED:\n"
           "a. Lampu LED 5 watt\n"
           "b. Lampu LED 8 watt\n"
           "c. Lampu LED 10 watt\n"
           "d. Lampu LED 15 watt\n"
           "e. Lampu LED 20 watt\n");
    printf("Masukkan pilihan Anda (a-e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);

    if(pilihan == 'a'){
        harga = 8000;
        printf("Harga Lampu LED 5 watt: %d\n", harga);
        tambahBelanja("Lampu LED 5 watt", harga);

    } else if(pilihan == 'b'){
        harga = 12000;
        printf("Harga Lampu LED 8 watt: %d\n", harga);
        tambahBelanja("Lampu LED 8 watt", harga);

    } else if(pilihan == 'c'){
        harga = 15000;
        printf("Harga Lampu LED 10 watt: %d\n", harga);
        tambahBelanja("Lampu LED 10 watt", harga);

    } else if(pilihan == 'd'){
        harga = 20000;   
        printf("Harga Lampu LED 15 watt: %d\n", harga);
        tambahBelanja("Lampu LED 15 watt", harga);

    } else if(pilihan == 'e'){
        harga = 24000;
        printf("Harga Lampu LED 20 watt: %d\n", harga);
        tambahBelanja("Lampu LED 20 watt", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    } else {
        printf("Pilihan tidak valid.\n");
        SubLampu();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan Lampu LED lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubLampu();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return 1;
}

int SubKipas(){
    char pilihan;
    int harga;
    printf("Berikut pilihan Kipas Angin Mini USB yang dapat anda pilih:\n");
    printf("Jenis Kipas:\n"
           "a. Kipas mini 3 watt\n"
           "b. Kipas mini 5 watt\n"
           "c. Kipas mini portable\n"
           "d. Kipas lipat mini\n"
           "e. Kipas mini stand\n");
    printf("Masukkan pilihan Anda (a-e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);

    if(pilihan == 'a'){
        harga = 15000;
        printf("Harga Kipas mini 3 watt: %d\n", harga);
        tambahBelanja("Kipas mini 3 watt", harga);

    } else if(pilihan == 'b'){
        harga = 20000;
        printf("Harga Kipas mini 5 watt: %d\n", harga);
        tambahBelanja("Kipas mini 5 watt", harga);

    } else if(pilihan == 'c'){
        harga = 25000;
        printf("Harga Kipas mini portable: %d\n", harga);
        tambahBelanja("Kipas mini portable", harga);

    } else if(pilihan == 'd'){
        harga = 28000;   
        printf("Harga Kipas lipat mini: %d\n", harga);
        tambahBelanja("Kipas lipat mini", harga);

    } else if(pilihan == 'e'){
        harga = 30000;
        printf("Harga Kipas mini stand: %d\n", harga);
        tambahBelanja("Kipas mini stand", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    } else {
        printf("Pilihan tidak valid.\n");
        SubKipas();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan Kipas Angin Mini lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubKipas();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return 1;
}

int SubSenter(){
    char pilihan;
    int harga;
    printf("Berikut pilihan Senter LED yang dapat anda pilih:\n");
    printf("Jenis Senter:\n"
           "a. Senter mini\n"
           "b. Senter sedang\n"
           "c. Senter besar\n"
           "d. Senter kepala (headlamp)\n"
           "e. Senter police LED\n");
    printf("Masukkan pilihan Anda (a-e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);

    if(pilihan == 'a'){
        harga = 12000;
        printf("Harga Senter mini: %d\n", harga);
        tambahBelanja("Senter mini", harga);

    } else if(pilihan == 'b'){
        harga = 20000;
        printf("Harga Senter sedang: %d\n", harga);
        tambahBelanja("Senter sedang", harga);

    } else if(pilihan == 'c'){
        harga = 35000;
        printf("Harga Senter besar: %d\n", harga);
        tambahBelanja("Senter besar", harga);

    } else if(pilihan == 'd'){
        harga = 25000;   
        printf("Harga Senter kepala: %d\n", harga);
        tambahBelanja("Senter kepala", harga);

    } else if(pilihan == 'e'){
        harga = 30000;
        printf("Harga Senter police LED: %d\n", harga);
        tambahBelanja("Senter police LED", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();
    } else {
        printf("Pilihan tidak valid.\n");
        SubSenter();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan Senter lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'K' || pilihan == 'k'){
            SubSenter();
        } else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return 1;
}

int SubStopKontak(){
    char pilihan;
    int harga;

    printf("Berikut pilihan Stop Kontak yang dapat anda pilih:\n");
    printf("Jenis Stop Kontak:\n"
           "a. Stop kontak 3 lubang\n"
           "b. Stop kontak 4 lubang\n"
           "c. Stop kontak + saklar\n"
           "d. Stop kontak kabel 1.5m\n"
           "e. Stop kontak T (3-way)\n");

    printf("Masukkan pilihan Anda (a-e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");
    scanf(" %c", &pilihan);

    if(pilihan == 'a'){
        harga = 18000;
        printf("Harga Stop kontak 3 lubang: %d\n", harga);
        tambahBelanja("Stop kontak 3 lubang", harga);
    }
    else if(pilihan == 'b'){
        harga = 22000;
        printf("Harga Stop kontak 4 lubang: %d\n", harga);
        tambahBelanja("Stop kontak 4 lubang", harga);
    }
    else if(pilihan == 'c'){
        harga = 25000;
        printf("Harga Stop kontak + saklar: %d\n", harga);
        tambahBelanja("Stop kontak + saklar", harga);
    }
    else if(pilihan == 'd'){
        harga = 28000;
        printf("Harga Stop kontak kabel 1.5m: %d\n", harga);
        tambahBelanja("Stop kontak kabel 1.5m", harga);
    }
    else if(pilihan == 'e'){
        harga = 7000;
        printf("Harga Stop kontak T (3-way): %d\n", harga);
        tambahBelanja("Stop kontak T (3-way)", harga);
    }
    else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();
    }
    else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else{
        printf("Pilihan tidak valid.\n");
        SubStopKontak();
    }

    if(pilihan=='a'||pilihan=='b'||pilihan=='c'||pilihan=='d'||pilihan=='e'){
        printf("Ingin memesan Stop Kontak lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k'){
            SubStopKontak();
        }
        else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        }
        else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return 1;
}

int SubSpeaker(){
    char pilihan;
    int harga;

    printf("Berikut pilihan Speaker Portable yang dapat anda pilih:\n");
    printf("Jenis Speaker:\n"
           "a. Speaker mini\n"
           "b. Speaker bluetooth kecil\n"
           "c. Speaker cube\n"
           "d. Speaker bass kecil\n"
           "e. Speaker waterproof mini\n");

    printf("Masukkan pilihan Anda (a-e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");
    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);

    if(pilihan == 'a'){
        harga = 25000;
        printf("Harga Speaker mini: %d\n", harga);
        tambahBelanja("Speaker mini", harga);
    }
    else if(pilihan == 'b'){
        harga = 35000;
        printf("Harga Speaker bluetooth kecil: %d\n", harga);
        tambahBelanja("Speaker bluetooth kecil", harga);
    }
    else if(pilihan == 'c'){
        harga = 40000;
        printf("Harga Speaker cube: %d\n", harga);
        tambahBelanja("Speaker cube", harga);
    }
    else if(pilihan == 'd'){
        harga = 45000;
        printf("Harga Speaker bass kecil: %d\n", harga);
        tambahBelanja("Speaker bass kecil", harga);
    }
    else if(pilihan == 'e'){
        harga = 50000;
        printf("Harga Speaker waterproof mini: %d\n", harga);
        tambahBelanja("Speaker waterproof mini", harga);
    }
    else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();
    }
    else if(pilihan == 'U' || pilihan == 'u'){
        main();
    }
    else{
        printf("Pilihan tidak valid.\n");
        SubSpeaker();
    }

    if(pilihan=='a'||pilihan=='b'||pilihan=='c'||pilihan=='d'||pilihan=='e'){
        printf("Ingin memesan Speaker lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k'){
            SubSpeaker();
        }
        else if(pilihan == 'X' || pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        }
        else if(pilihan == 'U' || pilihan == 'u'){
            main();
        }
    }

    return 1;
}

int SubSmartwatch(){
    char pilihan;
    printf("Berikut pilihan Smartwatch yang dapat anda pilih:\n");
    printf("Jenis Smartwatch:\n"
        "a. Samsung Galaxy Watch8 Classic\n"
        "b. Xiaomi Smart Band 9\n"
        "c. Huawei Watch Fit 4\n"
        "d. Imoo Smart Watch Phone Z7\n"
        "e. Garmin Venu X1 010-02980-13\n");
    printf("Masukkan pilihan Anda (a–e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    int harga;
    pilihan = tolower(pilihan);

    if(pilihan == 'a'){
        harga = 6999000;
        printf("Harga Samsung Galaxy Watch8 Classic: %d\n", harga);
        tambahBelanja("Samsung Galaxy Watch8 Classic", harga);

    } else if(pilihan == 'b'){
        harga = 569000;
        printf("Harga Xiaomi Smart Band 9: %d\n", harga);
        tambahBelanja("Xiaomi Smart Band 9", harga);

    } else if(pilihan == 'c'){
        harga = 859000;
        printf("Harga Huawei Watch Fit 4: %d\n", harga);
        tambahBelanja("Huawei Watch Fit 4", harga);

    } else if(pilihan == 'd'){
        harga = 2999000;
        printf("Harga Imoo Smart Watch Phone Z7: %d\n", harga);
        tambahBelanja("Imoo Smart Watch Phone Z7", harga);

    } else if(pilihan == 'e'){
        harga = 13439000;
        printf("Harga Garmin Venu X1 010-02980-13: %d\n", harga);
        tambahBelanja("Garmin Venu X1 010-02980-13", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();

    } else {
        printf("Pilihan tidak valid.\n");
        SubSmartwatch();
    }

    if(pilihan=='a'||pilihan=='b'||pilihan=='c'||pilihan=='d'||pilihan=='e'){
        printf("Ingin memesan Smartwatch lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k') {
          SubSmartwatch();
        }
        else if(pilihan == 'X' || pilihan == 'x'){ 
          printf("Terima kasih telah menggunakan program ini.\n");
          cetakStruk(); 
        }
        else if(pilihan == 'U' || pilihan == 'u'){
           main();
        }
    }

    return pilihan;
}

int SubDrone(){
    char pilihan;
    printf("Berikut pilihan Drone yang dapat anda pilih:\n");
    printf("Jenis Drone:\n"
        "a. DJI Mini 4K Drone\n"
        "b. DJI Mini 5 Pro Fly More Combo\n"
        "c. DJI Neo Basic Drone\n"
        "d. Huawei A22 PRO GPS\n"
        "e. Brica B-Pro 5 Sky Explorer Drone\n");
    printf("Masukkan pilihan Anda (a–e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 4939000;
        printf("Harga DJI Mini 4K Drone: %d\n", harga);
        tambahBelanja("DJI Mini 4K Drone", harga);

    } else if(pilihan == 'b'){
        harga = 17090000;
        printf("Harga DJI Mini 5 Pro Fly More Combo: %d\n", harga);
        tambahBelanja("DJI Mini 5 Pro Fly More Combo", harga);

    } else if(pilihan == 'c'){
        harga = 3000000;
        printf("Harga DJI Neo Basic Drone: %d\n", harga);
        tambahBelanja("DJI Neo Basic Drone", harga);

    } else if(pilihan == 'd'){
        harga = 1373000;
        printf("Harga Huawei A22 PRO GPS: %d\n", harga);
        tambahBelanja("Huawei A22 PRO GPS", harga);

    } else if(pilihan == 'e'){
        harga = 1645000;
        printf("Harga Brica B-Pro 5 Sky Explorer Drone: %d\n", harga);
        tambahBelanja("Brica B-Pro 5 Sky Explorer Drone", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();

    } else {
        printf("Pilihan tidak valid.\n");
        SubDrone();
    }

    if(pilihan >= 'a' && pilihan <= 'e'){
        printf("Ingin memesan Drone lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k') {
          SubDrone();
        }
        else if(pilihan == 'X' || pilihan == 'x'){ 
          printf("Terima kasih telah menggunakan program ini.\n");
          cetakStruk(); 
        }
        else if(pilihan == 'U' || pilihan == 'u') {
          main();
        } 
    }

    return pilihan;
}

int SubTablet(){
    char pilihan;
    printf("Berikut pilihan Tablet yang dapat anda pilih:\n");
    printf("Jenis Tablet:\n"
        "a. Huawei MatePad 11.5\n"
        "b. OPPO Pad SE 4+128GB\n"
        "c. Samsung Galaxy Tab A9\n"
        "d. Xiaomi Redmi Pad SE\n"
        "e. Apple iPad Pro 11\n");
    printf("Masukkan pilihan Anda (a–e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 5979000;
        printf("Harga Huawei MatePad 11.5: %d\n", harga);
        tambahBelanja("Huawei MatePad 11.5", harga);

    } else if(pilihan == 'b'){
        harga = 2999000;
        printf("Harga OPPO Pad SE 4+128GB: %d\n", harga);
        tambahBelanja("OPPO Pad SE 4+128GB", harga);

    } else if(pilihan == 'c'){
        harga = 1775000;
        printf("Harga Samsung Galaxy Tab A9: %d\n", harga);
        tambahBelanja("Samsung Galaxy Tab A9", harga);

    } else if(pilihan == 'd'){
        harga = 1649000;
        printf("Harga Xiaomi Redmi Pad SE: %d\n", harga);
        tambahBelanja("Xiaomi Redmi Pad SE", harga);

    } else if(pilihan == 'e'){
        harga = 23999000;
        printf("Harga Apple iPad Pro 11: %d\n", harga);
        tambahBelanja("Apple iPad Pro 11", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();

    } else {
        printf("Pilihan tidak valid.\n");
        SubTablet();
    }

    if(pilihan >= 'a' && pilihan <= 'e'){
        printf("Ingin memesan Tablet lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k') {
          SubTablet();
          }
        else if(pilihan == 'X' || pilihan == 'x'){ 
          printf("Terima kasih telah menggunakan program ini.\n");
           cetakStruk(); 
          }
        else if(pilihan == 'U' || pilihan == 'u') {
          main();
        }
    }

    return pilihan;
}

int SubMonitor(){
    char pilihan;
    printf("Berikut pilihan Monitor yang dapat anda pilih:\n");
    printf("Jenis Monitor:\n"
        "a. LG 24MR400-B 24 Inch IPS FHD\n"
        "b. Xiaomi 2K Monitor A27Qi\n"
        "c. LG 19M38A 19 Inch LED\n"
        "d. HGFRTEE Portable Monitor 15.6 Inch IPS FHD\n"
        "e. Philips LED 241v8b 24 Inch\n");
    printf("Masukkan pilihan Anda (a–e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 1268250;
        printf("Harga LG 24MR400-B: %d\n", harga);
        tambahBelanja("LG 24MR400-B 24 Inch IPS FHD", harga);

    } else if(pilihan == 'b'){
        harga = 2696500;
        printf("Harga Xiaomi 2K Monitor A27Qi: %d\n", harga);
        tambahBelanja("Xiaomi 2K Monitor A27Qi", harga);

    } else if(pilihan == 'c'){
        harga = 1099800;
        printf("Harga LG 19M38A 19 Inch LED: %d\n", harga);
        tambahBelanja("LG 19M38A 19 Inch LED", harga);

    } else if(pilihan == 'd'){
        harga = 909000;
        printf("Harga HGFRTEE Portable Monitor: %d\n", harga);
        tambahBelanja("HGFRTEE Portable Monitor 15.6 Inch IPS FHD", harga);

    } else if(pilihan == 'e'){
        harga = 1382250;
        printf("Harga Philips LED 241v8b 24 Inch: %d\n", harga);
        tambahBelanja("Philips LED 241v8b 24 Inch", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();

    } else {
        printf("Pilihan tidak valid.\n");
        SubMonitor();
    }

    if(pilihan >= 'a' && pilihan <= 'e'){
        printf("Ingin memesan Monitor lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k') {
        SubMonitor();
        }
        else if(pilihan == 'X' || pilihan == 'x'){ 
          printf("Terima kasih telah menggunakan program ini.\n"); 
          cetakStruk(); 
        }
        else if(pilihan == 'U' || pilihan == 'u') {
          main();
        }
    }
    return pilihan;
}

int SubWirelessEarphone(){
    char pilihan;
    printf("Berikut pilihan Wireless Earphone yang dapat anda pilih:\n");
    printf("Jenis Wireless Earphone:\n"
        "a. Apple AirPods Pro\n"
        "b. Baseus WM01\n"
        "c. JBL Wave Buds 2\n"
        "d. QKZ CK5 HiFi In-Ear\n"
        "e. TWS Pro 4 Wireless Earbuds\n");
    printf("Masukkan pilihan Anda (a–e)\n"
           "Ketik U untuk ke Menu Utama\n"
           "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 3499000;
        printf("Harga Apple AirPods Pro: %d\n", harga);
        tambahBelanja("Apple AirPods Pro", harga);

    } else if(pilihan == 'b'){
        harga = 170000;
        printf("Harga Baseus WM01: %d\n", harga);
        tambahBelanja("Baseus True Wireless Bluetooth WM01", harga);

    } else if(pilihan == 'c'){
        harga = 1169100;
        printf("Harga JBL Wave Buds 2: %d\n", harga);
        tambahBelanja("JBL Wave Buds 2", harga);

    } else if(pilihan == 'd'){
        harga = 34200;
        printf("Harga QKZ CK5 HiFi In-Ear: %d\n", harga);
        tambahBelanja("QKZ CK5 HiFi In-Ear Earphones", harga);

    } else if(pilihan == 'e'){
        harga = 39800;
        printf("Harga TWS Pro 4 Wireless Earbuds: %d\n", harga);
        tambahBelanja("TWS Pro 4 Wireless Earbuds", harga);

    } else if(pilihan == 'X' || pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'U' || pilihan == 'u'){
        main();

    } else {
        printf("Pilihan tidak valid.\n");
        SubWirelessEarphone();
    }

    if(pilihan >= 'a' && pilihan <= 'e'){
        printf("Ingin memesan Wireless Earphone lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);

        if(pilihan == 'K' || pilihan == 'k') {
          SubWirelessEarphone();
        }
        else if(pilihan == 'X' || pilihan == 'x'){ 
          printf("Terima kasih telah menggunakan program ini.\n"); 
          cetakStruk(); 
        }
        else if(pilihan == 'U' || pilihan == 'u') {
          main();
        }
    }
    return pilihan;
}

int SubLaptop(){
    char pilihan;
    printf("Berikut pilihan laptop yang dapat anda pilih:\n");
    printf("Jenis Laptop:\n"
        "a. Laptop LOQ\n"
        "b. Laptop TUF\n"
        "c. Laptop ASUS\n"
        "d. Laptop MSI\n"
        "e. Laptop Macbook\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 14000000;
        printf("Harga Laptop LOQ: %d\n", harga);
        tambahBelanja("Laptop LOQ", harga);

    } else if(pilihan == 'b' ){
        harga = 17000000;
        printf("Harga Laptop TUF: %d\n", harga);
        tambahBelanja("Laptop TUF", harga);

    } else if(pilihan == 'c'){
        harga = 11000000;
        printf("Harga Laptop ASUS: %d\n", harga);
        tambahBelanja("Laptop ASUS", harga);

    } else if(pilihan == 'd'){
        harga = 9500000;
        printf("Harga Laptop MSI: %d\n", harga);
        tambahBelanja("Laptop MSI", harga);

    } else if(pilihan == 'e'){
        harga = 10000000;
        printf("Harga Laptop Macbook: %d\n", harga);
        tambahBelanja("Laptop Macbook", harga);

    } else if(pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubLaptop();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan laptop lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'k'){
            SubLaptop();
        } else if(pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int SubHP(){
    char pilihan;
    printf("Berikut pilihan HP yang dapat anda pilih:\n");
    printf("Jenis HP:\n"
        "a. HP Samsung\n"
        "b. HP iPhone\n"
        "c. HP Oppo\n"
        "d. HP Vivo\n"
        "e. HP Advan\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 2300000;
        printf("Harga HP Samsung: %d\n", harga);
        tambahBelanja("HP Samsung", harga);

    } else if(pilihan == 'b' ){
        harga = 2400000;
        printf("Harga HP iPhone: %d\n", harga);
        tambahBelanja("HP iPhone", harga);

    } else if(pilihan == 'c'){
        harga = 2700000;
        printf("Harga HP Oppo: %d\n", harga);
        tambahBelanja("HP Oppo", harga);

    } else if(pilihan == 'd'){
        harga = 3500000;
        printf("Harga HP Vivo: %d\n", harga);
        tambahBelanja("HP Vivo", harga);

    } else if(pilihan == 'e'){
        harga = 2500000;
        printf("Harga HP Advan: %d\n", harga);
        tambahBelanja("HP Advan", harga);

    } else if(pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubHP();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan HP lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'k'){
            SubHP();
        } else if(pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int SubBlender(){
    char pilihan;
    printf("Berikut pilihan blender yang dapat anda pilih:\n");
    printf("Jenis Blender:\n"
        "a. Blender GP\n"
        "b. Blender ZA\n"
        "c. Blender CA\n"
        "d. Blender DA\n"
        "e. Blender BC\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 175000;
        printf("Harga Blender GP: %d\n", harga);
        tambahBelanja("Blender GP", harga);

    } else if(pilihan == 'b' ){
        harga = 274000;
        printf("Harga Blender ZA: %d\n", harga);
        tambahBelanja("Blender ZA", harga);

    } else if(pilihan == 'c'){
        harga = 135000;
        printf("Harga Blender CA: %d\n", harga);
        tambahBelanja("Blender CA", harga);

    } else if(pilihan == 'd'){
        harga = 155000;
        printf("Harga Blender DA: %d\n", harga);
        tambahBelanja("Blender DA", harga);

    } else if(pilihan == 'e'){
        harga = 150000;
        printf("Harga Blender BC: %d\n", harga);
        tambahBelanja("Blender BC", harga);

    } else if(pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubBlender();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan blender lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'k'){
            SubBlender();
        } else if(pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int SubRicecooker(){
    char pilihan;
    printf("Berikut pilihan rice cooker yang dapat anda pilih:\n");
    printf("Jenis Rice Cooker:\n"
        "a. Rice Cooker 17KI\n"
        "b. Rice Cooker 12II\n"
        "c. Rice Cooker 14AC\n"
        "d. Rice Cooker 15CD\n"
        "e. Rice Cooker 17ZA\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 255000;
        printf("Harga Rice Cooker 17KI: %d\n", harga);
        tambahBelanja("Rice Cooker 17KI", harga);

    } else if(pilihan == 'b' ){
        harga = 240000;
        printf("Harga Rice Cooker 12II: %d\n", harga);
        tambahBelanja("Rice Cooker 12II", harga);

    } else if(pilihan == 'c'){
        harga = 325000;
        printf("Harga Rice Cooker 14AC: %d\n", harga);
        tambahBelanja("Rice Cooker 14AC", harga);

    } else if(pilihan == 'd'){
        harga = 270000;
        printf("Harga Rice Cooker 15CD: %d\n", harga);
        tambahBelanja("Rice Cooker 15CD", harga);

    } else if(pilihan == 'e'){
        harga = 250000;
        printf("Harga Rice Cooker 17ZA: %d\n", harga);
        tambahBelanja("Rice Cooker 17ZA", harga);

    } else if(pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubRicecooker();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan rice cooker lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'k'){
            SubRicecooker();
        } else if(pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int SubPowerbank(){
    char pilihan;
    printf("Berikut pilihan power bank yang dapat anda pilih:\n");
    printf("Jenis Power Bank:\n"
        "a. Power Bank 18C\n"
        "b. Power Bank 19C\n"
        "c. Power Bank 20C\n"
        "d. Power Bank 21C\n"
        "e. Power Bank 22C\n");
    printf("Masukkan pilihan Anda (a-e)\n"
        "Ketik U untuk ke Menu Utama\n"
        "Ketik X untuk selesai: ");

    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);
    int harga;

    if(pilihan == 'a'){
        harga = 250000;
        printf("Harga Power Bank 18C: %d\n", harga);
        tambahBelanja("Power Bank 18C", harga);

    } else if(pilihan == 'b' ){
        harga = 270000;
        printf("Harga Power Bank 19C: %d\n", harga);
        tambahBelanja("Power Bank 19C", harga);

    } else if(pilihan == 'c'){
        harga = 320000;
        printf("Harga Power Bank 20C: %d\n", harga);
        tambahBelanja("Power Bank 20C", harga);

    } else if(pilihan == 'd'){
        harga = 350000;
        printf("Harga Power Bank 21C: %d\n", harga);
        tambahBelanja("Power Bank 21C", harga);

    } else if(pilihan == 'e'){
        harga = 300000;
        printf("Harga Power Bank 22C: %d\n", harga);
        tambahBelanja("Power Bank 22C", harga);

    } else if(pilihan == 'x'){
        printf("Terima kasih telah menggunakan program ini.\n");
        cetakStruk();

    } else if(pilihan == 'u'){
        main();
    }
    else {
        printf("Pilihan tidak valid.\n");
        SubPowerbank();
    }

    if(pilihan == 'a' || pilihan == 'b' || pilihan == 'c' || pilihan == 'd' || pilihan == 'e'){
        printf("Ingin memesan power bank lagi? (Ketik K untuk ya, U untuk ke Menu Utama, X untuk selesai): ");
        scanf(" %c", &pilihan);
        if(pilihan == 'k'){
            SubPowerbank();
        } else if(pilihan == 'x'){
            printf("Terima kasih telah menggunakan program ini.\n");
            cetakStruk();
        } else if(pilihan == 'u'){
            main();
        }
    }

    return pilihan;
}

int main(){
    int pilihanbesar = tampilkanMenu();

    switch(pilihanbesar){
        case 1: 
        SubKulkas(); 
        break;
        case 2: 
        SubCuci(); 
        break;
        case 3: 
        SubAc(); 
        break;
        case 4: 
        SubTV(); 
        break;
        case 5: 
        SubKompor(); 
        break;
        case 6: 
        SubLampu(); 
        break;
        case 7: 
        SubKipas(); 
        break;
        case 8: 
        SubSenter(); 
        break;
        case 9: 
        SubStopKontak(); 
        break;
        case 10: 
        SubSpeaker(); 
        break;
        case 11: 
        SubSmartwatch();
        break;
        case 12: 
        SubDrone();
        break;
        case 13:
        SubTablet();
        break;
        case 14:
        SubMonitor();
        break;
        case 15:
        SubWirelessEarphone();
        break;
        case 16:
        SubLaptop();
        break;
        case 17:
        SubHP();
        break;
        case 18:
        SubBlender();
        break;
        case 19:
        SubRicecooker();
        break;
        case 20:
        SubPowerbank();
        break;
        case 21: 
        cetakStruk(); 
        break;

        default:
            printf("Pilihan tidak valid.\n");
            main();
    }

    return 0;
}
