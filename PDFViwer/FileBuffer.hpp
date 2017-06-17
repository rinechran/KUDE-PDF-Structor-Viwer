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
		std::string getStringFindSeq(std::ifstream &in, const T &find);

		template <class T>
		std::string getStringUtilFind(std::ifstream &in, T & find);
	private:
		std::size_t mBufferSize = N - 1;
		std::size_t mReadSizeof = (sizeof(KUDE::TYPE::BYTE) * N) -1;
		KUDE::TYPE::BYTE mBuffer[N];
	};

	template<int N>
	template<class T>
	std::string FileBuffer<N>::getStringFindSeq(std::ifstream & in, const T & find) {
		std::string buffer;
		in.read(reinterpret_cast<char*>(&mBuffer[0]),
			mReadSizeof);
		mBuffer[mBufferSize] = NULL;
		buffer = mBuffer;

		std::size_t result = buffer.find(find);
		int back = mReadSizeof - (result+1);
		in.seekg(-back, std::ios::cur);
		buffer.resize(result);
		return buffer;
	}
	template<int N>
	template<class T>
	std::string FileBuffer<N>::getStringUtilFind(std::ifstream & in, T & find) {
		std::string buffer;
		for (int moveCounter = 1; ; moveCounter++) {
			in.read(reinterpret_cast<char*>(mBuffer),
				mReadSizeof);
			mBuffer[mBufferSize] = NULL;
			buffer += mBuffer;
			//return object 
			auto findResult = KUDE::findStr(buffer, find);
			if (findResult != std::string::npos) {
				int back = (moveCounter * mBufferSize) - (findResult + 1);
				in.seekg(-back, std::ios::cur);
				buffer.resize(findResult);
				KUDE::DEBUG::LOG(buffer);
				return buffer;
			}
		}


	}
}




