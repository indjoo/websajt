const time=document.querySelector("#time");
const quize=document.querySelector(".quize");

window.addEventListener("load",()=>{
    let count=time.innerHTML;
    setInterval(() => {
        if(count>0){
            count--;
            time.innerHTML=count;
        }else{
            quize.style.display="none";
            time.innerHTML="Kraj";
        }
    }, 1000);
    })