#include <fabric/error_handler.hpp>


void fabric::throw_error(unsigned long long err) {

	size_t enumLength = fabric::END_OF_FABRIC_ERROR_ENUM - 1;	//	Calculate length of enum
	enumLength = log2(enumLength) + 1;							//	Calculate length of enum

	if (err >> 4 == 1)			// has 'err' been ORed with FB_ALLWAYS_CRITICAl ?
		throw fabric::CriticalException(std::to_string(err) + " is critical");

	if (err >> 5 == 1)			// has 'err' been ORed with FB_NEVER_CRITICAL ?
		return;


	for (size_t i = 0; i < sizeof(err) * 8; i++){
		unsigned long long singleError = 0;
		singleError = err >> (sizeof(err) * 8 - (i + 1));
		singleError = singleError & 1;
		if (singleError == 1) {
			
			unsigned long long errValue = pow(2, sizeof(err) * 8 - (i + 1)); // pow(2, (sizeof(err) * 8 - (i + 1)) The '1' bit's value 
			

			for (size_t errorIdx = 0; errorIdx < enumLength; errorIdx++) { // errorIdx is the index of one member of the fabric_error
				if (pow(2, errorIdx) == errValue) { // pow(2, errorIdx): Actuall value set to enum member,
					if (pow(2,errorIdx) == fabric::Engine::get()->state){
						throw fabric::CriticalException(std::to_string(err) + " is critical");
					}
				}
			}
		}
	}


}
