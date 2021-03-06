#include <CoreFoundation/CoreFoundation.h>

main() {
     CFMessagePortRef remote = CFMessagePortCreateRemote(NULL, CFSTR("MyPort"));
     char *message = "Hello, world!";
     CFDataRef data, returnData = NULL;
     data = CFDataCreate(NULL, (const UInt8 *)message, strlen(message)+1);
     if (kCFMessagePortSuccess == CFMessagePortSendRequest(remote, 0, data, 1, 1, kCFRunLoopDefaultMode, &returnData) && NULL != returnData) {
         printf("here is our return data: %s\n", CFDataGetBytePtr(returnData));
         CFRelease(returnData);
     }
     CFRelease(data);
     CFRelease(remote);
}
