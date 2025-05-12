#pragma once

namespace lz10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; //клас простору для роботи з файлами
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(468, 240);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(307, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Суму квадратів від’ємних чисел";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(511, 366);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 57);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Записати у файл ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(511, 121);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 58);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Обчислити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(118, 361);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(138, 66);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Читати з файла дані ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(110, 81);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(163, 238);
			this->textBox1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(560, 302);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 16);
			this->label2->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(911, 524);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторна робота №10";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname = "numbers.txt";
		if (File::Exists(fname))
		{
			StreamReader^ reader = File::OpenText(fname);

			textBox1->Clear();

			String^ fileContent = reader->ReadToEnd();
			array<String^>^ numbers = fileContent->Split(' ');

			for (int i = 0; i < numbers->Length; i++)
			{
				textBox1->AppendText(numbers[i] + Environment::NewLine);
			}

			reader->Close();
		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ fileName = "output.txt";
	StreamWriter^ writer = File::CreateText(fileName);

	int product = 1;

	for (int i = 0; i < textBox1->Lines->Length; i++) {
		int number;
		if (int::TryParse(textBox1->Lines[i], number)) {
			if (number % 2 == 0) {
				product *= number;
				writer->WriteLine(number);
			}
		}
	}

	writer->WriteLine("Product: " + Convert::ToString(product));
	writer->Close();

	MessageBox::Show("Числа та їх суму квадратів було записано у файл " + fileName);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int sumOfSquares = 0;

	for (int i = 0; i < textBox1->Lines->Length; i++)
	{
		int number;
		if (int::TryParse(textBox1->Lines[i], number))
		{
			// Перевірка, чи число від'ємне
			if (number < 0)
			{
				sumOfSquares += number * number;
			}
		}
	}

	label2->Text = sumOfSquares.ToString();
}
};
}
