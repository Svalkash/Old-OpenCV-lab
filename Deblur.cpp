#include "Deblur.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

// Основная функция, реализующая восстановление изображения
int deblur(int blurLength, double blurAngle, int snr, std::string strInFileName, std::string outFileName)
{
	cv::Mat imgInC;
	imgInC = cv::imread(strInFileName, cv::IMREAD_COLOR);
	//Проверка на успешность загрузки
	if (imgInC.empty())
		return -1;
	cv::Mat imgIn[3];
	cv::split(imgInC, imgIn);
	cv::Mat imgOut[3];
	cv::Mat imgOutC;
	for (int i = 0; i < 3; ++i) {
		cv::Rect roi = cv::Rect(0, 0, imgIn[i].cols & -2, imgIn[i].rows & -2);
		cv::Mat Hw, h;
		calcPSF(h, roi.size(), blurLength, blurAngle);
		wnrFilter(h, Hw, 1.0 / double(snr));
		imgIn[i].convertTo(imgIn[i], CV_32F);
		applyFilter(imgIn[i](roi), imgOut[i], Hw);
		imgOut[i].convertTo(imgOut[i], CV_8U);
		cv::normalize(imgOut[i], imgOut[i], 0, 255, cv::NORM_MINMAX);
	}
	cv::merge(imgOut, 3, imgOutC);
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	cv::imshow("image", imgOutC);
	imwrite(outFileName, imgOutC);
	return 0;
}

//Вычисление функции распределения точек на основе введённых данных
void calcPSF(cv::Mat& outputImg, cv::Size filterSize, int len, double theta)
{
	cv::Mat h(filterSize, CV_32F, cv::Scalar(0));
	cv::Point point(filterSize.width / 2, filterSize.height / 2);
	ellipse(h, point, cv::Size(0, cvRound(float(len) / 2.0)), 90.0 - theta, 0, 360, cv::Scalar(255), cv::FILLED);
	cv::Scalar summa = sum(h);
	outputImg = h / summa[0];
}

//Смещение центра изображения для более удобной работы с ним
void shiftCenter(const cv::Mat& inputImg, cv::Mat& outputImg)
{
	outputImg = inputImg.clone();
	int centerX = outputImg.cols / 2;
	int centerY = outputImg.rows / 2;
	cv::Mat lu(outputImg, cv::Rect(0, 0, centerX, centerY));
	cv::Mat ru(outputImg, cv::Rect(centerX, 0, centerX, centerY));
	cv::Mat ld(outputImg, cv::Rect(0, centerY, centerX, centerY));
	cv::Mat rd(outputImg, cv::Rect(centerX, centerY, centerX, centerY));
	cv::Mat buf;
	lu.copyTo(buf);
	rd.copyTo(lu);
	buf.copyTo(rd);
	ru.copyTo(buf);
	ld.copyTo(ru);
	buf.copyTo(ld);
}

//Вычисление значений фильтра Винера на основе PSF
void wnrFilter(const cv::Mat& input_h_PSF, cv::Mat& output_G, double nsr)
{
	cv::Mat h_PSF_shifted;
	shiftCenter(input_h_PSF, h_PSF_shifted);
	cv::Mat planes[2] = { cv::Mat_<float>(h_PSF_shifted.clone()), cv::Mat::zeros(h_PSF_shifted.size(), CV_32F) };
	cv::Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI);
	split(complexI, planes);
	cv::Mat denom;
	pow(abs(planes[0]), 2, denom);
	denom += nsr;
	divide(planes[0], denom, output_G);
}

//Применение фильтра Винера к изображению
void applyFilter(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& H)
{
	cv::Mat planes[2] = { cv::Mat_<float>(inputImg.clone()), cv::Mat::zeros(inputImg.size(), CV_32F) };
	cv::Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI, cv::DFT_SCALE);
	cv::Mat planesH[2] = { cv::Mat_<float>(H.clone()), cv::Mat::zeros(H.size(), CV_32F) };
	cv::Mat complexH;
	merge(planesH, 2, complexH);
	cv::Mat complexIH;
	mulSpectrums(complexI, complexH, complexIH, 0);
	idft(complexIH, complexIH);
	split(complexIH, planes);
	outputImg = planes[0];
}