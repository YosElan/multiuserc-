#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur untuk menyimpan data nilai siswa
struct NilaiSiswa {
    string nama;
    double matematika;
    double fisika;
    double bahasaIndo;
    double english;
    double nilaiOOP;
};

// Fungsi untuk menghitung rata-rata nilai siswa
double hitungRataRata(const NilaiSiswa& siswa) {
    return (siswa.matematika + siswa.fisika + siswa.bahasaIndo + siswa.english + siswa.nilaiOOP) / 5.0;
}

// Fungsi untuk menampilkan data nilai siswa
void tampilkanDataSiswa(const NilaiSiswa& siswa) {
    cout << setw(15) << "Nama"
         << setw(15) << "Matematika"
         << setw(15) << "Fisika"
         << setw(15) << "Bahasa Indo"
         << setw(15) << "English"
         << setw(15) << "Nilai OOP"
         << setw(15) << "Rata-rata" << endl;

    cout << setw(15) << siswa.nama
         << setw(15) << siswa.matematika
         << setw(15) << siswa.fisika
         << setw(15) << siswa.bahasaIndo
         << setw(15) << siswa.english
         << setw(15) << siswa.nilaiOOP
         << setw(15) << hitungRataRata(siswa) << endl;
}

// Fungsi untuk menampilkan data nilai semua siswa
void tampilkanDataSemuaSiswa(const vector<NilaiSiswa>& daftarSiswa) {
    cout << setw(15) << "Nama"
         << setw(15) << "Matematika"
         << setw(15) << "Fisika"
         << setw(15) << "Bahasa Indo"
         << setw(15) << "English"
         << setw(15) << "Nilai OOP"
         << setw(15) << "Rata-rata" << endl;

    for (const NilaiSiswa& siswa : daftarSiswa) {
        cout << setw(15) << siswa.nama
             << setw(15) << siswa.matematika
             << setw(15) << siswa.fisika
             << setw(15) << siswa.bahasaIndo
             << setw(15) << siswa.english
             << setw(15) << siswa.nilaiOOP
             << setw(15) << hitungRataRata(siswa) << endl;
    }
}

// Fungsi untuk mengurutkan data nilai siswa berdasarkan rata-rata
void urutkanBerdasarkanRataRata(vector<NilaiSiswa>& daftarSiswa, bool urutDariTertinggi) {
    sort(daftarSiswa.begin(), daftarSiswa.end(), [urutDariTertinggi](const NilaiSiswa& a, const NilaiSiswa& b) {
        return (urutDariTertinggi ? hitungRataRata(a) > hitungRataRata(b) : hitungRataRata(a) < hitungRataRata(b));
    });
}

// Fungsi untuk menghitung dan menampilkan nilai maximal dan minimal siswa
void hitungDanTampilkanMinMax(const NilaiSiswa& siswa) {
    double nilaiMax = max({siswa.matematika, siswa.fisika, siswa.bahasaIndo, siswa.english, siswa.nilaiOOP});
    double nilaiMin = min({siswa.matematika, siswa.fisika, siswa.bahasaIndo, siswa.english, siswa.nilaiOOP});

    cout << "Nilai maximal: " << nilaiMax << endl;
    cout << "Nilai minimal: " << nilaiMin << endl;
}

int main() {
    // Data nilai siswa
    vector<NilaiSiswa> daftarSiswa = {
        {"Siswa1", 78, 92, 85, 88, 90},
        {"Siswa2", 88, 75, 80, 95, 82},
        {"Siswa3", 95, 90, 92, 88, 85},
        {"Siswa4", 82, 88, 75, 90, 78}
    };

    // Informasi login Walas
    string usernameWalas = "walas";
    string passwordWalas = "12345";

    // Informasi login siswa
    vector<pair<string, string>> loginSiswa = {
        {"Siswa1", "Siswa1"},
        {"Siswa2", "Siswa2"},
        {"Siswa3", "Siswa3"},
        {"Siswa4", "Siswa4"}
    };

    // Loop eksternal untuk pengelolaan login
    while (true) {
        string inputUsername;
        string inputPassword;

        cout << "Masukkan username: ";
        cin >> inputUsername;
        cout << "Masukkan password: ";
        cin >> inputPassword;

        // Mengecek apakah input merupakan login Walas
        if (inputUsername == usernameWalas && inputPassword == passwordWalas) {
            // Loop untuk pengelolaan opsi Walas
            while (true) {
                cout << "\nPilihan Walas:\n";
                cout << "1. Tampilkan data nilai semua siswa\n";
                cout << "2. Urutkan data nilai siswa dari tertinggi berdasarkan rata-rata\n";
                cout << "3. Urutkan data nilai siswa dari terendah berdasarkan rata-rata\n";
                cout << "4. Keluar\n";

                int pilihanWalas;
                cout << "Masukkan pilihan: ";
                cin >> pilihanWalas;

                switch (pilihanWalas) {
                    case 1:
                        // Menampilkan data nilai semua siswa
                        tampilkanDataSemuaSiswa(daftarSiswa);
                        break;
                    case 2:
                        // Mengurutkan data nilai siswa dari tertinggi berdasarkan rata-rata
                        urutkanBerdasarkanRataRata(daftarSiswa, true);
                        tampilkanDataSemuaSiswa(daftarSiswa);
                        break;
                    case 3:
                        // Mengurutkan data nilai siswa dari terendah berdasarkan rata-rata
                        urutkanBerdasarkanRataRata(daftarSiswa, false);
                        tampilkanDataSemuaSiswa(daftarSiswa);
                        break;
                    case 4:
                        // Keluar dari loop opsi Walas
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }

                // Jika pengguna memilih keluar, keluar dari loop pengelolaan opsi Walas
                if (pilihanWalas == 4) {
                    break;
                }
            }
        }
        // Mengecek apakah input merupakan login siswa
        else {
            auto siswaLogin = find_if(loginSiswa.begin(), loginSiswa.end(),
                [inputUsername, inputPassword](const pair<string, string>& loginPair) {
                    return (loginPair.first == inputUsername && loginPair.second == inputPassword);
                }
            );

            if (siswaLogin != loginSiswa.end()) {
                // Loop untuk pengelolaan opsi siswa
                while (true) {
                    // Mencari data nilai siswa yang sesuai dengan login
                    auto siswaData = find_if(daftarSiswa.begin(), daftarSiswa.end(),
                        [inputUsername](const NilaiSiswa& siswa) {
                            return siswa.nama == inputUsername;
                        }
                    );

                    if (siswaData != daftarSiswa.end()) {
                        cout << "\nPilihan Siswa:\n";
                        cout << "1. Tampilkan data nilai saya\n";
                        cout << "2. Hitung dan tampilkan nilai maximal dan minimal saya\n";
                        cout << "3. Keluar\n";

                        int pilihanSiswa;
                        cout << "Masukkan pilihan: ";
                        cin >> pilihanSiswa;

                        switch (pilihanSiswa) {
                            case 1:
                                // Menampilkan data nilai siswa sendiri
                                tampilkanDataSiswa(*siswaData);
                                break;
                            case 2:
                                // Menghitung dan menampilkan nilai maximal dan minimal siswa
                                hitungDanTampilkanMinMax(*siswaData);
                                break;
                            case 3:
                                // Keluar dari loop opsi siswa
                                break;
                            default:
                                cout << "Pilihan tidak valid.\n";
                        }

                        // Jika pengguna memilih keluar, keluar dari loop pengelolaan opsi siswa
                        if (pilihanSiswa == 3) {
                            break;
                        }
                    } else {
                        cout << "Data nilai siswa tidak ditemukan.\n";
                        break;
                    }
                }
            } else {
                cout << "Login gagal. Username atau password salah.\n";
            }
        }
    }

    return 0;
}

