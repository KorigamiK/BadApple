#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

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
            FRAME_SKIP = (int)badAppleVid.get(cv::CAP_PROP_FPS) / 15,
            TOTAL_FRAMES = (int)badAppleVid.get(cv::CAP_PROP_FRAME_COUNT) / FRAME_SKIP;

  const auto CONSOLE_FRAME_SIZE = cv::Size(VID_WIDTH_CONSOLE, VID_HEIGHT_CONSOLE);

  print(VID_HEIGHT);
  print(VID_WIDTH);

  return 0;
}
