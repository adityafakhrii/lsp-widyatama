#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    int npm;
    char nama[50];
    char tempat_lahir[50];
    char prodi[50];
} Mahasiswa;

Mahasiswa data[MAX];
int jumlah = 0;

void tambahData() {
    if (jumlah < MAX) {
        printf("Masukkan NPM: ");
        scanf("%d", &data[jumlah].npm);
        getchar();
        
        printf("Masukkan Nama: ");
        fgets(data[jumlah].nama, sizeof(data[jumlah].nama), stdin);
        data[jumlah].nama[strcspn(data[jumlah].nama, "\n")] = '\0';
        
        printf("Masukkan Tempat Lahir: ");
        fgets(data[jumlah].tempat_lahir, sizeof(data[jumlah].tempat_lahir), stdin);
        data[jumlah].tempat_lahir[strcspn(data[jumlah].tempat_lahir, "\n")] = '\0';
        
        printf("Masukkan Prodi: ");
        fgets(data[jumlah].prodi, sizeof(data[jumlah].prodi), stdin);
        data[jumlah].prodi[strcspn(data[jumlah].prodi, "\n")] = '\0';
        
        jumlah++;
        printf("Data berhasil ditambahkan.\n");
    } else {
        printf("Kapasitas penyimpanan penuh.\n");
    }
}

void hapusData() {
    int npm, i, j, found = 0;
    printf("Masukkan NPM yang akan dihapus: ");
    scanf("%d", &npm);
    
    for (i = 0; i < jumlah; i++) {
        if (data[i].npm == npm) {
            for (j = i; j < jumlah - 1; j++) {
                data[j] = data[j + 1];
            }
            jumlah--;
            found = 1;
            printf("Data dengan NPM %d berhasil dihapus.\n", npm);
            break;
        }
    }
    if (!found) {
        printf("Data dengan NPM %d tidak ditemukan.\n", npm);
    }
}

void tampilData() {
    if (jumlah == 0) {
        printf("Tidak ada data yang tersimpan.\n");
    } else {
        for (int i = 0; i < jumlah; i++) {
            printf("NPM: %d\n", data[i].npm);
            printf("Nama: %s\n", data[i].nama);
            printf("Tempat Lahir: %s\n", data[i].tempat_lahir);
            printf("Prodi: %s\n", data[i].prodi);
            printf("-------------------------\n");
        }
    }
}

void menu() {
    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampil Data\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                tampilData();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);
}

int main() {
    menu();
    return 0;
}
