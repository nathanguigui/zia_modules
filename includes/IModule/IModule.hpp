//
// Created by guigui on 1/29/20.
//

#ifndef CPP_RTYPE_2019_IMODULE_HPP
#define CPP_RTYPE_2019_IMODULE_HPP

#include "zia_modules/includes/HttpRequest/HttpRequest.hpp"
#include "zia_modules/includes/HttpResponse/HttpResponse.hpp"
#include "zia_modules/includes/ServerInstanceConfig/ServerInstanceConfig.hpp"

class IModule {
public:

    /// Hook called when request came on server
    virtual void handleRequest(HttpRequest &request) = 0;

    /// Hook called before response
    virtual void handlePreResponse(HttpRequest &request, HttpResponse &response) = 0;

    /// Hook called before zia create all server instances
    virtual void handlePreStart(std::vector<ServerInstanceConfig> &instances) = 0;

protected:
};

extern "C" IModule *createObject();

extern "C" void destroyObject(IModule *object );


#endif //CPP_RTYPE_2019_IMODULE_HPP
