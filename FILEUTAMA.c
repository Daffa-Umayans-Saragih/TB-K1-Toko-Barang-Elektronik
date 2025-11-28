#include <stdio.h>

int main(){
    printf("Pilih jenis alat elektronik yang ingin Anda beli:\n");
    printf("1. Kulkas\n"
           "2. Mesin Cuci\n"
           "3. AC\n"
           "4. TV\n"
           "5. Kompor Listrik\n"
           "6. Kabel\n"
           "7. Speaker\n"
           "8. Microwave\n"
           "9. Blender\n"
           "10. Vacuum Cleaner\n"
           "11. Rice Cooker\n"
           "12. Water Heater\n"
           "13. Dispenser\n"
           "14. Oven Listrik\n"
           "15. Blender\n"
           "16. Vacuum Cleaner\n"
           "17. Air Purifier\n"
           "18. Juicer\n"
           "19. Setrika\n"
           "20. Air Fryer\n"
        );
           
    printf("Masukkan pilihan Anda (1-20): ");
    int pilihan;
    scanf("%d", &pilihan);
    switch(pilihan){
        case 1:
            printf("Berikut pilihan kulkas yang dapat anda pilih:\n");
            printf("Jenis Kulkas:\n"
                   "a. Kulkas 1 Pintu\n"
                   "b. Kulkas 2 Pintu\n"
                   "c. Kulkas Side by Side\n"
                   "d. Kulkas French Door\n"
                   "e. Kulkas Mini\n");
            printf("Masukkan pilihan Anda (a-e): ");

            scanf(" %c", &pilihan);
            int harga;
            if(pilihan == 'a'){
                harga = 3000000;
                printf("Harga Kulkas 1 Pintu: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 5000000;
                printf("Harga Kulkas 2 Pintu: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 8000000;
                printf("Harga Kulkas Side by Side: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 12000000;   
                printf("Harga Kulkas French Door: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 150000;
                printf("Harga Kulkas Mini: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 2:
            printf("Berikut pilihan mesin cuci yang dapat anda pilih:\n");
            printf("Jenis Mesin Cuci:\n"
                   "a. Mesin Cuci Top Loading\n"
                   "b. Mesin Cuci Front Loading\n"
                   "c. Mesin Cuci Semi Automatic\n"
                   "d. Mesin Cuci Portable\n"
                   "e. Mesin Cuci Twin Tub\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 2500000;
                printf("Harga Mesin Cuci Top Loading: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 4000000;
                printf("Harga Mesin Cuci Front Loading: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1500000;
                printf("Harga Mesin Cuci Semi Automatic: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1000000;   
                printf("Harga Mesin Cuci Portable: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1800000;
                printf("Harga Mesin Cuci Twin Tub: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 3:
            printf("Berikut pilihan AC yang dapat anda pilih:\n");
            printf("Jenis AC:\n"
                   "a. AC Split\n"
                   "b. AC Window\n"
                   "c. AC Portable\n"
                   "d. AC Central\n"
                   "e. AC Ducted\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 3500000;
                printf("Harga AC Split: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 2500000;
                printf("Harga AC Window: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 3000000;
                printf("Harga AC Portable: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 15000000;   
                printf("Harga AC Central: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 12000000;
                printf("Harga AC Ducted: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 4:
            printf("Berikut pilihan TV yang dapat anda pilih:\n");
            printf("Jenis TV:\n"
                   "a. LED TV\n"
                   "b. OLED TV\n"
                   "c. QLED TV\n"
                   "d. Smart TV\n"
                   "e. 4K TV\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 4000000;
                printf("Harga LED TV: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 10000000;
                printf("Harga OLED TV: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 8000000;
                printf("Harga QLED TV: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 6000000;   
                printf("Harga Smart TV: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 12000000;
                printf("Harga 4K TV: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 5:
            printf("Berikut pilihan Kompor Listrik yang dapat anda pilih:\n");
            printf("Jenis Kompor Listrik:\n"
                   "a. Kompor Induksi\n"
                   "b. Kompor Halogen\n"
                   "c. Kompor Keramik\n"
                   "d. Kompor Listrik Portable\n"
                   "e. Kompor Listrik Tanam\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 2000000;
                printf("Harga Kompor Induksi: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 1500000;
                printf("Harga Kompor Halogen: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1800000;
                printf("Harga Kompor Keramik: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1000000;   
                printf("Harga Kompor Listrik Portable: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 2500000;
                printf("Harga Kompor Listrik Tanam: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 6:
            printf("Berikut pilihan Kabel yang dapat anda pilih:\n");
            printf("Jenis Kabel:\n"
                   "a. Kabel Power\n"
                   "b. Kabel HDMI\n"
                   "c. Kabel USB\n"
                   "d. Kabel Ethernet\n"
                   "e. Kabel Audio\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 50000;
                printf("Harga Kabel Power: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 100000;
                printf("Harga Kabel HDMI: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 75000;
                printf("Harga Kabel USB: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 60000;   
                printf("Harga Kabel Ethernet: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 80000;
                printf("Harga Kabel Audio: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 7:
            printf("Berikut pilihan Speaker yang dapat anda pilih:\n");
            printf("Jenis Speaker:\n"
                   "a. Speaker Bluetooth\n"
                   "b. Speaker Wired\n"
                   "c. Speaker Home Theater\n"
                   "d. Speaker Soundbar\n"
                   "e. Speaker Portable\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 300000;
                printf("Harga Speaker Bluetooth: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 200000;
                printf("Harga Speaker Wired: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1500000;
                printf("Harga Speaker Home Theater: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 800000;   
                printf("Harga Speaker Soundbar: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 250000;
                printf("Harga Speaker Portable: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 8:
            printf("Berikut pilihan Microwave yang dapat anda pilih:\n");
            printf("Jenis Microwave:\n"
                   "a. Microwave Oven\n"
                   "b. Convection Microwave\n"
                   "c. Solo Microwave\n"
                   "d. Grill Microwave\n"
                   "e. Over-the-Range Microwave\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 1200000;
                printf("Harga Microwave Oven: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 2000000;
                printf("Harga Convection Microwave: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 800000;
                printf("Harga Solo Microwave: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1500000;   
                printf("Harga Grill Microwave: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 2500000;
                printf("Harga Over-the-Range Microwave: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 9:
            printf("Berikut pilihan Blender yang dapat anda pilih:\n");
            printf("Jenis Blender:\n"
                   "a. Blender Standar\n"
                   "b. Blender Handheld\n"
                   "c. Blender Personal\n"
                   "d. Blender High-Speed\n"
                   "e. Blender Multifungsi\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 300000;
                printf("Harga Blender Standar: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 250000;
                printf("Harga Blender Handheld: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 200000;
                printf("Harga Blender Personal: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 600000;   
                printf("Harga Blender High-Speed: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 500000;
                printf("Harga Blender Multifungsi: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 10:
            printf("Berikut pilihan Vacuum Cleaner yang dapat anda pilih:\n");
            printf("Jenis Vacuum Cleaner:\n"
                   "a. Vacuum Cleaner Stick\n"
                   "b. Vacuum Cleaner Robot\n"
                   "c. Vacuum Cleaner Handheld\n"
                   "d. Vacuum Cleaner Canister\n"
                   "e. Vacuum Cleaner Upright\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 800000;
                printf("Harga Vacuum Cleaner Stick: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 2500000;
                printf("Harga Vacuum Cleaner Robot: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 500000;
                printf("Harga Vacuum Cleaner Handheld: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1200000;   
                printf("Harga Vacuum Cleaner Canister: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1000000;
                printf("Harga Vacuum Cleaner Upright: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 11:
            printf("Berikut pilihan Rice Cooker yang dapat anda pilih:\n");
            printf("Jenis Rice Cooker:\n"
                   "a. Rice Cooker Elektrik\n"
                   "b. Rice Cooker Digital\n"
                   "c. Rice Cooker Multifungsi\n"
                   "d. Rice Cooker Mini\n"
                   "e. Rice Cooker Induksi\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 400000;
                printf("Harga Rice Cooker Elektrik: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 800000;
                printf("Harga Rice Cooker Digital: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1000000;
                printf("Harga Rice Cooker Multifungsi: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 300000;   
                printf("Harga Rice Cooker Mini: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1200000;
                printf("Harga Rice Cooker Induksi: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 12:
            printf("Berikut pilihan Water Heater yang dapat anda pilih:\n");
            printf("Jenis Water Heater:\n"
                   "a. Water Heater Listrik\n"
                   "b. Water Heater Gas\n"
                   "c. Water Heater Tankless\n"
                   "d. Water Heater Penyimpanan\n"
                   "e. Water Heater Surya\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 700000;
                printf("Harga Water Heater Listrik: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 900000;
                printf("Harga Water Heater Gas: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1500000;
                printf("Harga Water Heater Tankless: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1200000;   
                printf("Harga Water Heater Penyimpanan: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 2000000;
                printf("Harga Water Heater Surya: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 13:
            printf("Berikut pilihan Dispenser yang dapat anda pilih:\n");
            printf("Jenis Dispenser:\n"
                   "a. Dispenser Air Dingin\n"
                   "b. Dispenser Air Panas\n"
                   "c. Dispenser 3 in 1\n"
                   "d. Dispenser Galon Bawah\n"
                   "e. Dispenser Portable\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 600000;
                printf("Harga Dispenser Air Dingin: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 700000;
                printf("Harga Dispenser Air Panas: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 900000;
                printf("Harga Dispenser 3 in 1: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 800000;   
                printf("Harga Dispenser Galon Bawah: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 500000;
                printf("Harga Dispenser Portable: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 14:
            printf("Berikut pilihan Oven Listrik yang dapat anda pilih:\n");
            printf("Jenis Oven Listrik:\n"
                   "a. Oven Listrik Konvensional\n"
                   "b. Oven Listrik Convection\n"
                   "c. Oven Listrik Toaster\n"
                   "d. Oven Listrik Microwave\n"
                   "e. Oven Listrik Rotisserie\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 1500000;
                printf("Harga Oven Listrik Konvensional: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 2500000;
                printf("Harga Oven Listrik Convection: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 800000;
                printf("Harga Oven Listrik Toaster: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 2000000;   
                printf("Harga Oven Listrik Microwave: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1800000;
                printf("Harga Oven Listrik Rotisserie: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 15:
            printf("Berikut pilihan Blender yang dapat anda pilih:\n");
            printf("Jenis Blender:\n"
                   "a. Blender Standar\n"
                   "b. Blender Handheld\n"
                   "c. Blender Personal\n"
                   "d. Blender High-Speed\n"
                   "e. Blender Multifungsi\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 300000;
                printf("Harga Blender Standar: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 250000;
                printf("Harga Blender Handheld: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 200000;
                printf("Harga Blender Personal: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 600000;   
                printf("Harga Blender High-Speed: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 500000;
                printf("Harga Blender Multifungsi: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 16:
            printf("Berikut pilihan Vacuum Cleaner yang dapat anda pilih:\n");
            printf("Jenis Vacuum Cleaner:\n"
                   "a. Vacuum Cleaner Stick\n"
                   "b. Vacuum Cleaner Robot\n"
                   "c. Vacuum Cleaner Handheld\n"
                   "d. Vacuum Cleaner Canister\n"
                   "e. Vacuum Cleaner Upright\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 800000;
                printf("Harga Vacuum Cleaner Stick: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 2500000;
                printf("Harga Vacuum Cleaner Robot: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 500000;
                printf("Harga Vacuum Cleaner Handheld: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1200000;   
                printf("Harga Vacuum Cleaner Canister: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1000000;
                printf("Harga Vacuum Cleaner Upright: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 17:
            printf("Berikut pilihan Air Purifier yang dapat anda pilih:\n");
            printf("Jenis Air Purifier:\n"
                   "a. Air Purifier HEPA\n"
                   "b. Air Purifier Ionizer\n"
                   "c. Air Purifier UV\n"
                   "d. Air Purifier Carbon\n"
                   "e. Air Purifier Hybrid\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 1200000;
                printf("Harga Air Purifier HEPA: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 1000000;
                printf("Harga Air Purifier Ionizer: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1500000;
                printf("Harga Air Purifier UV: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1300000;   
                printf("Harga Air Purifier Carbon: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 2000000;
                printf("Harga Air Purifier Hybrid: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 18:
            printf("Berikut pilihan Juicer yang dapat anda pilih:\n");
            printf("Jenis Juicer:\n"
                   "a. Juicer Centrifugal\n"
                   "b. Juicer Masticating\n"
                   "c. Juicer Triturating\n"
                   "d. Juicer Manual\n"
                   "e. Juicer Slow\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 600000;
                printf("Harga Juicer Centrifugal: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 1200000;
                printf("Harga Juicer Masticating: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1500000;
                printf("Harga Juicer Triturating: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 300000;   
                printf("Harga Juicer Manual: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1000000;
                printf("Harga Juicer Slow: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 19:
            printf("Berikut pilihan Setrika yang dapat anda pilih:\n");
            printf("Jenis Setrika:\n"
                   "a. Setrika Uap\n"
                   "b. Setrika Kering\n"
                   "c. Setrika Travel\n"
                   "d. Setrika Vertikal\n"
                   "e. Setrika Otomatis\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 400000;
                printf("Harga Setrika Uap: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 300000;
                printf("Harga Setrika Kering: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 250000;
                printf("Harga Setrika Travel: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 500000;   
                printf("Harga Setrika Vertikal: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 700000;
                printf("Harga Setrika Otomatis: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;
        case 20:
            printf("Berikut pilihan Air Fryer yang dapat anda pilih:\n");
            printf("Jenis Air Fryer:\n"
                   "a. Air Fryer Digital\n"
                   "b. Air Fryer Analog\n"
                   "c. Air Fryer Oven\n"
                   "d. Air Fryer Toaster\n"
                   "e. Air Fryer Multifungsi\n");
            printf("Masukkan pilihan Anda (a-e): ");
            scanf(" %c", &pilihan);
            if(pilihan == 'a'){
                harga = 1000000;
                printf("Harga Air Fryer Digital: %d\n", harga);
            } else if(pilihan == 'b'){
                harga = 800000;
                printf("Harga Air Fryer Analog: %d\n", harga);
            } else if(pilihan == 'c'){
                harga = 1500000;
                printf("Harga Air Fryer Oven: %d\n", harga);
            } else if(pilihan == 'd'){
                harga = 1200000;   
                printf("Harga Air Fryer Toaster: %d\n", harga);
            } else if(pilihan == 'e'){
                harga = 1800000;
                printf("Harga Air Fryer Multifungsi: %d\n", harga);
            } else {
                printf("Pilihan tidak valid.\n");
            }
            break;    
        default:
            printf("Pilihan tidak valid.\n");
    }

}