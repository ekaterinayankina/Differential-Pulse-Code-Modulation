#include "cBitStream.h"
bool cBitStream::eof()
{
	 return ifp.eof();
}
cBitStream::cBitStream(unsigned char *FileName, ModeType mode)
{
	CurMode = mode;
	// �������� ������ ��� ����� � ������ ������ ���������� ����� ��� unsigned long int
	Buffer = new unsigned char[cnBitStreamByteSize + 4];
	if (CurMode == mWrite)
	{
		ofp.open((char *)FileName, ios::binary);
		assert(!ofp.fail());
		ClearBuffer();
	}
	else if (CurMode == mRead)
	{
		ifp.open((char *)FileName, ios::binary);
		assert(!ifp.fail());
		LoadBuffer();
	}
}
void cBitStream::ClearBuffer(void)
{
	memset(Buffer, 0, cnBitStreamByteSize); // �������� ������ ����� � ����� 
	ptrCurrentBit = 0; // �������� ���������
	CurBufferBitSize = cnBitStreamBitSize; // ������ ������
}
void cBitStream::FlushBuffer(void)
{
	if (CurMode == mWrite)
		// ������ ����� � ������ ������
	{
		if (ptrCurrentBit != cnBitStreamBitSize) // ����������� ����� ������
			CurBufferBitSize = (ptrCurrentBit + 0x7) & 0xFFFFFFF8; // ��������� �����
																   // �������� ����� �� ����
		ofp.write((char *)Buffer, (CurBufferBitSize >> 3)
		); // ��������� ������� ������
		ClearBuffer();
	}
}
void cBitStream::LoadBuffer(void)
{
	if (CurMode == mRead) // ������ ����� � ������ ������
	{
		// ��������� ����� �� ����� 
		assert(!ifp.eof());
		// ����� �� ����� �����, � ������ ��� ���������
		ifp.read((char *)Buffer, cnBitStreamByteSize);
		CurBufferBitSize = unsigned long(ifp.gcount() << 3);
		// ������� ������� ����� ���� ���������
		ptrCurrentBit = 0;
	}
}
inline void cBitStream::GetBit(unsigned char *DataBit)
{
	*DataBit = (*(Buffer + (ptrCurrentBit >> 3))) >> (ptrCurrentBit & 0x7) &
		0x01; ptrCurrentBit++; // �������� ���������
}
inline void cBitStream::PutBit(unsigned char DataBit)
{
	if (DataBit) // ���������� ������ ���� ��� = 1
		*(Buffer + (ptrCurrentBit >> 3)) |= (1 << (ptrCurrentBit & 0x7)); // �������� ��� 
	ptrCurrentBit++; // � ����� ������ �������� ���������
}
void cBitStream::ReadBitField(unsigned long int **CodeWord, unsigned int CodeBitLength)
{
	unsigned char CurDataBit;


	unsigned long int Mask = 1;
	if (CurMode == mRead) // ���� ����� � ������ ������
	{
		**CodeWord = 0;
		for (unsigned int i = 0; i<CodeBitLength; i++)
		{
			if (ptrCurrentBit == CurBufferBitSize) // ���������, ������� �� ����� 
				LoadBuffer();
			if (CurBufferBitSize == 0)
			{
				*CodeWord = NULL;
				break;
			}
			GetBit(&CurDataBit);
			**CodeWord |= ((unsigned long int)(CurDataBit) << i);
		}
	}
}
void cBitStream::WriteBitField(unsigned long int CodeWord, unsigned int CodeBitLength)
{
	unsigned char CurDataBit;
	if (CurMode == mWrite) // ���� ����� � ������ ������
		for (unsigned int i = 0; i<CodeBitLength; i++)
		{
			CurDataBit = (unsigned char)(CodeWord & 1); // ����� ������� ���
			CodeWord >>= 1; // �������� �����
			PutBit(CurDataBit);
			if (ptrCurrentBit == cnBitStreamBitSize) FlushBuffer();
		}
}
cBitStream::~cBitStream(void)
{
	if ((CurMode == mWrite) && (ptrCurrentBit > 0)) FlushBuffer();
	ofp.flush();
	ofp.close();
	delete[cnBitStreamByteSize + 4] Buffer;
}
