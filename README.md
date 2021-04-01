# Studentų pažymių skaičiuoklė #
Programa yra skirta apskaičiuoti studento vidurkį/medianą, pagal jo įvestus/sugeneruotus arba iš failo nuskaitytus namų darbų ir egzamino pažymius.

## Veikimo principas ##

### Pagrindinis ###

* Vartotojas turi pasirinkti konteinerį (`deque`, `list`, `vector`). Visoje programoje pasirinktame konteineryje bus saugomi `Students` duomenys.
* Vartotojas turi pasirinkti ar nori apskaičiuoti **vidurkį/medianą**.
* Vartotojas turi pasirinkti ar nori įvesti duomenis **rankiniu būdu** (kitu atveju duomenys bus skaitomi iš tekstinių **sugeneruotų failų**). Tuomet vartotojas turi pasirinkti kurį failą nori naudoti.

#### Vartotojui pasirinkus duomenų įvedimą rankiniu būdu ####

* Vartotojas turi pasirinkti ar nori įvesti studentų skaičių.

* Kiekvienam studentui vartotojas turi įvesti:
  * vardą;
  * pavardę.
* Vartotojas gali pasirinkti ar nori įvesti studento pažymių kiekį rankiniu būdu:
  * Jei taip, vartotojas gali įvesti studentų pažymių kiekį. Tuomet vartotojas gali pasirinkti ar nori įvesti studento pažymius rankiniu būdu. Jei ne, programa atsitiktinai sugeneruoja studento pažymius.
  * Jei ne, vartotojas turi įvesti studento pažymius. Tai vartotojas gali daryti iki tol, kol vietoje pažymio neįveda `stop`.
  
* Vartotojas gali pasirinkti ar nori įvesti studento egzamino pažymį rankiniu būdu:
  * Jei taip, vartotojas turi įvesti egzamino pažymį.
  * Jei ne, programa atsitiktinai sugeneruoja šio studento egzamino pažymį.
  
* Vartotojas pasirenka ar nori įvesti dar vieną studentą (jei nežinomas studentų skaičius). Jei taip, visi 2 dalies punktai vykdomi dar kartą, iki tol, kol vartotojas nebenori įvesti daugiau studentų.

* Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  * Pavardę
  * Vardą
  * Galutinį pažymį (vidurkį/medianą).

#### Vartotojui pasirinkus duomenų įvedimą iš tekstinio failo ####

* Sugeneruojamas failai  (galimi 5 skirtingų dydžių failai (1000, 10000, 100000, 1000000, 10000000)).   

* Programa nuskaito duomenis iš pasirinkto failo.

* Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  * Pavardę
  * Vardą
  * Galutinį pažymį (vidurkį/medianą).

:heavy_exclamation_mark: **Pažymius vartotojas turi įvesti nenaudodamas tarpo - po kiekvieno įvesto pažymio vartotojas turi paspausti `enter`.**

:heavy_exclamation_mark: Galutinis vidurkis skaičiuojamas pagal formulę: `galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas`.

:heavy_exclamation_mark: Duomenys išvedami surikiuoti pagal studentų pavardes didėjimo tvarka.

:heavy_exclamation_mark: Programa išveda studentų duomenis į du failus: `Winners.txt` ir `Losers.txt`. Jei studento vidurkis < 5, jis pridedamas į `Losers` grupę, jei vidurkis didesnis - į `Winners` grupę.

### Papildomas ###

Programa išveda klaidą ir prašo pakartoti įvedimą šiais atvejais:

* Vartotojui vietoje `y` arba `n` įvedus kitokį simbolį;
* Vartotojui vietoje studentų ir pažymių skaičiaus įvedus: neleistiną simbolį, raidę, žodį arba skaičių, mažesnį už 1;
* Varototojui vietoje vardo ir pavardės įvedus ne žodį.
* Vartotojui vietoje pažymio (kuris turi būti nuo `1` iki `10`) įvedus bet kokį kitą simbolį ar žodį;
* Vartotojui vietoje pažymio (kuris turi būti nuo `1` iki `10`) arba `stop`, pažymių įvedimo funkcijoje su nežinomu pažymių kiekiu, įvedus bet kokį kitą simbolį ar žodį.
* Vartotojui pasirinkimo vietoje įvedus ne pasirinkimų intervale esantį skaičių ar kitą neleistiną simbolį.

:heavy_exclamation_mark: Pakartotinis įvedimas vyksta iki tol, kol vartotojas įveda teisingą norimą reikšmę.

Sistema nutraukia darbą šiais atvejais:

* Neegzistuojant duomenų failui.
* Duomenų faile studento pažymių vietose esant raidei, žodžiui ar kitam neleistinam simboliui.
* Duomenų faile studento pažymiui neatitinkant pažymių intervalo [0, 10].
* Duomenų faile studento pažymių nebuvimui (tuščia eilutė).
* Duomenų faile studento pažymiui esant iš daugiau nei 1 ar 2 simbolių.
* Įvykus bet kokiai sisteminei klaidai.

## Įdiegimo instrukcija ##
* Atsisiųskite norimą programos versiją (rekomenduojama atsisiųsti naujausią versiją) iš [Releases](https://github.com/aistestonciute/2_uzd/releases) aplanko.
* Išarchyvuokite parsisiųstą failą.
* Paleiskite programų failus per komandinę eilutę: 
   `g++ -o main main.cpp functions.cpp` `./main`.

## Veikimo instrukcija ##
* Paleidus programą sekite instrukcijas ir įveskite prašomus kintamuosius.

## Spartos analizė ##

Programos spartai ištirti buvo naudojami skirtingi konteineriai ir skirtingų dydžių failai. Spartos analizės buvo naudotas kompiuteris su šiais parametrais:
* Intel Core i7-9750H 2.60GHz procesorius
* 16 GB RAM
* 256 GB SSD

### Duomenų įvestis ###

Container | 1000 | 10000 | 1000000 | 10000000 | 10000000
------------ | -------------| -------------| -------------| -------------| -------------
*Deque* | 0.011s | 0.06s | 0.885s | 9.4s | 87.28s
*List* | 0.028s | 0.09s | 0.932s | 9.78s | 88.13s
*Vector* | 0.031s | 0.09s | 1.2s | 10.14s | 93.2s

### Duomenų grupavimas ###

Container | 1000 | 10000 | 1000000 | 10000000 | 10000000
------------ | -------------| -------------| -------------| -------------| -------------
*Deque* | 0s | 0.004s | 0.051s | 0.58s | 16.02s 
*List* | 0s | 0.0064s | 0.052s | 0.62s | 16.42s
*Vector* | 0s | 0.018s | 0.62s | 0.72s | 19.52s

## Versijos ##

* [v0.1](https://github.com/aistestonciute/2_uzd/releases/tag/0.1) Pradinė sistemos versija. Programa yra realizuota dviem būdais: su `C` tipo masyvais ir su `vektoriais`. Programa su C tipo masyvais saugoma **main_array.cpp**, o su vektoriais - **main_vector.cpp**.
* [v0.2](https://github.com/aistestonciute/2_uzd/releases/tag/0.2) Pridėta funkcija, leidžianti vartotojui pasirinkti kokiu būdu įvesti duomenis - rankiniu ar nuskaitymu iš tekstinio failo. Ši versija yra v0.1 patobulintas **main_vector.cpp** failas, realizuojantis programą tik su `<vector>` tipo konteineriais. Sutvarkytas duomenų paėmimas iš failo naudojant `buffer`. Pridėta `WINPAUSE`.
 * [v0.3](https://github.com/aistestonciute/2_uzd/releases/tag/0.3) Sukurtas `functions.cpp` failas, kuriame sudėtos visos [v0.2](https://github.com/aistestonciute/2_uzd/releases/tag/0.2) realizuotos funkcijos. Sukurtas `functions.hpp` - saugantis funkcijų aprašymus ir `struct Student`. `main.cpp` pridėtas klaidų mėtymas ir gaudymas (`exceptional handling`) su klaidų išraiškomis (`error case`). Šiame faile taip pat ištrintos visos funkcijos, palikta tik `int main()`.
 * [v0.4](https://github.com/aistestonciute/2_uzd/releases/tag/0.4) Sukurta funkcija, leidžianti generuoti duomenų failus (dydžiai: 1000, 10000, 100000, 1000000, 10000000). Pridėtas studentų rūšiavimas į dvi grupes: `Winners` (studento vidurkis >= 5) ir `Losers` (studento vidurkis < 5). `Winners` ir `Losers` išvedami į du atskirus failus: `Winners.txt` ir `Losers.txt` Atliktas programos veikimo (spartos) analizė su kiekvienu sugeneruotu duomenų failu.
 * [v0.5](https://github.com/aistestonciute/2_uzd/releases/tag/0.5) Pridėta galimybė pasirinkti norimą konteinerį (`deque`, `list`, `vector`) `Students` duomenis saugoti. Atlikta ir aprašyta spartos analizė.
