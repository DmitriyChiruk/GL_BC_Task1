#include "Book.h"

int main()
{
    struct Book HP1, HP2, HP3, HP4, HP5, HP6, HP7;

    BookInit(&HP1, "Harry Potter and the Philosopher`s stone", 15, 223, "English", 0.446f, 1997);
    BookInit(&HP2, "Harry Potter and the Chamber of secrets", 25, 251, "English", 0.512f, 1998);
    BookInit(&HP3, "Harry Potter and the Prisoner of Azkaban", 32, 317, "English", 0.575f, 1999);
    BookInit(&HP4, "Harry Potter and the Goblet of fire", 35, 636, "English", 0.893f, 2000);
    BookInit(&HP5, "Harry Potter and the Order of Phoenix", 35, 766, "English", 0.944f, 2003);
    BookInit(&HP6, "Harry Potter and the Half-Blood prince", 38, 607, "English", 0.884f, 2005);
    BookInit(&HP7, "Harry Potter and the Deathly Hallows", 42, 607, "English", 0.885f, 2007);

    BookBindNext(&HP1, &HP2);
    BookBindNext(&HP2, &HP3);
    BookBindNext(&HP3, &HP4);
    BookBindNext(&HP4, &HP5);
    BookBindNext(&HP5, &HP6);
    BookBindNext(&HP6, &HP7);

    BookPrintSeries(&HP1);

    system("pause");
}