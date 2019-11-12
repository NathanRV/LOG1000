#include "rabais_test.h"

void RabaisTest::setUp() {
		this->objet_a_tester = new Rabais();
}

void RabaisTest::tearDown() {
		delete this->objet_a_tester;
}

//d1 = <{client.id=90001}, {0.2}>
void RabaisTest::test_d1() {
	Facture une_facture;
	une_facture.ajouterItem(15);
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = annee_courante;
	adhesion.tm_mon = 5;
	adhesion.tm_mday = 25;
	
	Client* un_client = new Client(90001, "dummy", "dummy", 25, "A0A", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 90001);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.2, le_rabais, FLT_EPSILON);
}

//d2 = <{client.id=99999}, {0,15}>
void RabaisTest::test_d2() {
	Facture une_facture;
	une_facture.ajouterItem(15);
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = annee_courante;
	adhesion.tm_mon = 5;
	adhesion.tm_mday = 25;
	
	Client* un_client = new Client(90001, "Vlad", "Nathan", 25, "A0A", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 90001);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.15, le_rabais, FLT_EPSILON);
}