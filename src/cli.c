#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cli.h"

void print_help(const char *program_name)
{
	printf("Usage: %s [OPTIONS]\n", program_name);
	printf("\n");
	printf("Options:\n");
	printf("  -i, --input FILE       Input image file (default: data/boxes_1.ppm)\n");
	printf("  -o, --output FILE      Output image file (default: dist/output.ppm)\n");
	printf("  -f, --filter TYPE      Edge detection filter:\n");
	printf("                           0 = Sobel (default)\n");
	printf("                           1 = Canny\n");
	printf("                           2 = Laplacian\n");
	printf("  -t, --threshold VAL    Edge detection threshold 0.0-1.0 (default: 0.1)\n");
	printf("  -s, --sensitivity VAL  Edge detection sensitivity 0.0-1.0 (default: 0.5)\n");
	printf("  -h, --help             Show this help message\n");
	printf("\n");
	printf("TODO: Add options for:\n");
	printf("  - Shape detection (min_area, circularity, etc.)\n");
	printf("  - Video processing (fps, frame_range, etc.)\n");
	printf("  - Object tracking (max_distance, max_age, etc.)\n");
}

CLIOptions parse_cli_arguments(int argc, char *argv[])
{
	// Show help if no arguments provided
	if (argc == 1)
	{
		print_help(argv[0]);
		exit(EXIT_SUCCESS);
	}

	CLIOptions options = {
		.input_file = "data/boxes_1.ppm",
		.output_file = "dist/output.ppm",
		.filter_type = FILTER_SOBEL,
		.threshold = 0.1f,
		.sensitivity = 0.5f};

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--input") == 0)
		{
			if (i + 1 < argc)
				options.input_file = argv[++i];
			else
			{
				fprintf(stderr, "Error: -i/--input requires an argument\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0)
		{
			if (i + 1 < argc)
				options.output_file = argv[++i];
			else
			{
				fprintf(stderr, "Error: -o/--output requires an argument\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--filter") == 0)
		{
			if (i + 1 < argc)
				options.filter_type = (FilterType)atoi(argv[++i]);
			else
			{
				fprintf(stderr, "Error: -f/--filter requires an argument\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--threshold") == 0)
		{
			if (i + 1 < argc)
				options.threshold = atof(argv[++i]);
			else
			{
				fprintf(stderr, "Error: -t/--threshold requires an argument\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--sensitivity") == 0)
		{
			if (i + 1 < argc)
				options.sensitivity = atof(argv[++i]);
			else
			{
				fprintf(stderr, "Error: -s/--sensitivity requires an argument\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
		{
			print_help(argv[0]);
			exit(EXIT_SUCCESS);
		}
		else
		{
			fprintf(stderr, "Error: Unknown option '%s'\n", argv[i]);
			print_help(argv[0]);
			exit(EXIT_FAILURE);
		}

		// TODO: Add parsing for additional options
		// - Shape detection options (min_area, circularity, etc.)
		// - Video processing options (fps, frame_range, etc.)
		// - Object tracking options (max_distance, max_age, etc.)
	}

	return options;
}
