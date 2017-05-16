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
		//0000000000 65535 f

	public:
		Section() = default;
		Section(char * data);
		int getDataInt();
	private:
		char mData[11];
	};

	//3635 3533 3520 = 6 bit

	class SubSection {
		//3635 3533 3520 = 6 bit
		// 
		char mmSubSection[6];


	};

	struct Isdead {
		Isdead() = default;
		Isdead(char * data);
		bool isDead();
		
		operator char() const {
			return mIsDead[0];
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
//0000000000 65535 f 
