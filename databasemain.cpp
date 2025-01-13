#include "databasemain.h"
#include <fstream>
#include "json/json.hpp"

bool connectToDatabase()
{
    /////////////////////////////////////
    // OBTAIN DB CREDENTIALS FROM FILE //
    /////////////////////////////////////

    std::string rootDirectory = "C:/Users/kamil/Desktop/PROJEKT ICE ARROW/project";
    std::string fullPath = std::string(rootDirectory) + "/db/creadentials.txt";
    std::ifstream inputFile(fullPath.c_str());

    if (!inputFile.is_open()) {
        qDebug() << "Could not open the file!";
        return false;
    }

    nlohmann::json jsonData;
    try
    {
        inputFile >> jsonData;
    } catch (const nlohmann::json::parse_error& e) {
        qDebug() << "Parse error: " << e.what() << '\n';
        return false;
    }

    std::string hostName;
    int port;
    std::string databaseName;
    std::string userName;
    std::string password;

    try
    {
        hostName = jsonData.at("HostName").get<std::string>();
        qInfo(hostName.c_str());
        port = jsonData.at("Port").get<int>();
        databaseName = jsonData.at("DatabaseName").get<std::string>();
        userName = jsonData.at("UserName").get<std::string>();
        password = jsonData.at("Password").get<std::string>();
    } catch (const nlohmann::json::out_of_range& e) {
        qDebug() << "Access errr: " << e.what() << '\n';
        return false;
    }

    ///////////////////
    // CONNECT TO DB //
    ///////////////////

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(hostName.c_str());
    db.setPort(port);
    db.setDatabaseName(databaseName.c_str());
    db.setUserName(userName.c_str());
    db.setPassword(password.c_str());

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}
