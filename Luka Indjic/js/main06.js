//objekti

let user1={};
let user2=new Object();

let person={
    firstName:'Petar',
    lastName:'Petrovic',
    age: 20,
    isAdult: true,
    'is student': true 
}

console.log(person.firstName);

console.log(person['age']);
console.log(person['is student']);

person.newValue='Nova vrednost';
console.log(person);

delete person.newValue;
console.log(person);
delete person['is student'];
console.log(person);

const mara={
    firstName:'Mara',
    lastName:'Maric',
    age:40,
    yearStartProgramming:1998,
    isJavaScriptProgrammer:true,
    langauges:['php','JavaScript','C#'],
    calc:function() {
        this.ageOfProgramming=2021-this.yearStartProgramming;
    }
}

console.log(mara);
console.log(mara.firsName);
console.log(mara['firstName']);

const key='Name';
console.log(mara['first'+key]);
console.log(mara['last' +key]);
mara.location='Srbija';
console.log(mara);
console.log(mara.celc());
console.log('.............');
console.log(mara);
console.log(mara.langauges[1]);

for(let key in mara) {
    console.log(`${key} ima vrednost ${mara[key]}`);

}

// zadaci za vezbanje

//1
console.log(`${mara.firstName} ${mara.lastName} ima ${mara.age} godina i zna ${mara.langauges.length} programska jezika. Programica vec ${mara.ageOfProgramming} godine.`);

//2
let test={
    test1: 'test1',
    test2:'test2',
    test3:'test3'
}
console.log(test);
console.log('Lista svojstava objekta test su:');
for (let key in test) {
    console.log(`         *${key}`);
}

//3
delete test.test3;
console.log(test);

//4
test['novi test']='nova vrednost';
console.log(test);

//5
test.getValues=function()
{
    let=values;
    for(let key in test)
    {
        values.push(test[key]);
    }
    return values;
}

//6
console.log('.....................');
console.log(test.getValues());

//7
console.log(test.length);

Object.size=function(obj)
{
    counter=0;
    for(let key in obj)
    {
        counter++;
    }
    return counter;
}
console.log(Object.size(test));
console.log(Object.isFrozen(mara));
console.log(mara);

//8

let knjizara=[
    {
        naslov:'Na Drini cuprija',
        autor:'Ivo Andric',
        'na stanju':true
    },
    {
        naslov:'Lovac na zmajeve',
        autor:'Haled Hoseini',
        'na stanju':false
    },
    {
        naslov:'Koreni',
        autor:'Dobrica cosic',
        'na stanju':true
    }
]

let stampa=function(arr){
    for(let item of arr)
    {
        let stanje=(item['na stanju'])?'ima':'nema';
        console.log(`${item.naslov} autora ${item.autor} ${stanje} na stanju`);
    }
}
console.log(stampa(knjizara));