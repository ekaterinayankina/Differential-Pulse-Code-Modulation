#include "cBitStream.h"
bool cBitStream::eof()
{
	 return ifp.eof();
}
cBitStream::cBitStream(unsigned char *FileName, ModeType mode)
{
	CurMode = mode;
	// выделить память под буфер с учетом чтения последнего байта как unsigned long int
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
	memset(Buffer, 0, cnBitStreamByteSize); // упрощает запись битов в буфер 
	ptrCurrentBit = 0; // сбросить указатель
	CurBufferBitSize = cnBitStreamBitSize; // размер буфера
}
void cBitStream::FlushBuffer(void)
{
	if (CurMode == mWrite)
		// только буфер в режиме записи
	{
		if (ptrCurrentBit != cnBitStreamBitSize) // заполненная часть буфера
			CurBufferBitSize = (ptrCurrentBit + 0x7) & 0xFFFFFFF8; // округлить вверх
																   // сбросить буфер на диск
		ofp.write((char *)Buffer, (CurBufferBitSize >> 3)
		); // выполнить очистку буфера
		ClearBuffer();
	}
}
void cBitStream::LoadBuffer(void)
{
	if (CurMode == mRead) // только буфер в режиме чтения
	{
		// загрузить буфер из файла 
		assert(!ifp.eof());
		// дошли до конца файла, а данные еще требуются
		ifp.read((char *)Buffer, cnBitStreamByteSize);
		CurBufferBitSize = unsigned long(ifp.gcount() << 3);
		// сколько реально битов было прочитано
		ptrCurrentBit = 0;
	}
}
inline void cBitStream::GetBit(unsigned char *DataBit)
{
	*DataBit = (*(Buffer + (ptrCurrentBit >> 3))) >> (ptrCurrentBit & 0x7) &
		0x01; ptrCurrentBit++; // сместить указатель
}
inline void cBitStream::PutBit(unsigned char DataBit)
{
	if (DataBit) // записываем только если бит = 1
		*(Buffer + (ptrCurrentBit >> 3)) |= (1 << (ptrCurrentBit & 0x7)); // наложить бит 
	ptrCurrentBit++; // в любом случае сместить указатель
}
void cBitStream::ReadBitField(unsigned long int **CodeWord, unsigned int CodeBitLength)
{
	unsigned char CurDataBit;


	unsigned long int Mask = 1;
	if (CurMode == mRead) // если буфер в режиме чтения
	{
		**CodeWord = 0;
		for (unsigned int i = 0; i<CodeBitLength; i++)
		{
			if (ptrCurrentBit == CurBufferBitSize) // проверить, пройден ли буфер 
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
	if (CurMode == mWrite) // если буфер в режиме записи
		for (unsigned int i = 0; i<CodeBitLength; i++)
		{
			CurDataBit = (unsigned char)(CodeWord & 1); // взять младший бит
			CodeWord >>= 1; // сдвинуть слово
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
