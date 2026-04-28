#include "MainForm1.h"

using namespace Numbersystemconverterapp;

// --- Constructor ---
// This connects the code to the actual window you designed
MainForm::MainForm(void)
{
	InitializeComponent();
	score = 0;
	currentMode = ConversionType::None;

	// Set initial button states
	txtInput->Enabled = false;
	btnGenerate->Enabled = false;
	txtGuess->Enabled = false;
	btnCheck->Enabled = false;
}

// --- Conversion Helper Methods ---

String^ MainForm::DecToHex(int num)
{
	return Convert::ToString(num, 16)->ToUpper();
}

String^ MainForm::HexToDec(String^ hex)
{
	try {
		return Convert::ToInt32(hex, 16).ToString();
	}
	catch (...) { return "0"; }
}

String^ MainForm::DecToOct(int num)
{
	return Convert::ToString(num, 8);
}

String^ MainForm::OctToBin(String^ oct)
{
	String^ bin = "";
	for (int i = 0; i < oct->Length; i++)
	{
		// Convert each octal digit to 3-bit binary
		int val = oct[i] - '0';
		bin += Convert::ToString(val, 2)->PadLeft(3, '0');
	}
	return bin;
}

// --- Button Click Events ---

void MainForm::btnDecToHex_Click(Object^ sender, EventArgs^ e)
{
	currentMode = ConversionType::DecToHex;
	lblQuestion->Text = "ENTER DECIMAL (0-65535):";
	txtInput->Enabled = true;
	btnGenerate->Enabled = true;
	txtInput->Focus();
}

void MainForm::btnHexToDec_Click(Object^ sender, EventArgs^ e)
{
	currentMode = ConversionType::HexToDec;
	lblQuestion->Text = "ENTER HEX NUMBER:";
	txtInput->Enabled = true;
	btnGenerate->Enabled = true;
	txtInput->Focus();
}

void MainForm::btnDecToOct_Click(Object^ sender, EventArgs^ e)
{
	currentMode = ConversionType::DecToOct;
	lblQuestion->Text = "ENTER DECIMAL:";
	txtInput->Enabled = true;
	btnGenerate->Enabled = true;
	txtInput->Focus();
}

void MainForm::btnOctToBin_Click(Object^ sender, EventArgs^ e)
{
	currentMode = ConversionType::OctToBin;
	lblQuestion->Text = "ENTER OCTAL NUMBER:";
	txtInput->Enabled = true;
	btnGenerate->Enabled = true;
	txtInput->Focus();
}

void MainForm::btnGenerate_Click(Object^ sender, EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(txtInput->Text))
	{
		MessageBox::Show("Please enter a value first!");
		return;
	}

	try
	{
		if (currentMode == ConversionType::DecToHex)
			correctAnswer = DecToHex(Int32::Parse(txtInput->Text));
		else if (currentMode == ConversionType::HexToDec)
			correctAnswer = HexToDec(txtInput->Text);
		else if (currentMode == ConversionType::DecToOct)
			correctAnswer = DecToOct(Int32::Parse(txtInput->Text));
		else if (currentMode == ConversionType::OctToBin)
			correctAnswer = OctToBin(txtInput->Text);

		txtGuess->Enabled = true;
		btnCheck->Enabled = true;
		lblResult->Text = "Answer Generated!";
	}
	catch (...)
	{
		MessageBox::Show("Invalid Input for this conversion!");
	}
}

void MainForm::btnCheck_Click(Object^ sender, EventArgs^ e)
{
	// Normalize strings to compare them fairly (remove spaces, same case)
	String^ userGuess = txtGuess->Text->Trim()->ToUpper();
	String^ actual = correctAnswer->ToUpper();

	if (userGuess == actual)
	{
		score++;
		lblResult->Text = "CORRECT!";
	}
	else
	{
		lblResult->Text = "WRONG! Correct: " + correctAnswer;
	}

	lblScoreText->Text = "Score: " + score.ToString();
}

void MainForm::btnTryAgain_Click(Object^ sender, EventArgs^ e)
{
	txtInput->Clear();
	txtGuess->Clear();
	txtInput->Enabled = false;
	txtGuess->Enabled = false;
	btnGenerate->Enabled = false;
	btnCheck->Enabled = false;
	lblResult->Text = "Result";
	currentMode = ConversionType::None;
	lblQuestion->Text = "Choose Conversion:";
}

void MainForm::btnExit_Click(Object^ sender, EventArgs^ e)
{
	Application::Exit();
}