#include "rabais_test.h"


void RabaisTest::setUp() {
		this->objet_a_tester = new Rabais();
}

void RabaisTest::tearDown() {
		delete this->objet_a_tester;
}

// Correspond à getRabais = <{client.id=99999}, {0.2}>
void RabaisTest::test_getRabais() {
    Facture facture;
    facture.ajouterItem(15);
    //Obtenir année courante
    std::time_t t = std::time(0); //Heure courante
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

    tm adhesion;
    adhesion.tm_year = annee_courante;
    adhesion.tm_mon = 5;
    adhesion.tm_mday = 25;

    Client* client = new Client(99999, "Vlad", "Nathan", 25, "A0A", adhesion);
    this->objet_a_tester->ajouterClient(client);


	float rabais = this->objet_a_tester->getRabais(facture, 10456);
	CPPUNIT_ASSERT_EQUAL((float)0.2, rabais);
}