# Bouncing Balls In Terminal

Bu proje, terminalde hareket eden ve çarpışan renkli dairelerin animasyonunu gösteren basit bir C++ uygulamasıdır.

## Klasör Yapısı

- `src/` — Kaynak kodları (örn. `Main.cpp`)
- `lib/` — Derlenmiş nesne dosyaları
- `bin/` — Çalıştırılabilir dosyalar
- `.vscode/` — VSCode ayarları ve görevleri
- `makefile` — Derleme ve çalıştırma için komutlar

## Derleme ve Çalıştırma

### Makefile ile

```sh
mingw32-make
```
Bu komut sırasıyla derler ve programı çalıştırır.

### VSCode ile

- `Ctrl+Shift+B` ile "C/C++: g++.exe build active file" görevini çalıştırabilirsiniz.
- Ardından `src/Main.exe` veya `bin/program.exe` dosyasını çalıştırabilirsiniz.

## Program Hakkında

- Terminalde 3 adet renkli daire hareket eder ve kenarlara çarptıkça yön değiştirir.
- Renkler ANSI escape kodları ile gösterilir.
- Windows ortamında çalışır (`windows.h` ve `Sleep` fonksiyonu kullanılmıştır).

## Gereksinimler

- C++ derleyicisi (örn. MinGW g++)
- Windows işletim sistemi
- ANSI escape kodlarını destekleyen terminal

## Yazar

- Görkem
