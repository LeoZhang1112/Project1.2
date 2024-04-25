#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    printf("Usage:\n");
    printf("./main <input file> <output file>\n");
    exit(0);
  }

  char *input_file_name = argv[1];
  char *output_file_name = argv[2];

  FILE *input_file = fopen(input_file_name, "r");
  FILE *output_file = fopen(output_file_name, "w");

  if (input_file == NULL)
  {
    printf("Error: unable to open input file %s\n", input_file_name);
    exit(0);
  }

  if (output_file == NULL)
  {
    printf("Error: unable to open output file %s\n", output_file_name);
    fclose(input_file);
    exit(0);
  }

  /* YOUR CODE HERE */
  int length1, width1;
  fscanf(input_file, "%d %d", &length1, &width1);
  int **image = NULL;
  image = (int **)malloc(width1 * sizeof(int *));
  for (int i = 0; i < width1; i++)
  {
    image[i] = (int *)malloc(length1 * sizeof(int));
    for (int j = 0; j < length1; j++)
    {
      fscanf(input_file, "%d", &image[i][j]);
    }
  }
  int length2, width2;
  fscanf(input_file, "%d %d", &length2, &width2);
  int **kernel = NULL;
  kernel = (int **)malloc(width2 * sizeof(int *));
  for (int m = 0; m < width2; m++)
  {
    kernel[m] = (int *)malloc(length2 * sizeof(int));
    for (int n = 0; n < length2; n++)
    {
      fscanf(input_file, "%d", &kernel[m][n]);
    }
  }
  for (int x = 0; x < width1 - (width2 - 1); x++)
  {
    for (int y = 0; y < length1 - (length2 - 1); y++)
    {
      int tmp = 0;
      for (int a = 0; a < width2; a++)
      {
        for (int b = 0; b < length2; b++)
        {
          tmp += image[x + a][y + b] * kernel[a][b];
        }
      }
      fprintf(output_file, "%d ", tmp);
    }
    fprintf(output_file, "\n");
  }
  for (int i = 0; i < width1; i++)
  {
    free(image[i]);
  }
  free(image);
  for (int j = 0; j < width2; j++)
  {
    free(kernel[j]);
  }
  free(kernel);
  fclose(input_file);
  fclose(output_file);

  return 0;
}
