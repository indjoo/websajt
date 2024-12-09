(function sempahore(){
    const red=document.querySelector(".red");
    const yellow=document.querySelector(".yellow");
    const green=document.querySelector(".green");

    green.style.opacity=1;
    red.style.opacity=0.3;
    yellow.style.opacity=0.3;

    setTimeout(function(){
        green.style.opacity=0.3;
        red.style.opacity=0.3;
        yellow.style.opacity=1;
    },3000);
    setTimeout(function(){
        green.style.opacity=0.3;
        red.style.opacity=1;
        yellow.style.opacity=0.3;
    },5000);
    setTimeout(function(){
        green.style.opacity=0.3;
        red.style.opacity=1;
        yellow.style.opacity=1;
    },8000);
    
    setInterval(function(){
        sempahore();
    },10000);
})();
