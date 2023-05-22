#pragma once
#include "flog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const unsigned int inputBuffSize = 10000;

const char xorKey[] = "People should not be afraid of their governments. Governments should be afraid of their people.";
const char outFileName[] = "output.xor";

void xorCipher (char* input, int len);

void char2hexOutput (const char* outStr, int outStrLen);

void xorDeCipher (char* input);

void charOutput (const char* outStr);