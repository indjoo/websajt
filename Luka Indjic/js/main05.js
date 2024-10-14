let firstName="Luka";
let lastName="Indjic";
let backtick="backtick";

let dugiStringUViseRedova=`Lista korisnik
* Korisnik1
* Korisnik2
* Korisnik3
* Korisnik4`;
console.log(dugiStringUViseRedova);

//prvi karakter u stringu 1 nacin
let firstChar=firstName.charAt(0);
console.log(firstChar);
//drugi nacin
firstChar=firstName[0];
console.log(firstChar);
let Char=firstName.charAt(0);

//poslednji karatkter u stringu
console.log(firstName.length);
let lastChar=firstName[firstName.length-1];
console.log(lastChar);

console.log(firstName[15]);
console.log(firstName.charAt(15));

//prolazak kroz string
for(let char of firstName)
{
    console.log(char);
}


firstName[0]='d';
console.log(firstName[0]);

//metode u radu sa stringovima
console.log(firstName.toLowerCase());
console.log(firstName.toUpperCase());
console.log(firstName[0].toLowerCase());
console.log(firstName[firstName.length-1].toUpperCase);
console.log(firstName);


let recenica='Danas je lep dan';
console.log(recenica.indexOf('Danas'));
console.log(recenica.indexOf('an'));
console.log(recenica.indexOf('Danas',4));
console.log(recenica.indexOf('noc'));

//Primer: Pronaci broj ponavljanja substringa 'an' u stringu 'Danas je lep dan'

target='an';
position=0;
counter=0;

while(true)
{
    let pronadjenaPozicija=recenica.indexOf(target,position);
    if(pronadjenaPozicija==-1)break;
    position=pronadjenaPozicija+1;
    counter++;
    console.log(`Pronadjen substring 'an' u recenica 'Danas je lep dan' na ${position} pozicji`);

}
console.log(`Substring 'an' u recenici 'Danas je lep dan' je pronadjen ${counter} puta`);

//Primer: Pronaci broj ponavljanja substringa 'an' u string 'Danas je suncan dan',kraci nacin pisanja while petlje
let recenica2='Danas je suncan dan';
postion=-1;
counter=0;
while((position=recenica2.indexOf(target,postion+1))!=-1)
{
    console.log(`Pronadjen substring 'an' u recenici 'Danas je suncan dan' na ${postion} poziciji`);
    counter++;
}
console.log(`Pronadjen substring 'an' u recenici 'Danas je suncan dan' ${counter} puta`);

//Provera da li je neki substring pronadjen u nekom drugom stringu

if(recenica2.indexOf('suncan')!=-1)
{
    console.log('Substyring je pronadjen!');
}

//Pretraga se moze vrsiti od kraja ka pocetku
console.log(recenica2.lastIndexOf('suncan'));


console.log('includes');
console.log(recenica2.includes('Danas'));
console.log('startsWith');
console.log(recenica2.starsWith('Danas'));
console.log('endsWith');
console.log(recenica2.endsWith('suncan'));
console.log(recenica2.endsWith('dan'));

//slice- korisiti se kada je potrebno izdvajati neki string u okviru nekog stringa.
//Metoda vraca string koji pocinje od startne pozicije(start) i traje do kranje pozicije
// ne ujkljucujuci je.  nekiString.slice(start [, end])

let nekiString="Dobar dan";
console.log(nekiString.slice(0,5));//Dobar
console.log(nekiString.slice(0,1));//'D'
console.log(nekiString.slice(1)); // 'obar dan'

//Ukoliko se kao parametri proslede negativne vrednosti broji se od nazad, sa desne strane prema levoj
console.log(nekiString.slice(-5,-2));//r d

//substring
console.log(nekiString.substring(0,5));//'Dobar'
console.log(nekiString.substring(0,1));//'D'
console.log(nekiString.substring(5,0));//'Dobar'
console.log(nekiString.substring(1,0));//'D'

//substr- vraca deo stringa koji pocinje od date pozicije trazene duzine stringa(drugi parametar)
// nekiString.substr(start[, length])
//Ukoliko je prvi parametar negativan onda se pretraga radi od kraja stringa prema pocetku

console.log(nekiString.substr(0,5))//'Dobar'
console.log(nekiString.substr(6,2))//'a'
console.log(nekiString.substr(-5,2))//'r'

//trim-brise prazan prostor oko stringa

let strForTrim='  Neki string  ';
console.log(strForTrim);
console.log(strForTrim.trim()); 