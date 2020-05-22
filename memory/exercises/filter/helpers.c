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