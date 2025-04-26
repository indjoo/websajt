// Selektovanje DOM elemenata
const title = document.querySelector("#title");
const slide = document.querySelector(".slide");
const info = document.querySelector(".info");
const year = document.querySelector("#year");
const indicators = document.querySelectorAll(".indicator");
const description = document.querySelector("#intro");

let i = 0; 
let j = 1; 

const data = [
  {
    src: "images/glava-zene.png",
    title: "Глава жене",
    year: "1960",
    description:
      "Ово дело је инспирисано Пикасовом женом Жаклином Рок, с којом се оженио 1961. године. На слици су представљене њене круне очи, високе јагођице и равна црна коса.",
  },
  {
    src: "images/faun-sa-zvezdama.jpg",
    title: "Фаун са звездама",
    year: "1955",
    description:
      "Фаун са звездама настао је 1955. године, на врхунцу Пикасове романсе са Жаклином Рок, са којом се оженио 1961. Декоративни и разиграни графички квалитет рада карактеристичан је за Пикасов касни стил и посебно се односи на осликавање керамику коју је почео израђивати 1947.",
  },
  {
    src: "images/zena-u-belom.jpg",
    title: "Жена у белом",
    year: "1923",
    description:
      "Ово дело је једно од најпознатијих неокласицистичких слика, насликао га је по повратку у Париз након деловања. Он и његова супруга Олга су се на летовању дружили са харизматичним америчким емигрантима Џералдом и Саром Марфи. Будући да је Сара Марфи имала прелепе црте лица, многи верују да је ово платно њен портрет.",
  },
  {
    src: "images/zana-za-stolom.jpg",
    title: "Читање за столом",
    year: "1934",
    description:
      "На овој слици је представљена његова љубавница Марија Тереза Валтер која чита књигу. Пикасо се враћа омиљеној теми — жени која седи сама. Затамњена соба и сјај лампе дају јој етерично присуство, док јој амбарска коса, плава кожа и црвена круна појачавају младост.",
  },
  {
    src: "images/bista-coveka.jpg",
    title: "Биста човека",
    year: "1908",
    description:
      "У својим раним експериментима са кубизмом, Пикасо је у своје дело уводио незаобилазне сликовне елементе. Посебно се осврнуо на ибериску и афричку скулптуру, коју је виђао при честим посетама париском етнографском музеју Трокадеро.",
  },
];

function changeIndicators() {
  if (j < indicators.length) {
    indicators[j - 1].style.backgroundColor = "gray";
    indicators[j].style.backgroundColor = "#487F2E";
  } else {
    j = 0;
    indicators[j].style.backgroundColor = "#487F2E";
    indicators[indicators.length - 1].style.backgroundColor = "gray";
  }
  j++;
}


setInterval(() => {
  slide.classList.add("fade-out");
  info.classList.add("fade-out");

  setTimeout(() => {
    slide.src = data[i].src;
    title.innerHTML = data[i].title;
    year.innerHTML = data[i].year;
    description.innerHTML = data[i].description;

    slide.classList.remove("fade-out");
    info.classList.remove("fade-out");
  }, 1000);

  i++;
  if (i === data.length) {
    i = 0;
  }

  changeIndicators();
}, 2000);
