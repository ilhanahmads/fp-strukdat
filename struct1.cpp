#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    string nama;
    string jurusan;
    string NRP;
    int usia;
    string asal;
    string hobi;
    string gender;
    string nomorHP;
    float IPK;
    string alamat;
};

// Fungsi pilihan 1 (menampilkan data)
void tampilkanData(Mahasiswa mhs[], int jumlahMhs)
{
    for (int i = 0; i < jumlahMhs; i++)
    {
        cout << "========== Mahasiswa " << i + 1 << " ==========" << endl;
        cout << "Nama : " << mhs[i].nama << "\n";
        cout << "Jurusan : " << mhs[i].jurusan << "\n";
        cout << "NRP : " << mhs[i].NRP << "\n";
        cout << "Usia : " << mhs[i].usia << "\n";
        cout << "Asal : " << mhs[i].asal << "\n";
        cout << "Hobi : " << mhs[i].hobi << "\n";
        cout << "Gender : " << mhs[i].gender << "\n";
        cout << "Nomor HP : " << mhs[i].nomorHP << "\n";
        cout << "IPK : " << mhs[i].IPK << "\n";
        cout << "Alamat : " << mhs[i].alamat << "\n\n";
    }
}

// Fungsi pilihan 2 (menambahkan data)
void tambahData(Mahasiswa mhs[], int &jumlahMhs)
{
    if (jumlahMhs < 10)
    {
        cout << "Masukkan data mahasiswa ke-" << jumlahMhs + 1 << " :" << endl;
        cout << "Nama : ";
        cin >> mhs[jumlahMhs].nama;
        cout << "Jurusan : ";
        cin >> mhs[jumlahMhs].jurusan;
        cout << "NRP : ";
        cin >> mhs[jumlahMhs].NRP;
        cout << "Usia : ";
        cin >> mhs[jumlahMhs].usia;
        cout << "Asal : ";
        cin >> mhs[jumlahMhs].asal;
        cout << "Hobi : ";
        cin >> mhs[jumlahMhs].hobi;
        cout << "Gender : ";
        cin >> mhs[jumlahMhs].gender;
        cout << "Nomor HP : ";
        cin >> mhs[jumlahMhs].nomorHP;
        cout << "IPK : ";
        cin >> mhs[jumlahMhs].IPK;
        cout << "Alamat : ";
        cin >> mhs[jumlahMhs].alamat;

        jumlahMhs++;
        cout << "Data mahasiswa telah ditambahkan dan diperbarui." << endl;
    }
    else
    {
        cout << "Mohon maaf, jumlah data mahasiswa telah mencapai maksimum. Hapus salah satu data terlebih dahulu untuk menambahkan data baru." << endl;
    }
}

// Fungsi pilihan 3 (menghapus data)
void hapusData(Mahasiswa mhs[], int &jumlahMhs, int indeks)
{
    if (indeks >= 0 && indeks < jumlahMhs)
    {
        for (int i = indeks; i < jumlahMhs - 1; i++)
        {
            mhs[i] = mhs[i + 1];
        }
        jumlahMhs--;
        cout << "Data mahasiswa telah dihapus dan diperbarui." << endl;
    }
    else
    {
        cout << "Indeks data mahasiswa tidak valid." << endl;
    }
}

// Fungsi pilihan 4 (mengubah data)
void ubahData(Mahasiswa mhs[], int jumlahMhs)
{
    int indeksUbah;
    cout << "Masukkan indeks data yang ingin diubah : ";
    cin >> indeksUbah;

    if (indeksUbah >= 0 && indeksUbah < jumlahMhs)
    {
        cout << "Data saat ini untuk Mahasiswa " << indeksUbah + 1 << " :" << endl;
        cout << "Nama : " << mhs[indeksUbah].nama << "\n";
        cout << "Jurusan : " << mhs[indeksUbah].jurusan << "\n";
        cout << "NRP : " << mhs[indeksUbah].NRP << "\n";
        cout << "Usia : " << mhs[indeksUbah].usia << "\n";
        cout << "Asal : " << mhs[indeksUbah].asal << "\n";
        cout << "Hobi : " << mhs[indeksUbah].hobi << "\n";
        cout << "Gender : " << mhs[indeksUbah].gender << "\n";
        cout << "Nomor HP : " << mhs[indeksUbah].nomorHP << "\n";
        cout << "IPK : " << mhs[indeksUbah].IPK << "\n";
        cout << "Alamat : " << mhs[indeksUbah].alamat << "\n\n";

        cout << "Masukkan data yang baru :" << endl;
        cout << "Nama : ";
        cin >> mhs[indeksUbah].nama;
        cout << "Jurusan : ";
        cin >> mhs[indeksUbah].jurusan;
        cout << "NRP : ";
        cin >> mhs[indeksUbah].NRP;
        cout << "Usia : ";
        cin >> mhs[indeksUbah].usia;
        cout << "Asal : ";
        cin >> mhs[indeksUbah].asal;
        cout << "Hobi : ";
        cin >> mhs[indeksUbah].hobi;
        cout << "Gender : ";
        cin >> mhs[indeksUbah].gender;
        cout << "Nomor HP : ";
        cin >> mhs[indeksUbah].nomorHP;
        cout << "IPK : ";
        cin >> mhs[indeksUbah].IPK;
        cout << "Alamat : ";
        cin >> mhs[indeksUbah].alamat;

        cout << "Data mahasiswa telah diubah dan diperbarui." << endl;
    }
    else
    {
        cout << "Indeks data mahasiswa tidak valid." << endl;
    }
}

int main()
{
    Mahasiswa dataMahasiswa[10];
    int jumlahMahasiswa = 0;
    int opsi;

    do
    {
        cout << "Opsi :" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi : ";
        cin >> opsi;

        switch (opsi)
        {
        case 1:
            tampilkanData(dataMahasiswa, jumlahMahasiswa);
            break;
        case 2:
            tambahData(dataMahasiswa, jumlahMahasiswa);
            break;
        case 3:
            int indeksHapus;
            cout << "Masukkan indeks data yang akan dihapus : ";
            cin >> indeksHapus;
            hapusData(dataMahasiswa, jumlahMahasiswa, indeksHapus);
            break;
        case 4:
            ubahData(dataMahasiswa, jumlahMahasiswa);
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (opsi != 5);

    return 0;
}
