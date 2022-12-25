#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Book{
    char*        name;
    float        price;
    unsigned int pages;
    char*        language;
    float        weight;
    unsigned int year;

    struct Book*        next;
};

void BookInit(struct Book* this,  char* name, float price,
               unsigned int pages,  char* language, 
               float weight,  unsigned int year);
void BookPrint( struct Book* this);
void BookBindNext(struct Book* this,  struct Book* other);
void BookPrintSeries(struct Book* this);
