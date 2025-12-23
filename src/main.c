#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "filters.h"
#include "cli.h"

int main(int argc, char *argv[])
{
	CLIOptions options = parse_cli_arguments(argc, argv);

	Image img = load_ppm(options.input_file);
	printf("Processing: %s\n", options.input_file);
	printf("Image dimensions: %dx%d\n", img.width, img.height);

	// === PHASE 1: Edge Detection ===
	printf("Detecting edges...\n");

	printf("Threshold: %.2f, Sensitivity: %.2f\n", options.threshold, options.sensitivity);

	Image edges;
	switch (options.filter_type)
	{
	case FILTER_SOBEL: edges = sobel_edge_detection(img, options.threshold, options.sensitivity); break;
	case FILTER_CANNY: edges = canny_edge_detection(img, options.threshold, options.sensitivity); break;
	case FILTER_LAPLACIAN: edges = laplacian_edge_detection(img, options.threshold, options.sensitivity); break;
	default: break;
	}

	printf("Saving result: %s\n", options.output_file);
	save_ppm(options.output_file, edges);

	free_image(img);
	free_image(edges);

	printf("Done!\n");

	// TODO: Future phases

	// PHASE 2: Shape Detection

	// PHASE 3: Video Processing

	// PHASE 4: Object Tracking

	return EXIT_SUCCESS;
}
