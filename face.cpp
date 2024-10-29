#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_io.h>
#include <iostream>
#include <dlib/gui_widgets/widgets.h>

using namespace dlib;
using namespace std;

int main() {
    try {
        // Load image using dlib
        array2d<unsigned char> img;
        load_image(img, "/home/itstarkenn/Downloads/happy-multicultural-group-male-female-260nw-2291238385.jpg");

        // Initialize face detector
        frontal_face_detector detector = get_frontal_face_detector();

        // Detect faces in the image
        std::vector<rectangle> dets = detector(img);

        // Print the number of faces detected
        std::cout << "Number of faces detected: " << dets.size() << std::endl;

        // Draw rectangles around detected faces
        image_window win;
        win.set_image(img);
        win.clear_overlay();
        win.set_image(img);
        win.add_overlay(dets, rgb_pixel(255, 0, 0)); // Red rectangles

        // Save the output image with rectangles drawn
        // Convert array2d to an image format that can be saved
        matrix<rgb_pixel> img_rgb;
        assign_image(img_rgb, img);  // Convert to rgb_pixel format

        save_jpeg(img_rgb, "output_image.jpg");
        cout << "Output image saved successfully as 'output_image.jpg'!" << endl;

        cin.get(); // Wait for a key press to close the window
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
