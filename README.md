# Strukture-podataka-i-algoritmi
Treap:
Treap je binarno stablo pretraživanja gdje je svakom čvoru dodijeljen nasumični numerički prioritet.
Postoje mnoge metode koje služe za održavanje balansiranosti binarnog stabla pretrage (kao što su AVL stabla ili crveno-crna stabla). Jedan od načina je da se simulira slučajni redoslijed umetanja u stablo, odakle onda na osnovu teorije vjerovatnoće slijedi da će stablo biti balansirano sa velikom vjerovatnoćom (tj. visina stabla će biti 𝑂(log 𝑛)). 

Ideja je da elementi stabla pored vrijednosti (koja će u ovom slučaju biti i ključ za pretragu), sadrže i prioritete, koji se slučajno generišu pri umetanju elemenata u stablo. Svaka dva čvora treba da zadovoljavaju osobinu heapa za prioritete, tj. svaki čvor ima veći prioritet od svog djeteta, a manji od svog roditelja.
