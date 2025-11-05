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
        for (int i = 0; i < image_width; i++) {
            // get pixel rgb gradient: 0-1
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            // scale up pixel rgb values so they fit in range: [0, 255]
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            
            // rgb value for a single pixel
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}