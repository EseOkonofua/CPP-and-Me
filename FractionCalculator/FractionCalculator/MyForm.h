#pragma once
#include "fraction_13eio.h"	
namespace FractionCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TextBox^  f1Num;
	private: System::Windows::Forms::TextBox^  f1Den;
	private: System::Windows::Forms::TextBox^  f2Num;
	private: System::Windows::Forms::TextBox^  f2Den;
	protected:

	protected:





	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  addition;
	private: System::Windows::Forms::RadioButton^  subtraction;
	private: System::Windows::Forms::RadioButton^  division;
	private: System::Windows::Forms::RadioButton^  multiplication;
	private: System::Windows::Forms::TextBox^  resultNum;
	private: System::Windows::Forms::TextBox^  resultDen;







	private: System::Windows::Forms::Button^  equals;
	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::TextBox^  errorbox;



	private: System::Windows::Forms::GroupBox^  operations;
	private: System::Windows::Forms::Label^  label1;


	private: System::ComponentModel::IContainer^  components;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->f1Num = (gcnew System::Windows::Forms::TextBox());
			this->f1Den = (gcnew System::Windows::Forms::TextBox());
			this->f2Num = (gcnew System::Windows::Forms::TextBox());
			this->f2Den = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addition = (gcnew System::Windows::Forms::RadioButton());
			this->subtraction = (gcnew System::Windows::Forms::RadioButton());
			this->division = (gcnew System::Windows::Forms::RadioButton());
			this->multiplication = (gcnew System::Windows::Forms::RadioButton());
			this->resultNum = (gcnew System::Windows::Forms::TextBox());
			this->resultDen = (gcnew System::Windows::Forms::TextBox());
			this->equals = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->errorbox = (gcnew System::Windows::Forms::TextBox());
			this->operations = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->operations->SuspendLayout();
			this->SuspendLayout();
			// 
			// f1Num
			// 
			this->f1Num->Location = System::Drawing::Point(12, 35);
			this->f1Num->Name = L"f1Num";
			this->f1Num->Size = System::Drawing::Size(59, 20);
			this->f1Num->TabIndex = 0;
			this->f1Num->Text = L"0";
			this->f1Num->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->f1Num->TextChanged += gcnew System::EventHandler(this, &MyForm::f1Num_TextChanged);
			this->f1Num->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::f1Num_KeyPress);
			// 
			// f1Den
			// 
			this->f1Den->Location = System::Drawing::Point(12, 68);
			this->f1Den->Name = L"f1Den";
			this->f1Den->Size = System::Drawing::Size(59, 20);
			this->f1Den->TabIndex = 1;
			this->f1Den->Text = L"1";
			this->f1Den->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->f1Den->TextChanged += gcnew System::EventHandler(this, &MyForm::f1Den_TextChanged);
			this->f1Den->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::f1Den_KeyPress);
			// 
			// f2Num
			// 
			this->f2Num->Location = System::Drawing::Point(136, 35);
			this->f2Num->Name = L"f2Num";
			this->f2Num->Size = System::Drawing::Size(59, 20);
			this->f2Num->TabIndex = 6;
			this->f2Num->Text = L"0";
			this->f2Num->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->f2Num->TextChanged += gcnew System::EventHandler(this, &MyForm::f2Num_TextChanged);
			this->f2Num->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::f2Num_KeyPress);
			// 
			// f2Den
			// 
			this->f2Den->Location = System::Drawing::Point(136, 68);
			this->f2Den->Name = L"f2Den";
			this->f2Den->Size = System::Drawing::Size(59, 20);
			this->f2Den->TabIndex = 7;
			this->f2Den->Text = L"1";
			this->f2Den->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->f2Den->TextChanged += gcnew System::EventHandler(this, &MyForm::f2Den_TextChanged);
			this->f2Den->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::f2Den_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Fraction 1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(138, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Fraction 2";
			// 
			// addition
			// 
			this->addition->AutoSize = true;
			this->addition->Checked = true;
			this->addition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->addition->Location = System::Drawing::Point(10, 19);
			this->addition->Name = L"addition";
			this->addition->Size = System::Drawing::Size(36, 24);
			this->addition->TabIndex = 2;
			this->addition->TabStop = true;
			this->addition->Text = L"+";
			this->addition->UseVisualStyleBackColor = true;
			this->addition->CheckedChanged += gcnew System::EventHandler(this, &MyForm::addition_CheckedChanged);
			// 
			// subtraction
			// 
			this->subtraction->AutoSize = true;
			this->subtraction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->subtraction->Location = System::Drawing::Point(10, 49);
			this->subtraction->Name = L"subtraction";
			this->subtraction->Size = System::Drawing::Size(32, 24);
			this->subtraction->TabIndex = 3;
			this->subtraction->Text = L"-";
			this->subtraction->UseVisualStyleBackColor = true;
			this->subtraction->CheckedChanged += gcnew System::EventHandler(this, &MyForm::subtraction_CheckedChanged);
			// 
			// division
			// 
			this->division->AutoSize = true;
			this->division->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->division->Location = System::Drawing::Point(10, 79);
			this->division->Name = L"division";
			this->division->Size = System::Drawing::Size(31, 24);
			this->division->TabIndex = 4;
			this->division->Text = L"/";
			this->division->UseVisualStyleBackColor = true;
			this->division->CheckedChanged += gcnew System::EventHandler(this, &MyForm::division_CheckedChanged);
			// 
			// multiplication
			// 
			this->multiplication->AutoSize = true;
			this->multiplication->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->multiplication->Location = System::Drawing::Point(10, 111);
			this->multiplication->Name = L"multiplication";
			this->multiplication->Size = System::Drawing::Size(30, 17);
			this->multiplication->TabIndex = 5;
			this->multiplication->Text = L"x";
			this->multiplication->UseVisualStyleBackColor = true;
			this->multiplication->CheckedChanged += gcnew System::EventHandler(this, &MyForm::multiplication_CheckedChanged);
			// 
			// resultNum
			// 
			this->resultNum->Location = System::Drawing::Point(259, 35);
			this->resultNum->Name = L"resultNum";
			this->resultNum->ReadOnly = true;
			this->resultNum->Size = System::Drawing::Size(59, 20);
			this->resultNum->TabIndex = 9;
			this->resultNum->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// resultDen
			// 
			this->resultDen->Location = System::Drawing::Point(259, 68);
			this->resultDen->Name = L"resultDen";
			this->resultDen->ReadOnly = true;
			this->resultDen->Size = System::Drawing::Size(59, 20);
			this->resultDen->TabIndex = 10;
			this->resultDen->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// equals
			// 
			this->equals->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->equals->ForeColor = System::Drawing::Color::Black;
			this->equals->Location = System::Drawing::Point(210, 53);
			this->equals->Name = L"equals";
			this->equals->Size = System::Drawing::Size(36, 23);
			this->equals->TabIndex = 8;
			this->equals->Text = L"=";
			this->equals->UseVisualStyleBackColor = true;
			this->equals->Click += gcnew System::EventHandler(this, &MyForm::equals_Click);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(264, 146);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(47, 23);
			this->clear->TabIndex = 11;
			this->clear->Text = L"Reset";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &MyForm::clear_Click);
			// 
			// errorbox
			// 
			this->errorbox->ForeColor = System::Drawing::Color::Black;
			this->errorbox->Location = System::Drawing::Point(12, 182);
			this->errorbox->Name = L"errorbox";
			this->errorbox->ReadOnly = true;
			this->errorbox->Size = System::Drawing::Size(306, 20);
			this->errorbox->TabIndex = 12;
			// 
			// operations
			// 
			this->operations->Controls->Add(this->multiplication);
			this->operations->Controls->Add(this->division);
			this->operations->Controls->Add(this->subtraction);
			this->operations->Controls->Add(this->addition);
			this->operations->Location = System::Drawing::Point(74, 9);
			this->operations->Name = L"operations";
			this->operations->Size = System::Drawing::Size(56, 144);
			this->operations->TabIndex = 13;
			this->operations->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(272, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Result";
			// 
			// MyForm
			// 
			this->AcceptButton = this->equals;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(331, 205);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->operations);
			this->Controls->Add(this->errorbox);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->equals);
			this->Controls->Add(this->resultDen);
			this->Controls->Add(this->resultNum);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->f2Den);
			this->Controls->Add(this->f2Num);
			this->Controls->Add(this->f1Den);
			this->Controls->Add(this->f1Num);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Fraction Calculator by Ese Okonofua";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->operations->ResumeLayout(false);
			this->operations->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void equals_Click(System::Object^  sender, System::EventArgs^  e) {
		this->errorbox->Text = "";
		this->resultDen->Text = "";
		this->resultNum->Text = "";
		String^ f1Numerator = this->f1Num->Text;
		String^ f1Denominator = this->f1Den->Text;
		String^ f2Numerator = this->f2Num->Text;
		String^ f2Denominator = this->f2Den->Text;

		int f1Num, f1Den, f2Num, f2Den;
		bool result1 = Int32::TryParse(f1Numerator, f1Num);
		bool result2 = Int32::TryParse(f1Denominator, f1Den);
		bool result3 = Int32::TryParse(f2Numerator, f2Num);
		bool result4 = Int32::TryParse(f2Denominator, f2Den);
		if (!(result1 && result2 && result3 && result4)) {
			this->errorbox->Text = "Invalid input values!";
			this->resultNum->Text = "";
			this->resultDen->Text = "";
		}
		else if (f1Numerator == "" || f1Denominator == "" || f2Numerator == "" || f2Denominator == "") {
			this->errorbox->Text = "Must have integer values to complete operations! ";
			this->resultDen->Text = "";
			this->resultNum->Text = "";
		}
		else {
			Fraction solution;

			try {
				Fraction lFraction = Fraction(f1Num, f1Den);
				Fraction rFraction = Fraction(f2Num, f2Den);

				if (addition->Checked) {
					solution = lFraction + rFraction;
					String^ value = Convert::ToString(solution.numerator());
					String^ value2 = Convert::ToString(solution.denominator());
					if (value2 == "1")
						value2 = "";
					this->resultNum->Text = value;
					this->resultDen->Text = value2;
				}
				else if (subtraction->Checked) {
					solution = lFraction - rFraction;
					String^ value = Convert::ToString(solution.numerator());
					String^ value2 = Convert::ToString(solution.denominator());
					if (value2 == "1")
						value2 = "";
					this->resultNum->Text = value;
					this->resultDen->Text = value2;
				}
				else if (division->Checked) {
					solution = lFraction / rFraction;
					String^ value = Convert::ToString(solution.numerator());
					String^ value2 = Convert::ToString(solution.denominator());
					if (value2 == "1")
						value2 = "";
					this->resultNum->Text = value;
					this->resultDen->Text = value2;
				}
				else if (multiplication->Checked) {
					solution = lFraction*rFraction;
					String^ value = Convert::ToString(solution.numerator());
					String^ value2 = Convert::ToString(solution.denominator());
					if (value2 == "1")
						value2 = "";
					this->resultNum->Text = value;
					this->resultDen->Text = value2;
				}
			}
			catch (FractionException ex) {
				this->errorbox->Text = gcnew String(ex.what().c_str());
				this->resultDen->Text = "";
				this->resultNum->Text = "";
			}
		}
	}
	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
		this->f1Den->Text = "1";
		this->f1Num->Text = "0";
		this->f2Den->Text = "1";
		this->f2Num->Text = "0";
		this->resultDen->Text = "";
		this->resultNum->Text = "";
		this->errorbox->Text = "";
	}

	private: System::Void f1Num_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Accept only digits and the Backspace character
		if (e->KeyChar == '-' && !(this->f1Num->Text->Contains("-"))) {
			e->Handled = true;
			f1Num->Text = "-" + f1Num->Text;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}

	private: System::Void f1Num_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void f1Den_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void f2Num_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void f2Den_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}


	private: System::Void addition_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void subtraction_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void division_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void multiplication_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->resultNum->Text = "";
		this->resultDen->Text = "";
		this->errorbox->Text = "";
	}
	private: System::Void f1Den_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Accept only digits and the Backspace character
		if (e->KeyChar == '-' && !(this->f1Den->Text->Contains("-"))) {
			e->Handled = true;
			f1Den->Text = "-" + f1Den->Text;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
private: System::Void f2Num_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	// Accept only digits and the Backspace character
	if (e->KeyChar == '-' && !(this->f2Num->Text->Contains("-"))) {
		e->Handled = true;
		f2Num->Text = "-" + f2Num->Text;
	}
	// Accept only digits ".", "-" and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void f2Den_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	// Accept only digits and the Backspace character
	if (e->KeyChar == '-' && !(this->f2Den->Text->Contains("-"))) {
		e->Handled = true;
		f2Den->Text = "-" + f2Den->Text;
	}
	// Accept only digits ".", "-" and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->Alt && e->KeyCode == Keys::C)
		this->Close();
}
};
}
