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