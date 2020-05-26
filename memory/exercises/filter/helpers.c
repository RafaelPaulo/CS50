#include "helpers.h"
#include <math.h>
#include <stdio.h>

// prototypes
void swapPixels(RGBTRIPLE *px1, RGBTRIPLE *px2); // Swap pixels
int cap(int value);
int isValidIndexes(int i, int j, int height, int width);

int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}; // Vertical
int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; // Horizontal

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate the average pixel value
            float sum = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            int average = (int)round(sum / 3.0);

            // set each color value to the average value
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halfFloored = floor(width / 2);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfFloored; j++)
        {
            // If the width is odd, there is no need to swap the pixel in the middle.
            swapPixels(&image[i][j], &image[i][width - 1 - j]);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];

    // For each pixel in the image image[i][j]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get last width index
            int wEdgeIndex = width - 1;
            // Get last height index
            int hEdgeIndex = height - 1;
            // counter to count the number of pixel around this current image[i][j] pixel
            int counter = 0;

            // find the pixels around the image[i][j] pixel
            int lStart = (i - 1 < 0 ? 0 : i - 1),
                lEnd = (i + 1 > hEdgeIndex ? hEdgeIndex : i + 1),
                cStart = (j - 1 < 0 ? 0 : j - 1),
                cEnd = (j + 1 > wEdgeIndex ? wEdgeIndex : j + 1);

            float r = 0.00;
            float g = 0.00;
            float b = 0.00;

            // iterate over the pixels around and calculate the average of each color
            for (int ii = lStart; ii <= lEnd; ii++)
            {
                for (int jj = cStart; jj <= cEnd; jj++)
                {
                    r += image[ii][jj].rgbtRed;
                    g += image[ii][jj].rgbtGreen;
                    b += image[ii][jj].rgbtBlue;
                    counter++;
                }
            }

            imageCopy[i][j].rgbtRed = round(r / (float)counter);
            imageCopy[i][j].rgbtGreen = round(g / (float)counter);
            imageCopy[i][j].rgbtBlue = round(b / (float)counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageCopy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];

    // For each pixel in the image image[i][j]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rGX = 0.0;
            float gGX = 0.0;
            float bGX = 0.0;
            float rGY = 0.0;
            float gGY = 0.0;
            float bGY = 0.0;

            // iterate over the pixels around and calculate the average of each color
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (isValidIndexes(i + x, j + y, height, width))
                    {
                        float gxValue = GX[x + 1][y + 1];
                        float gyValue = GY[x + 1][y + 1];

                        int imgIndexI = i + x;
                        int imgIndexJ = j + y;

                        rGX += (gxValue * (float)image[imgIndexI][imgIndexJ].rgbtRed);
                        gGX += (gxValue * (float)image[imgIndexI][imgIndexJ].rgbtGreen);
                        bGX += (gxValue * (float)image[imgIndexI][imgIndexJ].rgbtBlue);

                        rGY += (gyValue * (float)image[imgIndexI][imgIndexJ].rgbtRed);
                        gGY += (gyValue * (float)image[imgIndexI][imgIndexJ].rgbtGreen);
                        bGY += (gyValue * (float)image[imgIndexI][imgIndexJ].rgbtBlue);
                    }
                }
            }

            imageCopy[i][j].rgbtRed   = cap(round(sqrt((rGX * rGX) + (rGY * rGY))));
            imageCopy[i][j].rgbtGreen = cap(round(sqrt((gGX * gGX) + (gGY * gGY))));
            imageCopy[i][j].rgbtBlue  = cap(round(sqrt((bGX * bGX) + (bGY * bGY))));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageCopy[i][j];
        }
    }

    return;
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}

int isValidIndexes(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

void swapPixels(RGBTRIPLE *px1, RGBTRIPLE *px2)
{
    RGBTRIPLE temp = *px1;
    *px1 = *px2;
    *px2 = temp;
}
