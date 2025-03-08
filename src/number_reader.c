#include "number_reader.h"

// METNİN OKUNABİLİR BİR SAYI OLUP OLMADIĞINI BULUR
// @param text: metin
// return success: metin okunabilir bir sayıysa true döner
// return error: metin okunabilir bir sayı değilse false döner
static bool isReadable(const char text[])
{
	bool result;
	int i;
	//
	result = true;
	i = 0;
	// İlk karakter işaret olabilir
	if (text[0] == '-' || text[0] == '+')
		i++;
	// Rakam Olmayan Karakter Var mı Kontrol Et
	while (text[i] != '\0')
	{
		if (text[i] < '0' || text[i] > '9')
			result = false;
		i++;
	}
	return result;
}

// SAYININ GERÇEK BAŞLANGIÇ İNDEXİNİ BULUR 
// Açıklama: Başındaki işareti ve gereksiz sıfırları atlar.
// @param number: metin
// @return success: sayının gerçek başlangıç indexi
static int getStartIndex(const char number[])
{
	int result;
	// 
	result = 0;
	// İlk Karakter İşaret Olabilir
	if (number[0] == '-' || number[0] == '+')
		result++;
	// Baştaki Gereksiz Sıfırları Atla
	while (number[result] == '0')
		result++;
	return result;
}

// SAYININ GERÇEK UZUNLUĞUNU BULUR 
// Açıklama: Başındaki işareti ve gereksiz sıfırları atlar.
// @param number: metin
// @return success: sayının gerçek uzunluğu
static int getLength(const char number[])
{
	int start;
	int result;
	// 
	start = getStartIndex(number);
	result = 0;
	// Metnin Sonuna Kadar İlerle
	while (number[start + result] != '\0')
		result++;
	return result;
}

// ÜÇLÜ GRUPTAKİ SAYIYI OKUR
// Açıklama: Sayılar okunurken sağdan 3'erli gruplara ayrılarak okunur. (bkz: 1.234.567)
// @param number: okunacak metin
// @param startIndex: okunacak grubun başlangıç indexi
// @param groupLength: okunacak grubun uzunluğu (soldan ilk grup, 3'lü olmak zorunda değildir)
// @param groupNo: okunacak grubun sağdan kaçıncı grup olduğu bilgisi
// @return void
static void read_group(const char number[], int startIndex, int groupLength, int groupNo)
{
	int digit1 = 0, digit2 = 0, digit3 = 0;
	int groupValue;
	// Gruptaki Rakamları Bul
	if (groupLength >= 3)
		digit1 = number[startIndex++] - '0';
	if (groupLength >= 2)
		digit2 = number[startIndex++] - '0';
	if (groupLength >= 1)
		digit3 = number[startIndex++] - '0';
	// Grubun Değerini Hesapla
	groupValue = digit1 * 100 + digit2 * 10 + digit3;
	// 1. Basamağı Oku
	if (digit1 > 1)
		printf("%s", onesAndTens[0][digit1]);
	if (digit1 != 0)
		printf("Yuz");
	// 2. Basamağı Oku
	if (digit2 != 0)
		printf("%s", onesAndTens[1][digit2]);
	// 3. Basamağı Oku
	if (digit3 != 0)
		if (!(groupNo == 1 && groupValue == 1))	// "bir bin" diye okunmaz!
			printf("%s", onesAndTens[0][digit3]);
	// Grup Numarasının Değerini Oku (örnek: Milyar, Trilyon...)
	if (groupValue != 0)
		printf("%s", largeNumberNames[groupNo]);
}

// SAYININ OKUNUŞUNU EKRANA YAZDIRIR
// @param number: metin olarak sayı
// return void
bool read_number(const char number[])
{
	int start, length, groupCount, firstGroupLength;
	// Argument Error
	if (!isReadable(number))
	{
		printf("Okunamaz!");
		return false;
	}
	// Get Info
	start = getStartIndex(number);
	length = getLength(number);
	groupCount = (length - 1) / 3;
	firstGroupLength = (length % 3) ? length % 3 : 3;
	// 
	if (length > MAX_LENGTH)
	{
		printf("Cok uzun!");
		return false;
	}
	// Read 0
	if (number[start] == '\0')
	{
		printf("Sifir");
		return true;
	}
	// Read Negative
	if (number[0] == '-')
		printf("Eksi");
	// Read First Group
	read_group(number, start, firstGroupLength, groupCount);
	start += firstGroupLength;
	// Read Other Groups
	for (groupCount = groupCount - 1; groupCount >= 0; groupCount--)
	{
		read_group(number, start, 3, groupCount);
		start += 3;
	}
	return true;
}
