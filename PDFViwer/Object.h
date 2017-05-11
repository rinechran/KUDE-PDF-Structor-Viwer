#pragma once
#include <cstdlib>
#include <iostream>




//3030 3030 3030 3030 3020  = 10bit 
//3635 3533 3520 = 6 bit
//6620 0A = f.. = 3bit;
//binary : 20(sequence)

//0000000000 65535 f 

namespace KUDE {
#pragma pack(push,1)
	class Section {
		//3030 3030 3030 3030 3020  = 10bit 

	public:
		Section() {
			std::memset(mData, NULL, sizeof(mData));
		}
		Section(char * data) {
			std::memcpy(mData, data, sizeof(mData));
		}
		int getDataInt() {
			mData[9] = NULL;
			return std::atoi(mData);
		}
	private:
		char mData[10];
	};

	//3635 3533 3520 = 6 bit

	class SubSection {
		//3635 3533 3520 = 6 bit
		// 
		char mmSubSection[6];

	};

	struct Isdead {
		Isdead() {
			std::memset(mIsDead, NULL, sizeof(mIsDead));
		}
		Isdead(char * data) {
			std::memcpy(mIsDead, data, sizeof(mIsDead));
		}
		bool isDead() {
			//mIsDead[0] :
			// f==true
			// n==false
			return mIsDead[0] == 'f' ? true : false;
		}

		char mIsDead[3];
		//6620 0A = f.. = 3bit;

	};

	

	struct ObjectLInk {
		Section mSection;
		SubSection mSubSection;
		Isdead mIsDead;

	};
#pragma pack(pop)
}