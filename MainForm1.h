#pragma once

namespace Numbersystemconverterapp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::GroupBox^ grpConversion;
	private: System::Windows::Forms::Button^ btnDecToHex;
	private: System::Windows::Forms::Button^ btnOctToBin;
	private: System::Windows::Forms::Button^ btnDecToOct;
	private: System::Windows::Forms::Button^ btnHexToDec;
	private: System::Windows::Forms::GroupBox^ grpQuestion;
	private: System::Windows::Forms::Label^ lblQuestion;
	private: System::Windows::Forms::Button^ btnGenerate;
	private: System::Windows::Forms::TextBox^ txtInput;
	private: System::Windows::Forms::GroupBox^ grpGuess;
	private: System::Windows::Forms::Label^ lblGuessText;
	private: System::Windows::Forms::Button^ btnCheck;
	private: System::Windows::Forms::TextBox^ txtGuess;
	private: System::Windows::Forms::GroupBox^ grpResult;
	private: System::Windows::Forms::Label^ lblResult;
	private: System::Windows::Forms::Label^ lblScoreText;
	private: System::Windows::Forms::Label^ lblScoreValue;
	private: System::Windows::Forms::Button^ btnTryAgain;
	private: System::Windows::Forms::Button^ btnExit;

	private:
		enum class ConversionType { None, DecToHex, HexToDec, DecToOct, OctToBin };
		ConversionType currentMode;
		String^ correctAnswer;
		int score;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->grpConversion = (gcnew System::Windows::Forms::GroupBox());
			this->btnOctToBin = (gcnew System::Windows::Forms::Button());
			this->btnDecToOct = (gcnew System::Windows::Forms::Button());
			this->btnHexToDec = (gcnew System::Windows::Forms::Button());
			this->btnDecToHex = (gcnew System::Windows::Forms::Button());
			this->grpQuestion = (gcnew System::Windows::Forms::GroupBox());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->lblQuestion = (gcnew System::Windows::Forms::Label());
			this->grpGuess = (gcnew System::Windows::Forms::GroupBox());
			this->btnCheck = (gcnew System::Windows::Forms::Button());
			this->txtGuess = (gcnew System::Windows::Forms::TextBox());
			this->lblGuessText = (gcnew System::Windows::Forms::Label());
			this->grpResult = (gcnew System::Windows::Forms::GroupBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnTryAgain = (gcnew System::Windows::Forms::Button());
			this->lblScoreText = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->grpConversion->SuspendLayout();
			this->grpQuestion->SuspendLayout();
			this->grpGuess->SuspendLayout();
			this->grpResult->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::DimGray;
			this->lblTitle->Location = System::Drawing::Point(234, 30);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(420, 38);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"NUMBER SYSTEM CONVERTER";
			// 
			// grpConversion
			// 
			this->grpConversion->Controls->Add(this->btnOctToBin);
			this->grpConversion->Controls->Add(this->btnDecToOct);
			this->grpConversion->Controls->Add(this->btnHexToDec);
			this->grpConversion->Controls->Add(this->btnDecToHex);
			this->grpConversion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->grpConversion->Location = System::Drawing::Point(93, 97);
			this->grpConversion->Name = L"grpConversion";
			this->grpConversion->Size = System::Drawing::Size(733, 100);
			this->grpConversion->TabIndex = 1;
			this->grpConversion->TabStop = false;
			this->grpConversion->Text = L"Choose Conversion:";
			// 
			// btnOctToBin
			// 
			this->btnOctToBin->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnOctToBin->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnOctToBin->Location = System::Drawing::Point(566, 53);
			this->btnOctToBin->Name = L"btnOctToBin";
			this->btnOctToBin->Size = System::Drawing::Size(143, 41);
			this->btnOctToBin->TabIndex = 3;
			this->btnOctToBin->Text = L"Oct → Bin";
			this->btnOctToBin->UseVisualStyleBackColor = false;
			this->btnOctToBin->Click += gcnew System::EventHandler(this, &MainForm::btnOctToBin_Click);
			// 
			// btnDecToOct
			// 
			this->btnDecToOct->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnDecToOct->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnDecToOct->Location = System::Drawing::Point(391, 53);
			this->btnDecToOct->Name = L"btnDecToOct";
			this->btnDecToOct->Size = System::Drawing::Size(154, 41);
			this->btnDecToOct->TabIndex = 2;
			this->btnDecToOct->Text = L"Dec → Oct";
			this->btnDecToOct->UseVisualStyleBackColor = false;
			this->btnDecToOct->Click += gcnew System::EventHandler(this, &MainForm::btnDecToOct_Click);
			// 
			// btnHexToDec
			// 
			this->btnHexToDec->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnHexToDec->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnHexToDec->Location = System::Drawing::Point(207, 53);
			this->btnHexToDec->Name = L"btnHexToDec";
			this->btnHexToDec->Size = System::Drawing::Size(156, 41);
			this->btnHexToDec->TabIndex = 1;
			this->btnHexToDec->Text = L"Hex → Dec";
			this->btnHexToDec->UseVisualStyleBackColor = false;
			this->btnHexToDec->Click += gcnew System::EventHandler(this, &MainForm::btnHexToDec_Click);
			// 
			// btnDecToHex
			// 
			this->btnDecToHex->BackColor = System::Drawing::Color::LightSeaGreen;
			this->btnDecToHex->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnDecToHex->Location = System::Drawing::Point(28, 53);
			this->btnDecToHex->Name = L"btnDecToHex";
			this->btnDecToHex->Size = System::Drawing::Size(152, 41);
			this->btnDecToHex->TabIndex = 0;
			this->btnDecToHex->Text = L"Dec → Hex";
			this->btnDecToHex->UseVisualStyleBackColor = false;
			this->btnDecToHex->Click += gcnew System::EventHandler(this, &MainForm::btnDecToHex_Click);
			// 
			// grpQuestion
			// 
			this->grpQuestion->Controls->Add(this->btnGenerate);
			this->grpQuestion->Controls->Add(this->txtInput);
			this->grpQuestion->Controls->Add(this->lblQuestion);
			this->grpQuestion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->grpQuestion->Location = System::Drawing::Point(93, 239);
			this->grpQuestion->Name = L"grpQuestion";
			this->grpQuestion->Size = System::Drawing::Size(733, 98);
			this->grpQuestion->TabIndex = 2;
			this->grpQuestion->TabStop = false;
			this->grpQuestion->Text = L"Question:";
			// 
			// btnGenerate
			// 
			this->btnGenerate->Location = System::Drawing::Point(586, 43);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(123, 41);
			this->btnGenerate->TabIndex = 5;
			this->btnGenerate->Text = L"Generate";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &MainForm::btnGenerate_Click);
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(299, 54);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(246, 30);
			this->txtInput->TabIndex = 4;
			// 
			// lblQuestion
			// 
			this->lblQuestion->AutoSize = true;
			this->lblQuestion->Location = System::Drawing::Point(13, 51);
			this->lblQuestion->Name = L"lblQuestion";
			this->lblQuestion->Size = System::Drawing::Size(160, 25);
			this->lblQuestion->TabIndex = 3;
			this->lblQuestion->Text = L"Enter value here:";
			// 
			// grpGuess
			// 
			this->grpGuess->Controls->Add(this->btnCheck);
			this->grpGuess->Controls->Add(this->txtGuess);
			this->grpGuess->Controls->Add(this->lblGuessText);
			this->grpGuess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->grpGuess->Location = System::Drawing::Point(93, 396);
			this->grpGuess->Name = L"grpGuess";
			this->grpGuess->Size = System::Drawing::Size(733, 100);
			this->grpGuess->TabIndex = 3;
			this->grpGuess->TabStop = false;
			this->grpGuess->Text = L"Your Guess\?";
			// 
			// btnCheck
			// 
			this->btnCheck->Location = System::Drawing::Point(586, 25);
			this->btnCheck->Name = L"btnCheck";
			this->btnCheck->Size = System::Drawing::Size(123, 41);
			this->btnCheck->TabIndex = 6;
			this->btnCheck->Text = L"Check Answer";
			this->btnCheck->UseVisualStyleBackColor = true;
			this->btnCheck->Click += gcnew System::EventHandler(this, &MainForm::btnCheck_Click);
			// 
			// txtGuess
			// 
			this->txtGuess->Location = System::Drawing::Point(303, 39);
			this->txtGuess->Name = L"txtGuess";
			this->txtGuess->Size = System::Drawing::Size(242, 30);
			this->txtGuess->TabIndex = 1;
			// 
			// lblGuessText
			// 
			this->lblGuessText->AutoSize = true;
			this->lblGuessText->Location = System::Drawing::Point(13, 42);
			this->lblGuessText->Name = L"lblGuessText";
			this->lblGuessText->Size = System::Drawing::Size(252, 25);
			this->lblGuessText->TabIndex = 0;
			this->lblGuessText->Text = L"Take a guess at the answer";
			// 
			// grpResult
			// 
			this->grpResult->Controls->Add(this->btnExit);
			this->grpResult->Controls->Add(this->btnTryAgain);
			this->grpResult->Controls->Add(this->lblScoreText);
			this->grpResult->Controls->Add(this->lblResult);
			this->grpResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->grpResult->Location = System::Drawing::Point(93, 523);
			this->grpResult->Name = L"grpResult";
			this->grpResult->Size = System::Drawing::Size(733, 100);
			this->grpResult->TabIndex = 4;
			this->grpResult->TabStop = false;
			this->grpResult->Text = L"Result:";
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Red;
			this->btnExit->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnExit->Location = System::Drawing::Point(586, 48);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(123, 41);
			this->btnExit->TabIndex = 4;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// btnTryAgain
			// 
			this->btnTryAgain->BackColor = System::Drawing::Color::SteelBlue;
			this->btnTryAgain->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnTryAgain->Location = System::Drawing::Point(438, 48);
			this->btnTryAgain->Name = L"btnTryAgain";
			this->btnTryAgain->Size = System::Drawing::Size(123, 41);
			this->btnTryAgain->TabIndex = 3;
			this->btnTryAgain->Text = L"Try Again";
			this->btnTryAgain->UseVisualStyleBackColor = false;
			this->btnTryAgain->Click += gcnew System::EventHandler(this, &MainForm::btnTryAgain_Click);
			// 
			// lblScoreText
			// 
			this->lblScoreText->AutoSize = true;
			this->lblScoreText->Location = System::Drawing::Point(263, 48);
			this->lblScoreText->Name = L"lblScoreText";
			this->lblScoreText->Size = System::Drawing::Size(86, 25);
			this->lblScoreText->TabIndex = 2;
			this->lblScoreText->Text = L"Score: 0";
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Location = System::Drawing::Point(13, 48);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(199, 25);
			this->lblResult->TabIndex = 1;
			this->lblResult->Text = L"CORRECT/ WRONG";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(889, 640);
			this->Controls->Add(this->grpResult);
			this->Controls->Add(this->grpGuess);
			this->Controls->Add(this->grpQuestion);
			this->Controls->Add(this->grpConversion);
			this->Controls->Add(this->lblTitle);
			this->Name = L"MainForm";
			this->Text = L"Number System Converter";
			this->grpConversion->ResumeLayout(false);
			this->grpQuestion->ResumeLayout(false);
			this->grpQuestion->PerformLayout();
			this->grpGuess->ResumeLayout(false);
			this->grpGuess->PerformLayout();
			this->grpResult->ResumeLayout(false);
			this->grpResult->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Declarations only 
		String^ DecToHex(int num);
		String^ HexToDec(String^ hex);
		String^ DecToOct(int num);
		String^ OctToBin(String^ oct);

	private:
		void btnDecToHex_Click(System::Object^ sender, System::EventArgs^ e);
		void btnHexToDec_Click(System::Object^ sender, System::EventArgs^ e);
		void btnDecToOct_Click(System::Object^ sender, System::EventArgs^ e);
		void btnOctToBin_Click(System::Object^ sender, System::EventArgs^ e);
		void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e);
		void btnCheck_Click(System::Object^ sender, System::EventArgs^ e);
		void btnTryAgain_Click(System::Object^ sender, System::EventArgs^ e);
		void btnExit_Click(System::Object^ sender, System::EventArgs^ e);
	};
}