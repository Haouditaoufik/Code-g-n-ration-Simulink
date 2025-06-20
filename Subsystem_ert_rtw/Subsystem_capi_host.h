#ifndef Subsystem_cap_host_h__
#define Subsystem_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

struct Subsystem_host_DataMapInfo_T {
  rtwCAPI_ModelMappingInfo mmi;
};

#ifdef __cplusplus

extern "C"
{

#endif

  void Subsystem_host_InitializeDataMapInfo(Subsystem_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}

#endif
#endif                                 // HOST_CAPI_BUILD
#endif                                 // Subsystem_cap_host_h__

// EOF: Subsystem_capi_host.h
