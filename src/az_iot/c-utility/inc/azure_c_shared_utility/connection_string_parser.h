// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef CONNECTION_STRING_PARSER_H
#define CONNECTION_STRING_PARSER_H

#include "az_iot/c-utility/inc/azure_c_shared_utility/map.h" 
#include "az_iot/c-utility/inc/azure_c_shared_utility/az_strings.h"

#include "az_iot/c-utility/inc/azure_c_shared_utility/umock_c_prod.h"

#ifdef __cplusplus
extern "C"
{
#endif

    MOCKABLE_FUNCTION(, MAP_HANDLE, connectionstringparser_parse_from_char, const char*, connection_string);
    MOCKABLE_FUNCTION(, MAP_HANDLE, connectionstringparser_parse, STRING_HANDLE, connection_string);
    MOCKABLE_FUNCTION(, int, connectionstringparser_splitHostName_from_char, const char*, hostName, STRING_HANDLE, nameString, STRING_HANDLE, suffixString);
    MOCKABLE_FUNCTION(, int, connectionstringparser_splitHostName, STRING_HANDLE, hostNameString, STRING_HANDLE, nameString, STRING_HANDLE, suffixString);

#ifdef __cplusplus
}
#endif

#endif /* CONNECTION_STRING_PARSER_H */
