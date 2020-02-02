# zia_modules

## Example module header:

```cpp
#include "IModule.hpp"

class ExampleModule : public IModule {
public:

    ExampleModule();

    virtual ~ExampleModule();

    /// Hook called when request came on server
    void handleRequest(HttpRequest &request) override;

    /// Hook called before response
    void handlePreResponse(HttpRequest &request, HttpResponse &response) override;

    /// Hook called before zia create instances
    void handlePreStart(std::vector<ServerInstanceConfig> &instances) override;

private:
};
```

### Hooks definition:

#### Handle Request:

```cpp
    void handleRequest(HttpRequest &request);
```
This hooks allows you to modify the client request before the server prepares the response.
It can be used for a rewrite module for example.

#### Handle Pre Response:

```cpp
    void handlePreResponse(HttpRequest &request, HttpResponse &response);
```
This hook allows you to modify the response and its content once the server has executed the request.
It can be used for a php module for example.

#### Handle Pre Start:

```cpp
    void handlePreStart(std::vector<ServerInstanceConfig> &instances);
```
This hook allows you to modify and create instances before the zia starts them.
It can be used to listen on multiple ports or to activate ssl.


## Example module source:

```cpp
    void ExampleModule::handleRequest(HttpRequest &request) {
        if (request.valid)
            std::cout << request.method << " " << request.uri << std::endl;
    }
    
    void ExampleModule::handlePreResponse(HttpRequest &request, HttpResponse &response) {
    
    }
    
    void ExampleModule::handlePreStart(std::vector<ServerInstanceConfig> &instances) {
    
    }
    
    extern "C" IModule *createObject() {
        return new ExampleModule();
    }
    
    extern "C" void destroyObject(IModule *object ) {
        delete dynamic_cast<ExampleModule *>(object);
    }
```

### Create & destroy object functions:

To be loaded dynamically the module must implement a function for the construction of the module and another for the suppression.
These functions must be marked `extern "C"`