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
void tambahTugas() {
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
    while (dataTugas[i].nama_matkul != "") {
        i++;
    }

    // Menambahkan Data Tugas Ke Array
    dataTugas[i].nama_matkul = nama_matkul;
    dataTugas[i].deskripsi_tugas = deskripsi_tugas;
    dataTugas[i].deadline.tanggal = tanggal;
    dataTugas[i].deadline.bulan = bulan;
    dataTugas[i].deadline.jam = jam;
    dataTugas[i].status = status;

    cout << "Tugas berhasil ditambahkan!" << endl;
    cout << "Tambah tugas lagi? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        tambahTugas(); // <-- Letak Rekursi
    } system("cls");
}

// Fungsi Untuk Melihat Daftar Tugas
void lihatDaftarTugas() {
    system("cls");
    cout << "**Daftar Tugas**" << endl;

    for (int i = 0; i < 100; i++) {
        if (dataTugas[i].nama_matkul != "") {
            cout << "-------------------------" << endl;
            cout << "Nama Mata Kuliah: " << dataTugas[i].nama_matkul << endl;
            cout << "Deskripsi Tugas: " << dataTugas[i].deskripsi_tugas << endl;
            cout << "Deadline: " << dataTugas[i].deadline.tanggal << " " << dataTugas[i].deadline.bulan << " " << dataTugas[i].deadline.jam << endl;
            cout << "Status: ";
            if (dataTugas[i].status == 0) {
                cout << "Belum Dikerjakan" << endl;
            } 
            else if (dataTugas[i].status == STATUS_SEDANG_DIKERJAKAN) {
                cout << "Sedang Dikerjakan" << endl;
            } else {
                cout << "Selesai" << endl;
            }
        }
    }
}

// Fungsi untuk mengubah status tugas
void ubahStatusTugas() {
    int id_tugas;

    cout << "**Ubah Status Tugas**" << endl;
    cout << "Masukkan ID tugas: ";
    cin >> id_tugas;

    // Mencari Data Tugas Dengan ID Yang Diberikan
    int i = 0;
    while (dataTugas[i].nama_matkul != "" && i < 100) {
        if (i == id_tugas) {
            break;
        }
        i++;
    }

    if (dataTugas[i].nama_matkul == "") {
        cout << "ID tugas tidak ditemukan!" << endl;
        return;
    }

    cout << "Status tugas saat ini: ";
    if (dataTugas[i].status == STATUS_BELUM_DIKERJAKAN) {
        cout << "Belum Dikerjakan" << endl;
    } else if (dataTugas[i].status == STATUS_SEDANG_DIKERJAKAN) {
        cout << "Sedang Dikerjakan" << endl;
    } else {
        cout << "Selesai" << endl;
    }

    cout << "Masukkan status baru (0: Belum Dikerjakan, 1: Sedang Dikerjakan, 2: Selesai): ";
    cin >> dataTugas[i].status;

    // Validasi Input Status Baru
    if (dataTugas[i].status < STATUS_BELUM_DIKERJAKAN || dataTugas[i].status > STATUS_SELESAI) {
        cout << "Status baru tidak valid!" << endl;
        return;
    }
    cout << "Status tugas berhasil diubah!" << endl;
}

// Fungsi untuk menghapus tugas berdasarkan indeks data
void hapusTugas() {
    int id_tugas;

    cout << "**Hapus Tugas**" << endl;
    cout << "Masukkan ID tugas: ";
    cin >> id_tugas;

    if (id_tugas < 0 || id_tugas >= 100 || dataTugas[id_tugas].nama_matkul == "") {
        cout << "Indeks tugas tidak valid atau tidak ditemukan!" << endl;
        return;
    }

    cout << "Tugas pada indeks " << id_tugas << " berhasil dihapus!" << endl;
    dataTugas[id_tugas].nama_matkul = "";
    dataTugas[id_tugas].deskripsi_tugas = "";
    dataTugas[id_tugas].deadline.tanggal = 0; // Set nilai default untuk tanggal
    dataTugas[id_tugas].deadline.bulan = ""; // Set nilai default untuk bulan
    dataTugas[id_tugas].deadline.jam = ""; // Set nilai default untuk jam
    dataTugas[id_tugas].status = STATUS_BELUM_DIKERJAKAN;
}

int main() {
    if (!login()) { // Menjalankan login function
       return 1; // Jika login gagal, program akan berhenti
    }
    // Fungsi Untuk Menampilkan Menu
    int menu;
    do{
        cout << "!!WELCOME DI JOKI TUGAS!!" << endl;
        cout << "1. Tambah Tugas" << endl;
        cout << "2. Lihat Daftar Tugas" << endl;
        cout << "3. Ubah Status Tugas" << endl;
        cout << "4. Hapus Tugas" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        switch (menu) {
            case 1:
                tambahTugas();
                break;
            case 2:
                lihatDaftarTugas();
                break;
            case 3:
                ubahStatusTugas();
                break;
            case 4:
                hapusTugas();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
        }
    } while (menu != 5);
    cout << "Terima kasih telah menggunakan program ini!\n";
}
