#pragma once

#include <msclr/marshal_cppstd.h>
#include "opencv2/imgcodecs.hpp"
#include "Deblur.h"

namespace opencvwithforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/*
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace System::Collections::Generic;
	*/
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			bufferOut = "result.jpg";
			this->lengthActive = true;
			this->angleActive = true;
			this->snrActive = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loadButton;
	private: System::Windows::Forms::OpenFileDialog^  openImage;
	private: System::Windows::Forms::SaveFileDialog^  saveImage;
	protected:





	private: System::Windows::Forms::Button^  saveButton;





	private: System::Windows::Forms::TextBox^  filenameBox;
	private: System::Windows::Forms::TrackBar^  snrBar;


	private: System::Windows::Forms::TrackBar^  lengthBar;
	private: System::Windows::Forms::TrackBar^  angleBar;
	private: System::Windows::Forms::Label^  lengthLabel;
	private: System::Windows::Forms::Label^  angleLabel;
	private: System::Windows::Forms::Label^  snrLabel;
	private: System::Windows::Forms::TextBox^  lengthBox;
	private: System::Windows::Forms::TextBox^  angleBox;
	private: System::Windows::Forms::TextBox^  snrBox;



















	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->openImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveImage = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->filenameBox = (gcnew System::Windows::Forms::TextBox());
			this->snrBar = (gcnew System::Windows::Forms::TrackBar());
			this->lengthBar = (gcnew System::Windows::Forms::TrackBar());
			this->angleBar = (gcnew System::Windows::Forms::TrackBar());
			this->lengthLabel = (gcnew System::Windows::Forms::Label());
			this->angleLabel = (gcnew System::Windows::Forms::Label());
			this->snrLabel = (gcnew System::Windows::Forms::Label());
			this->lengthBox = (gcnew System::Windows::Forms::TextBox());
			this->angleBox = (gcnew System::Windows::Forms::TextBox());
			this->snrBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->snrBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lengthBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleBar))->BeginInit();
			this->SuspendLayout();
			// 
			// loadButton
			// 
			this->loadButton->Location = System::Drawing::Point(508, 12);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(83, 23);
			this->loadButton->TabIndex = 0;
			this->loadButton->Text = L"Load Image";
			this->loadButton->UseVisualStyleBackColor = true;
			this->loadButton->Click += gcnew System::EventHandler(this, &MyForm::loadButton_Click);
			// 
			// openImage
			// 
			this->openImage->Filter = L"Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files (*.*)|*.*";
			this->openImage->Title = L"Open Image...";
			// 
			// saveImage
			// 
			this->saveImage->DefaultExt = L"jpg";
			this->saveImage->FileName = L"result.jpg";
			this->saveImage->Filter = L"JPG Files(*.JPG)|*.JPG|All files (*.*)|*.*";
			// 
			// saveButton
			// 
			this->saveButton->Enabled = false;
			this->saveButton->Location = System::Drawing::Point(597, 12);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(83, 23);
			this->saveButton->TabIndex = 6;
			this->saveButton->Text = L"Save Image";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MyForm::saveButton_Click);
			// 
			// filenameBox
			// 
			this->filenameBox->Location = System::Drawing::Point(12, 12);
			this->filenameBox->Name = L"filenameBox";
			this->filenameBox->ReadOnly = true;
			this->filenameBox->Size = System::Drawing::Size(490, 20);
			this->filenameBox->TabIndex = 5;
			// 
			// snrBar
			// 
			this->snrBar->Enabled = false;
			this->snrBar->Location = System::Drawing::Point(12, 143);
			this->snrBar->Maximum = 1000;
			this->snrBar->Name = L"snrBar";
			this->snrBar->Size = System::Drawing::Size(490, 45);
			this->snrBar->TabIndex = 9;
			this->snrBar->TickFrequency = 100;
			this->snrBar->Scroll += gcnew System::EventHandler(this, &MyForm::snrBar_Scroll);
			// 
			// lengthBar
			// 
			this->lengthBar->Enabled = false;
			this->lengthBar->Location = System::Drawing::Point(12, 41);
			this->lengthBar->Maximum = 0;
			this->lengthBar->Name = L"lengthBar";
			this->lengthBar->Size = System::Drawing::Size(490, 45);
			this->lengthBar->TabIndex = 10;
			this->lengthBar->Scroll += gcnew System::EventHandler(this, &MyForm::lengthBar_Scroll);
			// 
			// angleBar
			// 
			this->angleBar->Enabled = false;
			this->angleBar->Location = System::Drawing::Point(12, 92);
			this->angleBar->Maximum = 180;
			this->angleBar->Minimum = -180;
			this->angleBar->Name = L"angleBar";
			this->angleBar->Size = System::Drawing::Size(490, 45);
			this->angleBar->TabIndex = 11;
			this->angleBar->TickFrequency = 10;
			this->angleBar->Scroll += gcnew System::EventHandler(this, &MyForm::angleBar_Scroll);
			// 
			// lengthLabel
			// 
			this->lengthLabel->AutoSize = true;
			this->lengthLabel->Location = System::Drawing::Point(597, 41);
			this->lengthLabel->Name = L"lengthLabel";
			this->lengthLabel->Size = System::Drawing::Size(57, 13);
			this->lengthLabel->TabIndex = 15;
			this->lengthLabel->Text = L"Blur length";
			// 
			// angleLabel
			// 
			this->angleLabel->AutoSize = true;
			this->angleLabel->Location = System::Drawing::Point(597, 92);
			this->angleLabel->Name = L"angleLabel";
			this->angleLabel->Size = System::Drawing::Size(54, 13);
			this->angleLabel->TabIndex = 16;
			this->angleLabel->Text = L"Blur angle";
			// 
			// snrLabel
			// 
			this->snrLabel->AutoSize = true;
			this->snrLabel->Location = System::Drawing::Point(597, 143);
			this->snrLabel->Name = L"snrLabel";
			this->snrLabel->Size = System::Drawing::Size(30, 13);
			this->snrLabel->TabIndex = 17;
			this->snrLabel->Text = L"SNR";
			// 
			// lengthBox
			// 
			this->lengthBox->Enabled = false;
			this->lengthBox->Location = System::Drawing::Point(508, 41);
			this->lengthBox->Name = L"lengthBox";
			this->lengthBox->Size = System::Drawing::Size(83, 20);
			this->lengthBox->TabIndex = 21;
			this->lengthBox->TextChanged += gcnew System::EventHandler(this, &MyForm::lengthBox_TextChanged);
			// 
			// angleBox
			// 
			this->angleBox->Enabled = false;
			this->angleBox->Location = System::Drawing::Point(508, 92);
			this->angleBox->Name = L"angleBox";
			this->angleBox->Size = System::Drawing::Size(83, 20);
			this->angleBox->TabIndex = 22;
			// 
			// snrBox
			// 
			this->snrBox->Enabled = false;
			this->snrBox->Location = System::Drawing::Point(508, 143);
			this->snrBox->Name = L"snrBox";
			this->snrBox->Size = System::Drawing::Size(83, 20);
			this->snrBox->TabIndex = 23;
			this->snrBox->TextChanged += gcnew System::EventHandler(this, &MyForm::snrBox_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 177);
			this->Controls->Add(this->snrBox);
			this->Controls->Add(this->angleBox);
			this->Controls->Add(this->lengthBox);
			this->Controls->Add(this->snrLabel);
			this->Controls->Add(this->angleLabel);
			this->Controls->Add(this->lengthLabel);
			this->Controls->Add(this->angleBar);
			this->Controls->Add(this->lengthBar);
			this->Controls->Add(this->snrBar);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->filenameBox);
			this->Controls->Add(this->loadButton);
			this->Name = L"MyForm";
			this->Text = L"Deblur";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->snrBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lengthBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: property System::String^ bufferFile;
private: property System::String^ bufferOut;
		 //ни хрена не понятно, но очень интересно. Почему без property низя?
private: property System::Boolean^ lengthActive;
private: property System::Boolean^ angleActive;
private: property System::Boolean^ snrActive;

private: int reloadImg() {
	//filtering
	int ret = deblur(std::stoi(marshal_as<std::string>(this->lengthBox->Text)),
		std::stod(marshal_as<std::string>(this->angleBox->Text)),
		std::stoi(marshal_as<std::string>(this->snrBox->Text)),
		marshal_as<std::string>(this->bufferFile),
		marshal_as<std::string>(this->bufferOut));
	if (ret == -1) {
		System::Windows::Forms::MessageBox::Show("Empty image!");
		return -1;
	}
	return 0;
}

// Обработчик нажатия на кнопку загрузки нового файла
private: System::Void loadButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//open dialog
	System::Windows::Forms::DialogResult diaRes = this->openImage->ShowDialog();
	//take filename
	if (diaRes == System::Windows::Forms::DialogResult::OK) {
		try {
			String^ fn = this->openImage->FileName;
			//try to "open" orig file to throw exceptions.. and get some info
			System::Drawing::Image^ newImg = System::Drawing::Image::FromFile(fn);
			//creating buffer file name
			String^ res = System::IO::Path::GetExtension(fn);
			bufferFile = System::String::Concat("buffer", res);
			//copying
			System::IO::File::Copy(fn, bufferFile, true);
			//loading info: size, max. values...
			//filename
			this->filenameBox->Text = fn;
			//length
			this->lengthBar->Minimum = 0; //too small?
			this->lengthBar->Maximum = std::max(newImg->Height, newImg->Width); //too small?
			this->lengthBar->Value = 0;
			this->lengthActive = false;
			this->lengthBox->Text = marshal_as<System::String^>(std::to_string(0));
			this->lengthActive = true;
			//angle
			this->angleBar->Value = 0;
			this->angleActive = false;
			this->angleBox->Text = marshal_as<System::String^>(std::to_string(0));
			this->angleActive = true;
			//SNR
			this->snrBar->Value = this->snrBar->Maximum;
			this->snrActive = false;
			this->snrBox->Text = marshal_as<System::String^>(std::to_string(this->snrBar->Maximum));
			this->snrActive = true;
			//enabling all
			this->lengthBox->Enabled = true;
			this->angleBox->Enabled = true;
			this->snrBox->Enabled = true;
			this->lengthBar->Enabled = true;
			this->angleBar->Enabled = true;
			this->snrBar->Enabled = true;
			this->saveButton->Enabled = true;
			//reload
			reloadImg();
		}
		catch (System::OutOfMemoryException^) {
			System::Windows::Forms::MessageBox::Show("Invalid file!");
		}
		catch (System::IO::FileNotFoundException^) {
			System::Windows::Forms::MessageBox::Show("File not found!");
		}
	}
}

// Обработчик нажатия на кнопку сохранения исправленного файла
private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//open dialog
	System::Windows::Forms::DialogResult diaRes = this->saveImage->ShowDialog();
	//take filename
	if (diaRes == System::Windows::Forms::DialogResult::OK) {
		String^ fn = this->saveImage->FileName;
		//copying
		System::IO::File::Copy(bufferOut, this->saveImage->FileName, true);
	}
}

// Обработчик изменения введённого значения длины
private: System::Void lengthBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->lengthActive->CompareTo(true) == 0) {
		std::string textStr = marshal_as<std::string>(this->lengthBox->Text);
		auto it = textStr.begin();
		while (it != textStr.end())
			if ((*it) < '0' || (*it) > '9') {
				textStr.erase(it);
				it = textStr.begin();
			}
			else
				++it;
		if (textStr.length() == 0) {
			//"abort"
			this->lengthActive = false;
			this->lengthBox->Text = marshal_as<String^>(std::to_string(this->lengthBar->Value));
			this->lengthActive = true;
			return;
		}
		if (std::stoi(textStr) > this->lengthBar->Maximum || std::stoi(textStr) < this->lengthBar->Minimum) {
			//"abort"
			this->lengthActive = false;
			this->lengthBox->Text = marshal_as<String^>(std::to_string(this->lengthBar->Value));
			this->lengthActive = true;
			return;
		}
		//put back
		this->lengthActive = false;
		this->lengthBox->Text = marshal_as<String^>(textStr);
		this->lengthActive = true;
		//convert to bar
		this->lengthBar->Value = std::stoi(textStr);
		//reload
		reloadImg();
	}
}

// Обработчик изменения введённого значения угла
private: System::Void angleBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->angleActive->CompareTo(true) == 0) {
		std::string textStr = marshal_as<std::string>(this->angleBox->Text);
		//clearing
		while (textStr[0] != '-' && (textStr[0] < '0' || textStr[0] > '9'))
			textStr.erase(textStr.begin());
		if (textStr[0] == '-')
			while (textStr[1] < '0' || textStr[1] > '9')
				textStr.erase(++textStr.begin());
		else
			while (textStr[1] != '.' && (textStr[1] < '0' || textStr[1] > '9'))
				textStr.erase(++textStr.begin());
		//rest
		auto newbegin = textStr.begin();
		if (textStr[0] == '-')
			++newbegin;
		auto it = newbegin;
		bool seen = false;
		while (it != textStr.end()) {
			if ((*it) == '.') {
				if (seen) {
					textStr.erase(it);
					it = newbegin;
					seen = false;
				}
				else {
					seen = true;
					++it;
				}
			}
			else if ((*it) < '0' || (*it) > '9') {
				textStr.erase(it);
				it = newbegin;
				seen = false;
			}
			else
				++it;
		}
		if (textStr.length() == 0) {
			//"abort"
			this->angleActive = false;
			this->angleBox->Text = marshal_as<String^>(std::to_string(this->angleBar->Value));
			this->angleActive = true;
			return;
		}
		if (std::stoi(textStr) > this->angleBar->Maximum) {
			//"abort"
			this->angleActive = false;
			this->angleBox->Text = marshal_as<String^>(std::to_string(this->angleBar->Value));
			this->angleActive = true;
			return;
		}
		//put back
		this->angleActive = false;
		this->angleBox->Text = marshal_as<String^>(textStr);
		this->angleActive = true;
		//convert to bar
		this->angleBar->Value = std::round(std::stod(textStr));
		//reload
		reloadImg();
	}
}

// Обработчик изменения введённого значения SNR
private: System::Void snrBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->snrActive->CompareTo(true) == 0) {
		std::string textStr = marshal_as<std::string>(this->snrBox->Text);
		auto it = textStr.begin();
		while (it != textStr.end())
			if ((*it) < '0' || (*it) > '9') {
				textStr.erase(it);
				it = textStr.begin();
			}
			else
				++it;
		if (textStr.length() == 0) {
			//"abort"
			this->snrActive = false;
			this->snrBox->Text = marshal_as<String^>(std::to_string(this->snrBar->Value));
			this->snrActive = true;
			return;
		}
		if (std::stoi(textStr) > this->snrBar->Maximum || std::stoi(textStr) < this->snrBar->Minimum) {
			//"abort"
			this->snrActive = false;
			this->snrBox->Text = marshal_as<String^>(std::to_string(this->snrBar->Value));
			this->snrActive = true;
			return;
		}
		//put back
		this->snrActive = false;
		this->snrBox->Text = marshal_as<String^>(textStr);
		this->snrActive = true;
		//convert to bar
		this->snrBar->Value = std::stoi(textStr);
		//reload
		reloadImg();
	}
}

// Обработчик изменения введённого значения длины
private: System::Void lengthBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//convert to box
	this->lengthActive = false;
	this->lengthBox->Text = marshal_as<String^>(std::to_string(this->lengthBar->Value));
	this->lengthActive = true;
	//reload
	reloadImg();
}

// Обработчик изменения введённого значения угла
private: System::Void angleBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//convert to box
	this->angleActive = false;
	this->angleBox->Text = marshal_as<String^>(std::to_string(this->angleBar->Value));
	this->angleActive = true;
	//reload
	reloadImg();
}

// Обработчик изменения введённого значения SNR
private: System::Void snrBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//convert to box
	this->snrActive = false;
	this->snrBox->Text = marshal_as<String^>(std::to_string(this->snrBar->Value));
	this->snrActive = true;
	//reload
	reloadImg();
}

};
}