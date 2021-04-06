#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "fast.h"

void main()
{
	FILE* fp = fopen("sample.jpg", "rb");
	int width, height, threshold = 20, nCorners, widthStep;
	unsigned char* imgData = NULL;
	xy* corners = NULL;

	width = 300, height = 428;
	imgData = (unsigned char*)calloc(width * height, sizeof(unsigned char));

	fread(imgData, sizeof(unsigned char), width * height, fp);

	corners = fast9_detect_nonmax(imgData, width, height, width, threshold, &nCorners);

	for (int n = 0; n < nCorners; n++)
	{
		int x, y;
		x = corners[n].x, y = corners[n].y;
		imgData[y * width + x] = 255;
		if (y > 0)
		{
			imgData[(y - 1) * width + x] = 255;
		}
		if (y < height - 1)
		{
			imgData[(y + 1) * width + x] = 255;
		}
		if (x > 0)
		{
			imgData[y * width + (x - 1)] = 255;
		}
		if (x < width - 1)
		{
			imgData[y * width + (x + 1)] = 255;
		}
	}
	fp = fopen("yee", "wb");
	fwrite(imgData, sizeof(unsigned char), width * height, fp);
	fclose(fp);

	free(corners);
	free(imgData);
}