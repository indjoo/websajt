function kreirajNiz() {
    niz = [];
    for (let i = 20; i >= 10; i--) {
        if (i % 2 === 0) {
            niz.push(i);
        }
    }
    console.log("Kreirani niz:", niz);
}
function prosiriNiz()
{
    niz.push(5,4);
    niz.unshift(100);
    console.log("Prošireni niz:", niz);
}