#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {

    // Image Resolution
    int image_width = 256;
    int image_height = 256;

    // PPM File format:
    // P3 -> text-based (ASCII)
    // the dimensions
    // Max color val set to 255

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Render
    for (int j = 0; j < image_height; j++) {
        // write to logging output stream (clog) instead of standard (cout) for msg reporting/logging
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            // Simplification:
            // use our color (masked vec3 class) object to compute RGB values for every pixel, and write it to output
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                 \n";
}