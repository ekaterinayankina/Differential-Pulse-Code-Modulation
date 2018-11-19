#pragma once
#include<stdio.h>
#include<iostream>
#include <fstream> 
#include <assert.h> 
#pragma once 
using namespace std;
	// режимы работы с буфером (чтение/запись)
	enum ModeType { mRead, mWrite };
	// Размеры битового буфера в битах и байтах
	const unsigned long int cnBitStreamByteSize = 65536;
	const unsigned long int cnBitStreamBitSize = cnBitStreamByteSize * 8;
	class cBitStream {
		unsigned char *Buffer; // временный буфер
		unsigned long int ptrCurrentBit; // указатель на текущий (свободный) бит 
		ofstream ofp; // файл (при записи)
		ifstream ifp; // файл (при чтении)
		ModeType CurMode; // текущий режим работы с буфером (запись/чтение)
		unsigned long int CurBufferBitSize; // текущий размер буфера в битах
	public:
		bool eof();
		cBitStream(unsigned char *FileName, ModeType mode); // конструктор
		~cBitStream(void); // удаление буфера
						   // добавить/прочитать в буфер кодовое слово побитово
		void WriteBitField(unsigned long int CodeWord, unsigned int CodeBitLength); void
			ReadBitField(unsigned long int **CodeWord, unsigned int CodeBitLength);
	private:
		void PutBit(unsigned char DataBit); // добавить в буфер бит данных
		void GetBit(unsigned char *DataBit); // взять из буфера бит данных
		void FlushBuffer(void); // сбросить буфер на диск
		void LoadBuffer(void); // загрузить буфер с диска
		void ClearBuffer(void); // очистить буфер
	};