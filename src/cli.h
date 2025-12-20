#ifndef CLI_H
#define CLI_H

#include "filters.h"

typedef struct {
    const char *input_file;
    const char *output_file;
    FilterType filter_type;
    float threshold;          // Edge detection threshold (0.0-1.0, default 0.1)
    float sensitivity;        // Edge detection sensitivity (0.0-1.0, default 0.5)
    
    // TODO: Add fields for additional options
    // - Shape detection options (min_area, circularity, etc.)
    // - Video processing options (fps, frame_range, etc.)
    // - Object tracking options (max_distance, max_age, etc.)
} CLIOptions;

/*
 * Parse command line arguments and return options
 * Returns CLIOptions with default values if parsing fails
 */
CLIOptions parse_cli_arguments(int argc, char *argv[]);

void print_help(const char *program_name);

#endif
