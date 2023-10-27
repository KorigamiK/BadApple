#include <fstream>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

int main(int argc, char const *argv[]) {
  cv::VideoCapture badAppleVid("vid/badapple.mp4");
  if (!badAppleVid.isOpened()) {
    std::cout << "Error opening video stream or file" << std::endl;
    return -1;
  }

  const int EXPORT_WIDTH = 80;
  const int VID_WIDTH_CONSOLE = EXPORT_WIDTH;
  const int VID_WIDTH =
      static_cast<int>(badAppleVid.get(cv::CAP_PROP_FRAME_WIDTH));
  const int VID_HEIGHT =
      static_cast<int>(badAppleVid.get(cv::CAP_PROP_FRAME_HEIGHT));
  const int VID_HEIGHT_CONSOLE = VID_HEIGHT * EXPORT_WIDTH / (VID_WIDTH * 2);
  const int FRAME_SKIP =
      static_cast<int>(badAppleVid.get(cv::CAP_PROP_FPS) / 5); // 5 FPS
  const int TOTAL_FRAMES =
      static_cast<int>(badAppleVid.get(cv::CAP_PROP_FRAME_COUNT) / FRAME_SKIP);
  const auto CONSOLE_FRAME_SIZE =
      cv::Size(VID_WIDTH_CONSOLE, VID_HEIGHT_CONSOLE);

  std::cout << "Video width: " << VID_WIDTH << std::endl;
  std::cout << "Video height: " << VID_HEIGHT << std::endl;
  std::cout << "Total frames: " << TOTAL_FRAMES << std::endl;
  std::cout << "Total seconds: " << TOTAL_FRAMES / 5 << std::endl;

  cv::Mat vidFrame;
  badAppleVid >> vidFrame;

  cv::namedWindow("w", 1);
  std::ofstream myfile("frames.csv");
  while (!vidFrame.empty()) {
    badAppleVid >> vidFrame;
    vidFrame.convertTo(vidFrame, cv::COLOR_BGR2GRAY);
    cv::resize(vidFrame, vidFrame, cv::Size(16, 16));
    myfile << cv::format(vidFrame, cv::Formatter::FMT_CSV);
    cv::imshow("w", vidFrame);

    print(vidFrame);

    for (int i = 0; i < FRAME_SKIP; i++)
      badAppleVid >> vidFrame;

    cv::waitKey(200); // waits to display frame
  }
  myfile.close();

  std::cout << "\nFrames written to frames.csv" << std::endl;
  return 0;
}
