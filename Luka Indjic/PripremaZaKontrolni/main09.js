// 1
function nadjiPreskocen(arr)
{
    let n=arr.length+1;
    let ocekivanaSuma=n/2*(n+1);
    let stvarnaSuma=0;
    for(let i=0;i<arr.length;i++)
    {
        stvarnaSuma+=arr[i];
    }
    console.log(ocekivanaSuma-stvarnaSuma);
}
console.log(nadjiPreskocen([1,2,4,5,6]));
// 2
function proveriSumu(arr,testNumber)
{
    for(let i=0;i<arr.length;i++)
    {
        for(let j=i+1;j<=arr.length;j++)
        {
            if(arr[i]+arr[j]==testNumber)
            {
                return true;
            }

        }
    }
    return false;
}
console.log(proveriSumu([1,2,3,4], 12));

// 3
let najvecaSuma=function(arr) {
    let maxSum=0;
    for(let i=0;i<arr.length;i++)
    {
        for(let j=i+1;j<=arr.length;j++)
        {
            if(arr[i]+arr[j]>=maxSum)
            {
                maxSum=arr[i]+arr[j];
            }
        }
    }
    return maxSum;
}
console.log(najvecaSuma([100,2,3,7,1000]));

// 4
(function(arr){
    let maxLength=0;
    for(let item of arr)
    {
        if(item.length>=maxLength)
        {
            maxLength=item.length;
            console.log(`Clan niza ${item} ima najvecu duzinu ${maxLength}`);
        }
    }
})(['Danas', 'je','lep','dan']);

// 5
function firstLetterToUpper(str)
{
    let result='';
    let arrOfStr=str.split(' ');
    console.log(arrOfStr);
    for(let item of arrOfStr)
    {
        let newItem=item[0].toUpperCase() + item.substr(1)+ ' ';
        result+=newItem;
    }
    alert(result);
}
firstLetterToUpper(prompt('unesi recenicu'));

// 6
let undefinedToZero=function(e1){
    return (e1===undefined)?0:e1;
}
function treciNiz(arr1,arr2)
{
    let newArr=[ ];
    let maxLength=Math.max(arr1.length,arr2.length);
    for(let i=0;i<maxLength;i++)
    {
        newArr[i]=undefinedToZero(arr1[i])+undefinedToZero(arr2[i]);
    }
    console.log(newArr);
}
// 7
// 1. nacin

function createNewArray(arr1, arr2)
{
    let newArr=[];
    for(let i=0;i<Math.max(arr1.length,arr2.length);i++)
    {
        if(arr1[i]!== undefined && newArr.indexOf(arr1[i])===-1)
        {
            newArr.push(arr1[i]);
        }
        if(arr2[i]!==undefined && newArr.indexOf(arr2[i])===-1)
        {
            newArr.push(arr2[i]);
        }
    }
}
console.log(createNewArray([1,1,2,3,10,11,12],[4,5,6,6,7]));

// 2.nacin
 function createNewArray1(arr1,arr2)
 {
    let newArr=[];
    newArr=arr1.concat(arr2);
    newArr=[...new Set(newArr)];
    return newArr;
 }
 console.log(createNewArray([1,1,2,3,10,11,12],[4,5,6,6,7]));

 // 8

 function createDate(delimiter)
 {
    let currentDate=new Date();
    let datum=currentDate.getDate()+delimiter+(currentDate.getMonth()+1)+delimiter+currentDate.getFullYear();
    alert(datum);
 }
 console.log(createDate(prompt('Unesite delimiter za format datuma','/ ili . ili -')));

 // 9

let nameOfMonth=function()
{
    let currentDate=new Date();
    let mesec=currentDate.getMonth()+1;
    let naziv='';
    switch (mesec)
    {
        case 1:naziv='Januar';
        break;
        case 2:naziv='Februar';
        break;
        case 3:naziv='Mart';
        break;
        case 4:naziv='April';
        break;
        case 5:naziv='Maj';
        break;
        case 6:naziv='Jun';
        break;
        case 7:naziv='Jul';
        break;
        case 8:naziv='Avgust';
        break;
        case 9:naziv='Septembar';
        break;
        case 10:naziv='Oktobar';
        break;
        case 11:naziv='Novembar';
        break;
        default:naziv='Decembar';
    }
    return naziv;
}
console.log(nameOfMonth());

// 10

function isWeekend(date)
{
    let message='';
    if(date.Getday()==6 || date.Getday()==0)
    {
        message='Vikend je';
    }else{
        message='Radni je dan';
    }
    return message;
}
let nekiDatum=new Date("11/20/2021");
console.log(nekiDatum);
console.log(isWeekend(nekiDatum));