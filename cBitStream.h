#pragma once
#include<stdio.h>
#include<iostream>
#include <fstream> 
#include <assert.h> 
#pragma once 
using namespace std;
	// ������ ������ � ������� (������/������)
	enum ModeType { mRead, mWrite };
	// ������� �������� ������ � ����� � ������
	const unsigned long int cnBitStreamByteSize = 65536;
	const unsigned long int cnBitStreamBitSize = cnBitStreamByteSize * 8;
	class cBitStream {
		unsigned char *Buffer; // ��������� �����
		unsigned long int ptrCurrentBit; // ��������� �� ������� (���������) ��� 
		ofstream ofp; // ���� (��� ������)
		ifstream ifp; // ���� (��� ������)
		ModeType CurMode; // ������� ����� ������ � ������� (������/������)
		unsigned long int CurBufferBitSize; // ������� ������ ������ � �����
	public:
		bool eof();
		cBitStream(unsigned char *FileName, ModeType mode); // �����������
		~cBitStream(void); // �������� ������
						   // ��������/��������� � ����� ������� ����� ��������
		void WriteBitField(unsigned long int CodeWord, unsigned int CodeBitLength); void
			ReadBitField(unsigned long int **CodeWord, unsigned int CodeBitLength);
	private:
		void PutBit(unsigned char DataBit); // �������� � ����� ��� ������
		void GetBit(unsigned char *DataBit); // ����� �� ������ ��� ������
		void FlushBuffer(void); // �������� ����� �� ����
		void LoadBuffer(void); // ��������� ����� � �����
		void ClearBuffer(void); // �������� �����
	};