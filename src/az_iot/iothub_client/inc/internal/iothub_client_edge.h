#ifndef IOTHUB_CLIENT_EDGE_H
#define IOTHUB_CLIENT_EDGE_H

#include <stddef.h>

#include "az_iot/c-utility/inc/azure_c_shared_utility/macro_utils.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/umock_c_prod.h"

#include "az_iot/iothub_client/inc/internal/iothub_client_authorization.h"
#include "az_iot/iothub_client/inc/iothub_client_core_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct IOTHUB_CLIENT_EDGE_HANDLE_DATA_TAG* IOTHUB_CLIENT_EDGE_HANDLE;

    MOCKABLE_FUNCTION(, IOTHUB_CLIENT_EDGE_HANDLE, IoTHubClient_EdgeHandle_Create, const IOTHUB_CLIENT_CONFIG*, config, IOTHUB_AUTHORIZATION_HANDLE, authorizationHandle, const char*, module_id);
    MOCKABLE_FUNCTION(, void, IoTHubClient_EdgeHandle_Destroy, IOTHUB_CLIENT_EDGE_HANDLE, methodHandle);

    MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_Edge_DeviceMethodInvoke, IOTHUB_CLIENT_EDGE_HANDLE, moduleMethodHandle, const char*, deviceId, const char*, methodName, const char*, methodPayload, unsigned int, timeout, int*, responseStatus, unsigned char**, responsePayload, size_t*, responsePayloadSize);
    MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_Edge_ModuleMethodInvoke, IOTHUB_CLIENT_EDGE_HANDLE, moduleMethodHandle, const char*, deviceId, const char*, moduleId, const char*, methodName, const char*, methodPayload, unsigned int, timeout, int*, responseStatus, unsigned char**, responsePayload, size_t*, responsePayloadSize);

#ifdef __cplusplus
}
#endif

#endif /* IOTHUB_CLIENT_EDGE_H */