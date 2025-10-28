// main.cpp: Pedestrian Detection using OpenCV HOGDescriptor
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input_image_or_video>" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    cv::VideoCapture cap;
    if (input.find(".jpg") != std::string::npos || input.find(".png") != std::string::npos) {
        cap.open(input);
    } else {
        cap.open(input);
    }
    if (!cap.isOpened()) {
        std::cerr << "Error opening input: " << input << std::endl;
        return 1;
    }
    cv::HOGDescriptor hog;
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    cv::Mat frame;
    while (cap.read(frame)) {
        std::vector<cv::Rect> found;
        hog.detectMultiScale(frame, found);
        for (const auto& r : found) {
            cv::rectangle(frame, r, cv::Scalar(0,255,0), 2);
        }
        cv::imshow("Pedestrian Detection", frame);
        if (cv::waitKey(30) == 27) break;
    }
    return 0;
}
