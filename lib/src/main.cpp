#include <iostream>
#include <fstream>

#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

#define print(x) std::cout << x << '\n'

int main(int argc, char const *argv[])
{
  cv::VideoCapture badAppleVid("/home/korigamik/Dev/projects/tohou/apple-favicon/lib/vid/badapple.mp4");
  if (!badAppleVid.isOpened())
  {
    print("could not open file");
    return -1;
  }

  const int CONSOLE_WIDTH_CHAR = 80;
  const int VID_WIDTH = (int)badAppleVid.get(cv::CAP_PROP_FRAME_WIDTH),
            VID_HEIGHT = (int)badAppleVid.get(cv::CAP_PROP_FRAME_HEIGHT),
            VID_WIDTH_CONSOLE = CONSOLE_WIDTH_CHAR,
            VID_HEIGHT_CONSOLE = VID_HEIGHT * CONSOLE_WIDTH_CHAR / (VID_WIDTH * 2),
            FRAME_SKIP = (int)badAppleVid.get(cv::CAP_PROP_FPS) / 5, // 5 FPS
      TOTAL_FRAMES = (int)badAppleVid.get(cv::CAP_PROP_FRAME_COUNT) / FRAME_SKIP;
  const auto CONSOLE_FRAME_SIZE = cv::Size(VID_WIDTH_CONSOLE, VID_HEIGHT_CONSOLE);

  print(VID_HEIGHT);
  print(VID_WIDTH);

  cv::Mat vidFrame;
  badAppleVid >> vidFrame;

  cv::namedWindow("w", 1);
  std::ofstream myfile("frames.csv");
  while (!vidFrame.empty())
  {

    badAppleVid >> vidFrame;
    vidFrame.convertTo(vidFrame, cv::COLOR_BGR2GRAY);
    cv::resize(vidFrame, vidFrame, cv::Size(16, 16));
    myfile << cv::format(vidFrame, cv::Formatter::FMT_CSV);
    cv::imshow("w", vidFrame);

    print(vidFrame);

    for (int i = 0; i < FRAME_SKIP; i++)
      badAppleVid >> vidFrame;

    // cv::waitKey(200); // waits to display frame
  }
  myfile.close();
  return 0;
}
