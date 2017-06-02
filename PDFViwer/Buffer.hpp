#pragma once
#include "KUDEType.h"
#include "Utily.h"
#include <fstream>
#include <string>
namespace KUDE {
	template <int N>
	class FileBuffer
	{
	public:
		template <class T>
		std::string getStringFileSeq(std::ifstream &in, const T &find) {
			std::string buffer;
			in.read(reinterpret_cast<char*>(&mBuffer[0]),
				mBufferSizeof);
			mBuffer[mBufferSize] = NULL;
			buffer = mBuffer;

			std::size_t result = buffer.find(find);
			int back = mBufferSizeof - (result+1);
			in.seekg(-back, std::ios::cur);
			buffer.resize(result);
			return buffer;
		}

	private:
		std::size_t mBufferSize = N - 1;
		std::size_t mBufferSizeof = (sizeof(KUDE::TYPE::BYTE) * N) - 1;
		KUDE::TYPE::BYTE mBuffer[N];
	};
}




