# 📚 Kurikulum Belajar C++ untuk Robotika & AI

> **Catatan:** Semua sub-bab dipelajari secara berurutan.  
> **Tinkercad** mulai digunakan pada **Modul 11**.  
> Setiap sub-bab yang memungkinkan akan disertai **mini project coding** yang menyenangkan 🎮

---

## Daftar Isi
- [Modul 1: Perkenalan C++ dan Lingkungan Kerja](#modul-1-perkenalan-c-dan-lingkungan-kerja)
- [Modul 2: Variabel dan Tipe Data Dasar](#modul-2-variabel-dan-tipe-data-dasar)
- [Modul 3: Operator dan Ekspresi](#modul-3-operator-dan-ekspresi)
- [Modul 4: Percabangan (Control Flow)](#modul-4-percabangan-control-flow)
- [Modul 5: Perulangan (Loops)](#modul-5-perulangan-loops)
- [Modul 6: Fungsi](#modul-6-fungsi)
- [Modul 7: Array dan String Lanjutan](#modul-7-array-dan-string-lanjutan)
- [Modul 8: Pointer dan Referensi](#modul-8-pointer-dan-referensi)
- [Modul 9: Struct](#modul-9-struct)
- [Modul 10: Pengantar OOP](#modul-10-pengantar-pemrograman-berorientasi-objek-oop)
- [Modul 11: Masuk ke Dunia Arduino & Tinkercad](#modul-11-masuk-ke-dunia-arduino--tinkercad)
- [Modul 12: Digital I/O pada Arduino](#modul-12-digital-io-pada-arduino)
- [Modul 13: Analog I/O dan PWM](#modul-13-analog-io-dan-pwm)
- [Modul 14: Sensor dan Aktuator Dasar](#modul-14-sensor-dan-aktuator-dasar-di-tinkercad)
- [Modul 15: Komunikasi Serial](#modul-15-komunikasi-serial-untuk-debugging-dan-kontrol)
- [Modul 16: OOP dengan Arduino](#modul-16-mengintegrasikan-oop-dengan-arduino)
- [Modul 17: Logika Robotika & AI Sederhana](#modul-17-pengantar-logika-robotika--ai-sederhana)
- [Modul 18: Membaca dan Menulis Data](#modul-18-membaca-dan-menulis-data-ke-komputer)
- [Modul 19: Proyek Robot Penghindar Rintangan](#modul-19-proyek-menengah--simulasi-robot-penghindar-rintangan)
- [Modul 20: Proyek Akhir – Smart Parking System](#modul-20-proyek-akhir-portofolio--smart-parking-system)

---

### Modul 1: Perkenalan C++ dan Lingkungan Kerja
- **1a:** Apa itu C++ dan mengapa dipakai di robotika? (analogi: C++ adalah bahasa yang dipahami mikrokontroler)
- **1b:** Menginstal compiler (g++) dan text editor / IDE (rekomendasi: Code::Blocks atau VS Code + terminal) — langkah sangat detail
- **1c:** Program pertama: "Hello, World!" — struktur dasar (`main`, `#include <iostream>`, `std::cout`)
- **1d:** Cara kompilasi dan menjalankan program via terminal (tanpa membahas linker/preprocessor mendalam)
- **1e:** Komentar di kode dan pentingnya dokumentasi

### Modul 2: Variabel dan Tipe Data Dasar
- **2a:** Konsep variabel sebagai kotak penyimpanan berlabel
- **2b:** Tipe data integer (`int`) dan bilangan riil (`float`, `double`) — deklarasi & inisialisasi
- **2c:** Tipe data karakter (`char`) dan boolean (`bool`)
- **2d:** Tipe string (`std::string`) dari `<string>` — perbandingan singkat dengan C-string
- **2e:** Konstanta (`const`) dan aturan penamaan variabel
- **2f:** Input dari pengguna dengan `std::cin`

### Modul 3: Operator dan Ekspresi
- **3a:** Operator aritmatika (`+`, `-`, `*`, `/`, `%`) — analogi mesin hitung
- **3b:** Operator penugasan (`=`, `+=`, `-=`, dll.)
- **3c:** Operator perbandingan (`==`, `!=`, `<`, `>`, `<=`, `>=`)
- **3d:** Operator logika (`&&`, `||`, `!`) untuk pengambilan keputusan
- **3e:** Operator increment/decrement (`++`, `--`) serta postfix vs prefix (ringkas)
- **3f:** Konversi tipe data (type casting) implisit dan eksplisit
- **3g:** Prioritas operator dan penggunaan tanda kurung

### Modul 4: Percabangan (Control Flow)
- **4a:** Struktur `if` — analogi “kalau hujan bawa payung”
- **4b:** `if-else` dan nested `if`
- **4c:** `else if` untuk banyak kondisi
- **4d:** Operator ternary (`?:`) sebagai ringkasan `if-else`
- **4e:** Struktur `switch-case` (kapan menggunakannya)

### Modul 5: Perulangan (Loops)
- **5a:** Konsep perulangan — kenapa robot butuh mengulang tindakan
- **5b:** Perulangan `for` — sintaks, variabel counter, contoh mencetak angka
- **5c:** Perulangan `while` — selama kondisi benar
- **5d:** Perulangan `do-while` — dijalankan minimal sekali
- **5e:** Kontrol perulangan: `break` dan `continue`
- **5f:** Perulangan bersarang (nested loop) — contoh membuat pola bintang

### Modul 6: Fungsi
- **6a:** Konsep fungsi: resep yang bisa dipanggil berulang
- **6b:** Deklarasi dan definisi fungsi — return type, nama, parameter
- **6c:** Fungsi tanpa nilai balik (`void`)
- **6d:** Parameter dan argumen — pass by value
- **6e:** Lingkup variabel (global vs lokal)
- **6f:** Overloading fungsi (nama sama, parameter beda) — perkenalan
- **6g:** Rekursi dasar — fungsi memanggil diri sendiri (contoh faktorial, hati-hati base case)

### Modul 7: Array dan String Lanjutan
- **7a:** Mengapa array? — analogi loker berlabel nomor
- **7b:** Deklarasi dan inisialisasi array 1D, indeks dimulai dari 0
- **7c:** Looping melalui array dengan `for`
- **7d:** Array multidimensi (2D) — tabel data sensor
- **7e:** String C-style (array of char) vs `std::string` — operasi dasar: length, concatenation, akses karakter
- **7f:** Membalik string, mencari karakter, substring (method dasar `std::string`)

### Modul 8: Pointer dan Referensi
- **8a:** Alamat memori dan operator `&` — apa itu alamat variabel?
- **8b:** Deklarasi pointer, operator `*` untuk dereference — analogi alamat rumah dan isi rumah
- **8c:** Pointer dan array — hubungan erat
- **8d:** Pass by reference dengan reference (`&`) — menghindari copy data besar
- **8e:** Pointer sebagai parameter fungsi (pass by pointer)
- **8f:** Dynamic memory allocation: `new` dan `delete` — inti, fokus pada “mengapa” untuk robotika

### Modul 9: Struct
- **9a:** Membungkus beberapa variabel menjadi satu struct (analogi: KTP berisi nama, alamat, umur)
- **9b:** Mendefinisikan struct, membuat variabel struct, mengakses anggota
- **9c:** Array of struct — menyimpan banyak data sensor
- **9d:** Nested struct (struct di dalam struct) — sekilas
- **9e:** Passing struct ke fungsi (by value, by reference)

### Modul 10: Pengantar Pemrograman Berorientasi Objek (OOP)
- **10a:** Paradigma OOP — analogi: cetak biru mobil vs mobil sungguhan
- **10b:** Class dan Object — definisi class, membuat instance
- **10c:** Access specifier: `public` dan `private` — enkapsulasi
- **10d:** Constructor — fungsi otomatis saat objek lahir
- **10e:** Method (fungsi anggota) — setter dan getter
- **10f:** Destructor — sekilas pembersihan
- **10g:** Inheritance (pewarisan) — “class RobotDasar” diturunkan ke “RobotBerkaki”
- **10h:** Polymorphism dasar — fungsi virtual (sekilas untuk pemahaman)

### Modul 11: Masuk ke Dunia Arduino & Tinkercad
- **11a:** Apa itu mikrokontroler? (otak kecil robot) — analogi dengan komputer mini
- **11b:** Mengenal Arduino Uno: pin digital, analog, power — diagram
- **11c:** Menginstal Arduino IDE dan memilih board
- **11d:** Membuat akun Tinkercad dan memulai sirkuit virtual
- **11e:** Struktur program Arduino: `setup()` dan `loop()`
- **11f:** Program Arduino pertama: menyalakan LED built-in (tanpa komponen eksternal) — simulasi Tinkercad

### Modul 12: Digital I/O pada Arduino
- **12a:** `pinMode`, `digitalWrite`, `digitalRead` — mengontrol pin
- **12b:** Menyalakan LED eksternal dengan resistor (simulasi)
- **12c:** Membaca tombol tekan (push button) — logika input pull-up
- **12d:** Proyek mini: LED menyala hanya saat tombol ditekan (simulasi)

### Modul 13: Analog I/O dan PWM
- **13a:** Sinyal analog vs digital — analogi volume suara
- **13b:** `analogRead` — membaca potensiometer (simulasi)
- **13c:** `analogWrite` dan PWM — meredupkan LED (fading)
- **13d:** Proyek mini: Kontrol kecerahan LED dengan potensiometer

### Modul 14: Sensor dan Aktuator Dasar di Tinkercad
- **14a:** Sensor ultrasonik HC-SR04 — cara kerja (simulasi)
- **14b:** Membaca jarak dengan sensor ultrasonik dan menampilkan di Serial Monitor
- **14c:** Sensor suhu LM35 — mengonversi nilai analog ke suhu
- **14d:** Menggerakkan motor DC dengan driver L293D (simulasi)
- **14e:** Servo motor — mengontrol sudut dengan library Servo
- **14f:** Proyek mini: Termometer digital (LM35 + LCD 16x2) — menampilkan suhu di layar virtual

### Modul 15: Komunikasi Serial untuk Debugging dan Kontrol
- **15a:** `Serial.begin`, `Serial.print`, `Serial.println` — mengirim data ke PC
- **15b:** `Serial.read` dan parsing data — menerima perintah dari Serial Monitor
- **15c:** Proyek mini: Kendalikan LED via perintah teks (“ON”/”OFF”) dari Serial Monitor

### Modul 16: Mengintegrasikan OOP dengan Arduino
- **16a:** Membuat class untuk LED — menyembunyikan pin dan method
- **16b:** Membuat class untuk Sensor Ultrasonik
- **16c:** Memisahkan kode menjadi file header (`.h`) dan implementasi (`.cpp`) — sekilas
- **16d:** Proyek mini: Buat library sendiri untuk motor DC dan gunakan di program utama

### Modul 17: Pengantar Logika Robotika & AI Sederhana
- **17a:** Konsep robot line follower — membaca sensor garis
- **17b:** Decision making berdasarkan sensor (if-else berlapis)
- **17c:** State machine sederhana — contoh robot dengan state “maju”, “mundur”, “berhenti”
- **17d:** Simulasi robot line follower 2 sensor di Tinkercad

### Modul 18: Membaca dan Menulis Data ke Komputer
- **18a:** Dasar `fstream`: `ofstream`, `ifstream` — menulis log sensor ke file teks
- **18b:** Membaca file CSV (format manual parsing) di C++
- **18c:** Simulasi offline: program C++ murni yang mensimulasikan pembacaan data sensor lalu menyimpan ke file

### Modul 19: Proyek Menengah – Simulasi Robot Penghindar Rintangan
- **19a:** Arsitektur program: baca sensor jarak, kendalikan motor
- **19b:** Algoritma: jika jarak < 30 cm, mundur dan belok
- **19c:** Implementasi bertahap di Tinkercad, debug dengan Serial Monitor
- **19d:** Tambahkan LED indikator bahaya

### Modul 20: Proyek Akhir (Portofolio) – Smart Parking System
Proyek besar dikerjakan secara terarah dengan bimbingan langkah demi langkah.  
**“Smart Parking System” di Tinkercad** — simulasi tempat parkir mini dengan:
- Sensor ultrasonik untuk mendeteksi mobil
- Menampilkan slot tersedia di LCD
- Membuka/menutup palang otomatis (servo)

Semua logika ditulis dalam **C++ Arduino**, menerapkan OOP, array, serial debugging, dan state machine.  
Proyek ini hanya menggunakan konsep dari Modul 1–19.