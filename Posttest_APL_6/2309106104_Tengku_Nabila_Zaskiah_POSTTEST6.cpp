#include <iostream>
#include <string>

using namespace std;

// Fungsi login
int login() {
    system("cls");
    int loginAttempt = 0;
    string nama, nim;

    // Login
    while (loginAttempt < 3) {
        cout << "Masukkan Nama Anda: ";
        cin >> nama;
        cout << "Masukkan NIM Anda: ";
        cin >> nim;

        // Simulasi login (contoh: nama = "bila", nim = "104")
        system("cls");
        if (nama == "bila" && nim == "104") {
            cout << "Login berhasil! Welcome!, " << nama << "!" << endl;
            return 1;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            loginAttempt++;
        }
    }

    if (loginAttempt >= 3) {
        cout << "Anda telah gagal login sebanyak 3 kali. Mianhaeyo Program berhenti." << endl;
        return 0;
    }
}

// Deklarasi Nested Struct
struct Deadline {
    int tanggal;
    string bulan;
    string jam;
};

// Deklarasi Struct DataTugas
struct DataTugas {
    string nama_matkul;
    string deskripsi_tugas;
    Deadline deadline;
    int status; //( 0: Belum Dikerjakan, 1: Sedang Dikerjakan, 2: Selesai)
};

// Deklarasi Status Pengerjaan Tugas 
const int STATUS_BELUM_DIKERJAKAN = 0;
const int STATUS_SEDANG_DIKERJAKAN = 1;
const int STATUS_SELESAI = 2;

// Deklarasi Array dataTugas
DataTugas dataTugas[100]; // Maksimal 100 tugas

// Fungsi Untuk Menambahkan Tugas
void tambahTugas(DataTugas* &dataTugasPtr) {
    system("cls");
    string nama_matkul, deskripsi_tugas;
    int tanggal;
    string bulan, jam;
    int status;

    cout << "**Tambah Tugas**" << endl;

    cout << "Masukkan nama mata kuliah: ";
    cin >> nama_matkul;

    cout << "Masukkan deskripsi tugas: ";
    cin.ignore();
    getline(cin, deskripsi_tugas);

    cout << "Masukkan deadline tugas (tanggal): ";
    cin >> tanggal;
    cout << "Masukkan bulan deadline (nama): ";
    cin >> bulan;
    cout << "Masukkan jam deadline (hh:mm): ";
    cin >> jam;

    cout << "Masukkan status tugas (0: Belum Dikerjakan, 1: Sedang Dikerjakan, 2: Selesai): ";
    cin >> status;

    // Mencari Index Kosong Di Array
    int i = 0;
    while ((dataTugasPtr + i)->nama_matkul != "") {
        i++;
    }

    // Menambahkan Data Tugas Ke Array
    (dataTugasPtr + i)->nama_matkul = nama_matkul;
    (dataTugasPtr + i)->deskripsi_tugas = deskripsi_tugas;
    (dataTugasPtr + i)->deadline.tanggal = tanggal;
    (dataTugasPtr + i)->deadline.bulan = bulan;
    (dataTugasPtr + i)->deadline.jam = jam;
    (dataTugasPtr + i)->status = status;

    cout << "Tugas berhasil ditambahkan!" << endl;
    cout << "Tambah tugas lagi? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        tambahTugas(dataTugasPtr); // <-- Letak Rekursif
    } 
    system("cls");
}

// Fungsi Untuk Melihat Daftar Tugas
void lihatDaftarTugas(DataTugas* dataTugas) {
    system("cls");
    cout << "**Daftar Tugas**" << endl;

    for (int i = 0; i < 100; i++) {
        if ((dataTugas + i)->nama_matkul != "") {
            cout << "-------------------------" << endl;
            cout << "Nama Mata Kuliah: " << (dataTugas + i)->nama_matkul << endl;
            cout << "Deskripsi Tugas: " << (dataTugas + i)->deskripsi_tugas << endl;
            cout << "Deadline: " << (dataTugas + i)->deadline.tanggal << " " << (dataTugas + i)->deadline.bulan << " " << (dataTugas + i)->deadline.jam << endl;
            cout << "Status: ";
            if ((dataTugas + i)->status == 0) {
                cout << "Belum Dikerjakan" << endl;
            } 
            else if ((dataTugas + i)->status == STATUS_SEDANG_DIKERJAKAN) {
                cout << "Sedang Dikerjakan" << endl;
            } else {
                cout << "Selesai" << endl;
            }
        }
    }
}

// Fungsi untuk mengubah status tugas
void ubahStatusTugas(DataTugas* dataTugas) {
    int id_tugas;

    cout << "**Ubah Status Tugas**" << endl;
    cout << "Masukkan ID tugas: ";
    cin >> id_tugas;

    // Mencari Data Tugas Dengan ID Yang Diberikan
    int i = 0;
    while ((dataTugas + i)->nama_matkul != "" && i < 100) {
        if (i == id_tugas - 1) {
            break;
        }
        i++;
    }

    if ((dataTugas + i)->nama_matkul == "") {
        cout << "ID tugas tidak ditemukan!" << endl;
        return;
    }

    cout << "Status tugas saat ini: ";
    if ((dataTugas + i)->status == STATUS_BELUM_DIKERJAKAN) {
        cout << "Belum Dikerjakan" << endl;
    } else if ((dataTugas + i)->status == STATUS_SEDANG_DIKERJAKAN) {
        cout << "Sedang Dikerjakan" << endl;
    } else {
        cout << "Selesai" << endl;
    }
    
    cout << "Masukkan status baru (0: Belum Dikerjakan, 1: Sedang Dikerjakan, 2: Selesai): ";
    cin >> (dataTugas + i)->status;

    // Validasi Input Status Baru
    if ((dataTugas + i)->status < STATUS_BELUM_DIKERJAKAN || (dataTugas + i)->status > STATUS_SELESAI) {
        cout << "Status baru tidak valid!" << endl;
        return;
    }
    cout << "Status tugas berhasil diubah!" << endl;
}

// Fungsi untuk menghapus tugas berdasarkan indeks data
void hapusTugas(DataTugas* dataTugasPtr) {
    int id_tugas;

    cout << "**Hapus Tugas**" << endl;
    cout << "Masukkan ID tugas: ";
    cin >> id_tugas;

    // Mencari Data Tugas Dengan ID Yang Diberikan
    int i = 0;
    while ((dataTugasPtr + i)->nama_matkul != "" && i < 100) {
        if (i == id_tugas - 1) {
            break;
        }
        i++;
    }

    if ((dataTugasPtr + i)->nama_matkul == "") {
        cout << "ID tugas tidak ditemukan!" << endl;
        return;
    }

    cout << "Tugas pada indeks " << id_tugas << " berhasil dihapus!" << endl;
    (dataTugasPtr + i)->nama_matkul = "";
    (dataTugasPtr + i)->deskripsi_tugas = "";
    (dataTugasPtr + i)->deadline.tanggal = 0; // Set nilai default untuk tanggal
    (dataTugasPtr + i)->deadline.bulan = ""; // Set nilai default untuk bulan
    (dataTugasPtr + i)->deadline.jam = ""; // Set nilai default untuk jam
    (dataTugasPtr + i)->status = STATUS_BELUM_DIKERJAKAN;
}

// Fungsi untuk melakukan sorting nama mata kuliah secara descending
void sortNamaMatkulDescending(DataTugas* dataTugasPtr) {
    int n = 100;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dataTugasPtr + j)->nama_matkul < (dataTugasPtr + j + 1)->nama_matkul) {
                swap(dataTugasPtr[j], dataTugasPtr[j + 1]);
            }
        }
    }
}

// Fungsi untuk melakukan sorting deadline tanggal secara ascending
void sortDeadlineAscending(DataTugas* dataTugasPtr) {
    int n = 100;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dataTugasPtr + j)->deadline.tanggal > (dataTugasPtr + j + 1)->deadline.tanggal) {
                swap(dataTugasPtr[j], dataTugasPtr[j + 1]);
            }
        }
    }
}

// Fungsi untuk melakukan sorting status secara ascending
void sortStatusAscending(DataTugas* dataTugasPtr) {
    int n = 100;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dataTugasPtr + j)->deadline.tanggal > (dataTugasPtr + j + 1)->deadline.tanggal ||
                ((dataTugasPtr + j)->deadline.tanggal == (dataTugasPtr + j + 1)->deadline.tanggal &&
                 (dataTugasPtr + j)->deadline.bulan > (dataTugasPtr + j + 1)->deadline.bulan) ||
                ((dataTugasPtr + j)->deadline.tanggal == (dataTugasPtr + j + 1)->deadline.tanggal &&
                 (dataTugasPtr + j)->deadline.bulan == (dataTugasPtr + j + 1)->deadline.bulan &&
                 (dataTugasPtr + j)->deadline.jam > (dataTugasPtr + j + 1)->deadline.jam)) {
                swap(dataTugasPtr[j], dataTugasPtr[j + 1]);
            }
        }
    }
}

// Fungsi untuk mencari data mata kuliah pada array yang terurut secara ascending
// Fungsi untuk mencari data mata kuliah pada array yang terurut secara ascending
int searchNamaMatkulAscending(DataTugas* dataTugasPtr, string key) {
    for (int i = 0; i < 100; i++) {
        if ((dataTugasPtr + i)->nama_matkul == key) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk mencari data mata kuliah pada array yang terurut secara descending
int searchNamaMatkulDescending(DataTugas* dataTugasPtr, string key) {
    for (int i = 0; i < 100; i++) {
        if ((dataTugasPtr + i)->nama_matkul == key) {
            return i;
        }
    }
    return -1;
}

// Fungsi Utama
int main() {
    // Penyimpanan Data Tugas
    DataTugas* dataTugasPtr = dataTugas;

    // Login
    if (login()) {
        int menu;

        do {
            // Tampilan Menu
            cout << "=========!WELCOME DI JOKI TUGAS=========" << endl;
            cout << "|1. Tambah Tugas                       |" << endl;
            cout << "|2. Lihat Daftar Tugas                 |" << endl;
            cout << "|3. Ubah Status Tugas                  |" << endl;
            cout << "|4. Hapus Tugas                        |" << endl;
            cout << "|5. Sort Nama Mata Kuliah Descending   |" << endl;
            cout << "|6. Sort Deadline Ascending            |" << endl;
            cout << "|7. Sort Status Ascending              |" << endl;
            cout << "|8. Cari Nama Mata Kuliah Ascending    |" << endl;
            cout << "|9. Cari Nama Mata Kuliah Descending   |" << endl;
            cout << "|10. Keluar                            |" << endl;
            cout << "=======================================" << endl;
            cout << "Pilihan Anda: ";
            cin >> menu;

            // Pilihan Menu
            switch (menu) {
                case 1:
                    tambahTugas(dataTugasPtr);
                    break;
                case 2:
                    lihatDaftarTugas(dataTugasPtr);
                    break;
                case 3:
                    ubahStatusTugas(dataTugasPtr);
                    break;
                case 4:
                    hapusTugas(dataTugasPtr);
                    break;
                case 5:
                    sortNamaMatkulDescending(dataTugasPtr);
                    cout << "Sorting nama mata kuliah descending berhasil!" << endl;
                    break;
                case 6:
                    sortDeadlineAscending(dataTugasPtr);
                    cout << "Sorting deadline ascending berhasil!" << endl;
                    break;
                case 7:
                    sortStatusAscending(dataTugasPtr);
                    cout << "Sorting status ascending berhasil!" << endl;
                    break;
                case 8:
                    {
                        string key;
                        cout << "Masukkan nama mata kuliah yang ingin dicari: ";
                        cin >> key;
                        int index = searchNamaMatkulAscending(dataTugasPtr, key);
                        if (index != -1) {
                            cout << "Data ditemukan pada indeks " << index << endl;
                        } else {
                            cout << "Data tidak ditemukan" << endl;
                        }
                    }
                    break;
                case 9:
                    {
                        string key;
                        cout << "Masukkan nama mata kuliah yang ingin dicari: ";
                        cin >> key;
                        int index = searchNamaMatkulDescending(dataTugasPtr, key);
                        if (index != -1) {
                            cout << "Data ditemukan pada indeks " << index << endl;
                        } else {
                            cout << "Data tidak ditemukan" << endl;
                        }
                    }
                    break;
                case 10:
                    cout << "Terima kasih telah menggunakan aplikasi ini. Sampai jumpa lagi!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
            }
        } while (menu != 10);
    }
    cout << "Terima kasih telah menggunakan program ini!\n";
    return 0;
}
