const images=document.querySelectorAll('img');

const podaci=[
    {
        title:'Madjarska',
        url:'pages/hu.html',
        audio:new Audio('muzika/hu.ogg')
    },
    {
        title:'Rumunija',
        url:'pages/ru.html',
        audio:new Audio('muzika/ru.ogg')
    },
    {
        title:'Hrvatska',
        url:'pages/cro.html',
        audio:new Audio('muzika/cro.ogg')
    },
    {
        title:'Bosna i Hercegovina',
        url:'pages/bih.html',
        audio:new Audio('muzika/bh.ogg')
    },
    {
        title:'Srbija',
        url:'pages/rs.html',
        audio:new Audio('muzika/srb.mp3')
    },
    {
        title:'Crna Gora',
        url:'pages/cg.html',
        audio:new Audio('muzika/cg.mp3')
    },
    {
        title:'Albanija',
        url:'pages/al.html',
        audio:new Audio('muzika/al.ogg')
    },
    {
        title:'Makedonija',
        url:'pages/mkd.html',
        audio:new Audio('muzika/mkd.ogg')
    },
    {
        title:'Bugarska',
        url:'pages/bug.html',
        audio:new Audio('muzika/bg.mp3')
    }
]
for(let i=0;i<images.length;i++)
{
    images[i].addEventListener('mouseover',()=>{
        podaci[i].audioPlay();
    })
    images[i].addEventListener('mouseout',()=>{
        podaci[i].audio.pause();
        podaci[i].audio.currentTime=0;
    })
    images[i].addEventListener('click',()=>{
        open(podaci[i].url,podaci[i].title,'width=300,height=200');
    })
}