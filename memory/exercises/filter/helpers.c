#include "helpers.h"
#include <math.h>
#include <stdio.h>

// prototypes
int calculateAverage(RGBTRIPLE pixel); // Calculate the average number given a pixel; 
void swapPixels(RGBTRIPLE *px1, RGBTRIPLE *px2); // Swap pixels

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate the average pixel value
            int average = calculateAverage(image[i][j]);

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
                lEnd   = (i + 1 > hEdgeIndex ? hEdgeIndex : i + 1),
                cStart = (j - 1 < 0 ? 0 : j - 1),
                cEnd   = (j + 1 > wEdgeIndex ? wEdgeIndex : j + 1);

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
            image[i][j].rgbtRed = imageCopy[i][j].rgbtRed;
            image[i][j].rgbtGreen = imageCopy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imageCopy[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}




// ----

int calculateAverage(RGBTRIPLE pixel)
{
    return round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtRed) / 3);
}

void swapPixels(RGBTRIPLE *px1, RGBTRIPLE *px2)
{
    RGBTRIPLE temp = *px1;
    *px1 = *px2;
    *px2 = temp;
}
