cmake_minimum_required(VERSION 3.10)
project(FaceDetectionDLib)

# Set dlib_DIR to where Dlib was installed or built
set(dlib_DIR "/usr/local/lib/cmake/dlib")  # Adjust this path if necessary

find_package(dlib REQUIRED)

#include_directories(${dlib_INCLUDE_DIRS})

add_executable(FaceDetectionDLib test_web.cpp)  # Replace 'main.cpp' with your source file name

#target_link_libraries(face_landmark_detection ${dlib_LIBRARIES})
target_link_libraries(FaceDetectionDLib dlib::dlib)
set_target_properties(FaceDetectionDLib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(FaceDetectionDLib ${OpenCV_LIBS})



