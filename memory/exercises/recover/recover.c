#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define true  1
#define false 0

typedef char *string; // Data type String
typedef uint8_t BYTE; // unsigned char | 1 byte (8 bits) | 0 to 255 (2^8=256)

int isJpeg(BYTE image[]); // Verify if it is the header of a jpeg image

int main(int argc, char *argv[])
{
    // Validate input
    if (argc <= 1)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    string inputFilename = argv[1];

    // Open the file provided
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL)
    {
        printf("Could not open %s.\n", inputFilename);
        return 2;
    }

    int block_size = 512;
    BYTE memChuck[block_size];

    // track the number of bytes read from the inputFile
    int bytesRead = -1;
    int fileIsOpen = false;

    // track the number of images (.jpeg files) found
    int counter = 0;

    char imgName[8] = {'\0'};
    FILE *img = NULL;

    // Read from file
    while (feof(inputFile) == 0)
    {
        bytesRead = fread(memChuck, sizeof(BYTE), block_size, inputFile);
        if (bytesRead <= 0)
        {
            continue;
        }

        // unsure it is a jpeg file
        if (isJpeg(memChuck))
        {
            if (fileIsOpen)
            {
                // Close img
                fclose(img);
                img = NULL;
                fileIsOpen = false;
            }

            sprintf(imgName, "%03i.jpg", counter);

            img = fopen(imgName, "w");
            if (inputFile == NULL)
            {
                printf("Could not open %s.\n", imgName);
                return 3;
            }

            fwrite(memChuck, sizeof(BYTE), block_size, img);

            fileIsOpen = true;
            counter++;
        }
        else if (fileIsOpen)
        {
            fwrite(memChuck, sizeof(BYTE), block_size, img);
        }
    }

    if (fileIsOpen) {
        // Close img
        fclose(img);
    }

    // Close inputFile
    fclose(inputFile);
}

int isJpeg(BYTE image[])
{
    if (image[0] == 0xff && image[1] == 0xd8 && image[2] == 0xff && ((image[3] & 0xf0) == 0xe0))
    {
        return true;
    }
    return false;
}
