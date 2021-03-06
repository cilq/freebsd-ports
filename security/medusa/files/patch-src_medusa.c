--- src/medusa.c.orig	2012-03-01 17:39:35.000000000 +0000
+++ src/medusa.c
@@ -1438,6 +1438,7 @@ int setPassResult(sLogin *_psLogin, char
   }
 
   pthread_mutex_unlock(&_psLogin->psServer->ptmMutex);
+  return 0;
 }
 
 
@@ -1497,6 +1498,7 @@ int addMissedCredSet(sLogin *_psLogin, s
   _psLogin->psServer->iCredentialsMissed++;
 
   pthread_mutex_unlock(&_psLogin->psServer->ptmMutex);
+  return 0;
 }
 
 
@@ -1567,7 +1569,7 @@ void *startLoginThreadPool(void *arg)
   if (errcode != 0)
   {
     writeError(ERR_CRITICAL, "Failed to resolve hostname: %s - %s", _psServer->psHost->pHost, gai_strerror(errcode));
-    return;
+    return NULL;
   }
 
   if (res->ai_next != NULL)
@@ -1609,7 +1611,7 @@ void *startLoginThreadPool(void *arg)
     if ( thr_pool_queue(login_pool, startModule, (void *) &modParams[iLoginId]) < 0 )
     {
       writeError(ERR_CRITICAL, "Failed to add module launch task to login thread pool for server queue: %d.", _psServer->iId);
-      return;
+      return NULL;
     }
   }
 
@@ -1645,7 +1647,7 @@ void *startLoginThreadPool(void *arg)
     if ( thr_pool_queue(login_pool, startModule, (void *) &modParams[iLoginId]) < 0 )
     {
       writeError(ERR_CRITICAL, "Failed to add module launch task to login thread pool for server queue: %d.", _psServer->iId);
-      return;
+      return NULL;
     }
   
     /* wait for login thread pool to finish */
@@ -1675,7 +1677,7 @@ void *startLoginThreadPool(void *arg)
 
   free(_psServer->pHostIP); 
  
-  return;
+  return NULL;
 }
 
 
