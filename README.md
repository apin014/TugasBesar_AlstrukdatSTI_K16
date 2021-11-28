# TugasBesar_AlstrukdatSTI_K16
Ini adalah repository tugas besar kelompok 16 mata kuliah IF2111 Algoritma dan Struktur Data STI Semester Ganjil 2021/2022
Anggota:
1. Muhammad Davin Dzimar 18220046
2. Theodore Justin Lionar 18220011
3. Fikri Muhammad Fahreza 18220012
4. Bryan Eagan 18220041
5. Verawati Esteria S. Simatupang 18220002

## Deskripsi Singkat Program
Permainan **"Mobitangga"** adalah *digital board game* yang mengandung unsur permainan ular tangga, dipadukan dengan elemen *skill* yang memiliki bermacam efek mulai dari memberikan *buff* kepada pemain yang menggunakannya, hingga menggerakkan lawan secara paksa pada peta permainan. Permainan akan terus berputar hingga akhirnya salah satu dari 2 pemain berhasil mencapai petak terakhir pada *map*. Konfigurasi yang digunakan dalam setiap permainan dibaca dari file eksternal, terkandung di dalamnya adalah:
- Panjang *map*
- Representasi *map* berupa deretan karakter
- Nilai terbesar dari hasil *roll* dadu
- Jumlah *teleporter* yang berada pada *map*
- Pintu masuk dan pintu keluar setiap *teleporter*
<br />

## Cara Kompilasi dan Menjalankan Program
*Clone* repositori ini
```
    git clone https://github.com/apin014/TugasBesar_AlstrukdatSTI_K16
    cd TugasBesar_AlstrukdatSTI_K16
    cd bin
```
<br />

Jalankan *batch file* **compile_mobitangga.bat** atau kompilasi manual
```
    gcc -o Mobitangga ../src/main.c ../src/Console/console.c ../src/ConfigReader/readConfig.c ../src/MapOperating/mapOperate.c ../src/GameRound/gameRound.c ../src/Buff/buff.c ../src/Skill/skill.c ../src/ADT/mesin_kar.c ../src/ADT/mesin_kata.c ../src/ADT/array.c ../src/ADT/arrayChar.c ../src/ADT/listlinier.c ../src/ADT/player.c ../src/ADT/state.c
```
<br />

*Run* file executable **Mobitangga.exe**, kemudian setelah masuk ke dalam program pastikan bahwa setiap command yang diinput dalam program merupakan **Uppercase** dan tanpa *whitespace*.

> Note: Ketika muncul prompt untuk memasukkan PATH file konfigurasi, sebaiknya juga masukkan PATH yang lengkap untuk file tersebut