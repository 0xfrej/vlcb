#include "vlcb/common/can.h"

int main(void) {
	for(;;) {
		CanId id = 5;
		if (vlcb_defs_IsCanIdValid(id)) {
			break;
		}
	}
}
