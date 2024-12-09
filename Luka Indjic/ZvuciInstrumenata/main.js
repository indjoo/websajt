const images=document.querySelectorAll('.img');
const sounds=document.querySelectorAll('.speaker');
const readMore=document.querySelectorAll('.more');

const podaci=[
    {
        title:'Gitara',
        url:'https://sr.wikipedia.org/wiki/Гитара',
        audio:new Audio('resursi-zvuci-instrumenata\sounds\guitar.mp3'),
        readMore:'/pages/zicani.html'
    },
    {
        title:'Violina',
        url:' https://sr.wikipedia.org/wiki/Виолина',
        audio:new Audio('resursi-zvuci-instrumenata\sounds\violin.mp3'),
        readMore:'/pages/zicani.html'

    },
    {
        title:'Klavir',
        url:'https://sr.wikipedia.org/wiki/Клавир',
        audio:new Audio('resursi-zvuci-instrumenata\sounds\piano.mp3'),
        readMore:'/pages/zicani.html'

    },
    {
        title:'Bubnjevi',
        url:'https://sr.wikipedia.org/wiki/Бубњеви',
        audio:new Audio('resursi-zvuci-instrumenata\sounds\drums.mp3'),
        readMore:'/pages/zicani.html'

    },
    {
        title:'Harmonika',
        url:'https://sr.wikipedia.org/wiki/Хармоника',
        audio:new Audio('resursi-zvuci-instrumenata\sounds\harmonica.mp3'),
        readMore:'/pages/zicani.html'
    },
    {
        title:'Kontrafagot',
        url:'https://sr.wikipedia.org/wiki/Контрафагот',
        audio:new Audio('resursi-zvuci-instrumenata\sounds\contrafagot.mp3'),
        readMore:'/pages/zicani.html'
    }
]
for(let i=0;i<images.length;i++)
{
    sounds[i].addEventListener('mouseover',()=>{
        podaci[i].audio.play();
    })
    sounds[i].addEventListener('mouseout',()=>{
        podaci[i].audio.pause();
        podaci[i].audio.currentTime=0;
    })
    images[i].addEventListener('click',()=>{
        open(podaci[i].url,podaci[i].title);
    })
    readMore[i].addEventListener('click',()=>{
        open(podaci[i].readMore,'Saznaj vise','width=200,height=300');
    })
}