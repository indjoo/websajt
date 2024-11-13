function kreirajNiz1() {
    niz = [];
    for (let i = 1; i <= 21; i += 2) {
        niz.push(i);
    }
    console.log("Kreirani niz:", niz);
}
    function proveriOdgovor() {
        let odgovor = prompt("Da li želite da kreirate niz? (Da/Ne)");
        if (odgovor === 'da') {
            kreirajNiz1();
        } else {
            window.open('http://www.etspupin.edu.rs/', 'Školski Sajt', 'width=300,height=300,scrollbars=yes');
        }
    }