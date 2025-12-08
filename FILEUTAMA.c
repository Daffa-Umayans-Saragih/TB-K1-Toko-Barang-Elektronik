#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1;37m"

char namaBarang[100][100];
int hargaBarang[100];
int jumlahBarang = 0;


void header(const char *judul){
    printf(GREEN "========================================================\n" RESET);
    printf(GREEN "%s\n" RESET, judul);
    printf(GREEN "========================================================\n" RESET);
}

void garis(){
    printf("--------------------------------------------------------\n");
}


int getLogCounter() {
    FILE *f = fopen("log_counter.txt", "r");
    int num = 0;

    if (f) {
        fscanf(f, "%d", &num);
        fclose(f);
    }

    // update counter
    f = fopen("log_counter.txt", "w");
    fprintf(f, "%d", num + 1);
    fclose(f);

    return num + 1;
}

void simpanHistory(int total){
    
    int logNum = getLogCounter();

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char tanggal[50];
    strftime(tanggal, sizeof(tanggal), "%d-%m-%Y %H:%M:%S", t);

    char bonus[50] = "Tidak Ada";

    if(total >= 80000000) {
       strcpy(bonus, "Kulkas 2 Pintu");
    }
    else if(total >= 60000000) {
       strcpy(bonus, "Kulkas 1 Pintu");
    }
    else if(total >= 40000000) {
       strcpy(bonus, "OPPO Pad SE (4/128)");
    }
    else if(total >= 30000000) {
       strcpy(bonus, "Monitor LG 19M38A");
    }
    else if(total >= 20000000) {
       strcpy(bonus, "Xiaomi Smart Band 9");}

    else if(total >= 10000000) {
       strcpy(bonus, "Speaker Bluetooth Mini");
    }
    else if(total >= 3000000){
       strcpy(bonus, "Lampu LED 10W");
    }

    FILE *log = fopen("history_log.txt", "a");
    if(!log){
        printf("Gagal membuka file history_log!\n");
        return;
    }

    fprintf(log, "LOG %d | [%s] Total: Rp %d | Bonus: %s\n",
            logNum, tanggal, total, bonus);
    fclose(log);

    FILE *detail = fopen("history_detail.txt", "a");
    if(!detail){
        printf("Gagal membuka file history_detail!\n");
        return;
    }

    fprintf(detail, "=============== DETAIL HISTORY (LOG %d) ===============\n",
            logNum);
    fprintf(detail, "Tanggal : %s\n", tanggal);
    fprintf(detail, "Daftar Belanja:\n");

    for(int i = 0; i < jumlahBarang; i++){
        fprintf(detail, "%d. %s - Rp %d\n", i+1, namaBarang[i], hargaBarang[i]);
    }

    fprintf(detail, "TOTAL : Rp %d\n", total);
    fprintf(detail, "BONUS : %s\n", bonus);
    fprintf(detail, "========================================================\n\n");

    fclose(detail);
}

void tambahBelanja(const char *nama, int harga){
    strcpy(namaBarang[jumlahBarang], nama);
    hargaBarang[jumlahBarang] = harga;
    jumlahBarang++;
}

void cetakStruk(){
    header("                       STRUK PEMBELIAN");

    int total = 0;

    for(int i = 0; i < jumlahBarang; i++){
        printf("%d. %s - Rp %d\n", i+1, namaBarang[i], hargaBarang[i]);
        total += hargaBarang[i];
    }

    garis();
    printf(GREEN "                  TOTAL HARGA: Rp %d\n" RESET, total);
    garis();

    if (total >= 80000000) {
        printf("Selamat anda mendapat bonus Kulkas 2 Pintu\n");
    }
    else if (total >= 60000000) {
        printf("Selamat anda mendapat bonus Kulkas 1 Pintu\n");
    }
    else if (total >= 40000000) {
        printf("Selamat anda mendapat bonusOPPO Pad SE (4/128)\n");
    }
    else if (total >= 30000000) {
        printf("Selamat anda mendapat bonus Monitor LG 19M38A\n");
    }
    else if (total >= 20000000) {
        printf("Selamat anda mendapat bonus Xiaomi Smart Band 9\n");
    }
    else if (total >= 10000000) {
    printf("Selamat anda mendapat bonus Speaker Bluetooth Mini\n");
    }
    else if (total >= 3000000) {
        printf("Selamat anda mendapat bonus Lampu LED 10 Watt\n");
    }

    header("                        TERIMA KASIH");
    simpanHistory(total);    

    exit(0);
}


int SubKulkas(){
    header("Berikut pilihan kulkas yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Kulkas 1 Pintu    - Rp3.000.000\n"
        "b. Kulkas 2 Pintu    - Rp5.000.000\n"
        "c. Side by Side      - Rp8.000.000\n"
        "d. French Door       - Rp12.000.000\n"
        "e. Kulkas Mini       - Rp150.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);

    if(pilihan=='a'){ 
        harga=3000000;
        printf("Harga Kulkas 1 Pintu: %d\n", harga); 
        tambahBelanja("Kulkas 1 Pintu", harga); 
    }
    else if(pilihan=='b'){ 
        harga=5000000; 
        printf("Harga Kulkas 2 Pintu: %d\n", harga);
        tambahBelanja("Kulkas 2 Pintu", harga); 
    }
    else if(pilihan=='c'){ 
        harga=8000000; 
        printf("Harga Kulkas Side by Side: %d\n", harga);
        tambahBelanja("Side by Side", harga); 
    }
    else if(pilihan=='d'){ 
        harga=12000000; 
        printf("Harga Kulkas French Door: %d\n", harga);
        tambahBelanja("French Door", harga); 
    }
    else if(pilihan=='e'){ 
        harga=150000; 
        printf("Harga Kulkas Mini: %d\n", harga);
        tambahBelanja("Kulkas Mini", harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubKulkas();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan kulkas lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c", &pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubKulkas();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubKulkas();
        }
    } 
    return 0;
}


int SubCuci(){
    header("Berikut pilihan mesin cuci yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Top Loading       - Rp2.500.000\n"
        "b. Front Loading     - Rp4.000.000\n"
        "c. Semi Automatic    - Rp1.500.000\n"
        "d. Portable          - Rp1.000.000\n"
        "e. Twin Tub          - Rp1.800.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c", &pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ harga=2500000; tambahBelanja("Mesin Cuci Top Loading", harga); }
    else if(pilihan=='b'){ 
        harga=4000000; 
        printf("Harga Mesin Cuci Front Loading: %d\n", harga);
        tambahBelanja("Mesin Cuci Front Loading", harga); 
    }
    else if(pilihan=='c'){ 
        harga=1500000; 
        printf("Harga Mesin Cuci Semi Automatic: %d\n", harga);
        tambahBelanja("Mesin Cuci Semi Automatic", harga); 
    }
    else if(pilihan=='d'){ 
        harga=1000000;
        printf("Harga Mesin Cuci Portable: %d\n", harga);
        tambahBelanja("Mesin Cuci Portable", harga); 
    }
    else if(pilihan=='e'){ 
        harga=1800000; 
        printf("Harga Mesin Cuci Twin Tub: %d\n", harga);
        tambahBelanja("Mesin Cuci Twin Tub", harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubCuci();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Mesin Cuci lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c", &pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubCuci();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubCuci();
        }
    }

    return 0;
}


int SubAc(){
    header("Berikut pilihan AC yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. AC Split        - Rp3.500.000\n"
        "b. AC Window       - Rp2.500.000\n"
        "c. AC Portable     - Rp3.000.000\n"
        "d. AC Central      - Rp15.000.000\n"
        "e. AC Ducted       - Rp12.000.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=3500000; 
        printf("Harga AC Split: %d\n", harga);
        tambahBelanja("AC Split",harga); }
    else if(pilihan=='b'){ 
        harga=2500000; 
        printf("Harga AC Window: %d\n", harga);
        tambahBelanja("AC Window",harga);
    }
    else if(pilihan=='c'){ 
        harga=3000000; 
        printf("Harga AC Portable: %d\n", harga);
        tambahBelanja("AC Portable",harga); 
    }
    else if(pilihan=='d'){ 
        harga=15000000; 
        printf("Harga AC Central: %d\n", harga);
        tambahBelanja("AC Central",harga); 
    }
    else if(pilihan=='e'){ 
        harga=12000000; 
        printf("Harga AC Ducted: %d\n", harga);
        tambahBelanja("AC Ducted",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubAc();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan AC lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubAc();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubAc();
        }
    }

    return 0;
}


int SubTV(){
    header("Berikut pilihan TV yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. LED TV         - Rp4.000.000\n"
        "b. OLED TV        - Rp10.000.000\n"
        "c. QLED TV        - Rp8.000.000\n"
        "d. Smart TV       - Rp6.000.000\n"
        "e. 4K TV          - Rp12.000.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=4000000; 
        printf("Harga LED TV: %d\n", harga);
        tambahBelanja("LED TV",harga); 
    }
    else if(pilihan=='b'){ 
        harga=10000000;
        printf("Harga OLED TV: %d\n", harga); 
        tambahBelanja("OLED TV",harga); 
    }
    else if(pilihan=='c'){ 
        harga=8000000; 
        printf("Harga QLED TV: %d\n", harga);
        tambahBelanja("QLED TV",harga);
    }
    else if(pilihan=='d'){ 
        harga=6000000; 
        printf("Harga Smart TV: %d\n", harga);
        tambahBelanja("Smart TV",harga); 
    }
    else if(pilihan=='e'){
        harga=12000000; 
        printf("Harga 4K TV: %d\n", harga);
        tambahBelanja("4K TV",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubTV();
    }
    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan TV lagi, U untuk ke Menu Utama, X untuk selesai:");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubTV();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubTV();
        }
    }

    return 0;
}


int SubKompor(){
    header("Berikut pilihan Kompor Listrik yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Kompor Induksi      - Rp2.000.000\n"
        "b. Kompor Halogen      - Rp1.500.000\n"
        "c. Kompor Keramik      - Rp1.800.000\n"
        "d. Kompor Portable     - Rp1.000.000\n"
        "e. Kompor Tanam        - Rp2.500.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=2000000; 
        printf("Harga Kompor Induksi: %d\n", harga);
        tambahBelanja("Kompor Induksi",harga); 
    }
    else if(pilihan=='b'){ 
        harga=1500000; 
        printf("Harga Kompor Halogen: %d\n", harga);
        tambahBelanja("Kompor Halogen",harga); 
    }
    else if(pilihan=='c'){
        harga=1800000; 
        printf("Harga Kompor Keramik: %d\n", harga);
        tambahBelanja("Kompor Keramik",harga); 
    }
    else if(pilihan=='d'){ 
        harga=1000000; 
        printf("Harga Kompor Portable: %d\n", harga);
        tambahBelanja("Kompor Portable",harga); 
    }
    else if(pilihan=='e'){ 
        harga=2500000; 
        printf("Harga Kompor Tanam: %d\n", harga);
        tambahBelanja("Kompor Tanam",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubKompor();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Kompor Listrik lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubKompor();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubKompor();
        }
    }

    return 0;
}


int SubLampu(){
    header("Berikut pilihan Lampu LED yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. LED 5W    - Rp8.000\n"
        "b. LED 8W    - Rp12.000\n"
        "c. LED 10W   - Rp15.000\n"
        "d. LED 15W   - Rp20.000\n"
        "e. LED 20W   - Rp24.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=8000; 
        printf("Harga Lampu LED 5W: %d\n", harga);
        tambahBelanja("Lampu LED 5W",harga); 
    }
    else if(pilihan=='b'){ 
        harga=12000; 
        printf("Harga Lampu LED 8W: %d\n", harga);
        tambahBelanja("Lampu LED 8W",harga); 
    }
    else if(pilihan=='c'){ 
        harga=15000; 
        printf("Harga Lampu LED 10W: %d\n", harga);
        tambahBelanja("Lampu LED 10W",harga); 
    }
    else if(pilihan=='d'){ 
        harga=20000; 
        printf("Harga Lampu LED 15W: %d\n", harga);
        tambahBelanja("Lampu LED 15W",harga); 
    }
    else if(pilihan=='e'){ 
        harga=24000; 
        printf("Harga Lampu LED 20W: %d\n", harga);
        tambahBelanja("Lampu LED 20W",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubLampu();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Lampu LED lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubLampu();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
    }
    return 0;
}


int SubKipas(){
    header("Berikut pilihan Kipas Angin Mini yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Mini 3W        - Rp15.000\n"
        "b. Mini 5W        - Rp20.000\n"
        "c. Portable       - Rp25.000\n"
        "d. Lipat          - Rp28.000\n"
        "e. Mini Stand     - Rp30.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=15000; 
        printf("Harga Kipas Mini 3W: %d\n", harga);
        tambahBelanja("Kipas Mini 3W",harga); 
    }
    else if(pilihan=='b'){ 
        harga=20000; 
        printf("Harga Kipas Mini 5W: %d\n", harga);
        tambahBelanja("Kipas Mini 5W",harga); 
    }
    else if(pilihan=='c'){ 
        harga=25000; 
        printf("Harga Kipas Portable: %d\n", harga);
        tambahBelanja("Kipas Portable",harga); 
    }
    else if(pilihan=='d'){ 
        harga=28000; 
        printf("Harga Kipas Lipat: %d\n", harga);
        tambahBelanja("Kipas Lipat",harga); 
    }
    else if(pilihan=='e'){ 
        harga=30000; 
        printf("Harga Kipas Mini Stand: %d\n", harga);
        tambahBelanja("Kipas Mini Stand",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubKipas();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Kipas Mini lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubKipas();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubKipas();
        }
    }

    return 0;
}


int SubSenter(){
    header("Berikut pilihan Senter LED yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Mini         - Rp12.000\n"
        "b. Sedang       - Rp20.000\n"
        "c. Besar        - Rp35.000\n"
        "d. Headlamp     - Rp25.000\n"
        "e. Police LED   - Rp30.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=12000; 
        printf("Harga Senter Mini: %d\n", harga);
        tambahBelanja("Senter Mini",harga); 
    }
    else if(pilihan=='b'){ 
        harga=20000; 
        printf("Harga Senter Sedang: %d\n", harga);
        tambahBelanja("Senter Sedang",harga); 
    }
    else if(pilihan=='c'){ 
        harga=35000; 
        printf("Harga Senter Besar: %d\n", harga);
        tambahBelanja("Senter Besar",harga); 
    }
    else if(pilihan=='d'){ 
        harga=25000; 
        printf("Harga Headlamp: %d\n", harga);
        tambahBelanja("Headlamp",harga); 
    }
    else if(pilihan=='e'){ 
        harga=30000; tambahBelanja("Police LED",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubSenter();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Senter LED lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubSenter();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubSenter();
        }
    }

    return 0;
}


int SubStopKontak(){
    header("Berikut pilihan Stop Kontak yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. 3 Lubang     - Rp18.000\n"
        "b. 4 Lubang     - Rp22.000\n"
        "c. + Saklar     - Rp25.000\n"
        "d. Kabel 1.5m   - Rp28.000\n"
        "e. Stop T       - Rp7.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=18000; 
        printf("Harga Stop Kontak 3 Lubang: %d\n", harga);
        tambahBelanja("Stop Kontak 3 Lubang",harga); 
    }
    else if(pilihan=='b'){ 
        harga=22000; 
        printf("Harga Stop Kontak 4 Lubang: %d\n", harga);
        tambahBelanja("Stop Kontak 4 Lubang",harga); 
    }
    else if(pilihan=='c'){ 
        harga=25000; 
        printf("Harga Stop Kontak + Saklar: %d\n", harga);
        tambahBelanja("Stop Kontak + Saklar",harga); 
    }
    else if(pilihan=='d'){ 
        harga=28000; 
        printf("Harga Stop Kontak Kabel 1.5m: %d\n", harga);
        tambahBelanja("Stop Kontak Kabel 1.5m",harga); 
    }
    else if(pilihan=='e'){ 
        harga=7000; 
        printf("Harga Stop Kontak T: %d\n", harga);
        tambahBelanja("Stop Kontak T",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubStopKontak();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Stop Kontak lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubStopKontak();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubStopKontak();
        }
    }

    return 0;
}


int SubSpeaker(){
    header("Berikut pilihan Speaker Portable yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Speaker Mini               - Rp25.000\n"
        "b. BT Kecil                   - Rp35.000\n"
        "c. Cube                       - Rp40.000\n"
        "d. Bass                       - Rp45.000\n"
        "e. Waterproof                 - Rp50.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=25000; 
        printf("Harga Speaker Mini: %d\n", harga);
        tambahBelanja("Speaker Mini",harga); 
    }
    else if(pilihan=='b'){ \
        harga=35000; 
        printf("Harga Speaker Bluetooth Kecil: %d\n", harga);
        tambahBelanja("Speaker Bluetooth Kecil",harga); 
    }
    else if(pilihan=='c'){ 
        harga=40000;
        printf("Harga Speaker Cube: %d\n", harga); 
        tambahBelanja("Speaker Cube",harga); 
    }
    else if(pilihan=='d'){ 
        harga=45000;
        printf("Harga Speaker Bass: %d\n", harga);
        tambahBelanja("Speaker Bass",harga); 
    }
    else if(pilihan=='e'){ 
        harga=50000; 
        printf("Harga Speaker Waterproof: %d\n", harga);
        tambahBelanja("Speaker Waterproof",harga);
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubSpeaker();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Speaker Portable lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubSpeaker();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubSpeaker();
        }
    }

    return 0;
}


int SubSmartwatch(){
    header("Berikut pilihan Smartwatch yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Samsung Watch8 Classic      - Rp6.999.000\n"
        "b. Xiaomi Smart Band 9         - Rp569.000\n"
        "c. Huawei Watch Fit 4          - Rp859.000\n"
        "d. Imoo Z7                     - Rp2.999.000\n"
        "e. Garmin Venu X1              - Rp13.439.000\n"
    );

    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=6999000; 
        printf("Harga Samsung Watch8 Classic: %d\n", harga);
        tambahBelanja("Samsung Watch8 Classic",harga); 
    }
    else if(pilihan=='b'){ 
        harga=569000; 
        printf("Harga Xiaomi Smart Band 9: %d\n", harga);
        tambahBelanja("Xiaomi Smart Band 9",harga); 
    }
    else if(pilihan=='c'){ 
        harga=859000; 
        printf("Harga Huawei Watch Fit 4: %d\n", harga);
        tambahBelanja("Huawei Watch Fit 4",harga); 
    }
    else if(pilihan=='d'){ 
        harga=2999000; 
        printf("Harga Imoo Z7: %d\n", harga);
        tambahBelanja("Imoo Z7",harga); 
    }
    else if(pilihan=='e'){ 
        harga=13439000;
        printf("Harga Garmin Venu X1: %d\n", harga); 
        tambahBelanja("Garmin Venu X1",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubSmartwatch();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Smartwatch lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubSmartwatch();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubSmartwatch();
        }
    }

    return 0;
}


int SubDrone(){
    header("Berikut pilihan Drone yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. DJI Mini 4K              - Rp4.939.000\n"
        "b. DJI Mini 5 Pro Combo     - Rp17.090.000\n"
        "c. DJI Neo Basic            - Rp3.000.000\n"
        "d. Huawei A22 PRO GPS       - Rp1.373.000\n"
        "e. Brica Sky Explorer       - Rp1.645.000\n"
    );

    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan = tolower(pilihan);

    if(pilihan=='a'){ 
        harga=4939000; 
        printf("Harga DJI Mini 4K: %d\n", harga);
        tambahBelanja("DJI Mini 4K",harga); 
    }
    else if(pilihan=='b'){ 
        harga=17090000;
        printf("Harga DJI Mini 5 Pro Combo: %d\n", harga); 
        tambahBelanja("DJI Mini 5 Pro Combo",harga); 
    }
    else if(pilihan=='c'){ 
        harga=3000000; 
        printf("Harga DJI Neo Basic: %d\n", harga);
        tambahBelanja("DJI Neo Basic",harga); 
    }
    else if(pilihan=='d'){ 
        harga=1373000; 
        printf("Harga Huawei A22 PRO GPS: %d\n", harga);
        tambahBelanja("Huawei A22 PRO GPS",harga); 
    }
    else if(pilihan=='e'){ 
        harga=1645000;
        printf("Harga Brica Sky Explorer: %d\n", harga); 
        tambahBelanja("Brica Sky Explorer",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubDrone();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Drone lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubDrone();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubDrone();
        }
    }
    return 0;
}


int SubTablet(){
    header("Berikut pilihan Tablet yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Huawei MatePad 11.5        - Rp5.979.000\n"
        "b. OPPO Pad SE 4/128          - Rp2.999.000\n"
        "c. Samsung Tab A9             - Rp1.775.000\n"
        "d. Xiaomi Redmi Pad SE        - Rp1.649.000\n"
        "e. iPad Pro 11                - Rp23.999.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);

    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=5979000; 
        printf("Harga Huawei MatePad 11.5: %d\n", harga);
        tambahBelanja("Huawei MatePad 11.5",harga);
    }
    else if(pilihan=='b'){ 
        harga=2999000; 
        printf("Harga OPPO Pad SE 4/128: %d\n", harga);
        tambahBelanja("OPPO Pad SE 4/128",harga); 
    }
    else if(pilihan=='c'){ 
        harga=1775000; 
        printf("Harga Samsung Tab A9: %d\n", harga);
        tambahBelanja("Samsung Tab A9",harga); 
    }
    else if(pilihan=='d'){ 
        harga=1649000; 
        printf("Harga Xiaomi Redmi Pad SE: %d\n", harga);
        tambahBelanja("Xiaomi Redmi Pad SE",harga); 
    }
    else if(pilihan=='e'){ 
        harga=23999000;
        printf("Harga iPad Pro 11: %d\n", harga);
        tambahBelanja("iPad Pro 11",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubTablet();
    }
    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Tablet lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubTablet();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubTablet();
        }
    }
    return 0;
}


int SubMonitor(){
    header("Berikut pilihan Monitor yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. LG 24MR400-B 24\"         - Rp1.268.250\n"
        "b. Xiaomi A27Qi 2K          - Rp2.696.500\n"
        "c. LG 19M38A                - Rp1.099.800\n"
        "d. HGFRTEE Portable 15.6\"   - Rp909.000\n"
        "e. Philips 241v8b           - Rp1.382.250\n"
    );
    garis();

    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=1268250; 
        printf("Harga LG 24MR400-B 24\": %d\n", harga);
        tambahBelanja("LG 24MR400-B",harga); 
    }
    else if(pilihan=='b'){ 
        harga=2696500; 
        printf("Harga Xiaomi A27Qi 2K: %d\n", harga);
        tambahBelanja("Xiaomi A27Qi 2K",harga); 
    }
    else if(pilihan=='c'){ 
        harga=1099800;
        printf("Harga LG 19M38A: %d\n", harga); 
        tambahBelanja("LG 19M38A",harga); 
    }
    else if(pilihan=='d'){ 
        harga=909000; 
        printf("Harga HGFRTEE Portable 15.6\": %d\n", harga);
        tambahBelanja("HGFRTEE Portable",harga); 
    }
    else if(pilihan=='e'){ 
        harga=1382250; 
        printf("Harga Philips 241v8b: %d\n", harga);
        tambahBelanja("Philips 241v8b",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubMonitor();
    }
    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Monitor lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubMonitor();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubMonitor();
        }
    }

    return 0;
}


int SubWirelessEarphone(){
    header("Berikut pilihan Wireless Earphone yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. AirPods Pro              - Rp3.499.000\n"
        "b. Baseus WM01             - Rp170.000\n"
        "c. JBL Wave Buds 2         - Rp1.169.100\n"
        "d. QKZ CK5 HiFi            - Rp34.200\n"
        "e. TWS Pro 4               - Rp39.800\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);

    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=3499000;
        printf("Harga AirPods Pro: %d\n", harga); 
        tambahBelanja("AirPods Pro",harga); 
    }
    else if(pilihan=='b'){ 
        harga=170000; 
        printf("Harga Baseus WM01: %d\n", harga);
        tambahBelanja("Baseus WM01",harga); 
    }
    else if(pilihan=='c'){ 
        harga=1169100;
        printf("Harga JBL Wave Buds 2: %d\n", harga); 
        tambahBelanja("JBL Wave Buds 2",harga); 
    }
    else if(pilihan=='d'){ 
        harga=34200; 
        printf("Harga QKZ CK5 HiFi: %d\n", harga);
        tambahBelanja("QKZ CK5 HiFi",harga); 
    }
    else if(pilihan=='e'){ 
        harga=39800;
        printf("Harga TWS Pro 4: %d\n", harga); 
        tambahBelanja("TWS Pro 4",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubWirelessEarphone();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Wireless Earphone lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubWirelessEarphone();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubWirelessEarphone();
        }
    }

    return 0;
}


int SubLaptop(){
    header("Berikut pilihan Laptop yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Laptop LOQ     - Rp14.000.000\n"
        "b. Laptop TUF     - Rp17.000.000\n"
        "c. Laptop ASUS    - Rp11.000.000\n"
        "d. Laptop MSI     - Rp9.500.000\n"
        "e. Laptop Macbook - Rp10.000.000\n"
    );

    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);

    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=14000000; 
        printf("Harga Laptop LOQ: %d\n", harga);
        tambahBelanja("Laptop LOQ",harga); 
    }
    else if(pilihan=='b'){ 
        harga=17000000; 
        printf("Harga Laptop TUF: %d\n", harga);
        tambahBelanja("Laptop TUF",harga); 
    }
    else if(pilihan=='c'){ 
        harga=11000000; 
        printf("Harga Laptop ASUS: %d\n", harga);
        tambahBelanja("Laptop ASUS",harga); 
    }
    else if(pilihan=='d'){ 
        harga=9500000; 
        printf("Harga Laptop MSI: %d\n", harga);
        tambahBelanja("Laptop MSI",harga); 
    }
    else if(pilihan=='e'){ 
        harga=10000000; 
        printf("Harga Laptop Macbook: %d\n", harga);
        tambahBelanja("Laptop Macbook",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubLaptop();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Laptop lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubLaptop();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubLaptop();
        }
    }

    return 0;
}


int SubHP(){
    header("Berikut pilihan Handphone yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Samsung   - Rp2.300.000\n"
        "b. iPhone    - Rp2.400.000\n"
        "c. Oppo      - Rp2.700.000\n"
        "d. Vivo      - Rp3.500.000\n"
        "e. Advan     - Rp2.500.000\n"
    );
    garis();
    printf(GREEN "Masukkan pilihan Anda: " RESET);

    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=2300000; 
        printf("Harga HP Samsung: %d\n", harga);
        tambahBelanja("HP Samsung",harga); 
    }
    else if(pilihan=='b'){ 
        harga=2400000; 
        printf("Harga HP iPhone: %d\n", harga);
        tambahBelanja("HP iPhone",harga); 
    }
    else if(pilihan=='c'){ 
        harga=2700000; 
        printf("Harga HP Oppo: %d\n", harga);
        tambahBelanja("HP Oppo",harga); 
    }
    else if(pilihan=='d'){ 
        harga=3500000; 
        printf("Harga HP Vivo: %d\n", harga);
        tambahBelanja("HP Vivo",harga); 
    }
    else if(pilihan=='e'){ 
        harga=2500000; 
        printf("Harga HP Advan: %d\n", harga);
        tambahBelanja("HP Advan",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubHP();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Handphone lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);
        if (pilihan=='k' || pilihan=='K'){
            SubHP();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubHP();
        }
    }
    return 0;
}


int SubBlender(){
    header("Berikut pilihan Blender yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Blender GP - Rp175.000\n"
        "b. Blender ZA - Rp274.000\n"
        "c. Blender CA - Rp135.000\n"
        "d. Blender DA - Rp155.000\n"
        "e. Blender BC - Rp150.000\n"
    );
    garis();

    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=175000; 
        printf("Harga Blender GP: %d\n", harga);
        tambahBelanja("Blender GP",harga); 
    }
    else if(pilihan=='b'){ 
        harga=274000; 
        printf("Harga Blender ZA: %d\n", harga);
        tambahBelanja("Blender ZA",harga); 
    }
    else if(pilihan=='c'){ 
        harga=135000;
        printf("Harga Blender CA: %d\n", harga); 
        tambahBelanja("Blender CA",harga); 
    }
    else if(pilihan=='d'){ 
        harga=155000; 
        printf("Harga Blender DA: %d\n", harga);
        tambahBelanja("Blender DA",harga); 
    }
    else if(pilihan=='e'){
         harga=150000; 
         printf("Harga Blender BC: %d\n", harga);
         tambahBelanja("Blender BC",harga);
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        SubBlender();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Blender lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);

        if (pilihan=='k' || pilihan=='K'){
            SubBlender();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            SubBlender();
        }
    }

    return 0;
}


int SubRicecooker(){
    header("Berikut pilihan Rice Cooker yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. RC 17KI - Rp255.000\n"
        "b. RC 12II - Rp240.000\n"
        "c. RC 14AC - Rp325.000\n"
        "d. RC 15CD - Rp270.000\n"
        "e. RC 17ZA - Rp250.000\n"
    );
    garis();

    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c",&pilihan);
    pilihan=tolower(pilihan);

    if(pilihan=='a'){ 
        harga=255000; 
        printf("Harga Rice Cooker 17KI: %d\n", harga);
        tambahBelanja("Rice Cooker 17KI",harga); 
    }
    else if(pilihan=='b'){ 
        harga=240000;
        printf("Harga Rice Cooker 12II: %d\n", harga); 
        tambahBelanja("Rice Cooker 12II",harga); 
    }
    else if(pilihan=='c'){ 
        harga=325000;
        printf("Harga Rice Cooker 14AC: %d\n", harga); 
        tambahBelanja("Rice Cooker 14AC",harga); 
    }
    else if(pilihan=='d'){ 
        harga=270000;
        printf("Harga Rice Cooker 15CD: %d\n", harga);
        tambahBelanja("Rice Cooker 15CD",harga); 
    }
    else if(pilihan=='e'){ 
        harga=250000; 
        printf("Harga Rice Cooker 17ZA: %d\n", harga);
        tambahBelanja("Rice Cooker 17ZA",harga); 
    }
    else if(pilihan=='x') {
        cetakStruk();
    }
    else if(pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        return SubRicecooker();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Rice Cooker lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c",&pilihan);

        if (pilihan=='k' || pilihan=='K'){
            return SubRicecooker();
        }
        else if(pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if(pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            return SubRicecooker();
        }
    }

    return 0;
}


int SubPowerbank(){
    header("Berikut pilihan Power Bank yang dapat anda pilih:");
    char pilihan;
    int harga;

    printf(
        "a. Power Bank 18C - Rp250.000\n"
        "b. Power Bank 19C - Rp270.000\n"
        "c. Power Bank 20C - Rp320.000\n"
        "d. Power Bank 21C - Rp350.000\n"
        "e. Power Bank 22C - Rp300.000\n"

    );
    garis();

    printf(GREEN "Masukkan pilihan Anda: " RESET);
    scanf(" %c", &pilihan);
    pilihan = tolower(pilihan);

    if (pilihan=='a'){ 
        harga = 250000; 
        printf("Harga Power Bank 18C: %d\n", harga);
        tambahBelanja("Power Bank 18C", harga);
    }
    else if (pilihan=='b'){ 
        harga = 270000; 
        printf("Harga Power Bank 19C: %d\n", harga);
        tambahBelanja("Power Bank 19C", harga);
    }
    else if (pilihan=='c'){ 
        harga = 320000;
        printf("Harga Power Bank 20C: %d\n", harga); 
        tambahBelanja("Power Bank 20C", harga);
    }
    else if (pilihan=='d'){ 
        harga = 350000; 
        printf("Harga Power Bank 21C: %d\n", harga);
        tambahBelanja("Power Bank 21C", harga);
    }
    else if (pilihan=='e'){ 
        harga = 300000;
        printf("Harga Power Bank 22C: %d\n", harga); 
        tambahBelanja("Power Bank 22C", harga);
    }
    else if (pilihan=='x') {
        cetakStruk();
    }
    else if (pilihan=='u') {
        pemilihan();
    }
    else {
        printf("PILHAN ANDA TIDAK VALID.\n");
        return SubPowerbank();
    }

    if (pilihan=='a' || pilihan=='b' || pilihan=='c' || pilihan=='d' || pilihan=='e'){
        printf("Ketik K untuk pesan Power Bank lagi, U untuk ke Menu Utama, X untuk selesai: ");
        scanf(" %c", &pilihan);

        if (pilihan=='k' || pilihan=='K'){
            return SubPowerbank();
        }
        else if (pilihan=='x' || pilihan=='X'){
            cetakStruk();
        }
        else if (pilihan=='u' || pilihan=='U'){
            pemilihan();
        }
        else {
            printf("PILHAN ANDA TIDAK VALID.\n");
            return SubPowerbank();
        }
    }
    return 0;
}

int tampilkanMenu() {
    int pilihanbesar;
    int valid;

    while (1) {
        header("                        MENU UTAMA");

        printf(
        "1.  Kulkas\n"
        "2.  Mesin Cuci\n"
        "3.  AC\n"
        "4.  TV\n"
        "5.  Kompor Listrik\n"
        "6.  Lampu LED\n"
        "7.  Kipas Mini\n"
        "8.  Senter LED\n"
        "9.  Stop Kontak\n"
        "10. Speaker Portable\n"
        "11. SmartWatch\n"
        "12. Drone\n"
        "13. Tablet\n"
        "14. Monitor\n"
        "15. Wireless Earphone\n"
        "16. Laptop\n"
        "17. Handphone\n"
        "18. Blender\n"
        "19. Rice Cooker\n"
        "20. Power Bank\n"
        "21. Cetak Struk\n"
        );

        garis();

        printf(GREEN "Masukkan pilihan Anda (1-21): " RESET);

        valid = scanf("%d", &pilihanbesar);

        
        if (!valid) {
            printf( "\nInput tidak valid! Harus angka 1-21.\n\n" );
            while (getchar() != '\n');
            continue; 
        }

        if (pilihanbesar < 1 || pilihanbesar > 21) {
            printf( "\nPilihan tidak valid! Silakan pilih angka 1-21.\n\n" );
            continue;
        }

        return pilihanbesar; 
    }
}

int pemilihan(){
    int pilih = tampilkanMenu();

    switch(pilih){
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
            printf("pilihan tidak valid!\n");
            pemilihan();
            break;
    }

    return 0;
}

int main(){


    header("        Selamat Datang di Toko Elektronik Kami!");

    printf("Promo Bonus Belanja berdasarkan total pembelian:\n\n");
    printf("PAKET 1  | Belanja Rp 3.000.000 - 9.999.999\n");
    printf("Bonus    : Lampu LED 10 Watt\n\n");

    printf("PAKET 2  | Belanja Rp 10.000.000 - 19.999.999\n");
    printf("Bonus    : Speaker Bluetooth Mini\n\n");

    printf("PAKET 3  | Belanja Rp 20.000.000 - 29.999.999\n");
    printf("Bonus    : Smart Band Xiaomi Smart Band 9\n\n");
    

    printf("PAKET 5  | Belanja Rp 40.000.000 - 59.999.999\n");
    printf("Bonus    : Tablet OPPO Pad SE (4/128)\n\n");

    printf("PAKET 6  | Belanja Rp 60.000.000 - 79.999.999\n");
    printf("Bonus    : Kulkas 1 Pintu\n\n");

    printf("PAKET 7  | Belanja Rp 80.000.000 atau lebih\n");
    printf("Bonus    : Kulkas 2 Pintu\n\n");


    garis();
    printf("Tekan ENTER untuk melanjutkan...");
    scanf("%*c");
    garis();
    printf("Silakan mulai memilih barang:\n");

    pemilihan();

    return 0;
}
