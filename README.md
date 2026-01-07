 24360859090_OnurIpek
 🌌 Uzay Simülasyonu (Space Simulation)

Ders: Algoritmalar ve Programlama  
Okul: Bursa Teknik Üniversitesi  
Dönem: 2025-2026 Güz Dönemi  
Geliştirici: Onur İpek

 Proje Hakkında
Bu proje, C programlama dili kullanılarak geliştirilmiş konsol tabanlı bir uzay simülasyonu uygulamasıdır. Kullanıcı, bir bilim insanı rolünü üstlenerek çeşitli fizik deneylerini simüle eder. Girilen metrik değerlere (kütle, hız, yükseklik vb.) göre, Güneş Sistemi'ndeki gezegenlerde fiziksel sonuçların nasıl değiştiğini hesaplar ve listeler.


 Özellikler
* Kişiselleştirilmiş Deneyim: Kullanıcıdan bilim insanı adı alınarak simülasyon boyunca hitap edilir.
* Çoklu Gezegen Desteği: Hesaplamalar Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün ve Plüton için yerçekimi ivmeleri (g) baz alınarak yapılır.
* 9 Farklı Fizik Deneyi: Mekanik, enerji ve basınç konularını içeren geniş bir deney menüsü.
* Hata Yönetimi: Negatif değer girişleri Ternary Operator kullanılarak otomatik düzeltilir.
* Sürekli Akış: Kullanıcı çıkış yapana kadar yeni deneyler yapabilir.

 Deney Listesi
Simülasyon kapsamında aşağıdaki deneyler yapılabilmektedir:

1.  Serbest Düşme Deneyi: Belirli bir sürede düşülen mesafenin hesabı 
2.  Yukarı Atış Deneyi: Fırlatılan cismin çıkabileceği maksimum yükseklik 
3.  Ağırlık Deneyi:** Bir kütlenin farklı gezegenlerdeki ağırlığı
4.  Kütleçekimsel Potansiyel Enerji Deneyi
5.  Hidrostatik Basınç Deneyi: Sıvı basıncı hesabı 
6.  Arşimet Kaldırma Kuvveti Deneyi
7.  Basit Sarkaç Periyodu Deneyi: Sarkacın salınım süresi 
8.  Sabit İp Gerilmesi Deneyi 
9.  Asansör Deneyi: İvmelenen asansör içindeki cismin hissedilen ağırlığı 

 Teknik Detaylar
Proje isterleri doğrultusunda aşağıdaki teknik yapılar kullanılmıştır:
* Pointer Aritmetiği: Gezegenlerin yerçekimi ivmelerini tutan diziye erişim ve fonksiyonlara parametre gönderimi tamamen pointer mantığı ile yapılmıştır (`*(dizi + i)`).
* Modüler Yapı: Her deney ayrı bir fonksiyon olarak tasarlanmış, `main` bloğu sade tutulmuştur.
* Ternary Operator: `if-else` blokları yerine, fiziksel büyüklüklerin (kütle, zaman vb.) negatif girilmesini önlemek için `(kosul ? dogru : yanlis)` yapısı kullanılmıştır.
