//
// Created by guigui on 1/29/20.
//

#ifndef CPP_RTYPE_2019_HTTPREQUEST_HPP
#define CPP_RTYPE_2019_HTTPREQUEST_HPP

#include "../HttpHeader/HttpHeader.hpp"
#include <string>
#include <vector>

struct HttpRequest {
    std::string method;
    std::string uri;
    int httpMajorVersion;
    int httpMinorVersion;
    bool valid;
    std::vector<HttpHeader> headers;
};

#endif //CPP_RTYPE_2019_HTTPREQUEST_HPP
