#include "curlmain.h"

static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
    std::string& text = *static_cast<std::string*>(param);
    size_t totalsize = size * nmemb;
    text.append(static_cast<char*>(buffer), totalsize);
    return totalsize;
}

nlohmann::json getResponse()
{
    nlohmann::json empty = {};
    std::string sEmpty = "";

    std::string result;
    CURL* curl;
    CURLcode res;

    const std::string API_KEY = "e6d2883093f1ed3f0d5615825ba2c9f4";
    std::string q = "Rzeszów";
    std::string urlPrepare = "https://api.openweathermap.org/data/2.5/weather?";
    std::string urlReady = "";

    urlReady = urlPrepare + "q=" + q + "&APPID=" + API_KEY;


    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, urlReady.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        std::string rootDirectory = "C:/Users/kamil/Desktop/PROJEKT ICE ARROW/project";;
        std::string fullPath = std::string(rootDirectory) + "/curl/cacert.pem";
        qInfo(fullPath.c_str());

        curl_easy_setopt(curl, CURLOPT_CAINFO, fullPath.c_str());

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (CURLE_OK != res) {
            qDebug() << "CURL error: " << res << '\n';
            return empty;
        }
        curl_global_cleanup();


        try
        {
            nlohmann::json jsonResponse = nlohmann::json::parse(result);
            qDebug() << "Full JSON response:\n" << result.c_str();
            return jsonResponse;
        }
        catch (const nlohmann::json::parse_error& e)
        {
            qDebug() << "JSON Parsing error: " << e.what();
        }
        qDebug() << "try-catch block failed.";
        return empty;
    }
    qDebug() << "curl if statement failed.";
    return empty;
}
