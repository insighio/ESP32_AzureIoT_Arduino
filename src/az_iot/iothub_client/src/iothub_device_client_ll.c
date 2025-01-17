// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>
#include <string.h>
#include "az_iot/c-utility/inc/azure_c_shared_utility/optimize_size.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/gballoc.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/string_tokenizer.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/doublylinkedlist.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/xlogging.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/tickcounter.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/constbuffer.h"
#include "az_iot/c-utility/inc/azure_c_shared_utility/platform.h"

#include "az_iot/iothub_client/inc/iothub_client_core_ll.h"
#include "az_iot/iothub_client/inc/internal/iothub_client_authorization.h"
#include "az_iot/iothub_client/inc/iothub_device_client_ll.h"
#include "az_iot/iothub_client/inc/iothub_transport_ll.h"
#include "az_iot/iothub_client/inc/internal/iothub_client_private.h"
#include "az_iot/iothub_client/inc/iothub_client_options.h"
#include "az_iot/iothub_client/inc/iothub_client_version.h"
#include "az_iot/iothub_client/inc/internal/iothub_client_diagnostic.h"
#include <stdint.h>

#ifndef DONT_USE_UPLOADTOBLOB
#include "az_iot/iothub_client/inc/internal/iothub_client_ll_uploadtoblob.h"
#endif

IOTHUB_DEVICE_CLIENT_LL_HANDLE IoTHubDeviceClient_LL_CreateFromConnectionString(const char* connectionString, IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol)
{
    return (IOTHUB_DEVICE_CLIENT_LL_HANDLE)IoTHubClientCore_LL_CreateFromConnectionString(connectionString, protocol);
}

IOTHUB_DEVICE_CLIENT_LL_HANDLE IoTHubDeviceClient_LL_Create(const IOTHUB_CLIENT_CONFIG* config)
{
    return (IOTHUB_DEVICE_CLIENT_LL_HANDLE)IoTHubClientCore_LL_Create(config);
}

IOTHUB_DEVICE_CLIENT_LL_HANDLE IoTHubDeviceClient_LL_CreateWithTransport(const IOTHUB_CLIENT_DEVICE_CONFIG * config)
{
    return (IOTHUB_DEVICE_CLIENT_LL_HANDLE)IoTHubClientCore_LL_CreateWithTransport(config);
}

IOTHUB_DEVICE_CLIENT_LL_HANDLE IoTHubDeviceClient_LL_CreateFromDeviceAuth(const char* iothub_uri, const char* device_id, IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol)
{
    return (IOTHUB_DEVICE_CLIENT_LL_HANDLE)IoTHubClientCore_LL_CreateFromDeviceAuth(iothub_uri, device_id, protocol);
}

void IoTHubDeviceClient_LL_Destroy(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle)
{
    IoTHubClientCore_LL_Destroy((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SendEventAsync(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_MESSAGE_HANDLE eventMessageHandle, IOTHUB_CLIENT_EVENT_CONFIRMATION_CALLBACK eventConfirmationCallback, void* userContextCallback)
{
    return IoTHubClientCore_LL_SendEventAsync((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, eventMessageHandle, eventConfirmationCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_GetSendStatus(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_STATUS *iotHubClientStatus)
{
    return IoTHubClientCore_LL_GetSendStatus((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, iotHubClientStatus);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SetMessageCallback(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_MESSAGE_CALLBACK_ASYNC messageCallback, void* userContextCallback)
{
    return IoTHubClientCore_LL_SetMessageCallback((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, messageCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SetConnectionStatusCallback(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_CONNECTION_STATUS_CALLBACK connectionStatusCallback, void * userContextCallback)
{
    return IoTHubClientCore_LL_SetConnectionStatusCallback((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, connectionStatusCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SetRetryPolicy(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_RETRY_POLICY retryPolicy, size_t retryTimeoutLimitInSeconds)
{
    return IoTHubClientCore_LL_SetRetryPolicy((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, retryPolicy, retryTimeoutLimitInSeconds);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_GetRetryPolicy(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_RETRY_POLICY* retryPolicy, size_t* retryTimeoutLimitInSeconds)
{
    return IoTHubClientCore_LL_GetRetryPolicy((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, retryPolicy, retryTimeoutLimitInSeconds);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_GetLastMessageReceiveTime(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, time_t* lastMessageReceiveTime)
{
    return IoTHubClientCore_LL_GetLastMessageReceiveTime((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, lastMessageReceiveTime);
}

void IoTHubDeviceClient_LL_DoWork(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle)
{
    IoTHubClientCore_LL_DoWork((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SetOption(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, const char* optionName, const void* value)
{
    return IoTHubClientCore_LL_SetOption((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, optionName, value);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SetDeviceTwinCallback(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_DEVICE_TWIN_CALLBACK deviceTwinCallback, void* userContextCallback)
{
    return IoTHubClientCore_LL_SetDeviceTwinCallback((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, deviceTwinCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_GetTwinAsync(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_DEVICE_TWIN_CALLBACK deviceTwinCallback, void* userContextCallback)
{
    return IoTHubClientCore_LL_GetTwinAsync((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, deviceTwinCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SendReportedState(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, const unsigned char* reportedState, size_t size, IOTHUB_CLIENT_REPORTED_STATE_CALLBACK reportedStateCallback, void* userContextCallback)
{
    return IoTHubClientCore_LL_SendReportedState((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, reportedState, size, reportedStateCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SetDeviceMethodCallback(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, IOTHUB_CLIENT_DEVICE_METHOD_CALLBACK_ASYNC deviceMethodCallback, void* userContextCallback)
{
    return IoTHubClientCore_LL_SetDeviceMethodCallback((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, deviceMethodCallback, userContextCallback);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_DeviceMethodResponse(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, METHOD_HANDLE methodId, const unsigned char* response, size_t response_size, int status_response)
{
    return IoTHubClientCore_LL_DeviceMethodResponse((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, methodId, response, response_size, status_response);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_SendMessageDisposition(IOTHUB_DEVICE_CLIENT_LL_HANDLE device_ll_handle, IOTHUB_MESSAGE_HANDLE message, IOTHUBMESSAGE_DISPOSITION_RESULT disposition)
{
    return IoTHubClientCore_LL_SendMessageDisposition(device_ll_handle, message, disposition);
}

#ifndef DONT_USE_UPLOADTOBLOB
IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_UploadToBlob(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, const char* destinationFileName, const unsigned char* source, size_t size)
{
    return IoTHubClientCore_LL_UploadToBlob((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, destinationFileName, source, size);
}

IOTHUB_CLIENT_RESULT IoTHubDeviceClient_LL_UploadMultipleBlocksToBlob(IOTHUB_DEVICE_CLIENT_LL_HANDLE iotHubClientHandle, const char* destinationFileName, IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_CALLBACK_EX getDataCallbackEx, void* context)
{
    return IoTHubClientCore_LL_UploadMultipleBlocksToBlobEx((IOTHUB_CLIENT_CORE_LL_HANDLE)iotHubClientHandle, destinationFileName, getDataCallbackEx, context);
}

#endif
