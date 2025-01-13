#ifndef CURLMAIN_H
#define CURLMAIN_H

#define CURL_STATICLIB

#include "curl/curl.h"
#include "json/json.hpp"
#include <QDebug>



static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param);

nlohmann::json getResponse();

#endif // CURLMAIN_H
