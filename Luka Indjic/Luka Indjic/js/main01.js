let isProgrammingLanguage=true;
const dateOfBirth='01.01.2004.';

const COLOR_RED="#F00";

let FirstNumber=10;
let SecondNumber=45;
console.log(SecondNumber/FirstNumber);

let firstName='Luka';
let lastName='Indjic';
console.log(firstName + ' '+lastName);

let isAdult=true;
let isEmpyCart=false;

let age;
console.log(age);

console.age(null);
console.log(typeof (null)); //Bug u JavaScript-u

let test;
console.log(test);
let test2=null;
console.log(test2);

const mySymbol=Symbol('test');
const mySymbol2=Symbol('test');
if(mySymbol==mySymbol2)
    console.log(true);
else
    console.log(false);

let bignumber1= BigInt(12313012017126612);
console.log('Bigint');
console.log(bignumber1);

console.log(firstName+FirstNumber);

console.log(FirstNumber+'5');

console.log(true+5);// 6
console.log(false+1);// 1
console.log(true+null)//1

if(true==1)
    console.log(true);
else
{
    console.log(false);
}// true

if(true===1)
    console.log(true);
else
{
    console.log(false);
}// false


if(20=='20')
    console.log(true);
else
{
    console.log(false);
}

console.log(5+null);
console.log('5'+null);

console.log(undefined+5);
console.log(undefined+'5');
console.log(undefined+true);

let stranicaKvadrata=10;

let obim=4*stranicaKvadrata;
let povrsina=stranicaKvadrata*stranicaKvadrata;
console.log("Kvadrat stranice "+stranicaKvadrata+"cm ima obim "+obim+"cm i povrsinu"+povrsina+"cm^2");
//drugi nacin
// console.log(`Kvadrat stranice ${stranicaKvadrata}cm ima obim ${obim}cm i povrsinu${povrsina}cm^2`);

console.log("ovo je string \n\
u vise redova \n\
ispisan u \"\" navodnicima");