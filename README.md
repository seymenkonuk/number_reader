# Number Reader
> C dilinde, en fazla 171 basamaklı bir sayının Türkçe okunuşunu ekrana yazdıran bir kütüphane.

## Açıklama
Örnek programın çıktısı:
```bash
> ./test -488568485451 0 abc
-488568485451: EksiDortYuzSeksenSekizMilyarBesYuzAltmisSekizMilyonDortYuzSeksenBesBinDortYuzElliBir
0: Sifir
abc: Okunamaz!
```

## İçindekiler
<ol>
	<li>
		<a href="#başlangıç">Başlangıç</a>
		<ul>
			<li><a href="#bağımlılıklar">Bağımlılıklar</a></li>
			<li><a href="#kurulum">Kurulum</a></li>
			<li><a href="#yapılandırma">Yapılandırma</a></li>
			<li><a href="#derleme">Derleme</a></li>
			<li><a href="#çalıştırma">Çalıştırma</a></li>
		</ul>
	</li>
	<li><a href="#dizin-yapısı">Dizin Yapısı</a></li>
	<li><a href="#kullanım">Kullanım</a></li>
	<li><a href="#lisans">Lisans</a></li>
	<li><a href="#Iletişim">İletişim</a></li>
</ol>

## Başlangıç
### Bağımlılıklar
Proje aşağıdaki işletim sistemlerinde test edilmiştir:
- **Debian**

Projenin düzgün çalışabilmesi için aşağıdaki yazılımların sisteminizde kurulu olması gerekir:
- **C Derleyicisi** (GCC, Clang vb.)
- **Make** (Makefile kullanarak derlemek için)
- **Docker** (Docker kullanarak çalıştırmak için)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

### Kurulum
1. Bu repository'yi kendi bilgisayarınıza klonlayın:
	```bash
	git clone https://github.com/seymenkonuk/number_reader.git
	```

2. Projeye gidin:
	```bash
	cd number_reader
	```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

### Yapılandırma
Daha büyük sayıları okumak için **src/number_header.h** dosyasında aşağıdaki değişiklikleri yapınız:
1. 18\. satırdaki **largeNumberNames** değişkenine daha büyük sayıların okunuşunu ekleyiniz:
	```c
	static const char largeNumberNames[LARGE_NUMBER_COUNT][23] = {
		"", "Bin", "Milyon", "Milyar", 
		"Trilyon", "Katrilyon", "Kentilyon", "Seksilyon", 
		"Septilyon", "Oktilyon", "Nonilyon", "Desilyon", 
		"Undesilyon", "Dodesilyon", "Tredesilyon", "Kattuordesilyon", 
		"Kendesilyon", "Sexdesilyon", "Septendesilyon", "Oktodesilyon",
		"Novemdesilyon", "Vigintilyon", "Unvigintilyon", "Dovigintilyon", 
		"Trevigintilyon", "Kattuorvigintilyon", "Kenvigintilyon", "Sexvigintilyon", 
		"Septenvigintilyon", "Oktovigintilyon", "Novemvigintilyon", "Trigintilyon", 
		"Untrigintilyon", "Dotrigintilyon", "Tretrigintilyon", "Kattuortrigintilyon", 
		"Kentrigintilyon", "Sextrigintilyon", "Septentrigintilyon", "Oktotrigintilyon", 
		"Novemtrigintilyon", "Katragintilyon", "Unkatragintilyon", "Dokatragintilyon", 
		"Trekatragintilyon", "Kattuorkatragintilyon", "Kenkatragintilyon", "Sexkatragintilyon", 
		"Septenkatragintilyon", "Oktokatragintilyon", "Novemkatragintilyon", "Kenquagintilyon", 
		"Unkenquagintilyon", "Dokenquagintilyon", "Trekenquagintilyon", "Kattuorkenquagintilyon", 
		"Kenkenquagintilyon", "<yeni_deger1>", "<yeni_deger2>"
	};
	```
2. 9\. satırdaki **LARGE_NUMBER_COUNT** sabitinin değerini, largeNumberNames dizisinin uzunluğu olacak şekilde değiştiriniz:
	```c
	#define LARGE_NUMBER_COUNT <dizinin_uzunlugu>
	```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

### Derleme

Kütüphane, **Makefile** üzerinden kolayca derlenebilir ve linklenebilir.

- **Projeyi derlemek için**:

	```bash
	make
	```

- **Projeyi temizlemek için**:

	```bash
	make clean
	```

Makefile, kütüphanenizi derleyecek ve `bin/libnumber_reader.a` statik kütüphanesini oluşturacaktır.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

### Çalıştırma
Kütüphaneyi kullanan basit bir programı (`test/test.c`) **Docker** üzerinden çalıştırabilirsiniz:
1. Make ve Docker'ı kurunuz.
2. Aşağıdaki komutu çalıştırınız:
	```bash
	make docker
	```

Kütüphaneyi kullanan basit bir programı (`test/test.c`) **Makefile** üzerinden çalıştırabilirsiniz:
1. Make'i kurunuz.
2. Aşağıdaki komutu çalıştırınız:
	```bash
	make test
	```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Dizin Yapısı
```
├── number_reader/
│   ├── bin/			#Derlenmiş dosyalar
│   ├── obj/			#Obj dosyaları
│   ├── src/			#Kaynak kodlar
│   └── test/			#Projeyi kullanan örnek program
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Kullanım
Kütüphaneyi kendi C projenizde kullanabilmek için aşağıdaki adımları izleyebilirsiniz:


1. **Kütüphaneyi derleyerek `libnumber_reader.a` dosyasını elde edin.**

2. **libnumber_reader.a dosyasını `/path/to` dizinine yerleştirin.**

3. **src dizini içindeki bütün .h dosyalarını `/path/to/include/number_reader` dizinine yerleştirin.**

4. **Kütüphaneyi dahil edin**:

	`#include <number_reader/number_reader.h>` satırını, kullanmak istediğiniz C dosyasının başına ekleyin.

5. **Derleme sırasında kütüphaneyi linkleyin**:

	```bash
	gcc -o my_program my_program.c -L/path/to -lnumber_reader -I/path/to/include
	```

	Burada `/path/to` dizini herhangi bir dizin olabilir.


<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Lisans
Bu proje [MIT Lisansı](https://github.com/seymenkonuk/number_reader/blob/main/README.md) ile lisanslanmıştır.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Iletişim
Proje ile ilgili sorularınız veya önerileriniz için bana ulaşabilirsiniz:

GitHub: https://github.com/seymenkonuk

LinkedIn: https://www.linkedin.com/in/recep-seymen-konuk/

Proje Bağlantısı: [https://github.com/seymenkonuk/number_reader](https://github.com/seymenkonuk/number_reader)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---
