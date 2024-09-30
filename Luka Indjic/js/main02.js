console.log(3>2);
console.log(2=='2');
console.log('02'!=2);

let result=100<99;
console.log(result);
console.log('Danijela'>'Dana');//true

let answer=prompt('Koliko vi imate godina?','Unesite vase godine');

if(answer<18)
{
    console.log('Vi ste maloletna osoba');
}
else
{
    console.log('Vi ste punoletna osoba');
}

let newAnswer=prompt('Koliko vi imate godina?','Unesite vase godine');

if(newAnswer>=19)
{
    console.log('Vi ste zavrsili srednju skolu' );
}else if(newAnswer>=15 && newAnswer<19)
{
    console.log('vi ste ucenik srednje skole');
}else if(newAnswer<15 && newAnswer>=7)
{
    console.log('vi ste ucenik osnovne skole');
}else
{
    console.log('U vrticu ste :)');
}
