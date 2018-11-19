#pragma once
#include "cBitStream.h"
namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Label^  compression_;
	private: System::Windows::Forms::Label^  oshk_;


	private: System::Windows::Forms::TextBox^  bitpersample;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::TextBox^  compression;
	private: System::Windows::Forms::TextBox^  oshk;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->compression_ = (gcnew System::Windows::Forms::Label());
			this->oshk_ = (gcnew System::Windows::Forms::Label());
			this->bitpersample = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->compression = (gcnew System::Windows::Forms::TextBox());
			this->oshk = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 73);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Кодировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::Coder);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(29, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Декодировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::Decoder);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(29, 131);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Рассчитать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::Statistic);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(29, 160);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(93, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Очистить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::Clear);
			// 
			// compression_
			// 
			this->compression_->AutoSize = true;
			this->compression_->Location = System::Drawing::Point(398, 60);
			this->compression_->Name = L"compression_";
			this->compression_->Size = System::Drawing::Size(69, 13);
			this->compression_->TabIndex = 6;
			this->compression_->Text = L"компрессия";
			// 
			// oshk_
			// 
			this->oshk_->AutoSize = true;
			this->oshk_->Location = System::Drawing::Point(419, 112);
			this->oshk_->Name = L"oshk_";
			this->oshk_->Size = System::Drawing::Size(31, 13);
			this->oshk_->TabIndex = 7;
			this->oshk_->Text = L"ОСШ";
			// 
			// bitpersample
			// 
			this->bitpersample->Location = System::Drawing::Point(28, 33);
			this->bitpersample->Name = L"bitpersample";
			this->bitpersample->Size = System::Drawing::Size(100, 20);
			this->bitpersample->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"бит/отсчет";
			// 
			// compression
			// 
			this->compression->Location = System::Drawing::Point(385, 76);
			this->compression->Name = L"compression";
			this->compression->Size = System::Drawing::Size(100, 20);
			this->compression->TabIndex = 14;
			// 
			// oshk
			// 
			this->oshk->Location = System::Drawing::Point(385, 131);
			this->oshk->Name = L"oshk";
			this->oshk->Size = System::Drawing::Size(100, 20);
			this->oshk->TabIndex = 15;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(148, 76);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 17;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(161, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"размер файла1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(272, 76);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(269, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"размер файла2";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(148, 131);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 21;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(173, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Сигнал";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(272, 131);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 23;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(297, 115);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Шум";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(330, 10);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(25, 20);
			this->textBox5->TabIndex = 24;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(132, 13);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(194, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"диапазон квантования = 2 в степени";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 194);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->oshk);
			this->Controls->Add(this->compression);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bitpersample);
			this->Controls->Add(this->oshk_);
			this->Controls->Add(this->compression_);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		double SizeInputFile = 0;
		double SizeOutputFile = 0;
		int BIT_PER_SAMPLE = 0;
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		compression->Text = "0";
		oshk->Text = "0";
	}
	private: System::Void Coder(System::Object^ sender, System::EventArgs^ e) {
		if (bitpersample->Text == "")
		{
			MessageBox::Show("Поля ввода не заполнены!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		unsigned char fname1[] = "input.wav"; //исходный файл
		unsigned char fname2[] = "DIKM.dikm"; //закодированный файл
		cBitStream *inpbuf = new cBitStream(fname1, mRead);
		cBitStream *outpbuf = new cBitStream(fname2, mWrite);
		short *val = new short;
		unsigned long int *CodeWord = (unsigned long int*)val;
		BIT_PER_SAMPLE = Convert::ToInt32(bitpersample->Text);
		int stepen = Convert::ToInt32(textBox5->Text);
		int diapazon_cvantovaniya = pow (2.0, stepen);
		// перепись заголовока wav-файла
		for (int i = 0; i < 44; i++) {
			inpbuf->ReadBitField(&CodeWord, 8);
			outpbuf->WriteBitField(*CodeWord, 8);
		}
		//запись количества бит на отчет
		outpbuf->WriteBitField(BIT_PER_SAMPLE, 16);
		outpbuf->WriteBitField(stepen, 16); 
		//теперь обрабатываем его содержимое 
		ifstream input("input.wav", ios::in);
		input.seekg(0, input.end);
		//количество байт вх. файла
		unsigned long int numberOfBytes = (unsigned long int)input.tellg();
		input.close();
		SizeInputFile = numberOfBytes;
		//количество бит вх. файла без заголовка (только сами данные)
		unsigned long int numberOfWords = (numberOfBytes - 44) * 8 - 16;
		inpbuf->ReadBitField(&CodeWord, 16);
		//пока не закончились отсчеты
		double interval = diapazon_cvantovaniya / pow(2, BIT_PER_SAMPLE);
		int Zero_sample = 0;
		int n = 0;
		while (numberOfWords > 0)
		{
			//чтение очередного отсчета
			inpbuf->ReadBitField(&CodeWord, 16); 
			numberOfWords -= 16;
			//x-реал.значение отсчета
			unsigned long* x =  CodeWord;
			//x_- предсказанное значение, d- разность(ошибка предсказания)
			double d = (short) *x - Zero_sample;
			//квантование
			int D = 0;
			if (d<0) D = floor((d + 0.5*interval) / interval);
			else D = ceil((d - 0.5*interval) / interval);
			if (D > pow(2, BIT_PER_SAMPLE - 1) - 1) D = pow(2, BIT_PER_SAMPLE - 1) - 1;
			if (D < -1 * pow(2, BIT_PER_SAMPLE - 1)) D = -1 * pow(2, BIT_PER_SAMPLE - 1);
			//восстановленное значение отсчета
			Zero_sample += D*interval;
			//вывод в промежуточный файл
			outpbuf->WriteBitField((unsigned long)D, BIT_PER_SAMPLE);
			n++;
		}
		n++;
		button2->Enabled = true;
		delete inpbuf;
		delete outpbuf;
	}
	private: System::Void Decoder(System::Object^ sender, System::EventArgs^ e) {
		unsigned char fname1[] = "DIKM.dikm"; //закодированный файл
		unsigned char fname2[] = "output.wav"; //восстановленный файл 
		ifstream input("DIKM.dikm", ios::in);
		input.seekg(0, input.end);
		unsigned long int nFileLen = (unsigned long int)input.tellg();
		input.close();
		SizeOutputFile = nFileLen; //output, т.к. размер нужен для расчета компрессии (а для нее это out)
		cBitStream *inpbuf = new cBitStream(fname1, mRead);
		cBitStream *rebbuf = new cBitStream(fname2, mWrite);
		short *val = new short;
		unsigned long int *CodeWord = (unsigned long int*)val;
		//чтение заголовка
		for (int i = 0; i < 44; i++)
		{
			inpbuf->ReadBitField(&CodeWord, 8);
			rebbuf->WriteBitField(*CodeWord, 8);
		}
		//чтение количества бит на отсчет
		inpbuf->ReadBitField(&CodeWord, 16);
		BIT_PER_SAMPLE = *CodeWord;
		//чтение диапазона квантования
		_int16 Z;
		inpbuf->ReadBitField(&CodeWord, 16);
		Z= *CodeWord;
		int diapazon_cvantovaniya = pow(2.0, Z);
		//48- длина заголовка файла формата *.dikm
		nFileLen = (nFileLen - 44) * 8 - 32; 
		_int16 D; Z = 0;

		double interval = (double)diapazon_cvantovaniya / (double) pow(2.0, BIT_PER_SAMPLE);
		while (nFileLen >= BIT_PER_SAMPLE)
		{
			inpbuf->ReadBitField(&CodeWord,	BIT_PER_SAMPLE);
			nFileLen -= BIT_PER_SAMPLE;
			if (nFileLen <= BIT_PER_SAMPLE) {
				int vvv=0;
			}
			D = *CodeWord;
			Z += interval*D;
			rebbuf->WriteBitField((unsigned long)Z, 16);
		}
		button3->Enabled = true;
		delete inpbuf;
		delete rebbuf;
	}
	private: System::Void Statistic(System::Object^ sender, System::EventArgs^ e) {
		textBox1 -> Text = Convert::ToString(SizeInputFile);
		textBox2->Text = Convert::ToString(SizeOutputFile);
		SizeInputFile -= 44;
		SizeOutputFile -= 48;
		//Компрессия
		double compr_pow = SizeInputFile / SizeOutputFile; 
		compression->Text = Convert::ToString(compr_pow); 
		//Отношение сигнал/шум квантования
		double	signal = 0.0, noise = 0.0;
		unsigned char fname1[] = "input.wav";
		unsigned char fname2[] = "output.wav";
		cBitStream *inpbuf1 = new cBitStream(fname1, mRead);
		cBitStream *inpbuf2 = new cBitStream(fname2, mRead);
		unsigned long int *read_inp = new unsigned long int;
		unsigned long int *read_out = new unsigned long int;
		//считывание заголовка
		for (int i = 0; i < 44; i++)
		{
			inpbuf1->ReadBitField(&read_inp, 8);
			inpbuf2->ReadBitField(&read_out, 8);
		}
		//чтение самих отсчетов
		for (unsigned int i = 0; i < ((unsigned int)SizeInputFile / 16); i++)
		{
			inpbuf1->ReadBitField(&read_inp, 16);
			inpbuf2->ReadBitField(&read_out, 16); 
			if (inpbuf2->eof()) break;
			double x = *read_inp;
			double x_ = *read_out;
			signal += pow(x,2.0);
			noise += pow(((x_) - (x)),2.0);
		}
		textBox3-> Text = Convert::ToString(signal);
		textBox4->Text = Convert::ToString(noise);
		double SNR = 10.0*log10(signal /noise); 
		oshk->Text = Convert::ToString(SNR); 
		delete inpbuf1;
		delete inpbuf2;
	}
	private: System::Void Clear(System::Object^ sender, System::EventArgs^ e) {
		compression->Text = "0";
		oshk->Text = "0";
		bitpersample->Text = "";
		button2->Enabled = false;
		button3->Enabled = false;
	}

	};
}
