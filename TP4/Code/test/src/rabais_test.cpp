#include "rabais_test.h"

void RabaisTest::setUp() {
		this->objet_a_tester = new Rabais();//"../../data/clients.dat");
}

void RabaisTest::tearDown() {
		delete this->objet_a_tester;
}


//d1 = <{client.id=99999}, {0,15}>
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
	
	Client* un_client = new Client(99999, "Vlad", "Nathan", 25, "A0A", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 99999);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.15, le_rabais, FLT_EPSILON);
}

//d2 = <{client.id=14 770}, {0,16}>
void RabaisTest::test_d2() {
	Facture une_facture;
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = 2010;
	adhesion.tm_mon = 1;
	adhesion.tm_mday = 30;
	
	Client* un_client = new Client(14770, "Lemay", "Marc", 78, "H2H", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 14770);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.16, le_rabais, FLT_EPSILON);
}

//d3 = <{client.id=15 034}, {0,03}>
void RabaisTest::test_d3() {
	Facture une_facture;
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = 2019;
	adhesion.tm_mon = 1;
	adhesion.tm_mday = 15;
	
	Client* un_client = new Client(15034, "Thibault", "Danik", 25, "H3P", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 15034);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.03, le_rabais, FLT_EPSILON);
}


//d4 = <{client.id=12 554}, {0,08}>
void RabaisTest::test_d4() {
	Facture une_facture;
	une_facture.ajouterItem(850);
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = 2015;
	adhesion.tm_mon = 8;
	adhesion.tm_mday = 8;
	
	Client* un_client = new Client(12554, "Michaud", "Charlotte", 32, "G4S", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 12554);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.08, le_rabais, FLT_EPSILON);
}

//d5 = <{client.id=25 102}, {0,15}>
void RabaisTest::test_d5() {
	Facture une_facture;
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = 2008;
	adhesion.tm_mon = 12;
	adhesion.tm_mday = 13;
	
	Client* un_client = new Client(25102, "Tremblay", "Joseph", 66, "J4O", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 25102);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.15, le_rabais, FLT_EPSILON);
}

//d6 = <{client.id=10 456}, {0,06}>
void RabaisTest::test_d6() {
	Facture une_facture;
	
	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = 2016;
	adhesion.tm_mon = 10;
	adhesion.tm_mday = 25;
	
	Client* un_client = new Client(10456, "Lamoureux", "Thomas", 45, "H1C", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 10456);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.06, le_rabais, FLT_EPSILON);
}

//d7 = <{client.id=101}, {0,13}>
void RabaisTest::test_d7() {
	Facture une_facture;
	une_facture.ajouterItem(120);

	// Obtenir l'année courante.
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int annee_courante = now->tm_year + 1900;

	tm adhesion;
	adhesion.tm_year = 2000;
	adhesion.tm_mon = 1;
	adhesion.tm_mday = 1;
	
	Client* un_client = new Client(101, "Deschaises", "Yvan", 40, "J4O", adhesion);
	this->objet_a_tester->ajouterClient(un_client);
	
	float le_rabais = this->objet_a_tester->getRabais(une_facture, 101);
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL((float) 0.13, le_rabais, FLT_EPSILON);
}
