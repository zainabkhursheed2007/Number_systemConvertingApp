#pragma once

namespace Number_system_converter_app {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public enum class ConversionType {
        None,
        DecToHex,
        HexToDec,
        DecToOct,
        OctToBin
    };

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            currentMode = ConversionType::None;
            score = 0;
            txtInput->Enabled = false;
            btnGenerate->Enabled = false;
            txtGuess->Enabled = false;
            btnCheck->Enabled = false;
        }

    protected:
        ~MainForm()
        {
            if (components)
                delete components;
        }

    private:
        Button^ btnDecToHex;
        Button^ btnHexToDec;
        Button^ btnDecToOct;
        Button^ btnOctToBin;

        GroupBox^ grpConversion;
        GroupBox^ grpQuestion;
        Label^ lblQuestion;
        TextBox^ txtInput;
        Button^ btnGenerate;

        GroupBox^ grpGuess;
        Label^ lblGuessText;
        TextBox^ txtGuess;
        Button^ btnCheck;

        GroupBox^ grpResult;
        Label^ lblResult;
        Label^ lblScoreText;
        Label^ lblScoreValue;
        Button^ btnTryAgain;
        Button^ btnExit;

        ConversionType currentMode;
        String^ correctAnswer;
        int score;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->Text = "Number System Converter";
            this->BackColor = Color::LightGoldenrodYellow;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Size = Drawing::Size(800, 500);
            this->MaximizeBox = false;

            grpConversion = gcnew GroupBox();
            grpConversion->Text = "Choose Conversion";
            grpConversion->SetBounds(20, 20, 740, 80);

            btnDecToHex = gcnew Button();
            btnDecToHex->Text = "Dec to Hex";
            btnDecToHex->SetBounds(20, 30, 150, 30);
            btnDecToHex->Click += gcnew EventHandler(this, &MainForm::btnDecToHex_Click);

            btnHexToDec = gcnew Button();
            btnHexToDec->Text = "Hex to Dec";
            btnHexToDec->SetBounds(190, 30, 150, 30);
            btnHexToDec->Click += gcnew EventHandler(this, &MainForm::btnHexToDec_Click);

            btnDecToOct = gcnew Button();
            btnDecToOct->Text = "Dec to Oct";
            btnDecToOct->SetBounds(360, 30, 150, 30);
            btnDecToOct->Click += gcnew EventHandler(this, &MainForm::btnDecToOct_Click);

            btnOctToBin = gcnew Button();
            btnOctToBin->Text = "Oct to Bin";
            btnOctToBin->SetBounds(530, 30, 150, 30);
            btnOctToBin->Click += gcnew EventHandler(this, &MainForm::btnOctToBin_Click);

            grpConversion->Controls->AddRange(
                gcnew array<Control^>{ btnDecToHex, btnHexToDec, btnDecToOct, btnOctToBin });
            this->Controls->Add(grpConversion);

            grpQuestion = gcnew GroupBox();
            grpQuestion->Text = "Question";
            grpQuestion->SetBounds(20, 120, 740, 80);

            lblQuestion = gcnew Label();
            lblQuestion->Text = "Enter value here:";
            lblQuestion->SetBounds(20, 35, 200, 20);

            txtInput = gcnew TextBox();
            txtInput->SetBounds(230, 32, 200, 25);

            btnGenerate = gcnew Button();
            btnGenerate->Text = "Generate";
            btnGenerate->SetBounds(460, 30, 120, 30);
            btnGenerate->Click += gcnew EventHandler(this, &MainForm::btnGenerate_Click);

            grpQuestion->Controls->AddRange(
                gcnew array<Control^>{ lblQuestion, txtInput, btnGenerate });
            this->Controls->Add(grpQuestion);

            grpGuess = gcnew GroupBox();
            grpGuess->Text = "Your Guess?";
            grpGuess->SetBounds(20, 220, 740, 80);

            lblGuessText = gcnew Label();
            lblGuessText->Text = "Take a guess at the answer";
            lblGuessText->SetBounds(20, 35, 200, 20);

            txtGuess = gcnew TextBox();
            txtGuess->SetBounds(230, 32, 200, 25);

            btnCheck = gcnew Button();
            btnCheck->Text = "Check Answer";
            btnCheck->SetBounds(460, 30, 120, 30);
            btnCheck->Click += gcnew EventHandler(this, &MainForm::btnCheck_Click);

            grpGuess->Controls->AddRange(
                gcnew array<Control^>{ lblGuessText, txtGuess, btnCheck });
            this->Controls->Add(grpGuess);

            grpResult = gcnew GroupBox();
            grpResult->Text = "Result";
            grpResult->SetBounds(20, 320, 740, 80);

            lblResult = gcnew Label();
            lblResult->SetBounds(20, 35, 300, 20);

            lblScoreText = gcnew Label();
            lblScoreText->Text = "Score:";
            lblScoreText->SetBounds(330, 35, 50, 20);

            lblScoreValue = gcnew Label();
            lblScoreValue->Text = "0";
            lblScoreValue->SetBounds(380, 35, 40, 20);

            btnTryAgain = gcnew Button();
            btnTryAgain->Text = "Try Again";
            btnTryAgain->SetBounds(450, 30, 120, 30);
            btnTryAgain->Click += gcnew EventHandler(this, &MainForm::btnTryAgain_Click);

            btnExit = gcnew Button();
            btnExit->Text = "Exit";
            btnExit->BackColor = Color::Red;
            btnExit->ForeColor = Color::White;
            btnExit->SetBounds(590, 30, 120, 30);
            btnExit->Click += gcnew EventHandler(this, &MainForm::btnExit_Click);

            grpResult->Controls->AddRange(
                gcnew array<Control^>{ lblResult, lblScoreText, lblScoreValue, btnTryAgain, btnExit });
            this->Controls->Add(grpResult);
        }
#pragma endregion

        // ===== EVENT HANDLERS =====

        void btnDecToHex_Click(Object^, EventArgs^) {
            currentMode = ConversionType::DecToHex;
            lblQuestion->Text = "ENTER DECIMAL (0 to 65535):";
            txtInput->Enabled = true;
            btnGenerate->Enabled = true;
        }

        void btnHexToDec_Click(Object^, EventArgs^) {
            currentMode = ConversionType::HexToDec;
            lblQuestion->Text = "ENTER HEX NUMBER:";
            txtInput->Enabled = true;
            btnGenerate->Enabled = true;
        }

        void btnDecToOct_Click(Object^, EventArgs^) {
            currentMode = ConversionType::DecToOct;
            lblQuestion->Text = "ENTER DECIMAL:";
            txtInput->Enabled = true;
            btnGenerate->Enabled = true;
        }

        void btnOctToBin_Click(Object^, EventArgs^) {
            currentMode = ConversionType::OctToBin;
            lblQuestion->Text = "ENTER OCTAL NUMBER:";
            txtInput->Enabled = true;
            btnGenerate->Enabled = true;
        }

        void btnGenerate_Click(Object^, EventArgs^) {
            try {
                int baseVal =
                    (currentMode == ConversionType::HexToDec) ? 16 :
                    (currentMode == ConversionType::OctToBin) ? 8 : 10;

                int value = Convert::ToInt32(txtInput->Text, baseVal);

                switch (currentMode) {
                case ConversionType::DecToHex:
                    correctAnswer = value.ToString("X"); break;
                case ConversionType::HexToDec:
                    correctAnswer = value.ToString(); break;
                case ConversionType::DecToOct:
                    correctAnswer = Convert::ToString(value, 8); break;
                case ConversionType::OctToBin:
                    correctAnswer = Convert::ToString(value, 2); break;
                }

                txtGuess->Enabled = true;
                btnCheck->Enabled = true;
            }
            catch (...) {
                MessageBox::Show("Invalid input!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void btnCheck_Click(Object^, EventArgs^) {
            if (txtGuess->Text->ToUpper() == correctAnswer->ToUpper()) {
                score++;
                lblResult->Text = "CORRECT!";
            }
            else {
                lblResult->Text = "WRONG! Answer: " + correctAnswer;
            }
            lblScoreValue->Text = score.ToString();
        }

        void btnTryAgain_Click(Object^, EventArgs^) {
            txtInput->Clear();
            txtGuess->Clear();
            lblResult->Text = "";
            txtGuess->Enabled = false;
            btnCheck->Enabled = false;
        }

        void btnExit_Click(Object^, EventArgs^) {
            this->Close();
        }
    };
}
