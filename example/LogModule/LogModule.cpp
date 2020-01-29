//
// Created by guigui on 1/29/20.
//

#include "LogModule.hpp"

LogModule::LogModule() = default;

LogModule::~LogModule() = default;

void LogModule::handleRequest(HttpRequest &request) {
    if (request.valid)
        std::cout << request.method << " " << request.uri << std::endl;
}

void LogModule::handlePreResponse(HttpRequest &request, HttpResponse &response) {

}

void LogModule::handlePostResponse(HttpRequest &request, HttpResponse &response) {

}

extern "C" IModule *create_object() {
    return new LogModule();
}

extern "C" void destroy_object( IModule *object ) {
    delete dynamic_cast<LogModule *>(object);
}

