#include "conf.h"

void xorCipher (char* input) {

    const char* key = xorKey;

    while (*input != '\0') {

        *input ^= *(key);
        key++;
        input++;

        if (*key == '\0') key = xorKey;
    }
}

void xorDeCipher (char* input) {

    int iter = 0;
    char* save = input;

    for (;*input != '\0'; input += 2) {

        save[iter] = ((*input >= 'A' ? *input - 'A' + 10 : *input - '0') << 4) + (*(input + 1) >= 'A' ? *(input + 1) - 'A' + 10 : *(input + 1) - '0');
        iter++;
    }

    save[iter] = '\0';

    xorCipher (save);
}

void char2hexOutput (const char* outStr, int outStrLen) {

    assert (outStr != NULL);

    FILE* outFile = fopen (outFileName, "wb");
    assert (outFile != NULL);

    for (int i = 0; i < outStrLen; i++) fprintf (outFile, "%.02X", outStr[i]);

    fclose (outFile);
}

void charOutput (const char* outStr) {

    assert (outStr != NULL);

    FILE* outFile = fopen (outFileName, "wb");
    assert (outFile != NULL);

    fprintf (outFile, "%s", outStr);

    fclose (outFile);
}