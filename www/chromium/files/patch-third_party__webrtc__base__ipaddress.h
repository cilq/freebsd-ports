--- third_party/webrtc/base/ipaddress.h.orig	2014-10-10 09:16:13 UTC
+++ third_party/webrtc/base/ipaddress.h
@@ -17,6 +17,9 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #endif
+#if defined(WEBRTC_BSD)
+#include <sys/socket.h>
+#endif
 #if defined(WEBRTC_WIN)
 #include <winsock2.h>
 #include <ws2tcpip.h>
