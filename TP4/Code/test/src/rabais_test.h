// Classe qui teste la classe Diviseur
// Avec le framework CppUnit

// Librairies CppUnit nécessaires.
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

// Le fichier à tester, qui se trouve dans un répertoire différent.
#include "../../src/rabais.h"

// Classes utilisées par la classe à tester.
#include "../../src/client.h"
#include "../../src/facture.h"

class RabaisTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(RabaisTest);
    CPPUNIT_TEST(test_d1);
    CPPUNIT_TEST(test_d2);
    CPPUNIT_TEST_SUITE_END();
    
private:
	Rabais* objet_a_tester;
    
public:
	// Fonctions d'échafaudage
    void setUp();
    void tearDown();
    
    // Fonctions de tests
    void test_d1();
    void test_d2();

};




