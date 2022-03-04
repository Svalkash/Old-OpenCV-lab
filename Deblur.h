#pragma once

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"


int deblur(int blurLength, double blurAngle, int snr, std::string strInFileName, std::string outFileName);
void calcPSF(cv::Mat& outputImg, cv::Size filterSize, int len, double theta);
void shiftCenter(const cv::Mat& inputImg, cv::Mat& outputImg);
void applyFilter(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& H);
void wnrFilter(const cv::Mat& input_h_PSF, cv::Mat& output_G, double nsr);