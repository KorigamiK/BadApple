# BadApple/Lib

## Requirements

- [CMake](https://cmake.org/) 3.14 or higher
- [OpenCV](https://opencv.org/) 4.1.0 or higher
- [yt-dlp](https://github.com/yt-dlp/yt-dlp) 2021.10.10 or higher

### Arch Linux

Use the following command to install the required packages:

```sh
sudo pacman -S cmake opencv vtk hdf5
```

## Build

- Get the video file:

```sh
./get_video.sh
```

- Build and generate the `frames.csv` file:

```sh
cmake -S . -B build
cd build
cmake --build .
./BadApple
## Keep only the first 10000 lines
head -n 10000 frames.csv > ../public/frames.csv
```

## References

https://stackoverflow.com/questions/24337932/cannot-get-opencv-to-compile-because-of-undefined-references

https://cmake.org/cmake/help/latest/guide/tutorial/Packaging%20Debug%20and%20Release.html
