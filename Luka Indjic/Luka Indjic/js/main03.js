showMessage();

function showMessage()
{
    console.log('Pozdrav programeri!');
}
showMessage();
showMessage();
showMessage();


function ShowMessageToUser(firstName, lastName)
{
    console.log(`Pozdrav, ${firstName} ${lastname}`);
}
ShowMessageToUser('Luka','Indjic')

function calculateSum(firstOperand,secondOperand){
    return firstOperand+secondOperand;
}
let result=calculateSum(10,30);
console.log(result);
result=calculateSum(5,15);
console.log(result);

let newShowMessage=showMessage;
console.log("_ _ _ _ _ _ _ _ _ _ _ _ _");
console.log(newShowMessage);
showMessage();
newShowMessage();


const calcAge=function(yearOfBirth,yearOfDate)
{
    return yearOfDate-yearOfBirth;
}
console.log(calcAge(2004,2030));
console.log(calcAge(2004,2050));


function yesMessage()
{
    console.log('Vi ste punoletna osoba');
}
function noMessage()
{
    console.log('Vi niste punoletna osoba');
}
function isAdult(age,yes,no)
{
    if(age>=18)
    {
        yes();
    }else
    {
        no();
    }
}
isAdult(24,yesMessage,noMessage);
isAdult(14,yesMessage,noMessage);
isAdult(22,function(){console.log('Punoletna osoba')}, function(){console.log('maloletna osoba')});//Anonimus funkcija

let showMsg=(fname,lname)=> console.log(`Pozdrav,${fname} ${lname}`);
console.log('_______________')
showMsg('Luka','Indjic');

(function(){
    console.log('IIFE');
})();

let helloMsg=new Function('fname','console.log(`Pozdrav ${fname}`)');
helloMsg('Luka');

//ZADACI ZA VEZBANJE

//1
const PI=3.14;
function Obim(poluprecnik){
    let obimkruga=2*poluprecnik*PI
    return obimkruga;
}
let r=prompt('Unesite poluprecnik kruga: ');
console.log(Obim(r));

//2

let pravougaonik=function(a,b)
{
    return a*b;
}
a=prompt('Unesite stranicu a: ');
b=prompt('Unesite stranicu b: ');
console.log(`Povrsina praougaonika: ${pravougaonik(a,b)}`);

//3
function kvadrat(a,povrsina,obim){
    console.log(`Povrsina: ${povrsina(a)}, Obim: ${obim(a)}`);
}
a=prompt('Unesite stranicu kvadrata: ');
kvadrat(a,function(){return a*a},function(){return a*4});

//4
let pravougaonik1=(a,b)=>console.log(`Obim: ${2*a+2*b}`);

a=prompt('Unesite jednu stranicu pravougaonika: ');
b=prompt('Unesite drugu stranicu pravougaonika: ');

pravougaonik(a,b);

//5
let ime=prompt('Unesite ime');
(function(ime){
    console.log(`Pozdrav, `+ ime);
})(ime);