// Fonction "main" pour l'exécution des tests

// Librairies CppUnit nécessaires
#include <cppunit/ui/text/TestRunner.h>

// Fichiers contenant les tests
#include "rabais_test.h"

int main( int argc, char **argv)
{
    // Crée un objet pour exécuter les tests.
    // Va résenter les résultats sous forme textuelle.
    CppUnit::TextUi::TestRunner runner;

    // Ajoute la suite de tests sur les rabais
    runner.addTest(RabaisTest::suite());

    // Exécute les tests et affiche les résultats.
    runner.run();

    return 0;
}

