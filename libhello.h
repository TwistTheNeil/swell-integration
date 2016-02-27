#ifdef _WIN32
#include "stdafx.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
	__declspec (dllexport)
#endif
	void hello(void);
#ifdef __cplusplus
}
#endif
