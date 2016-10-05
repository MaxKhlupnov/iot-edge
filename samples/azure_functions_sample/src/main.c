// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>

#include "gateway.h"
#include "azure_c_shared_utility/platform.h"

int main(int argc, char** argv)
{
    GATEWAY_HANDLE gateway;

	platform_init();
	
    if (argc != 2)
    {
        printf("usage: azure_functions_sample configFile\n");
        printf("where configFile is the name of the file that contains the Gateway configuration\n");
    }
    else
    {
        if ((gateway = Gateway_Create_From_JSON(argv[1])) == NULL)
        {
            printf("failed to create the gateway from JSON\n");
        }
        else
        {
            printf("gateway successfully created from JSON\n");
            printf("gateway shall run until ENTER is pressed\n");
            (void)getchar();
            Gateway_LL_Destroy(gateway);
        }
    }
	return 0;
}
