#include "Book.h"

void BookInit(struct Book* this,  char* name,  float price,
               unsigned int pages,  char* language, 
               float weight,  unsigned int year)
{
    this->name =     name;
    this->price =    price;
    this->pages =    pages;
    this->language = language;
    this->weight =   weight;
    this->year =     year;

    this->next =     NULL;
}

void BookPrint( struct Book* this)
{
    printf("Book name: \t\t%s\n",     this->name);
    printf("Price: \t\t\t%.2f$\n",    this->price);
    printf("Number of pages: \t%d\n", this->pages);
    printf("Language: \t\t%s\n",      this->language);
    printf("Weight: \t\t%.3fkg\n",    this->weight);
    printf("Year: \t\t\t%d\n",        this->year);
    printf("------------------------------------------------------\n\n");
}

void BookBindNext(struct Book* this,  struct Book* other)
{
    this->next = other;
}

void BookPrintSeries(struct Book* this)
{
    while(this->next != NULL)
    {
        BookPrint(this);
        this = this->next;
    }
}
