#include "C1_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

C1_base::C1_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    loadProperties();
}

C1_base::~C1_base()
{
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void C1_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Component::start();
    ThreadedComponent::startThread();
}

void C1_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void C1_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void C1_base::loadProperties()
{
    addProperty(prop1,
                1.0,
                "prop1",
                "prop1",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(prop2,
                1,
                "prop2",
                "prop2",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(prop3,
                0.0,
                "prop3",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(memCapacity,
                "DCE:8dcef419-b440-4bcf-b893-cab79b6024fb",
                "memCapacity",
                "readwrite",
                "MiB",
                "external",
                "allocation");

}


